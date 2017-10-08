#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

int ICE_InitGameEngine();
int ICE_CloseGameEngine();
void ICE_GameLoop(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));

#endif
