#include <stdexcept>
#include <glad/glad.h>

#include <scp/Scene.hpp>
#include <scp/events.hpp>

#include <scp/Window.hpp>

#include <scp/graphics/opengl.hpp>

using scp::Window;
using scp::graphics::API;

static void errorCallback(int p_code, const char* p_message)
{
    std::cerr << "[GLFW ERROR " << p_code << "]: " << p_message << std::endl;
}










Window& Window::getInstance(int32_t p_width, 
            int32_t p_height, 
            std::string_view p_title, 
            bool p_fullscreen,
            graphics::API p_api,
            bool p_debugging)
{
    static Window window(p_width, p_height, p_title, p_fullscreen, p_api, p_debugging);
    return window;
}










Window::Window(int32_t p_width, int32_t p_height, std::string_view p_title, bool p_fullscreen, API p_graphicsAPI, bool p_debugging):
m_graphicsAPI(p_graphicsAPI)
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    glfwSetErrorCallback(errorCallback);
    
    if (p_graphicsAPI == API::OpenGL)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        if (p_debugging)
        {
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
        }
    }
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    // Determine the width of the window.
    if (p_width == SCREEN_SIZE)
    {
        m_width = videoMode->width;
    } 
    else if (p_width == HALF_SCREEN_SIZE)
    {
        m_width = videoMode->width / 2;
    }
    else if (p_width == SCREEN_SIZE_TIMES_66_PERCENT)
    {
        m_width = videoMode->width * 0.666666666666666666666666666667;
    }
    else
    {
        m_width = p_width;
    }
    
    // Determine the height of the window
    if (p_height == SCREEN_SIZE)
    {
        m_height = videoMode->height;
    }
    else if (p_height == HALF_SCREEN_SIZE)
    {
        m_height = videoMode->height / 2;
    }
    else if (p_height == SCREEN_SIZE_TIMES_66_PERCENT)
    {
        m_height = videoMode->height * 0.666666666666666666666666666667;
    }
    else
    {
        m_height = p_height;
    }
    
    GLFWmonitor* monitor = nullptr;
    
    // Determine if it is fullscreen
    if (p_fullscreen)
    {
        monitor = glfwGetPrimaryMonitor();
    }
    
    // Finally, create the window
    m_window = glfwCreateWindow(m_width, m_height, p_title.data(), monitor, nullptr);
    if (m_window == nullptr)
    {
        throw std::runtime_error("Failed to create the window.");
    }
    
    glfwSetWindowUserPointer(m_window, this);
    
    glfwSetWindowPos(m_window, (videoMode->width - m_width) / 2, (videoMode->height - m_height) / 2);
    
    // Perform OpenGL specific operations
    if (p_graphicsAPI == API::OpenGL)
    {
        glfwMakeContextCurrent(m_window);
        
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            throw std::runtime_error("Failed to initialize GLAD.");
        }
        
        if (p_debugging)
        {
            graphics::opengl::enableContextDebugging();
        }
    }
    
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    glfwSetKeyCallback(m_window, keyCallback);
    glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
    glfwSetCursorPosCallback(m_window, mousePosCallback);
    glfwSetScrollCallback(m_window, scrollCallback);
}










void Window::show() const
{
    glfwShowWindow(m_window);
}










bool Window::isOpen() const
{
    return !glfwWindowShouldClose(m_window);
}










uint32_t Window::getWidth() const
{
    return m_width;
}










uint32_t Window::getHeight() const
{
    return m_height;
}










void Window::update() const
{
    if (m_graphicsAPI == API::OpenGL)
    {
        glfwSwapBuffers(m_window);
    }
    
    glfwPollEvents();
}










Window::~Window()
{
    glfwDestroyWindow(m_window);
}










void Window::keyCallback(GLFWwindow* p_window, int p_keycode, int p_scancode, int p_action, int p_mods)
{
    events::KeyPressEvent event = {};
    event.m_key = p_keycode;
    event.m_scancode = p_scancode;
    event.m_action = p_action;
    event.m_mods = p_mods;
    
    Scene::activeScene->onKeyPress(event);
}










void Window::mouseButtonCallback(GLFWwindow* p_window, int p_button, int p_action, int p_mods)
{
    events::MouseButtonEvent event = {};
    event.m_button = p_button;
    event.m_action = p_action;
    event.m_mods = p_mods;
    
    Scene::activeScene->onMouseClick(event);
}










void Window::mousePosCallback(GLFWwindow* p_window, double p_x, double p_y)
{
    events::MouseMoveEvent event = {};
    event.m_x = p_x;
    event.m_y = p_y;
    
    Scene::activeScene->onMouseMove(event);
}










void Window::scrollCallback(GLFWwindow* p_window, double p_xoffset, double p_yoffset)
{
    events::MouseScrollEvent event = {};
    event.m_xoffset = p_xoffset;
    event.m_yoffset = p_yoffset;
    
    Window* windowObject = reinterpret_cast<Window*>(glfwGetWindowUserPointer(p_window));
    
    windowObject->m_totalScrollAmountX += p_xoffset;
    windowObject->m_totalScrollAmountY += p_yoffset;
    
    Scene::activeScene->onMouseScroll(event);
}










void Window::framebufferSizeCallback(GLFWwindow* p_window, int p_width, int p_height)
{
    Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(p_window));
    window->m_width = p_width;
    window->m_height = p_height;
    
    if (window->m_graphicsAPI == graphics::API::OpenGL)
    {
        glViewport(0, 0, p_width, p_height);
    }
}