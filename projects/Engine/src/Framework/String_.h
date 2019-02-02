#ifndef DEF_ICE_DYNSTRING
#define DEF_ICE_DYNSTRING

typedef char ICE_Char;

typedef ICE_Char* ICE_String;
typedef ICE_Char* ICE_StringStd;

#define ICE_STRING_MAX_BUFFER_SIZE 16384

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////// String

/**
* \brief Return the size of a std string (Work on ICE_String but is less faster)
* \param string String evaluated
* \return Size of the string
*/
int ICE_String_STDSize(ICE_StringStd string);

/**
* \brief Return size of the array of a ICE_String (dont work on std char*) (it's multiple of int)
* \param string String evaluated
* \return Size of the string
*/
int ICE_String_Size(ICE_String string);

/**
* \brief Return the containing size of the string (if there is 5 letter there is 6 wchar_t with the `\0`)
* \param string String evaluated
* \return
*/
int ICE_String_Contain(ICE_String string);

/**
* \brief Init a string with header int with information about the array and the string
* \param stdstring String to init into ICE_String
* \param ...
* \return A ICE_String that need to be Delete
*/
ICE_String ICE_String_Init(ICE_StringStd stdstring, ...);

/**
* \brief Free everything from the string
* \param string String to free
*/
void ICE_String_Free(ICE_String string);

/**
 * \brief Free a string if the dereferencer ptr to string is not null
 * \param string_ Ptr to a ICE_String
 */
void ICE_String_Destroy(ICE_String * string_);

/**
* \brief Write string on console + header information
* \param string String to write
*/
void ICE_String_Info(ICE_String string);

/**
* \brief Resize the string, it will troncate to the exact size writed (with `\0` counted)
* but the actual size of the array will be a multiple of wchar_t per int
* \param ptr_string Pointer of ICE_String
* \param size Size to resize string
*/
void ICE_String_Resize(ICE_String* ptr_string, const int size);


/**
* \brief
* \param ptr_string ptr to WString to edit
* \param value New Value
* \param ...Variables
*/
void ICE_String_Set(ICE_String* ptr_string, ICE_StringStd value, ...);

/**
 * \brief Set all the string to upper character
 * \param string string to edit to upper character
 */
void ICE_String_ToUpper(ICE_String string);

/**
 * \brief Return a string containing the extention of a path/file (ex "file.ext" will return ext)
 * you need to ICE_String_Free the returning string but the input string can be a ICE_String or a ICE_StringStd
 * \param string String to get the extention from, it can be any kind of ICE_String
 * \return 
 */
ICE_String ICE_String_GetExtension(ICE_StringStd string);


#endif

