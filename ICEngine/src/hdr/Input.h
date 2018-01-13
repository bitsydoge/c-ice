#ifndef DEF_ICE_INPUT
#define DEF_ICE_INPUT

// Enum miroired from SDL_SCANCODE
enum
{
	ICE_INPUT_UNKNOWN = 0,
	ICE_INPUT_A = 4,
	ICE_INPUT_B = 5,
	ICE_INPUT_C = 6,
	ICE_INPUT_D = 7,
	ICE_INPUT_E = 8,
	ICE_INPUT_F = 9,
	ICE_INPUT_G = 10,
	ICE_INPUT_H = 11,
	ICE_INPUT_I = 12,
	ICE_INPUT_J = 13,
	ICE_INPUT_K = 14,
	ICE_INPUT_L = 15,
	ICE_INPUT_M = 16,
	ICE_INPUT_N = 17,
	ICE_INPUT_O = 18,
	ICE_INPUT_P = 19,
	ICE_INPUT_Q = 20,
	ICE_INPUT_R = 21,
	ICE_INPUT_S = 22,
	ICE_INPUT_T = 23,
	ICE_INPUT_U = 24,
	ICE_INPUT_V = 25,
	ICE_INPUT_W = 26,
	ICE_INPUT_X = 27,
	ICE_INPUT_Y = 28,
	ICE_INPUT_Z = 29,

	ICE_INPUT_1 = 30,
	ICE_INPUT_2 = 31,
	ICE_INPUT_3 = 32,
	ICE_INPUT_4 = 33,
	ICE_INPUT_5 = 34,
	ICE_INPUT_6 = 35,
	ICE_INPUT_7 = 36,
	ICE_INPUT_8 = 37,
	ICE_INPUT_9 = 38,
	ICE_INPUT_0 = 39,

	ICE_INPUT_RETURN = 40,
	ICE_INPUT_ESCAPE = 41,
	ICE_INPUT_BACKSPACE = 42,
	ICE_INPUT_TAB = 43,
	ICE_INPUT_SPACE = 44,

	ICE_INPUT_MINUS = 45,
	ICE_INPUT_EQUALS = 46,
	ICE_INPUT_LEFTBRACKET = 47,
	ICE_INPUT_RIGHTBRACKET = 48,
	ICE_INPUT_BACKSLASH = 49, /**< Located at the lower left of the return
								 *   key on ISO keyboards and at the right end
								 *   of the QWERTY row on ANSI keyboards.
								 *   Produces REVERSE SOLIDUS (backslash) and
								 *   VERTICAL LINE in a US layout, REVERSE
								 *   SOLIDUS and VERTICAL LINE in a UK Mac
								 *   layout, NUMBER SIGN and TILDE in a UK
								 *   Windows layout, DOLLAR SIGN and POUND SIGN
								 *   in a Swiss German layout, NUMBER SIGN and
								 *   APOSTROPHE in a German layout, GRAVE
								 *   ACCENT and POUND SIGN in a French Mac
								 *   layout, and ASTERISK and MICRO SIGN in a
								 *   French Windows layout.
								 */
	ICE_INPUT_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
								 *   instead of 49 for the same key, but all
								 *   OSes I've seen treat the two codes
								 *   identically. So, as an implementor, unless
								 *   your keyboard generates both of those
								 *   codes and your OS treats them differently,
								 *   you should generate ICE_INPUT_BACKSLASH
								 *   instead of this code. As a user, you
								 *   should not rely on this code because SDL
								 *   will never generate it with most (all?)
								 *   keyboards.
								 */
	ICE_INPUT_SEMICOLON = 51,
	ICE_INPUT_APOSTROPHE = 52,
	ICE_INPUT_GRAVE = 53, /**< Located in the top left corner (on both ANSI
							 *   and ISO keyboards). Produces GRAVE ACCENT and
							 *   TILDE in a US Windows layout and in US and UK
							 *   Mac layouts on ANSI keyboards, GRAVE ACCENT
							 *   and NOT SIGN in a UK Windows layout, SECTION
							 *   SIGN and PLUS-MINUS SIGN in US and UK Mac
							 *   layouts on ISO keyboards, SECTION SIGN and
							 *   DEGREE SIGN in a Swiss German layout (Mac:
							 *   only on ISO keyboards), CIRCUMFLEX ACCENT and
							 *   DEGREE SIGN in a German layout (Mac: only on
							 *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
							 *   French Windows layout, COMMERCIAL AT and
							 *   NUMBER SIGN in a French Mac layout on ISO
							 *   keyboards, and LESS-THAN SIGN and GREATER-THAN
							 *   SIGN in a Swiss German, German, or French Mac
							 *   layout on ANSI keyboards.
							 */
	ICE_INPUT_COMMA = 54,
	ICE_INPUT_PERIOD = 55,
	ICE_INPUT_SLASH = 56,

