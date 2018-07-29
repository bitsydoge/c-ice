﻿#include "String_.h"
#include "Memory_.h"
#include <stdio.h>

// Number of char per int on that platform
static const int cpi = sizeof(int) / sizeof(ICE_Char);

// Number of wchar_t per int on that platform
static const int wcpi = sizeof(int) / sizeof(ICE_WChar);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//// String
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Return size of a standard string (work on ICE_String too)
int ICE_String_STDSize(ICE_StringStd string)
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
	int *tmp = (int*)(string - cpi * 2);
	return tmp[0];
}

// Return size of the string (if there is 5 letter there is 6 wchar_t with the `\0`)
int ICE_String_Contain(ICE_String string)
{
	int *tmp = (int*)(string - cpi * 2);
	return tmp[1];
}

// Init a string with header int with information about the array and the string
ICE_String ICE_String_Init(ICE_StringStd stdstring)
{
	const int size_string = ICE_String_STDSize(stdstring);
	int nb_int_to_malloc = size_string / cpi;

	if (size_string % cpi != 0)
		nb_int_to_malloc++;

	nb_int_to_malloc += 2;

	int * tmp = (int*)ICE_Malloc(sizeof(int)*nb_int_to_malloc);
	ICE_Char* string = (ICE_Char*)(tmp + 2);

	int* size_array = (int*)(string - (2 * cpi));
	int* contain_array = (int*)(string - (1 * cpi));

	*size_array = (nb_int_to_malloc - 2) * cpi;
	*contain_array = size_string;

	for (int i = 0; i < size_string; i++)
		string[i] = stdstring[i];

	return (ICE_String)string;
}

void ICE_String_Delete(ICE_String string)
{
	int *tmp = (int*)(string - (2 * cpi));
	ICE_Free(tmp);
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

	int *tmp = (int*)(ice_string - (2 * cpi));

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

	tmp = (int*)ICE_Realloc(tmp, sizeof(int)*(2 + nb_int_to_realloc));
	tmp[0] = nb_int_to_realloc * cpi;
	tmp[1] = bool_tronc ? size : contain_array;
	ice_string = (ICE_Char*)(tmp + 2);
	if (bool_tronc)
		(ice_string)[contain_array - 1] = '\0';

	*ptr_string = ice_string;
}

void ICE_String_Set(ICE_String* ptr_string, ICE_StringStd value)
{
	// Unoptimized
	ICE_String_Delete(*ptr_string);
	*ptr_string = ICE_String_Init(value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//// WString
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Return size of a standard string (work on ICE_WString too)
int ICE_WString_STDSize(ICE_WStringStd string)
{
	ICE_WChar actual; int size_string = 0;
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

// Return size of the array of a ICE_WString (dont work on std wchar_t*) (it's multiple of int)
int ICE_WString_Size(ICE_WString string)
{
	int *tmp = (int*)(string - wcpi * 2);
	return tmp[0];
}

// Return size of the string (if there is 5 letter there is 6 wchar_t with the `\0`)
int ICE_WString_Contain(ICE_WString string)
{
	int *tmp = (int*)(string - wcpi * 2);
	return tmp[1];
}

// Init a string with header int with information about the array and the string
ICE_WString ICE_WString_Init(ICE_WStringStd stdstring)
{
	const int size_string = ICE_WString_STDSize(stdstring);
	int nb_int_to_malloc = size_string / wcpi;

	if (size_string % wcpi != 0)
		nb_int_to_malloc++;

	nb_int_to_malloc += 2;

	int * tmp = (int*)ICE_Malloc(sizeof(int)*nb_int_to_malloc);
	ICE_WChar* string = (ICE_WChar*)(tmp + 2);

	int* size_array = (int*)(string - (2 * wcpi));
	int* contain_array = (int*)(string - (1 * wcpi));

	*size_array = (nb_int_to_malloc - 2) * wcpi;
	*contain_array = size_string;

	for (int i = 0; i < size_string; i++)
		string[i] = stdstring[i];

	return (ICE_WString)string;
}

void ICE_WString_Delete(ICE_WString string)
{
	int *tmp = (int*)(string - (2 * wcpi));
	ICE_Free(tmp);
}

// Draw string + header informations
void ICE_WString_Info(ICE_WString string)
{
	wprintf(L"STRING : \"%s\", SIZE : %d, CONTAIN : %d \n", string, ICE_WString_Size(string), ICE_WString_Contain(string));

}

// Resize the string, it will troncate to the exact size writed (with `\0` counted) 
// but the actual size of the array will be a multiple of wchar_t per int
void ICE_WString_Resize(ICE_WString* ptr_string, const int size)
{
	ICE_WString ice_string = *ptr_string;

	int *tmp = (int*)(ice_string - (2 * wcpi));

	int contain_array = tmp[1];

	int nb_int_to_realloc = size / wcpi;
	if (size%wcpi)
		nb_int_to_realloc++;

	int bool_tronc;

	if (size < contain_array)
	{
		bool_tronc = 1;
		contain_array = size;
	}
	else
		bool_tronc = 0;

	tmp = (int*)ICE_Realloc(tmp, sizeof(int)*(2 + nb_int_to_realloc));
	tmp[0] = nb_int_to_realloc * wcpi;
	tmp[1] = bool_tronc ? size : contain_array;
	ice_string = (ICE_WChar*)(tmp + 2);
	if (bool_tronc)
		(ice_string)[contain_array - 1] = '\0';

	*ptr_string = ice_string;
}

void ICE_WString_Set(ICE_WString* ptr_string, ICE_WStringStd value)
{
	// Unoptimized
	ICE_WString_Delete(*ptr_string);
	*ptr_string = ICE_WString_Init(value);
}