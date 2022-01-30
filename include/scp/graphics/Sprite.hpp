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
        
        // Notice that the texture is referred to by it's texture unit, rather
        // than by a name. This might cause some problems in the future, but 
        // for now it's good enough.
        uint16_t texture;
    }
}

#endif /* A4289B83_DC98_4959_8E27_4BE30C685F5E */