	ICE_INPUT_CAPSLOCK = 57,

	ICE_INPUT_F1 = 58,
	ICE_INPUT_F2 = 59,
	ICE_INPUT_F3 = 60,
	ICE_INPUT_F4 = 61,
	ICE_INPUT_F5 = 62,
	ICE_INPUT_F6 = 63,
	ICE_INPUT_F7 = 64,
	ICE_INPUT_F8 = 65,
	ICE_INPUT_F9 = 66,
	ICE_INPUT_F10 = 67,
	ICE_INPUT_F11 = 68,
	ICE_INPUT_F12 = 69,

	ICE_INPUT_PRINTSCREEN = 70,
	ICE_INPUT_SCROLLLOCK = 71,
	ICE_INPUT_PAUSE = 72,
	ICE_INPUT_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
							  does send code 73, not 117) */
	ICE_INPUT_HOME = 74,
	ICE_INPUT_PAGEUP = 75,
	ICE_INPUT_DELETE = 76,
	ICE_INPUT_END = 77,
	ICE_INPUT_PAGEDOWN = 78,
	ICE_INPUT_RIGHT = 79,
	ICE_INPUT_LEFT = 80,
	ICE_INPUT_DOWN = 81,
	ICE_INPUT_UP = 82,

	ICE_INPUT_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
									*/
	ICE_INPUT_KP_DIVIDE = 84,
	ICE_INPUT_KP_MULTIPLY = 85,
	ICE_INPUT_KP_MINUS = 86,
	ICE_INPUT_KP_PLUS = 87,
	ICE_INPUT_KP_ENTER = 88,
	ICE_INPUT_KP_1 = 89,
	ICE_INPUT_KP_2 = 90,
	ICE_INPUT_KP_3 = 91,
	ICE_INPUT_KP_4 = 92,
	ICE_INPUT_KP_5 = 93,
	ICE_INPUT_KP_6 = 94,
	ICE_INPUT_KP_7 = 95,
	ICE_INPUT_KP_8 = 96,
	ICE_INPUT_KP_9 = 97,
	ICE_INPUT_KP_0 = 98,
	ICE_INPUT_KP_PERIOD = 99,

	ICE_INPUT_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
									   *   keyboards have over ANSI ones,
									   *   located between left shift and Y.
									   *   Produces GRAVE ACCENT and TILDE in a
									   *   US or UK Mac layout, REVERSE SOLIDUS
									   *   (backslash) and VERTICAL LINE in a
									   *   US or UK Windows layout, and
									   *   LESS-THAN SIGN and GREATER-THAN SIGN
									   *   in a Swiss German, German, or French
									   *   layout. */
	ICE_INPUT_APPLICATION = 101, /**< windows contextual menu, compose */
	ICE_INPUT_POWER = 102, /**< The USB document says this is a status flag,
							  *   not a physical key - but some Mac keyboards
							  *   do have a power key. */
	ICE_INPUT_KP_EQUALS = 103,
	ICE_INPUT_F13 = 104,
	ICE_INPUT_F14 = 105,
	ICE_INPUT_F15 = 106,
	ICE_INPUT_F16 = 107,
	ICE_INPUT_F17 = 108,
	ICE_INPUT_F18 = 109,
	ICE_INPUT_F19 = 110,
	ICE_INPUT_F20 = 111,
	ICE_INPUT_F21 = 112,
	ICE_INPUT_F22 = 113,
	ICE_INPUT_F23 = 114,
	ICE_INPUT_F24 = 115,
	ICE_INPUT_EXECUTE = 116,
	ICE_INPUT_HELP = 117,
	ICE_INPUT_MENU = 118,
	ICE_INPUT_SELECT = 119,
	ICE_INPUT_STOP = 120,
	ICE_INPUT_AGAIN = 121,   /**< redo */
	ICE_INPUT_UNDO = 122,
	ICE_INPUT_CUT = 123,
	ICE_INPUT_COPY = 124,
	ICE_INPUT_PASTE = 125,
	ICE_INPUT_FIND = 126,
	ICE_INPUT_MUTE = 127,
	ICE_INPUT_VOLUMEUP = 128,
	ICE_INPUT_VOLUMEDOWN = 129,
	/* not sure whether there's a reason to enable these */
	/*     ICE_INPUT_LOCKINGCAPSLOCK = 130,  */
	/*     ICE_INPUT_LOCKINGNUMLOCK = 131, */
	/*     ICE_INPUT_LOCKINGSCROLLLOCK = 132, */
	ICE_INPUT_KP_COMMA = 133,
	ICE_INPUT_KP_EQUALSAS400 = 134,

	ICE_INPUT_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
									   footnotes in USB doc */
	ICE_INPUT_INTERNATIONAL2 = 136,
	ICE_INPUT_INTERNATIONAL3 = 137, /**< Yen */
	ICE_INPUT_INTERNATIONAL4 = 138,
	ICE_INPUT_INTERNATIONAL5 = 139,
	ICE_INPUT_INTERNATIONAL6 = 140,
	ICE_INPUT_INTERNATIONAL7 = 141,
	ICE_INPUT_INTERNATIONAL8 = 142,
	ICE_INPUT_INTERNATIONAL9 = 143,
	ICE_INPUT_LANG1 = 144, /**< Hangul/English toggle */
	ICE_INPUT_LANG2 = 145, /**< Hanja conversion */
	ICE_INPUT_LANG3 = 146, /**< Katakana */
	ICE_INPUT_LANG4 = 147, /**< Hiragana */
	ICE_INPUT_LANG5 = 148, /**< Zenkaku/Hankaku */
	ICE_INPUT_LANG6 = 149, /**< reserved */
	ICE_INPUT_LANG7 = 150, /**< reserved */
	ICE_INPUT_LANG8 = 151, /**< reserved */
	ICE_INPUT_LANG9 = 152, /**< reserved */

	ICE_INPUT_ALTERASE = 153, /**< Erase-Eaze */
	ICE_INPUT_SYSREQ = 154,
	ICE_INPUT_CANCEL = 155,
	ICE_INPUT_CLEAR = 156,
	ICE_INPUT_PRIOR = 157,
	ICE_INPUT_RETURN2 = 158,
	ICE_INPUT_SEPARATOR = 159,
	ICE_INPUT_OUT = 160,
	ICE_INPUT_OPER = 161,
	ICE_INPUT_CLEARAGAIN = 162,
	ICE_INPUT_CRSEL = 163,
	ICE_INPUT_EXSEL = 164,

	ICE_INPUT_KP_00 = 176,
	ICE_INPUT_KP_000 = 177,
	ICE_INPUT_THOUSANDSSEPARATOR = 178,
	ICE_INPUT_DECIMALSEPARATOR = 179,
	ICE_INPUT_CURRENCYUNIT = 180,
	ICE_INPUT_CURRENCYSUBUNIT = 181,
	ICE_INPUT_KP_LEFTPAREN = 182,
	ICE_INPUT_KP_RIGHTPAREN = 183,
	ICE_INPUT_KP_LEFTBRACE = 184,
	ICE_INPUT_KP_RIGHTBRACE = 185,
	ICE_INPUT_KP_TAB = 186,
	ICE_INPUT_KP_BACKSPACE = 187,
	ICE_INPUT_KP_A = 188,
	ICE_INPUT_KP_B = 189,
	ICE_INPUT_KP_C = 190,
	ICE_INPUT_KP_D = 191,
	ICE_INPUT_KP_E = 192,
	ICE_INPUT_KP_F = 193,
	ICE_INPUT_KP_XOR = 194,
	ICE_INPUT_KP_POWER = 195,
	ICE_INPUT_KP_PERCENT = 196,
	ICE_INPUT_KP_LESS = 197,
	ICE_INPUT_KP_GREATER = 198,
	ICE_INPUT_KP_AMPERSAND = 199,
	ICE_INPUT_KP_DBLAMPERSAND = 200,
	ICE_INPUT_KP_VERTICALBAR = 201,
	ICE_INPUT_KP_DBLVERTICALBAR = 202,
	ICE_INPUT_KP_COLON = 203,
