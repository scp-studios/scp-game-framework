#ifndef A4D7CCDE_7F39_4707_926A_1265CF37A983
#define A4D7CCDE_7F39_4707_926A_1265CF37A983

#include <scp/graphics/pch.hpp>

namespace scp
{
    namespace math
    {
        template <typename T>
        class Vector2;

        template <typename T>
        class Vector3;

        template <typename T>
        class Vector4;

        template <typename T>
        class Matrix4;
    }
    
    namespace graphics::opengl
    {

        // A simple shader class. It works with OpenGL. Mainly
        // Note: Might have to change the implementation later on, as this version
        // is rather simplistic.
        class Shader
        {
        public:
            Shader() = default;

            // Create a shader from a single source
            Shader(std::string_view source, std::string_view name);

            // Create a shader from multiple sources
            // Note: Geometry shaders are currently not fully supported.
            Shader(std::string_view vertexSource, std::string_view fragmentSource, std::string_view name);

            // Shaders aren't really copiable.
            Shader(Shader &) = delete;
            Shader &operator=(Shader &) = delete;

            // Move constructor and assignment operator
            Shader(Shader &&source);
            Shader &operator=(Shader &&source);

            // Use the shader
            void use() const;

            // Set Uniforms
            void setUniform(std::string_view name, bool value);
            void setUniform(std::string_view name, int value);
            void setUniform(std::string_view name, float value);
            void setUniform(std::string_view name, float valueX, float valueY);
            void setUniform(std::string_view name, float valueX, float valueY, float valueZ);
            void setUniform(std::string_view name, float valueX, float valueY, float valueZ, float valueW);
            void setUniform(std::string_view name, scp::math::Vector2<float> value);
            void setUniform(std::string_view name, scp::math::Vector3<float> value);
            void setUniform(std::string_view name, scp::math::Vector4<float> value);
            //void setUnifrom(std::string_view name, Matrix2<float> value);
            //void setUnifrom(std::string_view name, Matrix3<float> value);
            void setUniform(std::string_view name, scp::math::Matrix4<float> value);

            // Destructor
            ~Shader();

        private:
            // Move from utility function
            void moveFrom(Shader &source);

            // Destroy this object
            void destory();

            // The handle to the actual shader object in OpenGL
            unsigned int m_shader;
        };
    }
}

#endif /* A4D7CCDE_7F39_4707_926A_1265CF37A983 */
