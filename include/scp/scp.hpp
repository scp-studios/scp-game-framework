#ifndef DAE27DEC_A072_4922_9A23_927E82C871E8
#define DAE27DEC_A072_4922_9A23_927E82C871E8

#ifdef SCP_BUILD_WINDOWS_DLL
    #define SCPGFFUNC __declspec(dllexport)
#else
    #ifdef SCP_LINK_WINDOWS_DLL
        #define SCPGFFUNC __declspec(dllimport)
    #endif
#endif

#endif /* DAE27DEC_A072_4922_9A23_927E82C871E8 */
