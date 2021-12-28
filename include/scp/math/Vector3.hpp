#ifndef E4A0E9CE_5912_4B94_923E_68B682B27F99
#define E4A0E9CE_5912_4B94_923E_68B682B27F99

namespace scp::math
{
    template <typename T>
    class Vector3
    {
    public:
        // Constructor
        Vector3(): x(0), y(0)
        {
            
        }
        
        Vector3(T s): x(s), y(s), z(s)
        {
            
        }
        
        Vector3(T p_x, T p_y): x(p_x), y(p_y), z(0)
        {
            
        }
        
        Vector3(T p_x, T p_y, T p_z): x(p_x), y(p_y), z(p_z)
        {
            
        }
        
        // More stuff coming soon
        // ...
        
        T x;
        T y;
        T z;
    };
}

#endif /* E4A0E9CE_5912_4B94_923E_68B682B27F99 */
