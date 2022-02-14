#include <scp/utils/time-utils.hpp>
#include <GLFW/glfw3.h>

double scp::time_utils::getGLFWTime()
{
    return glfwGetTime();
}