#include "vkFunctions.h"
#include "lib.h"
#include "vkInstance.h"
#include "vkSurface.h"

VkInstance instance;
VkSurfaceKHR surface;

void vkInit() {
    loadGetInstanceProcAddr();
    loadPreInstanceFunctions();

    createVulkanInstance(&instance);
    loadInstanceFunctions(instance);

    createSurface(instance, &surface);

    vulkanReady = true;
}

void vkDestroy() {
    // vkDeviceWaitIdle() need to be used here (no logical device rn)

    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
}
