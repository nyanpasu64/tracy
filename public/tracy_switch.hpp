#pragma once

#include <cstring>
#include <switch.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

namespace tracy
{

#define TRACY_HAS_CUSTOM_SAFE_COPY
inline bool PlatformSafeMemcpy( void* /*dst*/, const void* /*src*/, size_t /*size*/ ) {
    return false;
}

#define TRACY_HAS_CUSTOM_THREAD_ID
inline uint32_t PlatformGetThreadId() {
    return (uint32_t) threadGetCurHandle();
}

#define TRACY_HAS_CUSTOM_USER_INFO
inline void PlatformGetHostname( char* buf, size_t size ) {
    if (gethostname(buf, size) < 0) {
        strcpy(buf, "switch");  // we receive 512 bytes
    }
}
inline const char* PlatformGetUserLogin() {
    return "switch";
}
inline const char* PlatformGetUserFullName() {
    return "switch";
}

}
