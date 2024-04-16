#ifndef VK_FUNCTIONS_H
#define VK_FUNCTIONS_H

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_android.h>

extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;

extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
extern PFN_vkCreateInstance vkCreateInstance;

extern PFN_vkDestroyInstance vkDestroyInstance;
extern PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
extern PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;

void loadGetInstanceProcAddr();
void loadPreInstanceFunctions();
void loadInstanceFunctions(VkInstance& instance);

#endif
