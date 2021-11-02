#ifndef A5E1BBBD_398C_43EE_9671_837D9AC3FBF4
#define A5E1BBBD_398C_43EE_9671_837D9AC3FBF4

namespace scp::graphics
{
    // This enumeration represents the graphics API the framework is currently
    // using. It mainly applies to window creation, as this framework does not
    // yet have an API agnostic wrapper.
    //
    // This is also the full list of all of the supported APIs.
    enum class api
    {
        opengl,
        vulkan
    };
}

#endif /* A5E1BBBD_398C_43EE_9671_837D9AC3FBF4 */
