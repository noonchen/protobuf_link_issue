#pragma once

#include <cstddef>

#ifdef _WIN32
  #ifdef SER_BUILD
    #define SER_API __declspec(dllexport)
  #else
    #define SER_API __declspec(dllimport)
  #endif
#else
  #define SER_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

SER_API size_t ser(const char* msg);

#ifdef __cplusplus
}
#endif