ICE_INPUT_KP_HASH = 204,
ICE_INPUT_KP_SPACE = 205,
ICE_INPUT_KP_AT = 206,
ICE_INPUT_KP_EXCLAM = 207,
ICE_INPUT_KP_MEMSTORE = 208,
ICE_INPUT_KP_MEMRECALL = 209,
ICE_INPUT_KP_MEMCLEAR = 210,
ICE_INPUT_KP_MEMADD = 211,
ICE_INPUT_KP_MEMSUBTRACT = 212,
ICE_INPUT_KP_MEMMULTIPLY = 213,
ICE_INPUT_KP_MEMDIVIDE = 214,
ICE_INPUT_KP_PLUSMINUS = 215,
ICE_INPUT_KP_CLEAR = 216,
ICE_INPUT_KP_CLEARENTRY = 217,
ICE_INPUT_KP_BINARY = 218,
ICE_INPUT_KP_OCTAL = 219,
ICE_INPUT_KP_DECIMAL = 220,
ICE_INPUT_KP_HEXADECIMAL = 221,

ICE_INPUT_LCTRL = 224,
ICE_INPUT_LSHIFT = 225,
ICE_INPUT_LALT = 226, /**< alt, option */
ICE_INPUT_LGUI = 227, /**< windows, command (apple), meta */
ICE_INPUT_RCTRL = 228,
ICE_INPUT_RSHIFT = 229,
ICE_INPUT_RALT = 230, /**< alt gr, option */
ICE_INPUT_RGUI = 231, /**< windows, command (apple), meta */

