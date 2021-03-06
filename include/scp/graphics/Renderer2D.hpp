#ifndef C3FF2564_ED22_4311_826E_665713DD2D6F
#define C3FF2564_ED22_4311_826E_665713DD2D6F

#include "pch.hpp"

#include <memory>

namespace scp::graphics
{
    // Forward declaration of the sprite struct
    struct Sprite;
    
    // A basic 2D renderer for now. I will add more stuff later on.
    class SCPGFFUNC  Renderer2D
    {
    public:
        Renderer2D() = default;
        
        Renderer2D(API api, std::string_view shaderSource);
        
        // Add a texture
        void addTexture(std::string_view path);
        
        // Add a texture from an array of bytes
        void addTexture(std::vector<uint8_t> data, bool raw = false);
        
        // Begin rendering
        void begin();
        
        // Render a simple textured quad
        void drawTexturedQuad(float width, float height, float posX, float posY, float uvRight, float uvLeft, float uvTop, float uvBottom, int8_t texture = 0);
        
        // Render a textureless quad
        void drawSolidColoredQuad(float width, float height, float posX, float posY, float red, float green, float blue, float alpha);
        
        // Render a sprite. Simple. But the implementation? Not so much.
        void drawSprite(const Sprite& sprite);
        
        // Stop rendering
        void end();
        
        // Virtual destructor
        virtual ~Renderer2D();
        
    private:
        // Implementations
        virtual void addTextureImpl(std::string_view path) {}
        virtual void addTextureImpl(std::vector<uint8_t> data, bool raw) {}
        virtual void beginImpl() {}
        virtual void drawTexturedQuadImpl(float width, float height, float posX, float posY, float uvRight, float uvLeft, float uvTop, float uvBottom, int8_t texture) {}
        virtual void drawSolidColoredQuadImpl(float width, float height, float posX, float posY, float red, float green, float blue, float alpha) {}
        virtual void drawSpriteImpl(const Sprite& sprite) {}
        virtual void endImpl() {}
        
        // The actual implementation of the renderer
        std::unique_ptr<Renderer2D> m_implementation;
    };
}

#endif /* C3FF2564_ED22_4311_826E_665713DD2D6F */
