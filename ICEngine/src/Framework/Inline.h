#ifndef ICE_GUARD_INLINE
#define ICE_GUARD_INLINE

#if defined(__APPLE__)
#define ICE_INLINE static inline
#else
#define ICE_INLINE inline
#endif

#endif