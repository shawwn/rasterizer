#define _CRT_SECURE_NO_WARNINGS

#if defined( WIN32 )
// Win32 Libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")

#include <windows.h>
#include <GL/gl.h>
#ifndef __wglext_h_
#define __wglext_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
** Copyright (c) 2007-2010 The Khronos Group Inc.
** 
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
** 
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
** 
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Function declaration macros - to move into glplatform.h */

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

/*************************************************************/

/* Header file version number */
/* wglext.h last updated 2010/08/06 */
/* Current version at http://www.opengl.org/registry/ */
#define WGL_WGLEXT_VERSION 22

#ifndef WGL_ARB_buffer_region
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB 0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB  0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB       0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB     0x00000008
#endif

#ifndef WGL_ARB_multisample
#define WGL_SAMPLE_BUFFERS_ARB         0x2041
#define WGL_SAMPLES_ARB                0x2042
#endif

#ifndef WGL_ARB_extensions_string
#endif

#ifndef WGL_ARB_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_ARB   0x2000
#define WGL_DRAW_TO_WINDOW_ARB         0x2001
#define WGL_DRAW_TO_BITMAP_ARB         0x2002
#define WGL_ACCELERATION_ARB           0x2003
#define WGL_NEED_PALETTE_ARB           0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB    0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB     0x2006
#define WGL_SWAP_METHOD_ARB            0x2007
#define WGL_NUMBER_OVERLAYS_ARB        0x2008
#define WGL_NUMBER_UNDERLAYS_ARB       0x2009
#define WGL_TRANSPARENT_ARB            0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB  0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_SHARE_DEPTH_ARB            0x200C
#define WGL_SHARE_STENCIL_ARB          0x200D
#define WGL_SHARE_ACCUM_ARB            0x200E
#define WGL_SUPPORT_GDI_ARB            0x200F
#define WGL_SUPPORT_OPENGL_ARB         0x2010
#define WGL_DOUBLE_BUFFER_ARB          0x2011
#define WGL_STEREO_ARB                 0x2012
#define WGL_PIXEL_TYPE_ARB             0x2013
#define WGL_COLOR_BITS_ARB             0x2014
#define WGL_RED_BITS_ARB               0x2015
#define WGL_RED_SHIFT_ARB              0x2016
#define WGL_GREEN_BITS_ARB             0x2017
#define WGL_GREEN_SHIFT_ARB            0x2018
#define WGL_BLUE_BITS_ARB              0x2019
#define WGL_BLUE_SHIFT_ARB             0x201A
#define WGL_ALPHA_BITS_ARB             0x201B
#define WGL_ALPHA_SHIFT_ARB            0x201C
#define WGL_ACCUM_BITS_ARB             0x201D
#define WGL_ACCUM_RED_BITS_ARB         0x201E
#define WGL_ACCUM_GREEN_BITS_ARB       0x201F
#define WGL_ACCUM_BLUE_BITS_ARB        0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB       0x2021
#define WGL_DEPTH_BITS_ARB             0x2022
#define WGL_STENCIL_BITS_ARB           0x2023
#define WGL_AUX_BUFFERS_ARB            0x2024
#define WGL_NO_ACCELERATION_ARB        0x2025
#define WGL_GENERIC_ACCELERATION_ARB   0x2026
#define WGL_FULL_ACCELERATION_ARB      0x2027
#define WGL_SWAP_EXCHANGE_ARB          0x2028
#define WGL_SWAP_COPY_ARB              0x2029
#define WGL_SWAP_UNDEFINED_ARB         0x202A
#define WGL_TYPE_RGBA_ARB              0x202B
#define WGL_TYPE_COLORINDEX_ARB        0x202C
#endif

#ifndef WGL_ARB_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_ARB   0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054
#endif

#ifndef WGL_ARB_pbuffer
#define WGL_DRAW_TO_PBUFFER_ARB        0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB     0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB      0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB     0x2030
#define WGL_PBUFFER_LARGEST_ARB        0x2033
#define WGL_PBUFFER_WIDTH_ARB          0x2034
#define WGL_PBUFFER_HEIGHT_ARB         0x2035
#define WGL_PBUFFER_LOST_ARB           0x2036
#endif

#ifndef WGL_ARB_render_texture
#define WGL_BIND_TO_TEXTURE_RGB_ARB    0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB   0x2071
#define WGL_TEXTURE_FORMAT_ARB         0x2072
#define WGL_TEXTURE_TARGET_ARB         0x2073
#define WGL_MIPMAP_TEXTURE_ARB         0x2074
#define WGL_TEXTURE_RGB_ARB            0x2075
#define WGL_TEXTURE_RGBA_ARB           0x2076
#define WGL_NO_TEXTURE_ARB             0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB       0x2078
#define WGL_TEXTURE_1D_ARB             0x2079
#define WGL_TEXTURE_2D_ARB             0x207A
#define WGL_MIPMAP_LEVEL_ARB           0x207B
#define WGL_CUBE_MAP_FACE_ARB          0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB             0x2083
#define WGL_FRONT_RIGHT_ARB            0x2084
#define WGL_BACK_LEFT_ARB              0x2085
#define WGL_BACK_RIGHT_ARB             0x2086
#define WGL_AUX0_ARB                   0x2087
#define WGL_AUX1_ARB                   0x2088
#define WGL_AUX2_ARB                   0x2089
#define WGL_AUX3_ARB                   0x208A
#define WGL_AUX4_ARB                   0x208B
#define WGL_AUX5_ARB                   0x208C
#define WGL_AUX6_ARB                   0x208D
#define WGL_AUX7_ARB                   0x208E
#define WGL_AUX8_ARB                   0x208F
#define WGL_AUX9_ARB                   0x2090
#endif

#ifndef WGL_ARB_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ARB        0x21A0
#endif

#ifndef WGL_ARB_framebuffer_sRGB
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB 0x20A9
#endif

#ifndef WGL_ARB_create_context
#define WGL_CONTEXT_DEBUG_BIT_ARB      0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB  0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB  0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB    0x2093
#define WGL_CONTEXT_FLAGS_ARB          0x2094
#define ERROR_INVALID_VERSION_ARB      0x2095
#endif

#ifndef WGL_ARB_create_context_profile
#define WGL_CONTEXT_PROFILE_MASK_ARB   0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_PROFILE_ARB      0x2096
#endif

#ifndef WGL_ARB_create_context_robustness
#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB  0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB  0x8261
#endif

#ifndef WGL_EXT_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_EXT   0x2043
#endif

#ifndef WGL_EXT_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_EXT   0x2000
#define WGL_DRAW_TO_WINDOW_EXT         0x2001
#define WGL_DRAW_TO_BITMAP_EXT         0x2002
#define WGL_ACCELERATION_EXT           0x2003
#define WGL_NEED_PALETTE_EXT           0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT    0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT     0x2006
#define WGL_SWAP_METHOD_EXT            0x2007
#define WGL_NUMBER_OVERLAYS_EXT        0x2008
#define WGL_NUMBER_UNDERLAYS_EXT       0x2009
#define WGL_TRANSPARENT_EXT            0x200A
#define WGL_TRANSPARENT_VALUE_EXT      0x200B
#define WGL_SHARE_DEPTH_EXT            0x200C
#define WGL_SHARE_STENCIL_EXT          0x200D
#define WGL_SHARE_ACCUM_EXT            0x200E
#define WGL_SUPPORT_GDI_EXT            0x200F
#define WGL_SUPPORT_OPENGL_EXT         0x2010
#define WGL_DOUBLE_BUFFER_EXT          0x2011
#define WGL_STEREO_EXT                 0x2012
#define WGL_PIXEL_TYPE_EXT             0x2013
#define WGL_COLOR_BITS_EXT             0x2014
#define WGL_RED_BITS_EXT               0x2015
#define WGL_RED_SHIFT_EXT              0x2016
#define WGL_GREEN_BITS_EXT             0x2017
#define WGL_GREEN_SHIFT_EXT            0x2018
#define WGL_BLUE_BITS_EXT              0x2019
#define WGL_BLUE_SHIFT_EXT             0x201A
#define WGL_ALPHA_BITS_EXT             0x201B
#define WGL_ALPHA_SHIFT_EXT            0x201C
#define WGL_ACCUM_BITS_EXT             0x201D
#define WGL_ACCUM_RED_BITS_EXT         0x201E
#define WGL_ACCUM_GREEN_BITS_EXT       0x201F
#define WGL_ACCUM_BLUE_BITS_EXT        0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT       0x2021
#define WGL_DEPTH_BITS_EXT             0x2022
#define WGL_STENCIL_BITS_EXT           0x2023
#define WGL_AUX_BUFFERS_EXT            0x2024
#define WGL_NO_ACCELERATION_EXT        0x2025
#define WGL_GENERIC_ACCELERATION_EXT   0x2026
#define WGL_FULL_ACCELERATION_EXT      0x2027
#define WGL_SWAP_EXCHANGE_EXT          0x2028
#define WGL_SWAP_COPY_EXT              0x2029
#define WGL_SWAP_UNDEFINED_EXT         0x202A
#define WGL_TYPE_RGBA_EXT              0x202B
#define WGL_TYPE_COLORINDEX_EXT        0x202C
#endif

#ifndef WGL_EXT_pbuffer
#define WGL_DRAW_TO_PBUFFER_EXT        0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT     0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT      0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT     0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT  0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT 0x2032
#define WGL_PBUFFER_LARGEST_EXT        0x2033
#define WGL_PBUFFER_WIDTH_EXT          0x2034
#define WGL_PBUFFER_HEIGHT_EXT         0x2035
#endif

#ifndef WGL_EXT_depth_float
#define WGL_DEPTH_FLOAT_EXT            0x2040
#endif

#ifndef WGL_3DFX_multisample
#define WGL_SAMPLE_BUFFERS_3DFX        0x2060
#define WGL_SAMPLES_3DFX               0x2061
#endif

