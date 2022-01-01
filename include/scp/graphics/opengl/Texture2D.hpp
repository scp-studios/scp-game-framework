#ifndef E921C4AE_EC65_4BE5_A8BC_61D325CE9128
#define E921C4AE_EC65_4BE5_A8BC_61D325CE9128

#include "../pch.hpp"

namespace scp::graphics::opengl
{
    class Texture2D
    {
    public:
        Texture2D() = default;
        
        // Construct a texture from an image path
        Texture2D(std::string_view imagePath, GLenum filtering = GL_LINEAR_MIPMAP_LINEAR);
        
        // Construct a texture from an array of bytes
        Texture2D(std::vector<uint8_t> imageData, bool raw = false, GLenum filtering = GL_LINEAR_MIPMAP_LINEAR);
        
        // Copy constructor
        Texture2D(Texture2D& src);
        
        // Copy assignment operator
        Texture2D& operator=(Texture2D& rhs);
        
        // Move constructor
        Texture2D(Texture2D&& src);
        
        // Move assignment operator
        Texture2D& operator=(Texture2D&& rhs);
        
        // Bind the current texture
        void bind() const;
        
        // Unbind whatever texture is bound
        void unbind() const;
        
        // Set the active texture unit
        void setTextureUnit(uint8_t unit);
        
        // Swap two textures
        static void swap(Texture2D& a, Texture2D& b);
        
        // Destructor
        ~Texture2D();
        
    private:
        // The actual handle to the OpenGL texture
        unsigned int m_handle;
        
        // Move ownership over from another Texture2D object
        void moveFrom(Texture2D& src);
        
        // Destroy this Texture2D object
        void destroy();
    };
}

#endif /* E921C4AE_EC65_4BE5_A8BC_61D325CE9128 */
