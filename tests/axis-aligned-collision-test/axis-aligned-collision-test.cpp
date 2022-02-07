#include <stdlib.h>

//#ifdef DO_NOT_DEFINE_THIS_MACRO_OR_ELSE_I_WILL_COME_OVER_TO_YOUR_HOUSE_AND_BEAT_YOU_WITH_A_BAT

#include <glad/glad.h>

#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/Input.hpp>
#include <scp/math.hpp>

#include <scp/graphics/opengl.hpp>
#include <scp/graphics/Renderer2D.hpp>
#include <scp/graphics/API.hpp>
#include <scp/graphics/Sprite.hpp>

#include <scp/physics/AxisAlignedBoxCollider.hpp>

#include <scp/utils/file-utils.hpp>

using scp::Window;
using scp::Scene;

using scp::graphics::Renderer2D;
using scp::graphics::Sprite;

using scp::math::Vector4;
using scp::math::Vector2;

using scp::physics::AxisAlignedBoxCollider;

namespace opengl = scp::graphics::opengl;
namespace fileutils = scp::utils::file_utils;

class MyScene: public Scene
{
public:
    MyScene(): renderer(scp::graphics::API::OpenGL, fileutils::loadAsString("../shaders/opengl_renderer2d.glsl")),
               thing1Collider(800 + 128, 800, 200, 200 + 128),
               thing2Collider(400 + 200, 400, 300, 300 + 200),
               Input(scp::Input::getInstance())
    {
        renderer.addTexture("../textures/TestTexture.png");
        
        opengl::enable2DBlending();
        
        thing1.baseColor = Vector4(0.0f);
        thing1.texture = 0;
        thing1.uv[0] = Vector2(1.0f, 0.0f);
        thing1.uv[1] = Vector2(1.0f, 1.0f);
        thing1.uv[2] = Vector2(0.0f, 1.0f);
        thing1.uv[3] = Vector2(0.0f, 0.0f);
        thing1.scale = Vector2(128.0f, 128.0f);
        thing1.position = Vector2(800.0f, 200.0f);
        thing1.applyTransforms();
        
        thing2.baseColor = Vector4(0.0f, 1.0f, 0.0f, 0.5f);
        thing2.texture = -1;
        thing2.uv[0] = Vector2(0.0f, 0.0f);
        thing2.uv[1] = Vector2(0.0f, 0.0f);
        thing2.uv[2] = Vector2(0.0f, 0.0f);
        thing2.uv[3] = Vector2(0.0f, 0.0f);
        thing2.scale = Vector2(200.0f, 200.0f);
        thing2.position = Vector2(400.0f, 300.0f);
        thing2.applyTransforms();
    }
    
    void onUpdate(double deltaTime) override
    {
        const double speed = 200.0;
        
        if (Input.isKeyDown(GLFW_KEY_UP))
        {
            thing1.position.y -= speed * deltaTime;
            thing1Collider.moveAlongY(-50.0 * deltaTime);
        }
        if (Input.isKeyDown(GLFW_KEY_DOWN))
        {
            thing1.position.y += speed * deltaTime;
            thing1Collider.moveAlongY(50.0 * deltaTime);
        }
        if (Input.isKeyDown(GLFW_KEY_LEFT))
        {
            thing1.position.x -= speed * deltaTime;
            thing1Collider.moveAlongX(-50.0 * deltaTime);
        }
        if (Input.isKeyDown(GLFW_KEY_RIGHT))
        {
            thing1.position.x += speed * deltaTime;
            thing1Collider.moveAlongX(50.0 * deltaTime);
        }
        
        if (Input.isKeyDown(GLFW_KEY_W))
        {
            thing2.position.y -= speed * deltaTime;
            thing2Collider.moveAlongY(-50.0 * deltaTime);
        }
        if (Input.isKeyDown(GLFW_KEY_S))
        {
            thing2.position.y += speed * deltaTime;
            thing2Collider.moveAlongY(50.0 * deltaTime);
        }
        if (Input.isKeyDown(GLFW_KEY_A))
        {
            thing2.position.x -= speed * deltaTime;
            thing2Collider.moveAlongX(-50.0 * deltaTime);
        }
        if (Input.isKeyDown(GLFW_KEY_D))
        {
            thing2.position.x += speed * deltaTime;
            thing2Collider.moveAlongX(50.0 * deltaTime);
        }
        
        if (thing2Collider.hasCollidedWith(thing1Collider))
        {
            thing2.baseColor = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
        }
        else 
        {
            thing2.baseColor = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
        }
        
        thing1.applyTransforms();
        thing2.applyTransforms();
    }
    
    void render() override
    {
        renderer.begin();
        
        //renderer.drawTexturedQuad(0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1);
        //renderer.drawTexturedQuad(128.0f, 128.0f, 800.0f, 200.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0);
        //renderer.drawSolidColoredQuad(200.0f, 200.0f, 400.0f, 300.0f, 0.0f, 1.0f, 0.0f, 0.5f);
        
        renderer.drawSprite(thing2);
        renderer.drawSprite(thing1);
        
        renderer.end();
    }
    
    ~MyScene()
    {
        
    }
    
private:
    Renderer2D renderer;
    
    Sprite thing1;
    Sprite thing2;
    
    AxisAlignedBoxCollider thing1Collider;
    AxisAlignedBoxCollider thing2Collider;
    
    scp::Input& Input;
};

class Application
{
public:
    Application(): window(Window::getInstance())
    {
        scp::graphics::opengl::enableContextDebugging();
        
        Scene::setActive<MyScene>();
        
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        
        lastFrame = 0.0;
        
        window.show();
        
        while (window.isOpen())
        {
            double currentFrame = glfwGetTime();
            double deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            
            Scene::updateActive(deltaTime);
            
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
    
    // The time of the last frame.
    double lastFrame;
};

//#endif

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