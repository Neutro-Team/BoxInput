#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <thread>
#include "lib.h"
#include "vulkan/vkMain.h"

ANativeWindow* window;
bool windowReady = false;

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MyVulkanSurface_initWindow(JNIEnv* env, jclass caller, jobject surface) {
    window = ANativeWindow_fromSurface(env, surface);
    windowReady = true;
}

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MyVulkanSurface_destroyWindow(JNIEnv* env, jclass caller) {
    ANativeWindow_release(window);
}

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MainActivity_launchApp(JNIEnv* env, jclass caller) {
    std::thread mainthread(entry);
    mainthread.detach();
}

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MainActivity_destroyApp(JNIEnv* env, jclass caller) {
    active = false;
    while (!vulkanReady) {}
    vkDestroy();
}
