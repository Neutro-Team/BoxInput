#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <thread>
#include <mutex>
#include "lib.h"
#include "vulkan/vkMain.h"

ANativeWindow* window = nullptr;
bool windowAlive = false;
bool vulkanAlive = true;

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MyVulkanSurface_initWindow(JNIEnv* env, jclass caller, jobject surface) {
    window = ANativeWindow_fromSurface(env, surface);
    windowAlive = true;
}

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MyVulkanSurface_destroyWindow(JNIEnv* env, jclass caller) {
    deinitMutex.lock();
    active = false;
    if (windowAlive) {
        windowAlive = false;
        if (vulkanAlive) {
            vulkanAlive = false;
            vkDestroy();
        }
        ANativeWindow_release(window);
    }
    deinitMutex.unlock();
}

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MainActivity_launchApp(JNIEnv* env, jclass caller) {
    std::thread mainthread(entry);
    mainthread.detach();
}

extern "C" JNIEXPORT void JNICALL Java_com_cucumbers_boxinput_MainActivity_destroyApp(JNIEnv* env, jclass caller) {
    deinitMutex.lock();
    active = false;
    if (windowAlive) {
        windowAlive = false;
        if (vulkanAlive) {
            vulkanAlive = false;
            vkDestroy();
        }
        ANativeWindow_release(window);
    }
<<<<<<< HEAD
    deinitMutex.unlock();
=======
>>>>>>> a5416b2d22950b6472f2c1109c493074cab5f1ad
}
