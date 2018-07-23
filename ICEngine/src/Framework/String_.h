#ifndef DEF_ICE_DYNSTRING
#define DEF_ICE_DYNSTRING

#include <wchar.h>

typedef wchar_t ICE_WChar;
typedef char ICE_Char;

typedef ICE_WChar* ICE_WString;
typedef ICE_WChar* ICE_WStringStd;

typedef ICE_Char* ICE_String;
typedef ICE_Char* ICE_StringStd;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////// String

/**
* \brief Return the size of a std string (Work on ICE_WString but is less faster)
* \param string String evaluated
* \return Size of the string
*/
int ICE_String_STDSize(ICE_StringStd string);

/**
* \brief Return size of the array of a ICE_WString (dont work on std char*) (it's multiple of int)
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
* \param stdstring String to init into ICE_WString
* \return A ICE_WString that need to be Delete
*/
ICE_String ICE_String_Init(ICE_StringStd stdstring);

/**
* \brief Free everything from the string
* \param string String to free
*/
void ICE_String_Delete(ICE_String string);

/**
* \brief Write string on console + header information
* \param string String to write
*/
void ICE_String_Info(ICE_String string);

/**
* \brief Resize the string, it will troncate to the exact size writed (with `\0` counted)
* but the actual size of the array will be a multiple of wchar_t per int
* \param ptr_string Pointer of ICE_WString
* \param size Size to resize string
*/
void ICE_String_Resize(ICE_String* ptr_string, const int size);


/**
* \brief
* \param ptr_string ptr to WString to edit
* \param value New Value
*/
void ICE_String_Set(ICE_String* ptr_string, ICE_StringStd value);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// WString

/**
 * \brief Return the size of a std string (Work on ICE_WString but is less faster)
 * \param string String evaluated
 * \return Size of the string
 */
int ICE_WString_STDSize(ICE_WStringStd string);

/**
 * \brief Return size of the array of a ICE_WString (dont work on std char*) (it's multiple of int)
 * \param string String evaluated
 * \return Size of the string
 */
int ICE_WString_Size(ICE_WString string);

/**
 * \brief Return the containing size of the string (if there is 5 letter there is 6 wchar_t with the `\0`)
 * \param string String evaluated
 * \return 
 */
int ICE_WString_Contain(ICE_WString string);

/**
 * \brief Init a string with header int with information about the array and the string
 * \param stdstring String to init into ICE_WString
 * \return A ICE_WString that need to be Delete
 */
ICE_WString ICE_WString_Init(ICE_WStringStd stdstring);

/**
 * \brief Free everything from the string
 * \param string String to free
 */
void ICE_WString_Delete(ICE_WString string);

/**
 * \brief Write string on console + header information
 * \param string String to write
 */
void ICE_WString_Info(ICE_WString string);

/**
 * \brief Resize the string, it will troncate to the exact size writed (with `\0` counted) 
 * but the actual size of the array will be a multiple of wchar_t per int
 * \param ptr_string Pointer of ICE_WString
 * \param size Size to resize string
 */
void ICE_WString_Resize(ICE_WString* ptr_string, const int size);


/**
 * \brief 
 * \param ptr_string ptr to WString to edit
 * \param value New Value
 */
void ICE_WString_Set(ICE_WString* ptr_string, ICE_WStringStd value);


#endif

