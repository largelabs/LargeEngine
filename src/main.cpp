#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
  std::cout << "Initializing LE environment:\n";
  glfwInit();

  VkExtensionProperties *vk_props = NULL;

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow *window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

  vk_props = (VkExtensionProperties *)realloc(vk_props, extensionCount * sizeof(VkExtensionProperties));

  vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, vk_props);

  std::cout << extensionCount << " extensions supported\n";

  for (uint32_t i = 0; i < extensionCount; i++) {
        VkExtensionProperties *props = &vk_props[i];
        std::cout << props->extensionName << ":" << std::endl;
        std::cout << "\tVersion: " << props->specVersion << std::endl;
        std::cout << std::endl << std::endl;
    }

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}
