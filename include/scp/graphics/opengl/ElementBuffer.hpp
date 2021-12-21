#ifndef BA6E8320_985D_4042_B1D9_7E8E4199EC92
#define BA6E8320_985D_4042_B1D9_7E8E4199EC92

#include "../pch.hpp"

namespace scp::graphics::opengl
{
    class ElementBuffer
    {
    public:
        ElementBuffer() = default;
        
        // Construct an empty vertex buffer with the specified size
        ElementBuffer(uint32_t size);
        
        // Construct a vertex buffer from an arbitrary vector
        template<typename T>
        ElementBuffer(std::vector<T> p_data)
        {
            glGenBuffers(1, &m_handle);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_data.size() * sizeof(T), p_data.data(), GL_STATIC_DRAW); // TODO: Might add a little optional thingy here
            
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
        
        // Copy constructor
        ElementBuffer(ElementBuffer& src);
        
        // Copy assignment operator
        ElementBuffer& operator=(ElementBuffer& src);
        
        // Move constructor
        ElementBuffer(ElementBuffer&& src);
        
        // Move assignment operator
        ElementBuffer& operator=(ElementBuffer&& src);
        
        // Bind the buffer
        void bind() const;
        
        // Unbind the buffer
        void unbind() const;
        
        // Set the data to an arbitrary vector
        template<typename T>
        void setData(std::vector<T> p_newData)
        {
            bind();
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_newData.size() * sizeof(T), p_newData.data(), GL_STATIC_DRAW);
            unbind();
        }
        
        // Swap two vertex buffers
        static void swap(ElementBuffer& a, ElementBuffer& b);
        
        // Destructor
        ~ElementBuffer();
        
    private:
        unsigned int m_handle;
        
        // Move ownership from another vertex buffer
        void moveFrom(ElementBuffer& src);
        
        // Destroy this buffer
        void destroy();
    };
}

#endif /* BA6E8320_985D_4042_B1D9_7E8E4199EC92 */
