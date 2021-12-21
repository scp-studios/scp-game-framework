#include <stdlib.h>

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
#include <scp/utils/string_utils.hpp>

using scp::Window;
using scp::Scene;
namespace opengl = scp::graphics::opengl;
using scp::graphics::opengl::Shader;
using scp::graphics::opengl::VertexArray;
using scp::graphics::opengl::VertexBuffer;
using scp::graphics::VertexLayout;
using scp::graphics::opengl::ElementBuffer;

class MyScene: public Scene
{
public:
    MyScene()
    {
        std::vector<float> vertices = {
             0.5f,  0.5f,
             0.5f, -0.5f,
            -0.5f, -0.5f,
            -0.5f,  0.5f
        };
        
        indices = {
            0, 1, 2,
            0, 3, 2
        };
        
        vertexBuffer = VertexBuffer(vertices);
        
        elementBuffer = ElementBuffer(indices);
        
        elementBuffer.bind();
        
        VertexLayout vertexLayout = {};
        vertexLayout.type = VertexLayout::Type::Float;
        vertexLayout.size = 2;
        vertexLayout.stride = 2 * sizeof(float);
        vertexLayout.offset = 0;
        
        vertexArray.addAttribute(0, vertexBuffer, vertexLayout);
        
        std::string shaderSource = scp::utils::file_utils::loadAsString("../shaders/opengl-graphics-test.glsl");
        shader = Shader(shaderSource);
    }
    
    void onUpdate() override
    {
        
    }
    
    void render() override
    {
        shader.use();
        
        std::cout << "Render" << std::endl;
        
        vertexArray.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    }
    
    ~MyScene()
    {
        
    }
    
private:
    VertexArray vertexArray;
    VertexBuffer vertexBuffer;
    ElementBuffer elementBuffer;
    std::vector<uint8_t> indices;
    Shader shader;
};

class Application
{
public:
    Application(): window(Window::getInstance())
    {
        //opengl::enableContextDebugging();
        
        Scene::setActive<MyScene>();
        
        window.show();
        
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        
        while (window.isOpen())
        {
            Scene::updateActive();
            
            glClear(GL_COLOR_BUFFER_BIT);
            
            Scene::renderActive();
            
            window.update();
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
    //#ifdef DO_NOT_DEFINE_THIS_MACRO_OR_ELSE_I_WILL_COME_OVER_TO_YOUR_HOUSE_AND_BEAT_YOU_WITH_A_BAT
    try
    {
        Application app;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    //#endif
    
    //std::cout << scp::utils::string_utils::startsWith("Hello World!", "Hello");
    
    return EXIT_SUCCESS;
}