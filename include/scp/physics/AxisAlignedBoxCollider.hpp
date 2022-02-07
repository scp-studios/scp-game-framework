#ifndef AE069409_165F_4668_B9FE_27666A88ACE4
#define AE069409_165F_4668_B9FE_27666A88ACE4

#include "pch.hpp"

namespace scp::physics
{
    class AxisAlignedBoxCollider
    {
    public:
        AxisAlignedBoxCollider(
            uint16_t right = 100, 
            uint16_t left = 0, 
            uint16_t top = 0, 
            uint16_t bottom = 100
        );
        
        bool hasCollidedWith(const AxisAlignedBoxCollider& other) const;
        
        void move(uint16_t x, uint16_t y);
        
    private:
        uint16_t right;
        uint16_t left;
        uint16_t top;
        uint16_t bottom;
    };
}

#endif /* AE069409_165F_4668_B9FE_27666A88ACE4 */
