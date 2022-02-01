#ifndef A4289B83_DC98_4959_8E27_4BE30C685F5E
#define A4289B83_DC98_4959_8E27_4BE30C685F5E

#include "pch.hpp"

#include <scp/math/Vector2.hpp>
#include <scp/math/Vector3.hpp>

namespace scp::graphics
{
    // Alright, so what this does is it basically just represents a block data
    // that can be useful for Sprite rendering. It does not have any actual
    // rendering capabilities, and it's not tied to any specific rendering API
    //
    // Currently, it's only meant to be used for 2D rendering. That's because a
    // sprite is usually 2D.
    struct Sprite
    {
        // This is the actual transformation matrix
        math::Matrix4<float> matrix;
        
        // These are mainly used for reference purposes only.
        math::Vector2<float> position;
        math::Vector3<float> orientation;
        math::Vector2<float> scale;
        
        // The base color, which is additively blended onto the texture, depen-
        // ding on the shader used. So, if you only want to have a texture, wi-
        // th no base color, set this to black.
        math::Vector4<float> baseColor;
        
        // The texture coordinates
        std::array<math::Vector2<float>, 4> uv;
        
        // Notice that the texture is referred to by it's texture unit, rather
        // than by a name. This might cause some problems in the future, but 
        // for now it's good enough.
        int16_t texture;
        
        // Apply the transformations. So far, it only supports applying the tr-
        // anslations and scale transformations, but I will add rotations later
        // on.
        // 
        // Note: You have to apply the transformations before it will show up -
        // on screen.
        void applyTransforms();
    };
}

#endif /* A4289B83_DC98_4959_8E27_4BE30C685F5E */
