#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>

#include <iostream>

void logVkExtensionProperties()
{
  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

  VkExtensionProperties *vk_props = (VkExtensionProperties *)malloc(extensionCount * sizeof(VkExtensionProperties));

  vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, vk_props);

  std::cout << extensionCount << " extensions supported on this system" << std::endl;
  std::cout << "_____________________________" << std::endl;

  for (uint32_t i = 0; i < extensionCount; i++) 
  {
    VkExtensionProperties *props = &vk_props[i];
    std::cout << props->extensionName << ":" << std::endl;
    std::cout << "\tVersion: " << props->specVersion << std::endl;
    std::cout << "_____________________________" << std::endl;
  }


  free(vk_props);
}

int main()
{
  std::cout << "Initializing LE environment:\n";
  glfwInit();
  logVkExtensionProperties();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow *window = glfwCreateWindow(1024, 768, "Vulkan window", nullptr, nullptr);

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}


