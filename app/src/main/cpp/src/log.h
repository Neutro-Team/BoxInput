#ifndef LOG_H
#define LOG_H

#include <android/log.h>

#define LOG(type, ...) __android_log_print(type, "BoxInput", __VA_ARGS__);

#endif
