#ifndef DEF_DEBUGUI_DEFINE
#define DEF_DEBUGUI_DEFINE
#if defined(_DEBUG) && !defined(__APPLE__) && defined (_IUP_DEBUGUI_USE)

void ICE_DebugGUI_ThreadStart();
void ICE_DebugGUI_ThreadFunction();
void ICE_DebugGUI_Close();

#else

#define ICE_DebugGUI_ThreadStart();
#define ICE_DebugGUI_ThreadFunction();
#define ICE_DebugGUI_Close();

#endif
#endif