#ifndef WGL_EXT_multisample
#define WGL_SAMPLE_BUFFERS_EXT         0x2041
#define WGL_SAMPLES_EXT                0x2042
#endif

#ifndef WGL_I3D_digital_video_control
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053
#endif

#ifndef WGL_I3D_gamma
#define WGL_GAMMA_TABLE_SIZE_I3D       0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D  0x204F
#endif

#ifndef WGL_I3D_genlock
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D 0x2044
#define WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D 0x204C
#endif

#ifndef WGL_I3D_image_buffer
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D 0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D      0x00000002
#endif

#ifndef WGL_I3D_swap_frame_lock
#endif

#ifndef WGL_NV_render_depth_texture
#define WGL_BIND_TO_TEXTURE_DEPTH_NV   0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV    0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV 0x20A6
#define WGL_DEPTH_COMPONENT_NV         0x20A7
#endif

#ifndef WGL_NV_render_texture_rectangle
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV       0x20A2
#endif

#ifndef WGL_ATI_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ATI        0x21A0
#endif

#ifndef WGL_NV_float_buffer
#define WGL_FLOAT_COMPONENTS_NV        0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV         0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV        0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV       0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV      0x20B8
#endif

#ifndef WGL_3DL_stereo_control
#define WGL_STEREO_EMITTER_ENABLE_3DL  0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL 0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL 0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL 0x2058
#endif

#ifndef WGL_EXT_pixel_format_packed_float
#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT 0x20A8
#endif

#ifndef WGL_EXT_framebuffer_sRGB
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x20A9
#endif

#ifndef WGL_NV_present_video
#define WGL_NUM_VIDEO_SLOTS_NV         0x20F0
#endif

#ifndef WGL_NV_video_out
#define WGL_BIND_TO_VIDEO_RGB_NV       0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV      0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV         0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV         0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV         0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV 0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV 0x20C7
#define WGL_VIDEO_OUT_FRAME            0x20C8
#define WGL_VIDEO_OUT_FIELD_1          0x20C9
#define WGL_VIDEO_OUT_FIELD_2          0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2 0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1 0x20CC
#endif

#ifndef WGL_NV_swap_group
#endif

#ifndef WGL_NV_gpu_affinity
#define WGL_ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define WGL_ERROR_MISSING_AFFINITY_MASK_NV 0x20D1
#endif

#ifndef WGL_AMD_gpu_association
#define WGL_GPU_VENDOR_AMD             0x1F00
#define WGL_GPU_RENDERER_STRING_AMD    0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD 0x21A2
#define WGL_GPU_RAM_AMD                0x21A3
#define WGL_GPU_CLOCK_AMD              0x21A4
#define WGL_GPU_NUM_PIPES_AMD          0x21A5
#define WGL_GPU_NUM_SIMD_AMD           0x21A6
#define WGL_GPU_NUM_RB_AMD             0x21A7
#define WGL_GPU_NUM_SPI_AMD            0x21A8
#endif

#ifndef WGL_NV_video_capture
#define WGL_UNIQUE_ID_NV               0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV 0x20CF
#endif

#ifndef WGL_NV_copy_image
#endif

#ifndef WGL_NV_multisample_coverage
#define WGL_COVERAGE_SAMPLES_NV        0x2042
#define WGL_COLOR_SAMPLES_NV           0x20B9
#endif

#ifndef WGL_EXT_create_context_es2_profile
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004
#endif


/*************************************************************/

#ifndef WGL_ARB_pbuffer
DECLARE_HANDLE(HPBUFFERARB);
#endif
#ifndef WGL_EXT_pbuffer
DECLARE_HANDLE(HPBUFFEREXT);
#endif
#ifndef WGL_NV_present_video
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#endif
#ifndef WGL_NV_video_output
DECLARE_HANDLE(HPVIDEODEV);
#endif
#ifndef WGL_NV_gpu_affinity
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);

typedef struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
} GPU_DEVICE, *PGPU_DEVICE;
#endif
#ifndef WGL_NV_video_capture
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#endif

