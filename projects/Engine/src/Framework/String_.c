#include "String_.h"
#include "Memory_.h"
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include "Assert_.h"
#include "Log.h"
#include "Crossplatform_.h"
#include "BasicTypes.h"

// Number of char per int on that platform
static const int cpi = sizeof(int) / sizeof(ICE_Char);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//// String
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Return size of a standard string (work on ICE_String too)
int ICE_StringStd_Size(ICE_StringStd string)
{
	ICE_Char actual; int size_string = 0;
	if (string)
	{
		do
		{
			actual = string[size_string];
			size_string++;
		} while (actual != '\0');
	}

	return size_string;
}

// Return size of the array of a ICE_String (dont work on std wchar_t*) (it's multiple of int)
int ICE_String_Size(ICE_String string)
{
	int *tmp = (int*)(string - 2 * cpi);
	return tmp[0];
}

// Return size of the string (if there is 5 letter there is 6 wchar_t with the `\0`)
int ICE_String_Contain(ICE_String string)
{
	int *tmp = (int*)(string - 2 * cpi);
	return tmp[1];
}

// Init a string with header int with information about the array and the string
ICE_String ICE_String_Init(ICE_StringStd stdstring, ...)
{
	va_list args;
	va_start(args, stdstring);
	ICE_Char buffer[ICE_STRING_MAX_BUFFER_SIZE];
	vsnprintf(buffer, ICE_STRING_MAX_BUFFER_SIZE, stdstring, args);
	va_end(args);

	const int size_string = ICE_StringStd_Size(buffer);
	int nb_int_to_malloc = size_string / cpi;

	if (size_string % cpi != 0)
		nb_int_to_malloc++;

	nb_int_to_malloc += 2;

	int * tmp = (int*)ICE_Malloc(sizeof(int)*nb_int_to_malloc);
	ICE_Char* string = (ICE_Char*)(tmp + 2);

	int* size_array = (int*)(string - (cpi * 2));
	int* contain_array = (int*)(string - (1 * cpi));

	*size_array = (nb_int_to_malloc - 2) * cpi;
	*contain_array = size_string;

	for (int i = 0; i < size_string; i++)
		string[i] = buffer[i];

	return string;
}

ICE_String ICE_String_Init2(ICE_StringStd stdstring, ...)
{
	va_list args;
	va_start(args, stdstring);
	ICE_StringStd buffer;
	ICE_Xplat_vasprintf(&buffer, stdstring, args);
	va_end(args);

	const int size_string = ICE_StringStd_Size(buffer);
	int nb_int_to_malloc = size_string / cpi;

	if (size_string % cpi != 0)
		nb_int_to_malloc++;

	nb_int_to_malloc += 2;

	int * tmp = (int*)ICE_Malloc(sizeof(int)*nb_int_to_malloc);
	ICE_Char* string = (ICE_Char*)(tmp + 2);

	int* size_array = (int*)(string - (cpi * 2));
	int* contain_array = (int*)(string - (1 * cpi));

	*size_array = (nb_int_to_malloc - 2) * cpi;
	*contain_array = size_string;

	for (int i = 0; i < size_string; i++)
		string[i] = buffer[i];

	ICE_Free(buffer);
	return string;
}

void ICE_String_Free(ICE_String string)
{
	if(string != NULL)
	{
		int *tmp = (int*)(string - (cpi * 2));
		ICE_Free(tmp);
	}
	else
		ICE_Log_Warning("This string is already Freed");
}

void ICE_String_Destroy(ICE_String * string_)
{
	//ICE_Assert(string_ != NULL, "The pointer is NULL");
	ICE_String_Free(*string_);
	*string_ = NULL;
}

// Draw string + header informations
void ICE_String_Info(ICE_String string)
{
	printf("STRING : \"%s\", SIZE : %d, CONTAIN : %d \n", string, ICE_String_Size(string), ICE_String_Contain(string));
}

// Resize the string, it will troncate to the exact size writed (with `\0` counted) 
// but the actual size of the array will be a multiple of wchar_t per int
void ICE_String_Resize(ICE_String* ptr_string, const int size)
{
	ICE_String ice_string = *ptr_string;

	int *tmp = (int*)(ice_string - (cpi * 2));

	int contain_array = tmp[1];

	int nb_int_to_realloc = size / cpi;
	if (size%cpi)
		nb_int_to_realloc++;

	int bool_tronc;

	if (size < contain_array)
	{
		bool_tronc = 1;
		contain_array = size;
	}
	else
		bool_tronc = 0;

	tmp = (int*)ICE_Realloc(tmp, sizeof(int)*(nb_int_to_realloc + 2));
	tmp[0] = nb_int_to_realloc * cpi;
	tmp[1] = bool_tronc ? size : contain_array;
	ice_string = (ICE_Char*)(tmp + 2);
	if (bool_tronc)
		(ice_string)[contain_array - 1] = '\0';

	*ptr_string = ice_string;
}

void ICE_String_Set(ICE_String* ptr_string, ICE_StringStd value, ...)
{
	va_list args;
	va_start(args, value);
	ICE_Char buffer[ICE_STRING_MAX_BUFFER_SIZE];
	vsnprintf(buffer, ICE_STRING_MAX_BUFFER_SIZE, value, args);
	ICE_String_Free(*ptr_string);
	*ptr_string = ICE_String_Init(buffer);
	va_end(args);
}

void ICE_String_Set2(ICE_String* ptr_string, ICE_StringStd value, ...)
{
	va_list args;
	va_start(args, value);
	ICE_StringStd buffer;
	ICE_Xplat_vasprintf(&buffer, value, args);
	ICE_String_Free(*ptr_string);
	*ptr_string = ICE_String_Init(buffer);
	ICE_Free(buffer);
	va_end(args);
}

// TOOLS

void ICE_String_ToUpper(ICE_String string)
{
	for (int i = 0; i < ICE_String_Contain(string); i++)
		string[i] = toupper(string[i]);
}

ICE_String ICE_String_GetExtension(ICE_StringStd string_)
{
	ICE_StringStd ex = strrchr(string_, '.');
	if (!ex || ex == string_)
	{
		//free(ex);
		return ICE_String_Init("");
	}
	ICE_String string_returned = ICE_String_Init(ex + 1);
	//free(ex);
	return string_returned;
}

ICE_Bool ICE_String_StartWith(ICE_StringStd full, ICE_StringStd start)
{
	if(ICE_StringStd_Size(full) >= ICE_StringStd_Size(start))
	{
		for(int i = 0; i < ICE_StringStd_Size(start)-1; i++)
			if(start[i] != full[i])
				return ICE_False;
		return ICE_True;
	}
	return ICE_False;
}

int ICE_String_Cmp(ICE_StringStd a, ICE_StringStd b)
{
	if(strcmp(a, b) != 0)
		return ICE_False;
	return ICE_True;
}

int ICE_String_CPI()
{
	return cpi;
}