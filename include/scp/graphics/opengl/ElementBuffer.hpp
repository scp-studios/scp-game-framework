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
        ElementBuffer(uint32_t size, unsigned int usage = GL_STATIC_DRAW);
        
        // Construct a vertex buffer from an arbitrary vector
        template<typename T>
        ElementBuffer(std::vector<T> p_data, unsigned int usage = GL_STATIC_DRAW): m_usage(usage)
        {
            glGenBuffers(1, &m_handle);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_data.size() * sizeof(T), p_data.data(), usage); // TODO: Might add a little optional thingy here
            
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
        
        // Set a subset of the buffer to a data specified
        template<typename T>
        void setSubData(std::vector<T> p_data, uint32_t p_offset)
        {
            bind();
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, p_offset, p_data.size() * sizeof(T), p_data.data());
            unbind();
        }
        
        // Swap two vertex buffers
        static void swap(ElementBuffer& a, ElementBuffer& b);
        
        // Destructor
        ~ElementBuffer();
        
    private:
        unsigned int m_handle;
        
        // How the buffer is going to be used
        unsigned int m_usage;
        
        // Move ownership from another vertex buffer
        void moveFrom(ElementBuffer& src);
        
        // Destroy this buffer
        void destroy();
    };
}

#endif /* BA6E8320_985D_4042_B1D9_7E8E4199EC92 */
