#include <scp/graphics/opengl/Renderer2D.hpp>

#include <scp/graphics/Renderer2D.hpp>

using scp::graphics::Renderer2D;

Renderer2D::Renderer2D(API api, std::string_view shaderSource)
{
    switch (api)
    {
        case API::OpenGL:
            m_implementation = std::make_unique<scp::graphics::opengl::Renderer2D>(shaderSource);
        default:
            m_implementation = std::make_unique<scp::graphics::opengl::Renderer2D>(shaderSource);
    }
}

void Renderer2D::addTexture(std::string_view path)
{
    m_implementation->addTextureImpl(path);
}

void Renderer2D::addTexture(std::vector<uint8_t> data, bool raw)
{
    m_implementation->addTextureImpl(data, raw);
}

void Renderer2D::begin()
{
    m_implementation->beginImpl();
}

void Renderer2D::drawTexturedQuad(float width, float height, float posX, float posY, float uvRight, float uvLeft, float uvTop, float uvBottom, int8_t texture)
{
    m_implementation->drawTexturedQuadImpl(width, height, posX, posY, uvRight, uvLeft, uvTop, uvBottom, texture);
}

void Renderer2D::drawSolidColoredQuad(float width, float height, float posX, float posY, float red, float green, float blue, float alpha)
{
    m_implementation->drawSolidColoredQuadImpl(width, height, posX, posY, red, green, blue, alpha);
}

void Renderer2D::end()
{
    m_implementation->endImpl();
}

Renderer2D::~Renderer2D()
{
    
}