#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern HANDLE WINAPI wglCreateBufferRegionARB (HDC hDC, int iLayerPlane, UINT uType);
extern VOID WINAPI wglDeleteBufferRegionARB (HANDLE hRegion);
extern BOOL WINAPI wglSaveBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height);
extern BOOL WINAPI wglRestoreBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef HANDLE (WINAPI * PFNWGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
typedef VOID (WINAPI * PFNWGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
typedef BOOL (WINAPI * PFNWGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
typedef BOOL (WINAPI * PFNWGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
#endif

#ifndef WGL_ARB_multisample
#define WGL_ARB_multisample 1
#endif

#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern const char * WINAPI wglGetExtensionsStringARB (HDC hdc);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef const char * (WINAPI * PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
#endif

#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetPixelFormatAttribivARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
extern BOOL WINAPI wglGetPixelFormatAttribfvARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
extern BOOL WINAPI wglChoosePixelFormatARB (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
#endif

#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglMakeContextCurrentARB (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
extern HDC WINAPI wglGetCurrentReadDCARB (void);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (WINAPI * PFNWGLGETCURRENTREADDCARBPROC) (void);
#endif

#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern HPBUFFERARB WINAPI wglCreatePbufferARB (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
extern HDC WINAPI wglGetPbufferDCARB (HPBUFFERARB hPbuffer);
extern int WINAPI wglReleasePbufferDCARB (HPBUFFERARB hPbuffer, HDC hDC);
extern BOOL WINAPI wglDestroyPbufferARB (HPBUFFERARB hPbuffer);
extern BOOL WINAPI wglQueryPbufferARB (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef HPBUFFERARB (WINAPI * PFNWGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
typedef HDC (WINAPI * PFNWGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
typedef int (WINAPI * PFNWGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
typedef BOOL (WINAPI * PFNWGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
typedef BOOL (WINAPI * PFNWGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
#endif

#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglBindTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
extern BOOL WINAPI wglReleaseTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
extern BOOL WINAPI wglSetPbufferAttribARB (HPBUFFERARB hPbuffer, const int *piAttribList);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (WINAPI * PFNWGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (WINAPI * PFNWGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int *piAttribList);
#endif

#ifndef WGL_ARB_pixel_format_float
#define WGL_ARB_pixel_format_float 1
#endif

#ifndef WGL_ARB_framebuffer_sRGB
#define WGL_ARB_framebuffer_sRGB 1
#endif

#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern HGLRC WINAPI wglCreateContextAttribsARB (HDC hDC, HGLRC hShareContext, const int *attribList);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int *attribList);
#endif

#ifndef WGL_ARB_create_context_profile
#define WGL_ARB_create_context_profile 1
#endif

#ifndef WGL_ARB_create_context_robustness
#define WGL_ARB_create_context_robustness 1
#endif

#ifndef WGL_EXT_display_color_table
#define WGL_EXT_display_color_table 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern GLboolean WINAPI wglCreateDisplayColorTableEXT (GLushort id);
extern GLboolean WINAPI wglLoadDisplayColorTableEXT (const GLushort *table, GLuint length);
extern GLboolean WINAPI wglBindDisplayColorTableEXT (GLushort id);
extern VOID WINAPI wglDestroyDisplayColorTableEXT (GLushort id);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef GLboolean (WINAPI * PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
typedef GLboolean (WINAPI * PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort *table, GLuint length);
typedef GLboolean (WINAPI * PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
typedef VOID (WINAPI * PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
#endif

#ifndef WGL_EXT_extensions_string
#define WGL_EXT_extensions_string 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern const char * WINAPI wglGetExtensionsStringEXT (void);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef const char * (WINAPI * PFNWGLGETEXTENSIONSSTRINGEXTPROC) (void);
#endif

#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglMakeContextCurrentEXT (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
extern HDC WINAPI wglGetCurrentReadDCEXT (void);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (WINAPI * PFNWGLGETCURRENTREADDCEXTPROC) (void);
#endif

#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern HPBUFFEREXT WINAPI wglCreatePbufferEXT (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
extern HDC WINAPI wglGetPbufferDCEXT (HPBUFFEREXT hPbuffer);
extern int WINAPI wglReleasePbufferDCEXT (HPBUFFEREXT hPbuffer, HDC hDC);
extern BOOL WINAPI wglDestroyPbufferEXT (HPBUFFEREXT hPbuffer);
extern BOOL WINAPI wglQueryPbufferEXT (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef HPBUFFEREXT (WINAPI * PFNWGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
typedef HDC (WINAPI * PFNWGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
typedef int (WINAPI * PFNWGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
typedef BOOL (WINAPI * PFNWGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
typedef BOOL (WINAPI * PFNWGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
#endif

#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetPixelFormatAttribivEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
extern BOOL WINAPI wglGetPixelFormatAttribfvEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
extern BOOL WINAPI wglChoosePixelFormatEXT (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
#endif

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglSwapIntervalEXT (int interval);
extern int WINAPI wglGetSwapIntervalEXT (void);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC) (int interval);
typedef int (WINAPI * PFNWGLGETSWAPINTERVALEXTPROC) (void);
#endif

#ifndef WGL_EXT_depth_float
#define WGL_EXT_depth_float 1
#endif

#ifndef WGL_NV_vertex_array_range
#define WGL_NV_vertex_array_range 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern void* WINAPI wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
extern void WINAPI wglFreeMemoryNV (void *pointer);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef void* (WINAPI * PFNWGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
typedef void (WINAPI * PFNWGLFREEMEMORYNVPROC) (void *pointer);
#endif

#ifndef WGL_3DFX_multisample
#define WGL_3DFX_multisample 1
#endif

#ifndef WGL_EXT_multisample
#define WGL_EXT_multisample 1
#endif

#ifndef WGL_OML_sync_control
#define WGL_OML_sync_control 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetSyncValuesOML (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
extern BOOL WINAPI wglGetMscRateOML (HDC hdc, INT32 *numerator, INT32 *denominator);
extern INT64 WINAPI wglSwapBuffersMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
extern INT64 WINAPI wglSwapLayerBuffersMscOML (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
extern BOOL WINAPI wglWaitForMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
extern BOOL WINAPI wglWaitForSbcOML (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
typedef BOOL (WINAPI * PFNWGLGETMSCRATEOMLPROC) (HDC hdc, INT32 *numerator, INT32 *denominator);
typedef INT64 (WINAPI * PFNWGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef INT64 (WINAPI * PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef BOOL (WINAPI * PFNWGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
typedef BOOL (WINAPI * PFNWGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
#endif

#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetDigitalVideoParametersI3D (HDC hDC, int iAttribute, int *piValue);
extern BOOL WINAPI wglSetDigitalVideoParametersI3D (HDC hDC, int iAttribute, const int *piValue);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
typedef BOOL (WINAPI * PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
#endif

#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetGammaTableParametersI3D (HDC hDC, int iAttribute, int *piValue);
extern BOOL WINAPI wglSetGammaTableParametersI3D (HDC hDC, int iAttribute, const int *piValue);
extern BOOL WINAPI wglGetGammaTableI3D (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
extern BOOL WINAPI wglSetGammaTableI3D (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
typedef BOOL (WINAPI * PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
typedef BOOL (WINAPI * PFNWGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
typedef BOOL (WINAPI * PFNWGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
#endif

#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglEnableGenlockI3D (HDC hDC);
extern BOOL WINAPI wglDisableGenlockI3D (HDC hDC);
extern BOOL WINAPI wglIsEnabledGenlockI3D (HDC hDC, BOOL *pFlag);
extern BOOL WINAPI wglGenlockSourceI3D (HDC hDC, UINT uSource);
extern BOOL WINAPI wglGetGenlockSourceI3D (HDC hDC, UINT *uSource);
extern BOOL WINAPI wglGenlockSourceEdgeI3D (HDC hDC, UINT uEdge);
extern BOOL WINAPI wglGetGenlockSourceEdgeI3D (HDC hDC, UINT *uEdge);
extern BOOL WINAPI wglGenlockSampleRateI3D (HDC hDC, UINT uRate);
extern BOOL WINAPI wglGetGenlockSampleRateI3D (HDC hDC, UINT *uRate);
extern BOOL WINAPI wglGenlockSourceDelayI3D (HDC hDC, UINT uDelay);
extern BOOL WINAPI wglGetGenlockSourceDelayI3D (HDC hDC, UINT *uDelay);
extern BOOL WINAPI wglQueryGenlockMaxSourceDelayI3D (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLENABLEGENLOCKI3DPROC) (HDC hDC);
typedef BOOL (WINAPI * PFNWGLDISABLEGENLOCKI3DPROC) (HDC hDC);
typedef BOOL (WINAPI * PFNWGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL *pFlag);
typedef BOOL (WINAPI * PFNWGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT *uSource);
typedef BOOL (WINAPI * PFNWGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT *uEdge);
typedef BOOL (WINAPI * PFNWGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT *uRate);
typedef BOOL (WINAPI * PFNWGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT *uDelay);
typedef BOOL (WINAPI * PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
#endif

#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern LPVOID WINAPI wglCreateImageBufferI3D (HDC hDC, DWORD dwSize, UINT uFlags);
extern BOOL WINAPI wglDestroyImageBufferI3D (HDC hDC, LPVOID pAddress);
extern BOOL WINAPI wglAssociateImageBufferEventsI3D (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
extern BOOL WINAPI wglReleaseImageBufferEventsI3D (HDC hDC, const LPVOID *pAddress, UINT count);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef LPVOID (WINAPI * PFNWGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
typedef BOOL (WINAPI * PFNWGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
typedef BOOL (WINAPI * PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
typedef BOOL (WINAPI * PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID *pAddress, UINT count);
#endif

#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglEnableFrameLockI3D (void);
extern BOOL WINAPI wglDisableFrameLockI3D (void);
extern BOOL WINAPI wglIsEnabledFrameLockI3D (BOOL *pFlag);
extern BOOL WINAPI wglQueryFrameLockMasterI3D (BOOL *pFlag);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLENABLEFRAMELOCKI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLDISABLEFRAMELOCKI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLISENABLEDFRAMELOCKI3DPROC) (BOOL *pFlag);
typedef BOOL (WINAPI * PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL *pFlag);
#endif

#ifndef WGL_I3D_swap_frame_usage
#define WGL_I3D_swap_frame_usage 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetFrameUsageI3D (float *pUsage);
extern BOOL WINAPI wglBeginFrameTrackingI3D (void);
extern BOOL WINAPI wglEndFrameTrackingI3D (void);
extern BOOL WINAPI wglQueryFrameTrackingI3D (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETFRAMEUSAGEI3DPROC) (float *pUsage);
typedef BOOL (WINAPI * PFNWGLBEGINFRAMETRACKINGI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLENDFRAMETRACKINGI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLQUERYFRAMETRACKINGI3DPROC) (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
#endif

#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float 1
#endif

#ifndef WGL_NV_float_buffer
#define WGL_NV_float_buffer 1
#endif

#ifndef WGL_3DL_stereo_control
#define WGL_3DL_stereo_control 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglSetStereoEmitterState3DL (HDC hDC, UINT uState);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLSETSTEREOEMITTERSTATE3DLPROC) (HDC hDC, UINT uState);
#endif

#ifndef WGL_EXT_pixel_format_packed_float
#define WGL_EXT_pixel_format_packed_float 1
#endif

#ifndef WGL_EXT_framebuffer_sRGB
#define WGL_EXT_framebuffer_sRGB 1
#endif

#ifndef WGL_NV_present_video
#define WGL_NV_present_video 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern int WINAPI wglEnumerateVideoDevicesNV (HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
extern BOOL WINAPI wglBindVideoDeviceNV (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
extern BOOL WINAPI wglQueryCurrentContextNV (int iAttribute, int *piValue);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef int (WINAPI * PFNWGLENUMERATEVIDEODEVICESNVPROC) (HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
typedef BOOL (WINAPI * PFNWGLBINDVIDEODEVICENVPROC) (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
typedef BOOL (WINAPI * PFNWGLQUERYCURRENTCONTEXTNVPROC) (int iAttribute, int *piValue);
#endif

#ifndef WGL_NV_video_output
#define WGL_NV_video_output 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglGetVideoDeviceNV (HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
extern BOOL WINAPI wglReleaseVideoDeviceNV (HPVIDEODEV hVideoDevice);
extern BOOL WINAPI wglBindVideoImageNV (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
extern BOOL WINAPI wglReleaseVideoImageNV (HPBUFFERARB hPbuffer, int iVideoBuffer);
extern BOOL WINAPI wglSendPbufferToVideoNV (HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
extern BOOL WINAPI wglGetVideoInfoNV (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLGETVIDEODEVICENVPROC) (HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
typedef BOOL (WINAPI * PFNWGLRELEASEVIDEODEVICENVPROC) (HPVIDEODEV hVideoDevice);
typedef BOOL (WINAPI * PFNWGLBINDVIDEOIMAGENVPROC) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (WINAPI * PFNWGLRELEASEVIDEOIMAGENVPROC) (HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (WINAPI * PFNWGLSENDPBUFFERTOVIDEONVPROC) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
typedef BOOL (WINAPI * PFNWGLGETVIDEOINFONVPROC) (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
#endif

#ifndef WGL_NV_swap_group
#define WGL_NV_swap_group 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglJoinSwapGroupNV (HDC hDC, GLuint group);
extern BOOL WINAPI wglBindSwapBarrierNV (GLuint group, GLuint barrier);
extern BOOL WINAPI wglQuerySwapGroupNV (HDC hDC, GLuint *group, GLuint *barrier);
extern BOOL WINAPI wglQueryMaxSwapGroupsNV (HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
extern BOOL WINAPI wglQueryFrameCountNV (HDC hDC, GLuint *count);
extern BOOL WINAPI wglResetFrameCountNV (HDC hDC);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLJOINSWAPGROUPNVPROC) (HDC hDC, GLuint group);
typedef BOOL (WINAPI * PFNWGLBINDSWAPBARRIERNVPROC) (GLuint group, GLuint barrier);
typedef BOOL (WINAPI * PFNWGLQUERYSWAPGROUPNVPROC) (HDC hDC, GLuint *group, GLuint *barrier);
typedef BOOL (WINAPI * PFNWGLQUERYMAXSWAPGROUPSNVPROC) (HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
typedef BOOL (WINAPI * PFNWGLQUERYFRAMECOUNTNVPROC) (HDC hDC, GLuint *count);
typedef BOOL (WINAPI * PFNWGLRESETFRAMECOUNTNVPROC) (HDC hDC);
#endif

#ifndef WGL_NV_gpu_affinity
#define WGL_NV_gpu_affinity 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglEnumGpusNV (UINT iGpuIndex, HGPUNV *phGpu);
extern BOOL WINAPI wglEnumGpuDevicesNV (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
extern HDC WINAPI wglCreateAffinityDCNV (const HGPUNV *phGpuList);
extern BOOL WINAPI wglEnumGpusFromAffinityDCNV (HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
extern BOOL WINAPI wglDeleteDCNV (HDC hdc);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLENUMGPUSNVPROC) (UINT iGpuIndex, HGPUNV *phGpu);
typedef BOOL (WINAPI * PFNWGLENUMGPUDEVICESNVPROC) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
typedef HDC (WINAPI * PFNWGLCREATEAFFINITYDCNVPROC) (const HGPUNV *phGpuList);
typedef BOOL (WINAPI * PFNWGLENUMGPUSFROMAFFINITYDCNVPROC) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
typedef BOOL (WINAPI * PFNWGLDELETEDCNVPROC) (HDC hdc);
#endif

#ifndef WGL_AMD_gpu_association
#define WGL_AMD_gpu_association 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern UINT WINAPI wglGetGPUIDsAMD (UINT maxCount, UINT *ids);
extern INT WINAPI wglGetGPUInfoAMD (UINT id, int property, GLenum dataType, UINT size, void *data);
extern UINT WINAPI wglGetContextGPUIDAMD (HGLRC hglrc);
extern HGLRC WINAPI wglCreateAssociatedContextAMD (UINT id);
extern HGLRC WINAPI wglCreateAssociatedContextAttribsAMD (UINT id, HGLRC hShareContext, const int *attribList);
extern BOOL WINAPI wglDeleteAssociatedContextAMD (HGLRC hglrc);
extern BOOL WINAPI wglMakeAssociatedContextCurrentAMD (HGLRC hglrc);
extern HGLRC WINAPI wglGetCurrentAssociatedContextAMD (void);
extern VOID WINAPI wglBlitContextFramebufferAMD (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef UINT (WINAPI * PFNWGLGETGPUIDSAMDPROC) (UINT maxCount, UINT *ids);
typedef INT (WINAPI * PFNWGLGETGPUINFOAMDPROC) (UINT id, int property, GLenum dataType, UINT size, void *data);
typedef UINT (WINAPI * PFNWGLGETCONTEXTGPUIDAMDPROC) (HGLRC hglrc);
typedef HGLRC (WINAPI * PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC) (UINT id);
typedef HGLRC (WINAPI * PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC) (UINT id, HGLRC hShareContext, const int *attribList);
typedef BOOL (WINAPI * PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC) (HGLRC hglrc);
typedef BOOL (WINAPI * PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC) (HGLRC hglrc);
typedef HGLRC (WINAPI * PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC) (void);
typedef VOID (WINAPI * PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC) (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif

#ifndef WGL_NV_video_capture
#define WGL_NV_video_capture 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglBindVideoCaptureDeviceNV (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
extern UINT WINAPI wglEnumerateVideoCaptureDevicesNV (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
extern BOOL WINAPI wglLockVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
extern BOOL WINAPI wglQueryVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
extern BOOL WINAPI wglReleaseVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLBINDVIDEOCAPTUREDEVICENVPROC) (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
typedef UINT (WINAPI * PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC) (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
typedef BOOL (WINAPI * PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
typedef BOOL (WINAPI * PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
typedef BOOL (WINAPI * PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
#endif

#ifndef WGL_NV_copy_image
#define WGL_NV_copy_image 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern BOOL WINAPI wglCopyImageSubDataNV (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#endif /* WGL_WGLEXT_PROTOTYPES */
typedef BOOL (WINAPI * PFNWGLCOPYIMAGESUBDATANVPROC) (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#endif

#ifndef WGL_NV_multisample_coverage
#define WGL_NV_multisample_coverage 1
#endif


#ifdef __cplusplus
}
#endif
#endif // defined( WIN32 )

#endif

/* 
   A C-program for MT19937, with initialization improved 2002/2/10.
   Coded by Takuji Nishimura and Makoto Matsumoto.
   This is a faster version by taking Shawn Cokus's optimization,
   Matthe Bellew's simplification, Isaku Wada's real version.

   Before using, initialize the state by using init_genrand(seed) 
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.                          

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
*/

/* Period parameters */  
#define MERSENNE_N 624
#define MERSENNE_M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UMASK 0x80000000UL /* most significant w-r bits */
#define LMASK 0x7fffffffUL /* least significant r bits */
#define MIXBITS(u,v) ( ((u) & UMASK) | ((v) & LMASK) )
#define TWIST(u,v) ((MIXBITS(u,v) >> 1) ^ ((v)&1UL ? MATRIX_A : 0UL))

static unsigned long state[MERSENNE_N]; /* the array for the state vector  */
static int left = 1;
static int initf = 0;
static unsigned long *next;

/* initializes state[MERSENNE_N] with a seed */
void init_genrand(unsigned long s)
{
    int j;
    state[0]= s & 0xffffffffUL;
    for (j=1; j<MERSENNE_N; j++) {
        state[j] = (1812433253UL * (state[j-1] ^ (state[j-1] >> 30)) + j); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array state[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        state[j] &= 0xffffffffUL;  /* for >32 bit machines */
    }
    left = 1; initf = 1;
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
void init_by_array(unsigned long init_key[], int key_length)
{
    int i, j, k;
    init_genrand(19650218UL);
    i=1; j=0;
    k = (MERSENNE_N>key_length ? MERSENNE_N : key_length);
    for (; k; k--) {
        state[i] = (state[i] ^ ((state[i-1] ^ (state[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        state[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=MERSENNE_N) { state[0] = state[MERSENNE_N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=MERSENNE_N-1; k; k--) {
        state[i] = (state[i] ^ ((state[i-1] ^ (state[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        state[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=MERSENNE_N) { state[0] = state[MERSENNE_N-1]; i=1; }
    }

    state[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */ 
    left = 1; initf = 1;
}

static void next_state(void)
{
    unsigned long *p=state;
    int j;

    /* if init_genrand() has not been called, */
    /* a default initial seed is used         */
    if (initf==0) init_genrand(5489UL);

    left = MERSENNE_N;
    next = state;
    
    for (j=MERSENNE_N-MERSENNE_M+1; --j; p++) 
        *p = p[MERSENNE_M] ^ TWIST(p[0], p[1]);

    for (j=MERSENNE_M; --j; p++) 
        *p = p[MERSENNE_M-MERSENNE_N] ^ TWIST(p[0], p[1]);

    *p = p[MERSENNE_M-MERSENNE_N] ^ TWIST(p[0], state[0]);
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return (long)(y>>1);
}

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return (double)y * (1.0/4294967295.0); 
    /* divided by 2^32-1 */ 
}

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return (double)y * (1.0/4294967296.0); 
    /* divided by 2^32 */
}

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return ((double)y + 0.5) * (1.0/4294967296.0); 
    /* divided by 2^32 */
}

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void) 
{ 
    unsigned long a=genrand_int32()>>5, b=genrand_int32()>>6; 
    return(a*67108864.0+b)*(1.0/9007199254740992.0); 
} 
/* These real versions are due to Isaku Wada, 2002/01/09 added */


//========================================================================
// Filename:	main_win.cpp
// Date:		01-28-11
// License:		MIT License (free to distribute, modify, and sell; see LICENSE file)
//
// (c) 2011 Shawn Presser
//========================================================================

#define WINDOW_WIDTH		800
#define WINDOW_HEIGHT		600

//========================================================================
// Types
//========================================================================
typedef unsigned int		uint;
typedef unsigned char		byte;

// fixed-width types
typedef unsigned int		uint32_t;
typedef unsigned short		uint16_t;
typedef unsigned char		uint8_t;

//========================================================================
// Assertion
//========================================================================
#include <assert.h>

#define Assert( cond )														\
	assert( cond )

#define FatalError( msg )													\
{\
	assert( 0 && (msg) );													\
}

#define FatalError_( name )													\
{\
	assert( !#name );														\
}

//========================================================================
// Memory
//========================================================================
#include <memory.h>

#ifndef NULL
#define NULL 0
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define				MemSet( p, size, byteval )								\
	memset( p, byteval, size )

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define				MemZero( p, size )										\
	memset( p, 0, size );

//========================================================================
// SAllocator
//========================================================================
#include <stdlib.h>

typedef void*		(*MemAlloc_fn)( uint bytes );
typedef void		(*MemFree_fn)( void* p );

typedef struct SAllocator_t
{
	MemAlloc_fn		memalloc;
	MemFree_fn		memfree;
} SAllocator;
SAllocator			g_allocator;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void*				MemAlloc( uint bytes )
{
	if ( g_allocator.memalloc )
		return g_allocator.memalloc( bytes );
	else
		return malloc( bytes );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void*				MemAllocZeroed( uint bytes )
{
	// allocate the result.
	void* p;
	if ( g_allocator.memalloc )
		p = g_allocator.memalloc( bytes );
	else
		p = malloc( bytes );

	// set each byte of the result to zero.
	MemZero( p, bytes );

	// return the result.
	return p;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void				MemFree( void* p )
{
	if ( g_allocator.memfree )
		g_allocator.memfree( p );
	else
		free( p );
}

//========================================================================
// Object
//========================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define				ObjNew( type )											\
	MemAllocZeroed( sizeof( type ) )

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define				ObjDel( obj )											\
{\
	MemFree( obj );															\
	( obj ) = NULL;															\
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define				ObjZero( p, obj )										\
	MemZero( p, sizeof( obj ) );

//========================================================================
// 16.16 Fixed Point
//========================================================================

#define	F_TO_16_16( v )														\
	(long)( (v) * 65536.0f + 0.5 )
#define F_FROM_16_16( i )													\
	( (float)(i) / 65536.0f )

#define	MUL_16_16( a, b )													\
	(long)( ((a)*(b) + 0x8000) >> 16 )

//========================================================================
// Math
//========================================================================
#include <math.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define		FloatIsPositive( x )										\
	( (x) >= 0.0f )

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	Sqrt( float x )
{
	return sqrtf( x );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	Lerp( float a, float b, float t )
{
	return a + t*( b - a );
}
double	LerpD( double a, double b, double t )
{
	return a + t*( b - a );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define Floor( f )															\
	floorf( f )

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define Round( x )															\
	floorf( (x) + 0.5f )
#define RoundD( x )															\
	floor( (x) + 0.5 )

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define RoundInt( x )														\
	(int)( (x) + 0.5f )
#define RoundIntD( x )														\
	(int)( (x) + 0.5 )

//========================================================================
// Random Numbers
//========================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double	RandomValue()
{
#if 1
	return genrand_real1();
#else
	return rand() / (double)RAND_MAX;
#endif
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int		RandomInt( int hi )
{
	return RoundIntD( hi*genrand_real1() );
}

//========================================================================
// SVec3
//========================================================================
typedef struct SVec3_t
{
	float x;
	float y;
	float z;
} SVec3;

#define V3( V, Px, Py, Pz )													\
{\
	(V).x = (Px);															\
	(V).y = (Py);															\
	(V).z = (Pz);															\
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	V3_Add( SVec3* p, const SVec3* a, const SVec3* b )
{
	p->x = a->x + b->x;
	p->y = a->y + b->y;
	p->z = a->z + b->z;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	V3_Sub( SVec3* p, SVec3* a, SVec3* b )
{
	p->x = a->x - b->x;
	p->y = a->y - b->y;
	p->z = a->z - b->z;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	V3_Mul( SVec3* p, SVec3* a, float s )
{
	p->x = s * a->x;
	p->y = s * a->y;
	p->z = s * a->z;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	V3_MagSq( SVec3* v )
{
	float x2 = v->x * v->x;
	float y2 = v->y * v->y;
	float z2 = v->z * v->z;
	
	return x2 + y2 + z2;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	V3_Length( SVec3* v )
{
	float x2 = v->x * v->x;
	float y2 = v->y * v->y;
	float z2 = v->z * v->z;
	
	return Sqrt( x2 + y2 + z2 );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	V3_Dot( SVec3* v1, SVec3* v2 )
{
	float x = v1->x * v2->x;
	float y = v1->y * v2->y;
	float z = v1->z * v2->z;
	
	return x + y + z;
}

//========================================================================
// 3D Geometry
//========================================================================

//========================================================================
// SVec2
//========================================================================
typedef struct SVec2_t
{
	float x;
	float y;
} SVec2;

#define V2( V, Px, Py )														\
{\
	(V).x = (Px);															\
	(V).y = (Py);															\
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	V2_Add( SVec2* p, const SVec2* a, const SVec2* b )
{
	p->x = a->x + b->x;
	p->y = a->y + b->y;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	V2_Sub( SVec2* p, SVec2* a, SVec2* b )
{
	p->x = a->x - b->x;
	p->y = a->y - b->y;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	V2_Mul( SVec2* p, SVec2* a, float s )
{
	p->x = s * a->x;
	p->y = s * a->y;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	V2_MagSq( SVec2* v )
{
	float x2 = v->x * v->x;
	float y2 = v->y * v->y;
	
	return x2 + y2;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	V2_Length( SVec2* v )
{
	float x2 = v->x * v->x;
	float y2 = v->y * v->y;
	
	return Sqrt( x2 + y2 );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float	V2_Dot( SVec2* v1, SVec2* v2 )
{
	float x = v1->x * v2->x;
	float y = v1->y * v2->y;
	
	return x + y;
}

//========================================================================
// 2D Geometry
//========================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float		Geo2D_Det(	float a, float b,
						float c, float d )
{
	return a*d - b*c;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float		Geo2D_Dot( const float* A, const float* B )
{
	return
		A[0]*B[0] +
		A[1]*B[1];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float		Geo2D_PlaneVsPoint( const float* planeNormal, const float planeDist, const float* pt )
{
	// Ax + By + C = 0
	// Ax + By = -C
	// (planeNormalX)*x + (planeNormalY)*y + planeDist = 0
	return Geo2D_Dot( planeNormal, pt ) + planeDist;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		Geo2D_Perpendicular( float* P )
{
	// For any 2D point (x,y) then
	//
	//	(y,-x)
	//
	// will rotate the point 90 degrees around origin.

	float x = P[0];
	float y = P[1];

	P[0] = y;
	P[1] = -x;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int		Geo2D_TriVsPoint( const float* TA, const float* TB, const float* TC, const float* P )
{
	float	An[2];	float Ad;
	float	Bn[2];	float Bd;
	float	Cn[2];	float Cd;

	Bn[0] = (TC[0] - TA[0]);
	Bn[1] = (TC[1] - TA[1]);
	Geo2D_Perpendicular( Bn );
	Bd = -Geo2D_Dot( TA, Bn );
	if ( !FloatIsPositive( Geo2D_Dot( Bn, P ) + Bd ) )
		return 0;

	Cn[0] = (TA[0] - TB[0]);
	Cn[1] = (TA[1] - TB[1]);
	Geo2D_Perpendicular( Cn );
	Cd = -Geo2D_Dot( TB, Cn );
	if ( !FloatIsPositive( Geo2D_Dot( Cn, P ) + Cd ) )
		return 0;

	An[0] = (TB[0] - TC[0]);
	An[1] = (TB[1] - TC[1]);
	Geo2D_Perpendicular( An );
	Ad = -Geo2D_Dot( TC, An );
	if ( !FloatIsPositive( Geo2D_Dot( An, P ) + Ad ) )
		return 0;

	return 1;
}

//========================================================================
// SVertex
//========================================================================
typedef struct SVertex_t
{
	SVec3	pos;
	SVec2	uv;
} SVertex;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		Vert( SVertex* p, const SVec3* pos, const SVec2* uv )
{
	p->pos = *pos;
	p->uv = *uv;
}

//========================================================================
// STri
//========================================================================
typedef struct STri_t
{
	SVertex		v[3];
} STri;

//========================================================================
// SPixel
//========================================================================
typedef struct SPixel_t
{
	byte	a;
	byte	r;
	byte	g;
	byte	b;
} SPixel;

//========================================================================
// SFramebuffer
//========================================================================
typedef struct SFramebuffer_t
{
	uint		w;
	uint		h;
	SPixel*		p;
	int			manage;
} SFramebuffer;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SFramebuffer*
SFramebuffer_New( uint w, uint h, void* pBackbuffer )
{
	SFramebuffer* ret;

	Assert( w > 0 );
	Assert( h > 0 );
	
	ret = MemAlloc( sizeof( SFramebuffer ) );
	ret->w = w;
	ret->h = h;
	ret->p = pBackbuffer;
	ret->manage = 0;
	if ( ret->p == NULL )
	{
		ret->p = MemAlloc( w * h );
		ret->manage = 1;
	}
	
	return ret;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
SFramebuffer_Free( SFramebuffer** p )
{
	if ( *p != NULL )
	{
		if ( (*p)->manage )
			MemFree( (*p)->p );

		ObjDel( *p );
	}
}

//========================================================================
// File operations
//========================================================================
#include <stdio.h>

//-----------------------------------------------------------------
void*
ReadEntireFile( uint* outSize, const char* path )
{
	void*		outMem;
	size_t		ret;

	*outSize = 0;
	outMem = 0;

	{
		FILE* fp = fopen( path, "rb" );
		if ( fp )
		{
			fseek( fp, 0, SEEK_END );
			*outSize = ftell( fp );
			fseek( fp, 0, SEEK_SET );

			outMem = MemAlloc( *outSize );
			ret = fread( outMem, 1, *outSize, fp );
			Assert( ret == *outSize );

			fclose( fp );
		}
	}
	
	return outMem;
}

//========================================================================
// Image operations
//========================================================================

//-----------------------------------------------------------------
// ReadBMP loads image data from a BMP file that resides in memory,
// converts each pixel to 32-bits-per-pixel BGRA format, then returns 
// a pointer to a buffer that contains the pixel data.  (Note: be sure 
// to free() the buffer after you're done with it.)
//
// Feel free to copy and paste this routine into your own projects.
// I have tested this routine on Windows XP against all types of BMP 
// files except 16-bit and 32-bit. It should run fine on Linux also.
//
// First, read a BMP file into memory (e.g. with fread() or 
// std::ifstream::read), then pass a pointer to the file data as the 
// 'bmp' parameter.  Set 'bmpSize' to the total size of the BMP file, 
// in bytes.
//
// On success, 'outWidth' and 'outHeight' are set to the dimensions 
// of the image.  The size in bytes of the returned buffer is:
//
//              4 * outWidth * outHeight
//
// If there was an error, 'outWidth' and 'outHeight' are set to 0,
// and null is returned.
//
// Every four bytes of the buffer represents a single pixel: 
//
//              -----------------------------
//             | byte offset | color channel |
//              -----------------------------
//                   0            blue
//                   1            green
//                   2            red
//                   3            alpha
// 
// If the BMP file does not have an alpha channel (24-bit BMP or less),
// then the alpha byte of each pixel is set to 'fully opaque'
// (value 255).
//
// NOTE: BMP compression is not currently supported, but feel free 
// to add that if it's needed.
//
// ReadBMP was implemented in accordance with the information 
// found here:
//
//      http://en.wikipedia.org/wiki/BMP_file_format
//
// You should be able to copy and paste this function into your 
// own C++ project without any problems.  The routine depends on 
// the following headers:  
// 
//      <assert.h>, to use assert()
//      <stdlib.h>, to use malloc()
//      <stdint.h>, to use standard fixed-length types like uint32_t.
//
// If you're compiling the routine with Visual Studio 2005, you'll
// need to download the <stdint.h> header file from here:
//
//      http://msinttypes.googlecode.com/svn/trunk/stdint.h
//
// (It's a good idea anyway to get into the habit of using uint32_t 
// rather than assuming that 'unsigned int' is 32-bits wide.)
//
void*
ReadBMP( unsigned int* outWidth, unsigned int* outHeight, const void* bmp, size_t bmpSize )
{
	uint8_t*	outImg;

	uint8_t*	data;

    // clear the out parameters.
    *outWidth = 0;
    *outHeight = 0;
	outImg = NULL;

    // if the bmp size is less than the size of the BMP header, it is invalid, so abort.
	{
		const size_t kBmpHeaderSize = 54;
		if( bmpSize < kBmpHeaderSize )
			return 0;
	}

    data = (uint8_t*)bmp;

    // read the magic number.
	{
	    uint16_t magic = *(uint16_t*)( data );

	    // if the image data isn't a BMP, abort.
	    const int kBmpMagicNumber = 0x4D42; // ascii code for the characters 'B' and 'M'
	    if ( magic != kBmpMagicNumber )
	    {
	        assert( !"ReadBMP: the file wasn't a BMP file." );
	        return 0;
	    }
	}

    // read the starting address of the image data.
	{
	    uint32_t imgDataOffset = *(uint32_t*)( data + 10 );

	    // read the width and height of the image.
	    uint32_t width = *(uint32_t*)( data + 18 );
	    uint32_t height = *(uint32_t*)( data + 22 );

	    // read the bits-per-pixel of the image.
	    uint16_t bpp = *(uint32_t*)( data + 28 );

	    // read the compression type.  (currently, no compression support is implemented.)
		{
			uint32_t compression = *(uint32_t*)( data + 30 );
			if ( compression != 0 )
			{
				assert( !"ReadBMP: BMP compression isn't supported." );
				return 0;
			}
		}

		{
		    // calculate the number of pixels per row.
		    uint32_t rowSize = 4 * ( ( bpp*width + 31 ) / 32 );
		    uint32_t fileSize = imgDataOffset + rowSize*height;

		    // if the bmp isn't large enough to contain that image, 
		    // abort.
		    if ( bmpSize < fileSize )
		    {
		        assert( !"ReadBMP: the BMP file is corrupt (too short)." );
		        return 0;
		    }

		    // allocate a buffer to hold the image pixels.
		    outImg = (uint8_t*)malloc( 4*width*height );

			switch( bpp )
			{
				// 32 bits per pixel.  I'm not sure if this case ever happens, 
				// but it's supported if it does.
			case 32: 
				{
					// just read the pixel data verbatim.
					memcpy( outImg, data + imgDataOffset, rowSize*height );
				}
				break;

				// 24 bits per pixel.
			case 24:
				{
					size_t			i;

					// read the pixel data and set the alpha channel to 'full'.
					uint8_t* pixels = (uint8_t*)( data + imgDataOffset );
					uint8_t* outPixel = outImg;
					for ( i = 0; i < width*height; ++i )
					{
						outPixel[ 0 ] = pixels[ 0 ];
						outPixel[ 1 ] = pixels[ 1 ];
						outPixel[ 2 ] = pixels[ 2 ];
						outPixel[ 3 ] = 255;

						// advance to the next pixel.
						pixels += 3;
						outPixel += 4;
					}
				}
				break;

				// 16 bits per pixel.
			case 16:
				{
					size_t	i, j;

					uint16_t* pixels = (uint16_t*)( data + imgDataOffset );
					uint8_t* outPixel = outImg;
					for ( i = 0; i < width*height; ++i )
					{
						uint16_t pixel = *pixels;

						// expand the 16-bit pixel.  According to MSDN documentation on
						// BITMAPINFOHEADER, each color channel is represented with 5 bits,
						// not 5-6-5 as you might expect.
						for ( j = 0; j < 3; ++j )
						{
							// read the lowest 5 bits of the current pixel.
							outPixel[ j ] = ( pixel & 0x001F );

							// shift the pixel over by 5 bits.
							pixel >>= 5;
						}

						// set the alpha channel to 'full'.
						outPixel[ 3 ] = 255;

						// advance to the next pixel.
						++pixels;
						outPixel += 4;
					}
				}
				break;

				// indexed color data.
			case 8:
			case 4:
			case 1:
				{
					int			i;
					size_t		y;
					size_t		numColors;

					// prepare a table to hold the colors.
					uint32_t colorTable[ 256 ];
					for ( i = 0; i < 256; ++i )
						colorTable[ i ] = 0;

					// calculate the number of colors stored in the BMP color table.
					numColors = (1 << bpp);

					// read the color table.
					memcpy( colorTable, data + 54, 4*numColors );

					// force each color in the color table to have full alpha.
					for ( i = 0; i < 256; ++i )
						colorTable[ i ] |= 0xFF000000;

					for ( y = 0; y < height; ++y )
					{
						// grab a pointer to the current row of pixels.
						uint8_t* bytes = (uint8_t*)( data + imgDataOffset + rowSize*y );
						uint32_t* pix = (uint32_t*)( outImg + 4*width*y );

						// iterate over each pixel in that row.
						unsigned int pixCount = 0;
						while ( pixCount < width )
						{
							// iterate over each index in the current byte (backwards).
							for ( i = 8 - bpp; i >= 0 && pixCount < width; i -= bpp )
							{
								// sanity check that we're not about to overrun the buffer.
								assert( ((size_t)pix - (size_t)outImg)/4 < bpp*width*height );

								// look up the color in the color table and store it.
								{
									const int idxMask = (1 << bpp) - 1;
									*pix = colorTable[ (*bytes >> i) & idxMask ];
								}

								// advance to the next pixel in the current byte.
								++pixCount;
								++pix;
							}

							// advance to the next byte.
							++bytes;
						}
					}
				}
				break;

			default:
				{
					assert( !"unsupported BMP format." );
					return 0;
				}
			}
		}

		*outWidth = width;
		*outHeight = height;
	}

    return outImg;
}

//========================================================================
// SRasterizer
//========================================================================
typedef struct SRasterizer_t
{
	SFramebuffer*		backbuffer;
	uint				pixelsDrawn;

	uint32_t*			texBits;
	uint				texW, texH;

} SRasterizer;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SRasterizer*
R_New()
{
	SRasterizer* ret = ObjNew( SRasterizer );
	return ret;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
R_Delete( SRasterizer** pRast )
{
	if ( pRast != NULL )
	{
		SFramebuffer_Free( &(*pRast)->backbuffer );
		ObjDel( *pRast );
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
R_Resize( SRasterizer* r, uint width, uint height, void* pBackbuffer )
{
	// free the backbuffer.
	SFramebuffer_Free( &r->backbuffer );

	// reallocate the backbuffer
	if ( !(width == 0 && height == 0 && pBackbuffer == NULL) )
	{
		Assert( width != 0 && height != 0 );
		r->backbuffer = SFramebuffer_New( width, height, pBackbuffer );
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
R_CalcBarycentric( float* outUV,
				  const float* S, const float* T, float invDetST,
				  float Ox, float Oy )
{
#if 1
	// invert the 2x2 matrix to go from "UV -> XY" to "XY -> UV"
	//
	// [ a b ] -1    [  d -b ]        [ a b ]
	// [ c d ]     = [ -c  a ] / det( [ c d ] )
	//

	//
	// [ Sx Sy ] -1    [  Ty -Sy ]        [ Sx Sy ]
	// [ Tx Ty ]     = [ -Tx  Sx ] / det( [ Tx Ty ] )
	//

	float invS[2] = {  T[1], -S[1] };
	float invT[2] = { -T[0],  S[0] };

	invS[0] *= invDetST; invS[1] *= invDetST;
	invT[0] *= invDetST; invT[1] *= invDetST;

	outUV[0] = invS[0]*Ox + invS[1]*Oy;
	outUV[1] = invT[0]*Ox + invT[1]*Oy;

#else
	// U = Ox*Ty - Tx*Oy
	// V = Ox*Sy - Sx*Oy
	outUV[0] = (-S[0]*Ox + S[1]*Oy) * invDetST;
	outUV[1] = (-T[0]*Ox + T[1]*Oy) * invDetST;
#endif
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		R_SetTexture( SRasterizer* r, void* bits, uint width, uint height )
{
	r->texBits = bits;
	r->texW = width;
	r->texH = height;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint32_t		R_SampleTexture( SRasterizer* r, float u, float v )
{
	int		x, y;

	x = RoundInt( r->texW * u );
	y = RoundInt( r->texH * v );

	return r->texBits[ y*r->texW + x ];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		R_DrawTri( SRasterizer* r, STri* tri )
{
	int		i;
	int		y, x;
	int		W, H;

	SVertex*	V[3];
	SVec2		P[3];

	float		O[2];

	float		S[3];
	float		T[3];
	float		invDetST;
	float		UV[2];

	const float*	A;
	const float*	B;
	const float*	C;

	W = r->backbuffer->w;
	H = r->backbuffer->h;

	for ( i = 0; i < 3; ++i )
		V[i] = tri->v + i;

	// TODO: sort verts?

	for ( i = 0; i < 3; ++i )
	{
		P[i].x = W*( 0.5f*(V[i]->pos.x) + 0.5f );
		P[i].y = H*( 0.5f*(V[i]->pos.y) + 0.5f );
	}

	A = (const float*)&P[0].x;
	B = (const float*)&P[1].x;
	C = (const float*)&P[2].x;

	S[0] = B[0] - A[0];
	S[1] = B[1] - A[1];
	S[2] = -Geo2D_Dot( S, B );

	T[0] = C[0] - A[0];
	T[1] = C[1] - A[1];
	T[2] = -Geo2D_Dot( T, C );

	{
		float detST = Geo2D_Det(
			S[0], S[1],
			T[0], T[1] );

		Assert( detST > 0.0f );
		if ( detST <= 0.0f )
			return;

		/*
		Assert( fabs( detST ) >= 1.0f );
		if ( fabs( detST ) < 1.0f )
		{
			return;
		}
		*/

		invDetST = 1.0f / detST;

		// solve for U coefficient.
		UV[0] = Geo2D_Det(
			-S[2], S[1],
			-T[2], T[1] );
		UV[0] *= invDetST;

		// solve for V coefficient.
		UV[1] = Geo2D_Det(
			S[0], -S[2],
			T[0], -T[2] );
		UV[1] *= invDetST;
	}

#if 1
	{
		float Ouv[2];
		float OuvDx[2];
		float OuvDy[2];
		float Puv[2];
		uint32_t tex = 0;

		R_CalcBarycentric( Ouv,   S, T, invDetST, A[0], A[1] );
		R_CalcBarycentric( OuvDx, S, T, invDetST,  1.0f,  0.0f );
		R_CalcBarycentric( OuvDy, S, T, invDetST,  0.0f, +1.0f );

		O[1] = +0.5f;
		for ( y = 0; y < H; ++y )
		{
			O[0] = +0.5f;
			Puv[0] = O[0]*OuvDx[0] + O[1]*OuvDx[1];
			Puv[1] = O[0]*OuvDy[0] + O[1]*OuvDy[1];

			for ( x = 0; x < W; ++x )
			{
				SPixel* p = &r->backbuffer->p[ y*W + x ];

				if ( Geo2D_TriVsPoint( (const float*)&P[0], (const float*)&P[1], (const float*)&P[2], O ) )
				{
					Puv[0] = ((O[0] - A[0])*OuvDx[0] + (O[1] - A[1])*OuvDx[1]);
					Puv[1] = ((O[0] - A[0])*OuvDy[0] + (O[1] - A[1])*OuvDy[1]);

#if 0
					p->b = 0;//RandomInt( 255 );
					p->r = (byte)(256.0f*Puv[0]);
					p->g = (byte)(256.0f*Puv[1]);
					p->a = 255;
#else
					tex = R_SampleTexture( r,
						V[0]->uv.x + Puv[0]*V[1]->uv.x + Puv[0]*V[2]->uv.x,
						V[0]->uv.y + Puv[1]*V[1]->uv.y + Puv[1]*V[2]->uv.y );

					memcpy( p, &tex, 4 );
#endif

					++r->pixelsDrawn;
				}

				O[0] += 1.0f;
				Puv[0] += OuvDx[0];
				Puv[1] += OuvDy[0];
			}

			O[1] += 1.0f;
		}
	}
#else
	// TODO
	for ( y = 0; y < H; ++y )
		for ( x = 0; x < W; ++x )
		{
			SPixel* p = &r->backbuffer->p[ y*W + x ];
			p->r = RandomInt( 255 );
			//p->r = (byte)((genrand_int32()/(double)0xFFFFFFFF) * 255.0);
			p->g = p->r;
			p->b = p->r;
			p->a = 255;
		}
	if (0)
	{
		for ( y = 1; y < H; ++y )
			for ( x = 0; x < W; ++x )
			{
				SPixel* q = &r->backbuffer->p[ 0*W + x ];
				SPixel* p = &r->backbuffer->p[ y*W + x ];
				memcpy( p, q, sizeof( SPixel ) );
			}
	}
	for ( y = 0; y < H; ++y )
		for ( x = W-1; x < W; ++x )
		{
			SPixel* p = &r->backbuffer->p[ y*W + x ];
			p->r = 255;
			p->g = 0;
			p->b = 0;
			p->a = 255;
		}
	for ( y = 0; y < H; ++y )
		for ( x = 0; x < 1; ++x )
		{
			SPixel* p = &r->backbuffer->p[ y*W + x ];
			p->r = 128;
			p->g = 0;
			p->b = 0;
			p->a = 255;
		}
	for ( y = 0; y < 1; ++y )
		for ( x = 0; x < W; ++x )
		{
			SPixel* p = &r->backbuffer->p[ y*W + x ];
			p->r = 0;
			p->g = 128;
			p->b = 0;
			p->a = 255;
		}
	for ( y = H-1; y < H; ++y )
		for ( x = 0; x < W; ++x )
		{
			SPixel* p = &r->backbuffer->p[ y*W + x ];
			p->r = 0;
			p->g = 255;
			p->b = 0;
			p->a = 255;
		}
#endif
}

//========================================================================
// SApp
//========================================================================

typedef unsigned int	( *Sys_GetTime_fn )(); // should return milliseconds.
typedef void			( *Sys_DoEvents_fn )(); // should display the backbuffer.

typedef struct SApp_t
{
	// Public
	int				fps;
	uint			milliseconds;
	uint			seconds;
	SRasterizer*	rast;

	// Private
	int				_fpsCounter;

	uint			texW, texH;
	uint32_t*		texBits;

} SApp;
SApp*		App;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
App_Startup( unsigned long randseed )
{
	if ( App == NULL )
	{
		App = ObjNew( SApp );

		init_genrand( randseed );
		App->rast = R_New();

		{
			uint bmpSize;
			void* bmp = ReadEntireFile( &bmpSize, "C:\\code\\media\\test2.bmp" );
			if ( bmp )
			{
				App->texBits = ReadBMP( &App->texW, &App->texH, bmp, bmpSize );
				R_SetTexture( App->rast, App->texBits, App->texW, App->texH );
			}
		}

		return 1;
	}

	return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
App_Shutdown()
{
	if ( App != NULL )
	{
		R_Delete( &App->rast );

		timeEndPeriod( 1 );

		ObjDel( App );
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
App_Resize( uint width, uint height, void** backbufferBits )
{
	if ( App != NULL )
	{
		if ( App->rast != NULL )
			R_Resize( App->rast, width, height, backbufferBits );
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
App_Update( uint dt )
{
	if ( App == NULL )
		return 0;

	if ( dt <= 0 )
		return 1;

	// advance time.
	{
		App->milliseconds += dt;
		if ( App->seconds != App->milliseconds / 1000 )
		{
			App->seconds = App->milliseconds / 1000;
			App->fps = App->_fpsCounter;
			App->_fpsCounter = 0;
		}
		++App->_fpsCounter;
	}

	// draw current frame.

	// test fill rule.
	{
		const int W = App->rast->backbuffer->w;
		const int H = App->rast->backbuffer->h;

		STri	t;

		const float	kSmallW = -0.0f / (float)W;
		//const float	kSmallW = 0.0f;

		MemZero( &t, sizeof( STri ) );
		V2( t.v[0].uv, 0.0f, 0.0f );
		V2( t.v[1].uv, 1.0f, 0.0f );
		V2( t.v[2].uv, 0.0f, 1.0f );
		//V2( t.v[2].uv, 0.0f, Lerp( 0.5f, 1.0f, (float)RandomValue() ) );


#if 0
		V2( t.v[0].pos, -0.60f, -0.60f );
		V2( t.v[1].pos,  0.50f, -0.50f );
		V2( t.v[2].pos, -0.50f,  0.50f );
		//for ( i = 0; i < 3; ++i )
			//t.v[i].pos.x += 1.0f / (float)W + kSmallW;
		R_DrawTri( App->rast, &t );
#endif

#if 1
		{
			V2( t.v[0].pos, -1.0f,  1.0f );
			V2( t.v[1].pos, -1.0f, -1.0f );
			V2( t.v[2].pos,  1.0f, -1.0f );
			R_DrawTri( App->rast, &t );

			V2( t.v[0].pos, -1.0f,  1.0f );
			V2( t.v[1].pos,  1.0f, -1.0f );
			V2( t.v[2].pos,  1.0f,  1.0f );
			R_DrawTri( App->rast, &t );

			/*
			Assert( App->rast->pixelsDrawn == (W*H)/2 );
			*/
		}
#endif

		App->rast->pixelsDrawn = 0;
	}

	return 1;
}

//========================================================================
// Windows
//========================================================================
#include <windows.h>
#include <time.h>
//#include "wglext.h"

int				g_done;

HGLRC			g_hglrc;

HDC				g_DependentDC;
HBITMAP			g_DependentBitmap;

HDC				g_MemoryDC;
HBITMAP			g_MemoryBitmap;

HWND			g_wnd;
HDC				g_wndDC;
void*			g_wndBits;
uint			g_wndW;
uint			g_wndH;

LRESULT CALLBACK			WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int				WndDoEvents()
{
	MSG msg;

	if ( g_done )
		return 0;

	while ( PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) )
	{
		if ( GetMessage( &msg, NULL, 0, 0 ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			g_done = TRUE;
			return 0;
		}
	}

	glClearColor(0.0f, 1.0f, 0.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);						// Enable Texture Mapping ( NEW )

	{
		GLuint tex = 0;

		glGenTextures(1, &tex);					// Create The Texture

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, tex);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, g_wndW, g_wndH, 0, GL_RGBA, GL_UNSIGNED_BYTE, g_wndBits);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);	// Linear Filtering
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);	// Linear Filtering

		glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Top Left Of The Texture and Quad
		// Back Face
		glEnd();

		glDeleteTextures(1, &tex);
	}

	SwapBuffers( g_wndDC );

	//RedrawWindow( hwnd, NULL, NULL, RDW_INVALIDATE );
	InvalidateRect( g_wnd, NULL, FALSE );

	return !g_done;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	SetupBuffering( HWND hWnd, HDC hDC, const BITMAPINFO* bmi,
						   void**		outBits,
						   HDC*			outMemoryDC,
						   HBITMAP*		outMemoryBitmap,
						   HDC*			outDependentDC,
						   HBITMAP*		outDependentBitmap)
{
	uint w, h;
	{
		RECT rect;
		GetClientRect( hWnd, &rect );
		w = rect.right - rect.left;
		h = rect.bottom - rect.top;
	}

	/*
	1) Create a device independent bitmap using CreateDIBSection (use a negative
	height to make the DIB top->down so the pointer is to pixel (0,0) in
	the upper left corner)
	*/
	*outMemoryBitmap = CreateDIBSection( hDC, bmi, DIB_RGB_COLORS, outBits, 0, 0 );
	if ( !*outMemoryBitmap )
		FatalError_( CreateDIBSection );

	/*
	2) Create a memory DC using CreateCompatibleDC with the DC for your window
	(which should have the 'Own DC' flag set in the window class)
	*/
	*outMemoryDC = CreateCompatibleDC( hDC );
	if ( !*outMemoryDC )
		FatalError( TEXT( "CreateCompatibleDC failed! (MemoryDC)" ) );

	/*
	3) Select the DIB into the DC created in step 2
	*/
	SelectObject( *outMemoryDC, *outMemoryBitmap );

	/*
	4) Create a device dependent bitmap using CreateCompatibleBitmap with
	the DC for your window 
	*/
	*outDependentBitmap = CreateCompatibleBitmap( hDC, w, h );
	if ( !*outDependentBitmap )
		FatalError_( CreateCompatibleBitmap );

	/*
	5) Create a memory DC using CreateCompatibleDC with the DC for your window 
	*/
	*outDependentDC = CreateCompatibleDC( hDC );
	if ( !*outDependentDC )
		FatalError( TEXT( "CreateCompatibleDC failed! (DependentDC)" ) );

	/*
	6) SelectObject the bitmap into the DC created in step 5
	*/
	SelectObject( *outDependentDC, *outDependentBitmap );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	FreeBuffering( void** bits,
					  HDC* memDC, HBITMAP* memBitmap,
					  HDC* depDC, HBITMAP* depBitmap )
{
	*bits = NULL;

	if ( *depDC )
	{
		DeleteDC( *depDC );
		*depDC = NULL;
	}

	if ( *depBitmap )
	{
		DeleteObject( *depBitmap );
		*depBitmap = NULL;
	}

	if ( *memDC )
	{
		DeleteDC( *memDC );
		*memDC = NULL;
	}

	if ( *memBitmap )
	{
		DeleteObject( *memBitmap );
		*memBitmap = NULL;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	WndResize( HWND hWnd, HDC hDC )
{
	BITMAPINFO			bmi;

	FreeBuffering( &g_wndBits, &g_MemoryDC, &g_MemoryBitmap, &g_DependentDC, &g_DependentBitmap );

	if ( hWnd == NULL )
	{
		assert( hDC == NULL );
		return;
	}

	{
		RECT rect;
		GetClientRect( hWnd, &rect );
		g_wndW = rect.right - rect.left;
		g_wndH = rect.bottom - rect.top;
	}

	{
		BITMAPINFOHEADER*	bih;
		bih = &bmi.bmiHeader;
		ZeroMemory( bih, sizeof( BITMAPINFOHEADER ) );
		bih->biSize			= sizeof( BITMAPINFOHEADER );
		bih->biWidth		= g_wndW;
		bih->biHeight		= -(int)g_wndH;
		bih->biCompression	= BI_RGB;
		bih->biPlanes		= 1;
		bih->biBitCount		= 32;
	}

	SetupBuffering( hWnd, hDC, &bmi,
		&g_wndBits,
		&g_MemoryDC, &g_MemoryBitmap, &g_DependentDC, &g_DependentBitmap );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
WGLExtensionSupported( HDC hdc, const char *extension_name )
{
    // this is pointer to function which returns pointer to string with list of all wgl extensions
    PFNWGLGETEXTENSIONSSTRINGARBPROC _wglGetExtensionsStringARB = NULL;
	const char* extensions;

    // determine pointer to wglGetExtensionsStringARB function
    _wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) wglGetProcAddress("wglGetExtensionsStringARB");

	extensions = _wglGetExtensionsStringARB(hdc);

    if (strstr(extensions, extension_name) == NULL)
    {
        // string was not found
        return 0;
    }

    // extension is supported
    return 1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int WINAPI
WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
    static TCHAR szAppName[] = TEXT ("rasterizer");
    WNDCLASSEX   wndclassex = {0};

	DWORD		dwStyle, dwExStyle;

	RECT		rect;

	dwStyle = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	dwExStyle = WS_OVERLAPPEDWINDOW;

    wndclassex.cbSize        = sizeof(WNDCLASSEX);
    wndclassex.style         = dwStyle;
    wndclassex.lpfnWndProc   = WndProc;
    wndclassex.cbClsExtra    = 0;
    wndclassex.cbWndExtra    = 0;
    wndclassex.hInstance     = hInstance;
    wndclassex.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
    wndclassex.hCursor       = LoadCursor (NULL, IDC_ARROW);
    //wndclassex.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
    wndclassex.hbrBackground = NULL;
    wndclassex.lpszMenuName  = NULL;
    wndclassex.lpszClassName = szAppName;
    wndclassex.hIconSm       = wndclassex.hIcon;

	g_wndW = WINDOW_WIDTH;
	g_wndH = WINDOW_HEIGHT;

	rect.right = WINDOW_WIDTH;
	rect.bottom = WINDOW_HEIGHT;
	rect.left = 0;
	rect.top = 0;

	if ( !AdjustWindowRectEx( &rect, dwStyle, FALSE, dwExStyle ) )
	{
		MessageBox (NULL, TEXT ("AdjustWindowRectEx failed!"), szAppName, MB_ICONERROR);
		return 0;
	}
	
    if (!RegisterClassEx (&wndclassex))
    {
        MessageBox (NULL, TEXT ("RegisterClassEx failed!"), szAppName, MB_ICONERROR);
        return 0;
    }

    g_wnd = CreateWindowEx (WS_EX_OVERLAPPEDWINDOW, 
		                  szAppName, 
        		          TEXT ("WindowTitle"),
                		  dwExStyle,
						  0,
						  0,
						  rect.right - rect.left,
						  rect.bottom - rect.top,
        		          NULL, 
                		  NULL, 
		                  hInstance,
        		          NULL); 
    if ( !g_wnd )
    {
        MessageBox (NULL, TEXT ("CreateWindowdEx failed!"), szAppName, MB_ICONERROR);
        return 0;
    }

	g_wndDC = GetDC( g_wnd );
    if ( !g_wndDC )
    {
        MessageBox (NULL, TEXT ("GetDC failed!"), szAppName, MB_ICONERROR);
        return 0;
    }

	App_Startup( (long)time(NULL) );

	{
		PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
		PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;

		if ( WGLExtensionSupported( g_wndDC, "WGL_EXT_swap_control" ) )
		{
			// Extension is supported, init pointers.
			wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) wglGetProcAddress("wglSwapIntervalEXT");

			// this is another function from WGL_EXT_swap_control extension
			wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC) wglGetProcAddress("wglGetSwapIntervalEXT");

			wglSwapIntervalEXT( 1 );
		}
	}

	WndResize( g_wnd, g_wndDC );
	App_Resize( g_wndW, g_wndH, g_wndBits );

    ShowWindow( g_wnd, iCmdShow );
    UpdateWindow( g_wnd );

	{
		DWORD startTime = timeGetTime();
		DWORD prevTime = startTime;
		DWORD dTime = 0;
		uint prevFPS = ~0;
		while ( WndDoEvents() )
		{
			if ( !App_Update( dTime ) )
				break;

			if ( App->fps != prevFPS )
			{
				char buf[512];
				_itoa( App->fps, buf, 10 );
				SetWindowTextA( g_wnd, buf );

				prevFPS = App->fps;
			}

			// calc frame time delta.
			{
				DWORD curTime = timeGetTime();
				dTime = curTime - prevTime;
				prevTime = curTime;
			}
		}
	}
	g_done = TRUE;

	WndResize( NULL, NULL );
	App_Shutdown();

    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
LRESULT CALLBACK
WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch ( message )
    {
    case WM_CREATE:
		{
			HDC hdc;

			hdc = GetDC( hwnd );
			{
				PIXELFORMATDESCRIPTOR pfd = { 
					sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd  
					1,                     // version number  
					PFD_DRAW_TO_WINDOW |   // support window  
					PFD_SUPPORT_OPENGL |   // support OpenGL  
					PFD_DOUBLEBUFFER,      // double buffered  
					PFD_TYPE_RGBA,         // RGBA type  
					24,                    // 24-bit color depth  
					0, 0, 0, 0, 0, 0,      // color bits ignored  
					0,                     // no alpha buffer  
					0,                     // shift bit ignored  
					0,                     // no accumulation buffer  
					0, 0, 0, 0,            // accum bits ignored  
					32,                    // 32-bit z-buffer  
					0,                     // no stencil buffer  
					0,                     // no auxiliary buffer  
					PFD_MAIN_PLANE,        // main layer  
					0,                     // reserved  
					0, 0, 0                // layer masks ignored  
				}; 
				int  iPixelFormat; 

				// get the best available match of pixel format for the device context   
				iPixelFormat = ChoosePixelFormat( hdc, &pfd ); 

				// make that the pixel format of the device context  
				SetPixelFormat( hdc, iPixelFormat, &pfd );
			}

			// create a rendering context  
			g_hglrc = wglCreateContext( hdc ); 
			// make it the calling thread's current rendering context 
			wglMakeCurrent( hdc, g_hglrc );

			timeBeginPeriod( 1 );
		}
        return 0;

	case WM_CLOSE:
	case WM_QUIT:
		{
			// make the rendering context not current.
			wglMakeCurrent( NULL, NULL ); 

			// delete the rendering context.
			wglDeleteContext( g_hglrc );
			g_hglrc = NULL;
		}
			g_done = TRUE;

		break;

	case WM_SIZE:
		{
			WndResize( hwnd, g_wndDC );
			App_Resize( g_wndW, g_wndH, g_wndBits );
			if ( g_hglrc != NULL )
				glViewport( 0, 0, g_wndW, g_wndH );
		}
		return 0;

	case WM_ERASEBKGND:
		return 1;
		
#if 0
    case WM_PAINT:
		{
			HDC hDC;
			PAINTSTRUCT ps;

			//Begin drawing
			hDC = BeginPaint( hwnd, &ps );

			if ( g_rast != NULL )
			{
				/*
				10) Use BitBlt or StretchBlt to copy from the DC in step 5 to your window
				*/
				if ( !BitBlt( hDC,
					ps.rcPaint.left,
					ps.rcPaint.top,
					ps.rcPaint.right - ps.rcPaint.left + 1,
					ps.rcPaint.bottom - ps.rcPaint.top + 1,
					g_DependentDC,
					0, 0, SRCCOPY ) )
				{
					FatalError_( BitBlt_WM_PAINT );
				}
			}

			EndPaint( hwnd, &ps );
		}
        return 1;
#endif
		
    case WM_DESTROY:
        PostQuitMessage( 0 );
        return 0;
    }
    return DefWindowProc( hwnd, message, wParam, lParam );
}
