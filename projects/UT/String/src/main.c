#include <ICE.h>
#include "Framework/UnitTest.h"

int ICE_UT_MAIN()
{
	// ICE_String_Contain() and ICE_String_SizeSTD() and ICE_String_Free()
	ICE_StringStd test0 = "Je suis une phrase tous ce qu'il y a de banale";
	ICE_UT_EQUAL(ICE_String_STDSize(test0), 47);
	test0 = ICE_String_Init(test0);
	ICE_UT_EQUAL(ICE_String_Contain(test0), 47);
	ICE_String_Free(test0); test0 = NULL;

	// ICE_String_Cmp()
	ICE_UT_EQUAL(ICE_String_Cmp("Hello World", "Hello World"), ICE_True);
	ICE_UT_EQUAL(ICE_String_Cmp("Hello World", "Jardin Magique"), ICE_False);

	// ICE_String_Init() && ICE_String_Destroy()
	ICE_String test1 = ICE_String_Init("Hello world !");
	ICE_UT_EQUAL(ICE_String_Cmp(test1, "Hello world !"), ICE_True);
	ICE_String_Destroy(&test1);
	ICE_UT_EQUAL(test1, NULL);

	// ICE_String_Init2() && ICE_String_Destroy()
	ICE_String test2 = ICE_String_Init2("Bonsoir la pyramide de kheops");
	ICE_UT_EQUAL(ICE_String_Cmp(test2, "Bonsoir la pyramide de kheops"), ICE_True);
	ICE_String_Destroy(&test2);
	ICE_UT_EQUAL(test2, NULL);

	// ICE_String_Set()
	ICE_String test3 = ICE_String_Init("Hollaketal 55 64 21");
	ICE_String_Set(&test3, "Chatlut ahah");
	ICE_UT_EQUAL(ICE_String_Cmp(test3, "Chatlut ahah"), ICE_True);
	ICE_String test4 = ICE_String_Init("String 50 20 10 %s", "50");
	ICE_String_Set(&test3, test4);
	ICE_UT_EQUAL(ICE_String_Cmp(test3, test4), ICE_True);
	ICE_UT_EQUAL(ICE_String_Cmp(test3, "String 50 20 10 50"), ICE_True);
	ICE_UT_EQUAL(ICE_String_Cmp(test4, "String 50 20 10 50"), ICE_True);
	ICE_String_Destroy(&test3);
	ICE_String_Destroy(&test4);

	// ICE_String_Set2()
	ICE_String test5 = ICE_String_Init("Hollaketal 55 64 21");
	ICE_String_Set(&test5, "Chatlut ahah");
	ICE_UT_EQUAL(ICE_String_Cmp(test5, "Chatlut ahah"), ICE_True);
	ICE_String test6 = ICE_String_Init("String 50 20 10 %s", "50");
	ICE_String_Set(&test5, test6);
	ICE_UT_EQUAL(ICE_String_Cmp(test5, test6), ICE_True);
	ICE_UT_EQUAL(ICE_String_Cmp(test5, "String 50 20 10 50"), ICE_True);
	ICE_UT_EQUAL(ICE_String_Cmp(test5, "String 50 20 10 50"), ICE_True);
	ICE_String_Destroy(&test5);
	ICE_String_Destroy(&test6);

	// ICE_String_GetExtension() && ICE_String_ToUpper()
	ICE_String test7 = ICE_String_GetExtension("Hello.jpgaeg");
	ICE_UT_EQUAL(ICE_String_Cmp("jpgaeg", test7), ICE_True);
	ICE_String_Destroy(&test7);
	test7 = ICE_String_GetExtension("Helsqdgqsghqshsqh545487qshsqhlo.HmDe");
	ICE_UT_EQUAL(ICE_String_Cmp("HmDe", test7), ICE_True);
	ICE_String_Destroy(&test7);
	test7 = ICE_String_GetExtension("Hedddddd545457ddddzfgkgkekkekeo.abc");
	ICE_String_ToUpper(test7);
	ICE_UT_EQUAL(ICE_String_Cmp("ABC", test7), ICE_True);
	ICE_String_Destroy(&test7);

	// ICE_String_StartWith()
	ICE_UT_EQUAL(ICE_String_StartWith("Hello World","Hello"), ICE_True);
	ICE_UT_EQUAL(ICE_String_StartWith("Hello","Hello World"), ICE_False);
	ICE_UT_EQUAL(ICE_String_StartWith("res://","res://"), ICE_True);
	ICE_UT_EQUAL(ICE_String_StartWith("asset://image.png","asset://"), ICE_True);
	ICE_UT_EQUAL(ICE_String_StartWith("res://","Camembert"), ICE_False);


	// ICE_String_Resize()
	ICE_String test8 = ICE_String_Init("Hello World !");
	ICE_UT_COMPARE(ICE_String_Size(test8)%ICE_String_CPI(), ==, 0);
	ICE_String_Resize(&test8, 200);
	ICE_UT_COMPARE(ICE_String_Size(test8), !=, ICE_String_STDSize("Hello World !"));
	ICE_String_Destroy(&test8);

	ICE_UT_LOOP(5000)
	{
		ICE_String test9 = ICE_String_Init("Lorem Ipsum is simply dummy text of the printing and typesetting industry. \
					Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,\
					when an unknown printer took a galley of type and scrambled it to make a type specimen book.\
					It has survived not only five centuries, but also the leap into electronic typesetting, \
					remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset \
					sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like \
					Aldus PageMaker including versions of Lorem Ipsum.");
		ICE_UT_EQUAL(ICE_String_Contain(test9), 603);
		ICE_String_Destroy(&test9);
	}
}