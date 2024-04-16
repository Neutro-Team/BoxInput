#include <android/native_window.h>
#include "vkFunctions.h"
#include "jni/javaConnector.h"
#include "log.h"

void createSurface(VkInstance& instance, VkSurfaceKHR* holder) {
    while (!windowReady) {}

    VkAndroidSurfaceCreateInfoKHR surfaceInfo = {};
    surfaceInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    surfaceInfo.window = window;

    if (vkCreateAndroidSurfaceKHR(instance, &surfaceInfo, nullptr, holder) != VK_SUCCESS)
        LOG(ANDROID_LOG_FATAL, "failed to create android vulkan surface");
}
