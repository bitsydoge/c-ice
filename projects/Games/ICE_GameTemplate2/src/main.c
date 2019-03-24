#include "Engine/Core.h"
#include "Engine/Entity.h"
#include "Engine/Debug.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"
#include "Engine/Texture.h"
#include "Framework/Random.h"
#include <stdio.h>
#include "Engine/TagComponent.h"
#include "Framework/Log.h"
#include "External/libs/strpool.h"
#include "Engine/Data.h"

#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_FULLSCREEN 0

void Debug_Draw()
{
	ICE_Debug_CameraDraw();
	ICE_Debug_DrawFps(2);
	ICE_Debug_DrawCoordinate();
	ICE_Debug_CameraControl();
}

struct DATA_GLOBAL
{
	ICE_EntityID entity_test;
	ICE_TextureID texture;
	ICE_TextureID texture2;
	ICE_TagID ennemy_tag;
	ICE_TagID allied_tag;
	ICE_TagID allied_tag_test;
	ICE_TagID explosive_tag;
	ICE_TagID test_tag;
	ICE_TagID test_tag_test;
	ICE_TagID helloworld_tag;

}; typedef struct DATA_GLOBAL DATA_GLOBAL;
ICE_DataID DATA_GLOBAL_ID = 0;

void ICE_Game_Create()
{
	DATA_GLOBAL_ID = ICE_Data_Add(sizeof(DATA_GLOBAL));
	DATA_GLOBAL* D = ICE_Data_Get(DATA_GLOBAL_ID);


	ICE_Render_Color(ICE_Color_New(50, 70, 150));
	ICE_Debug_CallbackDraw(Debug_Draw);

	D->texture = ICE_Texture_Load("res\\entity.png");
	D->texture2 = ICE_Texture_Load("res\\space.jpg");

	ICE_Graphics2D * graphics2d;
	ICE_Control2D * control2d;

	D->entity_test = ICE_Entity_Create(ICE_Vect_New(0, 0));
	graphics2d = ICE_Entity_GetGraphics2D(D->entity_test);
	control2d = ICE_Entity_GetControl2D(D->entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture2);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture2);
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	D->entity_test = ICE_Entity_Create(ICE_Vect_New(0, 0));
	graphics2d = ICE_Entity_GetGraphics2D(D->entity_test);
	control2d = ICE_Entity_GetControl2D(D->entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture);
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	D->entity_test = ICE_Entity_Create(ICE_Vect_New(100, 100));
	graphics2d = ICE_Entity_GetGraphics2D(D->entity_test);
	control2d = ICE_Entity_GetControl2D(D->entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture);
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	D->entity_test = ICE_Entity_Create(ICE_Vect_New(-100, -100));
	graphics2d = ICE_Entity_GetGraphics2D(D->entity_test);
	control2d = ICE_Entity_GetControl2D(D->entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture);
	ICE_Graphics2D_SetScale(graphics2d, ICE_Vect_New(1.5, 0.8));
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	D->entity_test = ICE_Entity_Create(ICE_Vect_New(100, -100));
	graphics2d = ICE_Entity_GetGraphics2D(D->entity_test);
	control2d = ICE_Entity_GetControl2D(D->entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture);
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	D->entity_test = ICE_Entity_Create(ICE_Vect_New(-100, 100));
	graphics2d = ICE_Entity_GetGraphics2D(D->entity_test);
	control2d = ICE_Entity_GetControl2D(D->entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, D->texture);
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	D->ennemy_tag = ICE_Tag_Create("Enemy");
	D->allied_tag = ICE_Tag_Create("Allied");
	D->allied_tag_test = ICE_Tag_Create("Allied");
	D->explosive_tag = ICE_Tag_Create("Explosive");
	D->test_tag = ICE_Tag_Create("Test");
	D->test_tag_test = ICE_Tag_Create("Test");
	D->helloworld_tag = ICE_Tag_Create("HelloWorld");

	ICE_TagComponent* tag_component = ICE_Entity_GetTagComponent(D->entity_test);
	ICE_TagComponent_Add(tag_component, D->ennemy_tag);
	ICE_TagComponent_Add(tag_component, D->allied_tag);
	ICE_TagComponent_Add(tag_component, D->test_tag);

	if (ICE_TagComponent_Have(tag_component, D->ennemy_tag))
		ICE_Log_Succes("This entity is an ennemy");
	else
		ICE_Log_Error("This entity is not an ennemy");

	if (ICE_TagComponent_Have(tag_component, D->allied_tag))
		ICE_Log_Succes("This entity is an allied");
	else
		ICE_Log_Error("This entity is not an allied");

	if (ICE_TagComponent_Have(tag_component, D->explosive_tag))
		ICE_Log_Succes("This entity is an explosive");
	else
		ICE_Log_Error("This entity is not an explosive");

	ICE_Index nb_tag;
	ICE_TagID * tag_array = ICE_TagComponent_GetAllTag(tag_component, &nb_tag);
	for(ICE_Index i = 0; i < nb_tag; i++)
		ICE_Log_Succes("%d : %s", i, ICE_Tag_GetName(tag_array[i]));
	ICE_TagComponent_GetAllTag_Free(tag_array);
}



void ICE_Game_Update()
{
	if (ICE_Input_OnPress(ICE_KEY_K))
	{
		ICE_Screenshot(NULL, "png");
	}
}

void ICE_Game_Destroy()
{
	
}