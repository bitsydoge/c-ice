#ifndef ICE_GUARD_INLINE
#define ICE_GUARD_INLINE

#if defined(__APPLE__)
#define ICE_INLINE static inline 
#elif defined(_MSC_VER)
#define ICE_INLINE __forceinline
#else
#define ICE_INLINE inline
#endif

#endif