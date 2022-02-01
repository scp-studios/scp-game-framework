#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/graphics/opengl.hpp>
#include <scp/graphics/opengl/VertexArray.hpp>
#include <scp/graphics/opengl/VertexBuffer.hpp>
#include <scp/graphics/opengl/Shader.hpp>
#include <scp/graphics/VertexLayout.hpp>
#include <scp/graphics/opengl/ElementBuffer.hpp>
#include <scp/graphics/opengl.hpp>
#include <scp/utils/file-utils.hpp>
#include <scp/math/Matrix4.hpp>
#include <scp/math/Vector3.hpp>
#include <scp/math.hpp>
#include <scp/math/transformations.hpp>
#include <scp/Input.hpp>

using scp::Window;
using scp::Scene;
using scp::graphics::opengl::Shader;
using scp::graphics::opengl::VertexArray;
using scp::graphics::opengl::VertexBuffer;
using scp::graphics::VertexLayout;
using scp::graphics::opengl::ElementBuffer;

namespace math = scp::math;

static float deltaTime = 0.0;

class MyScene: public Scene
{
public:
    MyScene(): model(1.0f), Input(scp::Input::getInstance())
    {
        std::vector<float> vertices = {
             0.1f,  0.1f,
             0.1f, -0.1f,
            -0.1f, -0.1f,
            -0.1f,  0.1f
        };
        
        indices = {
            0, 1, 2,
            0, 3, 2
        };
        
        vertexBuffer = VertexBuffer(vertices);
        
        elementBuffer = ElementBuffer(indices);
        
        // NVIDIA's drivers demands that we bind vertex arrays before element
        // buffers for some reasons.
        vertexArray.bind();
        elementBuffer.bind();
        
        VertexLayout vertexLayout = {};
        vertexLayout.type = VertexLayout::Type::Float;
        vertexLayout.size = 2;
        vertexLayout.stride = 2 * sizeof(float);
        vertexLayout.offset = 0;
        
        vertexArray.addAttribute(0, vertexBuffer, vertexLayout);
        
        std::string shaderSource = scp::utils::file_utils::loadAsString("../shaders/opengl-math-test.glsl");
        shader = Shader(shaderSource, "../shaders/opengl-math-test.glsl");
    }
    
    void onUpdate(double p_deltaTime) override
    {
        if (Input.isKeyDown(GLFW_KEY_RIGHT))
        {
            model = math::transformations::translate(model, scp::math::Vector3(0.5f * deltaTime, 0.0f, 0.0f));
        }
        if (Input.isKeyDown(GLFW_KEY_LEFT))
        {
            model = math::transformations::translate(model, scp::math::Vector3(-0.5f * deltaTime, 0.0f, 0.0f));
        }
        if (Input.isKeyDown(GLFW_KEY_UP))
        {
            model = math::transformations::translate(model, scp::math::Vector3(0.0f, 0.5f * deltaTime, 0.0f));
        }
        if (Input.isKeyDown(GLFW_KEY_DOWN))
        {
            model = math::transformations::translate(model, scp::math::Vector3(0.0f, -0.5f * deltaTime, 0.0f));
        }
    }
    
    void render() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        shader.use();
        
        shader.setUniform("model", model);
        
        vertexArray.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    }
private:
    VertexArray vertexArray;
    VertexBuffer vertexBuffer;
    ElementBuffer elementBuffer;
    std::vector<uint8_t> indices;
    Shader shader;
    scp::math::Matrix4<float> model;
    scp::Input& Input;
};

class Application
{
public:
    Application(): window(Window::getInstance())
    {
        Scene::setActive<MyScene>();
    }
    
    void mainLoop()
    {
        window.show();
        
        while (window.isOpen())
        {
            double startTime = glfwGetTime();
            
            Scene::updateActive(0.0);
            
            Scene::renderActive();
            
            window.update();
            
            double endTime = glfwGetTime();
            deltaTime = endTime - startTime;
        }
    }
    
    ~Application()
    {
        
    }
private:
    Window& window;
};

int main()
{
    try
    {
        Application app;
        app.mainLoop();
    } catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}