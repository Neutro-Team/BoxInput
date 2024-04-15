#include <vulkan/vulkan.h>
#include <dlfcn.h>

PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;

PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkCreateInstance vkCreateInstance;

void loadGetInstanceProcAddr() {
    void* libvulkan = dlopen("libvulkan.so", RTLD_NOW);
    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(libvulkan, "vkGetInstanceProcAddr");
    dlclose(libvulkan);
}

void loadPreInstanceFunctions() {
    vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceLayerProperties");
    vkCreateInstance = (PFN_vkCreateInstance)vkGetInstanceProcAddr(nullptr, "vkCreateInstance");
}
