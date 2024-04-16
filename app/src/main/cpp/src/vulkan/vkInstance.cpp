#include <array>
#include "vkFunctions.h"
#include "log.h"

constexpr bool usevvl = true;

void createVulkanInstance(VkInstance* holder) {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.apiVersion = VK_API_VERSION_1_0;

    constexpr std::array<const char*, 2> exts = {
        "VK_KHR_surface",
        "VK_KHR_android_surface"
    };

    VkInstanceCreateInfo instanceInfo = {};
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pApplicationInfo = &appInfo;
    instanceInfo.enabledExtensionCount = exts.size();
    instanceInfo.ppEnabledExtensionNames = exts.data();

    if (usevvl) {
        constexpr std::array<const char*, 1> layers = {
            "VK_LAYER_KHRONOS_validation"
        };

        // the validation layer is included in apk so there's no way for it to not exist, so i think we can skip checking for it 

        instanceInfo.enabledLayerCount = layers.size();
        instanceInfo.ppEnabledLayerNames = layers.data();
    }

    if (vkCreateInstance(&instanceInfo, nullptr, holder) != VK_SUCCESS)
        LOG(ANDROID_LOG_FATAL, "failed to create vulkan instance");
}
