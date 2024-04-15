#include <vulkan/vulkan.h>
#include "vkFunctions.h"

void vkInit() {
    loadGetInstanceProcAddr();
    loadPreInstanceFunctions();
}

void vkDestroy() {
    // vkDeviceWaitIdle() need to be used here (no logical device rn)
}
