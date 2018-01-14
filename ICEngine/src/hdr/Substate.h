#ifndef DEF_ICE_SUBSTATE
#define DEF_ICE_SUBSTATE

int iceSubstateLoop(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));
void iceSubstateQuit();

#endif
