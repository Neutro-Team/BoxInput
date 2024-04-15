#include <vulkan/vulkan.h>
#include "vkFunctions.h"

void vkInit() {
    loadGetInstanceProcAddr();
    loadPreInstanceFunctions();
}

void vkDestroy() {

}