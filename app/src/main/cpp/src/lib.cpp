#include <vulkan/vulkan.h>
#include "vulkan/vkMain.h"
#include <android/native_window.h>
#include "jni/javaConnector.h"

bool active = true;

// entry point of the app
void entry() {
    vkInit();
    while (active) {



    }
}
