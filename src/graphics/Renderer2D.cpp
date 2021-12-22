#include <scp/graphics/opengl/Renderer2D.hpp>

#include <scp/graphics/Renderer2D.hpp>

using scp::graphics::Renderer2D;

Renderer2D::Renderer2D(API api)
{
    switch (api)
    {
        case API::OpenGL:
            m_implementation = std::make_unique<scp::graphics::opengl::Renderer2D>();
        default:
            m_implementation = std::make_unique<scp::graphics::opengl::Renderer2D>();
    }
}

uint64_t Renderer2D::addSprite(uint32_t width, uint32_t height, uint32_t uvOffsetX, uint32_t uvOffsetY)
{
    return m_implementation->addSpriteImpl(width, height, uvOffsetX, uvOffsetY);
}

void Renderer2D::render()
{
    m_implementation->renderImpl();
}

Renderer2D::~Renderer2D()
{
    
}