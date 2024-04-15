#include <vulkan/vulkan.h>
#include "vulkan/vkMain.h"
#include <android/native_window.h>
#include "jni/javaConnector.h"
#include <mutex>

bool active = true;
// since we can get a call from java to deinitialise in seperate thread, we should ensure that there's no race condition
std::mutex deinitMutex;

// entry point of the app
void entry() {
    vkInit();
    deinitMutex.lock();
    while (active) {
        deinitMutex.unlock();



        deinitMutex.lock();
    }
    deinitMutex.lock();
    vulkanAlive = false;
    vkDestroy();
    deinitMutex.unlock();
}
