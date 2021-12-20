#ifndef CEED3053_417D_46C3_A470_D326BCCC318A
#define CEED3053_417D_46C3_A470_D326BCCC318A

#include "pch.hpp"

namespace scp::graphics
{
    struct VertexLayout
    {
        enum class Type
        {
            Int, UnsignedInt, Float, Double
        };
        
        Type type;
        uint16_t stride;
        uint16_t offset;
        uint8_t size;
    };
}

#endif /* CEED3053_417D_46C3_A470_D326BCCC318A */