ICE_INPUT_MODE = 257,    /**< I'm not sure if this is really not covered
							*   by any of the above, but since there's a
							*   special KMOD_MODE for it I'm adding it here
							*/

							/* @} *//* Usage page 0x07 */

									/**
									*  \name Usage page 0x0C
									*
									*  These values are mapped from usage page 0x0C (USB consumer page).
									*/
									/* @{ */

	ICE_INPUT_AUDIONEXT = 258,
	ICE_INPUT_AUDIOPREV = 259,
	ICE_INPUT_AUDIOSTOP = 260,
	ICE_INPUT_AUDIOPLAY = 261,
	ICE_INPUT_AUDIOMUTE = 262,
	ICE_INPUT_MEDIASELECT = 263,
	ICE_INPUT_WWW = 264,
	ICE_INPUT_MAIL = 265,
	ICE_INPUT_CALCULATOR = 266,
	ICE_INPUT_COMPUTER = 267,
	ICE_INPUT_AC_SEARCH = 268,
	ICE_INPUT_AC_HOME = 269,
	ICE_INPUT_AC_BACK = 270,
	ICE_INPUT_AC_FORWARD = 271,
	ICE_INPUT_AC_STOP = 272,
	ICE_INPUT_AC_REFRESH = 273,
	ICE_INPUT_AC_BOOKMARKS = 274,

	/* @} *//* Usage page 0x0C */

			/**
			*  \name Walther keys
			*
			*  These are values that Christian Walther added (for mac keyboard?).
			*/
			/* @{ */

	ICE_INPUT_BRIGHTNESSDOWN = 275,
	ICE_INPUT_BRIGHTNESSUP = 276,
	ICE_INPUT_DISPLAYSWITCH = 277, /**< display mirroring/dual display
									  switch, video mode switch */
	ICE_INPUT_KBDILLUMTOGGLE = 278,
	ICE_INPUT_KBDILLUMDOWN = 279,
	ICE_INPUT_KBDILLUMUP = 280,
	ICE_INPUT_EJECT = 281,
	ICE_INPUT_SLEEP = 282,

	ICE_INPUT_APP1 = 283,
	ICE_INPUT_APP2 = 284,

	/* @} *//* Walther keys */

			/**
			*  \name Usage page 0x0C (additional media keys)
			*
			*  These values are mapped from usage page 0x0C (USB consumer page).
			*/
			/* @{ */

	ICE_INPUT_AUDIOREWIND = 285,
	ICE_INPUT_AUDIOFASTFORWARD = 286,

	/* @} *//* Usage page 0x0C (additional media keys) */

			/* Add any other keys here. */

	ICE_INPUT_SCANCODES = 512, /**< not a key, just marks the number of scancodes
							for array bounds */
	ICE_INPUT_OTHER = 600,

	//  Mouse
	ICE_INPUT_LEFTCLICK = 601,
	ICE_INPUT_RIGHTCLICK = 602,
	ICE_INPUT_WHEELUP = 603,
	ICE_INPUT_WHEELDOWN = 604
};

#include "TypesCore.h"
#include <string.h>
#include <stdio.h>
#include "Terminal.h"

int iceInputReturn();
void iceInputReset();
iceBool iceInputButton(int button);

#endif