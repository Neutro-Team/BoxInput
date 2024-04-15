#ifndef VK_FUNCTIONS_H
#define VK_FUNCTIONS_H

extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;

extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
extern PFN_vkCreateInstance vkCreateInstance;

void loadGetInstanceProcAddr();
void loadPreInstanceFunctions();

#endif
