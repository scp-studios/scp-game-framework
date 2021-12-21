#ifndef C3FF2564_ED22_4311_826E_665713DD2D6F
#define C3FF2564_ED22_4311_826E_665713DD2D6F

#include "pch.hpp"

#include <memory>

namespace scp::graphics
{
    class Renderer2D
    {
    public:
        Renderer2D(API api);
        
        // Kept basic for now. Add more parameters later. Returns the ID of the sprite
        uint64_t addSprite(uint32_t width, uint32_t height, uint32_t uvOffsetX, uint32_t uvOffsetY);
        
        // Render everything in the batch
        void render();
        
        // Destructor
        ~Renderer2D();
        
    private:
        // Implementations
        virtual void addSpriteImpl(uint32_t width, uint32_t height, uint32_t uvOffsetX, uint32_t uvOffsetY) = 0;
        virtual void renderImpl() = 0;
        
        std::unique_ptr<Renderer2D> implementation;
    };
}

#endif /* C3FF2564_ED22_4311_826E_665713DD2D6F */
