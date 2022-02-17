#ifndef E1807A30_2BAB_4F2B_812D_33D2F4822F2F
#define E1807A30_2BAB_4F2B_812D_33D2F4822F2F

// Note: This not supposed to represent a Scene class that you would see in a
// game engine. It is supposed to be simply a container for a state in the 
// game and to handle stuff like events and stuff.

#include <scp/core-pch.hpp>

#include <scp/events.hpp>

#include <scp/scp.hpp>

namespace scp
{
    class SCPGFFUNC  Scene
    {
    public:
        // The window has to be a friend class in order for it to pass events
        friend class Window;
        
        // Default Constructor. It will serve as the "onCreate" function
        Scene() = default;
        
        // Templated version
        template<typename SceneType, typename... ArgTypes>
        static void setActive(ArgTypes... args)
        {
            if (activeScene != nullptr)
            {
                delete activeScene;
            }
            
            activeScene = new SceneType(args...);
        }
        
        // Update the active scene
        static void updateActive(double deltaTime);
        
        // Render the active scene
        static void renderActive();
        
        // Destructor. It will serve as the "onDestroy" function.
        virtual ~Scene() = default;
        
    private:
        // Called every iteration of the update thread
        virtual void onUpdate(double deltaTime);
        
        // Rendering
        virtual void render();
        
        // Events
        virtual void onKeyPress(events::KeyPressEvent& event);
        virtual void onMouseClick(events::MouseButtonEvent& event);
        virtual void onMouseMove(events::MouseMoveEvent& event);
        virtual void onMouseScroll(events::MouseScrollEvent& event);
        
        // The currently active scene
        static Scene* activeScene;
    };
}

#endif /* E1807A30_2BAB_4F2B_812D_33D2F4822F2F */
