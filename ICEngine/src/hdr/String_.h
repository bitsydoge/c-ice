#ifndef DEF_ICE_DYNSTRING
#define DEF_ICE_DYNSTRING

typedef char* ICE_String;

int ICE_String_STDSize(char * string);

// Return size of the array of a ICE_String (dont work on std char*) (it's multiple of int)
int ICE_String_Size(ICE_String string);

// Return size of the string (if there is 5 letter there is 6 char with the `\0`)
int ICE_String_Contain(ICE_String string);

// Init a string with header int with information about the array and the string
ICE_String ICE_String_Init(char* stdstring);

void ICE_String_Delete(ICE_String string);

// Draw string + header informations
void ICE_String_Write(ICE_String string);

// Resize the string, it will troncate to the exact size writed (with `\0` counted) 
// but the actual size of the array will be a multiple of char per int
void ICE_String_Resize(ICE_String* ptr_string, int size);

#endif

