#define _CRT_SECURE_NO_WARNINGS

#if defined( WIN32 )
// Win32 Libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#endif //defined( WIN32 )

//***********************************************************************/
// Fundamentals
//***********************************************************************/

//=======================================================================/
// Types
//=======================================================================/

// basic types
typedef unsigned int		uint;
typedef unsigned char		byte;

// fixed-width types
typedef unsigned int		uint32_t;
typedef unsigned short		uint16_t;
typedef unsigned char		uint8_t;

//=======================================================================/
// Assert
//=======================================================================/
#include <assert.h>
#define Assert( x )				assert( x )

//=======================================================================/
// Memory
//=======================================================================/
#include <stdlib.h>
#include <memory.h>

#define MemAlloc( size )		malloc( size )
#define MemCAlloc( size )		calloc( 1, size )
#define MemFree( p )			free( p )
#define MemSet( p, val, size )	memset( p, val, size )
#define MemZero( p, size )		memset( p, 0, size )

#define ObjAlloc( type )		MemCAlloc( sizeof( type ) )
#define ObjFree( p )			MemFree( p )

//***********************************************************************/
// Vector Math
//***********************************************************************/
#include <math.h>
typedef struct SVec2_t
{
	union
	{
		float		m[2];
		struct
		{
			float	x;
			float	y;
		};
	};
} SVec2;

typedef struct SVec3_t
{
	union
	{
		float		m[3];
		struct
		{
			float	x;
			float	y;
			float	z;
		};
	};
} SVec3;

typedef struct SVec4_t
{
	union
	{
		float		m[4];
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w;
		};
	};
} SVec4;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const SVec2*
Vec2( SVec2* v, float x, float y )
{
	v->x = x;
	v->y = y;
	return v;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const SVec3*
Vec3( SVec3* v, float x, float y, float z )
{
	v->x = x;
	v->y = y;
	v->z = z;
	return v;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const SVec4*
Vec4( SVec4* v, float x, float y, float z, float w )
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
	return v;
}

//***********************************************************************/
// 2D Geometry
//***********************************************************************/
void
Geo2D_Perpendicular( float* X, float* Y )
{
	float x = *X;
	float y = *Y;
	*X = -y;
	*Y =  x;
}

//***********************************************************************/
// Graphics - Vertex
//***********************************************************************/
typedef struct GrVertex_t
{
	SVec3	pos;
	SVec2	tex;
} GrVertex;

//***********************************************************************/
// Graphics - Framebuffer
//***********************************************************************/

//=======================================================================/
// ARGB
//=======================================================================/
typedef struct ARGB_t
{
	union
	{
		byte		m[4];
		uint32_t	color;
	};
} ARGB;

//=======================================================================/
// Framebuffer
//=======================================================================/
typedef struct SFramebuffer_t
{
	uint	w;			// width
	uint	h;			// height
	ARGB*	colors;		// BGRA pixels
} SFramebuffer;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SFramebuffer*
Framebuffer_New( uint width, uint height )
{
	SFramebuffer*	obj;

	Assert( width > 0 && height > 0 );
	
	obj = ObjAlloc( SFramebuffer );
	obj->w			= width;
	obj->h			= height;
	obj->colors		= MemAlloc( sizeof( ARGB ) * width * height );

	return obj;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
Framebuffer_Delete( SFramebuffer** obj )
{
	Assert( obj != NULL );
	if ( *obj )
	{
		free( (*obj)->colors );
		free( (*obj) );

		(*obj) = NULL;
	}
}

//=======================================================================/
// Rasterizer
//=======================================================================/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
Rasterizer_Barycentric( float* u, float* v,
					   float x, float y,
					   float Sx, float Sy,
					   float Tx, float Ty )
{
	// [ Sx Sy ][ u ]   [ x ]
	// [ Tx Ty ][ v ] = [ y ]
	//
	//      | x Sy |   | Sx Sy |
	// u =  | y Ty | / | Tx Ty |
	//
	//      | Sx x |   | Sx Sy |
	// v =  | Tx y | / | Tx Ty |
	//

	*u = ( x*Ty - Sy*y ) / ( Sx*Ty - Sy*Tx );
	*v = ( Sx*y - x*Tx ) / ( Sx*Ty - Sy*Tx );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
Rasterizer_Inside( float Px, float Py,
				  float Ax, float Ay,
				  float Bx, float By,
				  float Cx, float Cy )
{
	float ABx, ABy, ABd;
	float BCx, BCy, BCd;
	float CAx, CAy, CAd;

	ABx = Bx - Ax;
	ABy = By - Ay;
	Geo2D_Perpendicular( &ABx, &ABy );
	ABd = -( ABx*Ax + ABy*Ay );

	BCx = Cx - Bx;
	BCy = Cy - By;
	Geo2D_Perpendicular( &BCx, &BCy );
	BCd = -( BCx*Bx + BCy*By );

	CAx = Ax - Cx;
	CAy = Ay - Cy;
	Geo2D_Perpendicular( &CAx, &CAy );
	CAd = -( CAx*Cx + CAy*Cy );

	{
		float dAB, dBC, dCA;

		dAB = ( ABx*Px + ABy*Py );
		dBC = ( BCx*Px + BCy*Py );
		dCA = ( CAx*Px + CAy*Py );

		if ( dAB >= -ABd )
		{
			if ( dBC >= -BCd )
			{
				if ( dCA >= -CAd )
					return 1;
			}
		}
	}

	return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
Rasterizer_DrawTri( SFramebuffer* fb, const GrVertex* verts )
{
	int		W, H;

	SVec2	S;
	SVec2	T;

	const GrVertex*		A;
	const GrVertex*		B;
	const GrVertex*		C;

	float	Ax, Ay, Bx, By, Cx, Cy;

	float	det;

	W = (int)fb->w;
	H = (int)fb->h;

	A = &verts[0];
	B = &verts[1];
	C = &verts[2];

	Ax = W*( 0.5f*A->pos.x + 0.5f );
	Ay = H*( 0.5f*A->pos.y + 0.5f );
	Bx = W*( 0.5f*B->pos.x + 0.5f );
	By = H*( 0.5f*B->pos.y + 0.5f );
	Cx = W*( 0.5f*C->pos.x + 0.5f );
	Cy = H*( 0.5f*C->pos.y + 0.5f );

	Vec2( &S,
		Bx - Ax,
		By - Ay );

	Vec2( &T,
		Cx - Ax,
		Cy - Ay );

	det = S.x*T.y - S.y*T.x;
	if ( det <= 0.0f )
		return;

	{
		int		y, x;

		for ( y = 0; y < H; ++y )
		{
			for ( x = 0; x < W; ++x )
			{
				float	u, v, w;
				float	r = 0.0f;
				float	g = 0.0f;
				float	b = 0.0f;

				ARGB* pixel = &fb->colors[ y*W + x ];

				if ( Rasterizer_Inside(
					(float)x, (float)y,
					Ax, Ay,
					Bx, By,
					Cx, Cy ) )
				{
					Rasterizer_Barycentric(
						&u, &v,
						x - Ax, y - Ay,
						S.x, T.x,
						S.y, T.y );

					//w = 1.0f - u - v;

					r = u;
					g = v;
					//b = 0.5f*w + 0.5f;

					if ( r < 0.0f ) r = 0.0f;
					if ( r > 1.0f ) r = 1.0f;

					if ( g < 0.0f ) g = 0.0f;
					if ( g > 1.0f ) g = 1.0f;

					if ( b < 0.0f ) b = 0.0f;
					if ( b > 1.0f ) b = 1.0f;

					pixel->m[0] = (byte)( ( r * 255.0f ) );
					pixel->m[1] = (byte)( ( g * 255.0f ) );
					pixel->m[2] = (byte)( ( b * 255.0f ) );

					pixel->m[3] = 0;
				}
			}
		}
	}
}

//***********************************************************************/
// Application
//***********************************************************************/
typedef struct SApp_t
{
	// public.
	SFramebuffer*	framebuffer;

	uint			fps;

	// private.
	uint			_fpsCounter;
	uint			_fpsClock;
} SApp;

SApp	App;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
App_Startup( long iRandSeed )
{
	srand( iRandSeed );

	MemZero( &App, sizeof( SApp ) );

	{
		SVec3 vA;
		vA.x = 1.0f;
		vA.y = 2.0f;
		vA.z = 3.0f;

		{
			int i;
			for ( i = 0; i < 3; ++i )
				vA.m[i] = 0.0f;
		}
	}

	return 1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
App_Resize( uint width, uint height )
{
	Framebuffer_Delete( &App.framebuffer );
	App.framebuffer = Framebuffer_New( width, height );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
App_Shutdown()
{
	Framebuffer_Delete( &App.framebuffer );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
App_Update( uint dt )
{
	if ( dt > 0 )
	{
		// update FPS.
		{
			App._fpsClock += dt;
			if ( App._fpsClock >= 1000 )
			{
				App.fps = App._fpsCounter;
				App._fpsCounter = 0;
				App._fpsClock %= 1000;
			}
			++App._fpsCounter;
		}

		// rasterize.
		if ( 0 )
		{
			uint y, x;
			for ( y = 0; y < App.framebuffer->h; ++y )
			{
				for ( x = 0; x < App.framebuffer->w; ++x )
				{
					ARGB* pixel = &App.framebuffer->colors[ y*App.framebuffer->w + x ];

					pixel->m[0] = rand() % 256;
					pixel->m[1] = pixel->m[0];
					pixel->m[2] = pixel->m[0];
					pixel->m[3] = pixel->m[0];
				}
			}

			for ( y = 0; y < 1; ++y )
			{
				for ( x = 0; x < App.framebuffer->w; ++x )
				{
					ARGB* pixel = &App.framebuffer->colors[ y*App.framebuffer->w + x ];
					pixel->color = 0x0000FF00;
				}
			}
			for ( y = App.framebuffer->h - 1; y < App.framebuffer->h; ++y )
			{
				for ( x = 0; x < App.framebuffer->w; ++x )
				{
					ARGB* pixel = &App.framebuffer->colors[ y*App.framebuffer->w + x ];
					pixel->color = 0x00007F00;
				}
			}

			for ( y = 0; y < App.framebuffer->h; ++y )
			{
				for ( x = 0; x < 1; ++x )
				{
					ARGB* pixel = &App.framebuffer->colors[ y*App.framebuffer->w + x ];
					pixel->color = 0x000000FF;
				}
			}
			for ( y = 0; y < App.framebuffer->h; ++y )
			{
				for ( x = App.framebuffer->w - 1; x < App.framebuffer->w; ++x )
				{
					ARGB* pixel = &App.framebuffer->colors[ y*App.framebuffer->w + x ];
					pixel->color = 0x0000007F;
				}
			}
		}
		else
		{
			GrVertex v[3];
			//Vec3( &v[0].position,  1.0f, 1.0f, 0.0f ); Vec2( &v[0].texcoord, 1.0f, 1.0f );
			//Vec3( &v[1].position, -1.0f, 1.0f, 0.0f ); Vec2( &v[1].texcoord, 0.0f, 1.0f );
			//Vec3( &v[2].position, -1.0f,-1.0f, 0.0f ); Vec2( &v[2].texcoord, 0.0f, 0.0f );
			Vec3( &v[0].pos,  0.0f, 0.6f, 0.0f ); Vec2( &v[0].tex, 1.0f, 1.0f );
			Vec3( &v[1].pos, -1.0f, 0.1f, 0.0f ); Vec2( &v[1].tex, 0.0f, 1.0f );
			Vec3( &v[2].pos,  1.0f, 0.5f, 0.0f ); Vec2( &v[2].tex, 0.0f, 0.0f );
			Rasterizer_DrawTri( App.framebuffer, v );
		}
	}
	return 1;
}

//***********************************************************************/
// Windows
//***********************************************************************/
#if defined( WIN32 )

// Windows headers.
#include <windows.h>
#include <time.h>

// OpenGL headers.
#include <GL/GL.h>

// forward declarations.
LRESULT CALLBACK			WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HWND
Wnd_CreateWindow( unsigned int x, unsigned int y,
				 unsigned int width, unsigned int height )
{
	HINSTANCE		hInstance;

	static TCHAR	szAppName[] = TEXT( "rasterizer" );
	static BOOL		bNeedRegister = TRUE;

	WNDCLASSEX		wndclassex = {0};

	DWORD			dwStyle, dwExStyle;

	RECT			rect;

	HWND			hwnd;

	hInstance	= GetModuleHandle( NULL );

	dwStyle		= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	dwExStyle	= WS_OVERLAPPEDWINDOW;

	wndclassex.cbSize        = sizeof( WNDCLASSEX );
	wndclassex.style         = dwStyle;
	wndclassex.lpfnWndProc   = WndProc;
	wndclassex.cbClsExtra    = 0;
	wndclassex.cbWndExtra    = 0;
	wndclassex.hInstance     = hInstance;
	wndclassex.hIcon         = LoadIcon( NULL, IDI_APPLICATION );
	wndclassex.hCursor       = LoadCursor( NULL, IDC_ARROW );
	wndclassex.hbrBackground = NULL;//(HBRUSH)GetStockObject( WHITE_BRUSH );
	wndclassex.lpszMenuName  = NULL;
	wndclassex.lpszClassName = szAppName;
	wndclassex.hIconSm       = wndclassex.hIcon;

	rect.right	= width;
	rect.bottom	= height;
	rect.left	= 0;
	rect.top	= 0;

	if ( !AdjustWindowRectEx( &rect, dwStyle, FALSE, dwExStyle ) )
	{
		MessageBox( NULL, TEXT( "AdjustWindowRectEx failed!" ), szAppName, MB_ICONERROR );
		return 0;
	}

	if ( bNeedRegister )
	{
		if ( !RegisterClassEx( &wndclassex ) )
		{
			MessageBox( NULL, TEXT( "RegisterClassEx failed!" ), szAppName, MB_ICONERROR );
			return 0;
		}
		bNeedRegister = FALSE;
	}

	hwnd = CreateWindowEx( WS_EX_OVERLAPPEDWINDOW, 
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
		NULL ); 
	if ( !hwnd )
	{
		MessageBox( NULL, TEXT( "CreateWindowEx failed!" ), szAppName, MB_ICONERROR );
		return 0;
	}

	return hwnd;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef const char * (WINAPI * PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
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
typedef BOOL	( WINAPI * PFNWGLSWAPINTERVALEXTPROC )( int interval );
typedef int		( WINAPI * PFNWGLGETSWAPINTERVALEXTPROC )( void );
int
Wnd_SetVSync( HDC hDC, int enabled )
{
	static PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
	static PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;

	if ( wglSwapIntervalEXT == NULL || wglGetSwapIntervalEXT == NULL )
	{
		if ( WGLExtensionSupported( hDC, "WGL_EXT_swap_control" ) )
		{
			wglSwapIntervalEXT		= (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress( "wglSwapIntervalEXT" );
			wglGetSwapIntervalEXT	= (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress( "wglGetSwapIntervalEXT" );
		}
	}

	if ( wglSwapIntervalEXT == NULL || wglGetSwapIntervalEXT == NULL )
		return 0;

	wglSwapIntervalEXT( enabled );
	return 1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HGLRC
Wnd_StartupGL( HDC hDC )
{
	HGLRC	hGLRC;

	int		iPixelFormat; 

	PIXELFORMATDESCRIPTOR pfd =
	{
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

	// get the best available match of pixel format for the device context   
	iPixelFormat = ChoosePixelFormat( hDC, &pfd ); 

	// make that the pixel format of the device context  
	SetPixelFormat( hDC, iPixelFormat, &pfd );

	// create a rendering context  
	hGLRC = wglCreateContext( hDC ); 

	// make it the calling thread's current rendering context 
	wglMakeCurrent( hDC, hGLRC );

	return hGLRC;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
Wnd_ShutdownGL( HGLRC hGLRC )
{
	// make the rendering context not current.
	wglMakeCurrent( NULL, NULL ); 

	// delete the rendering context.
	wglDeleteContext( hGLRC );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
Wnd_FrameGL( uint32_t* colors, unsigned int width, unsigned int height )
{
	// clear the framebuffer.
	glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// load the frame.
	{
		GLuint	tex = 0;

		glEnable( GL_TEXTURE_2D );

		// transfer the current frame to OpenGL.
		glGenTextures( 1, &tex );
		glBindTexture( GL_TEXTURE_2D, tex );
		glTexImage2D( GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, colors );

		// use point sampling.
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	}

	// render the frame.
	glBegin( GL_QUADS );
	{
		glTexCoord2f( 1.0f, 0.0f ); glVertex2f( 1.0f,-1.0f );
		glTexCoord2f( 1.0f, 1.0f ); glVertex2f( 1.0f, 1.0f );
		glTexCoord2f( 0.0f, 1.0f ); glVertex2f(-1.0f, 1.0f );
		glTexCoord2f( 0.0f, 0.0f ); glVertex2f(-1.0f,-1.0f );
	}
	glEnd();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
Wnd_DoEvents()
{
	MSG msg;

	while ( PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) )
	{
		if ( GetMessage( &msg, NULL, 0, 0 ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int WINAPI
WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
	HWND		hWnd;
	HDC			hDC;

	hWnd = Wnd_CreateWindow( 100, 100, 800, 600 );

	hDC = GetDC( hWnd );
    if ( !hDC )
    {
        MessageBox( NULL, TEXT( "GetDC failed!" ), TEXT( "Error" ), MB_ICONERROR );
        return 0;
    }

	Wnd_SetVSync( hDC, 1 );

    ShowWindow( hWnd, iCmdShow );
    UpdateWindow( hWnd );

	{
		DWORD startTime = timeGetTime();
		DWORD prevTime = startTime;
		DWORD dTime = 0;
		unsigned int prevFPS = ~0;
		while ( Wnd_DoEvents() )
		{
			if ( !App_Update( dTime ) )
				break;

			if ( App.fps != prevFPS )
			{
				char buf[ 512 ];
				_itoa( App.fps, buf, 10 );
				SetWindowTextA( hWnd, buf );

				prevFPS = App.fps;
			}

			Wnd_FrameGL( (uint32_t*)App.framebuffer->colors, App.framebuffer->w, App.framebuffer->h );

			SwapBuffers( hDC );

			// calc frame time delta.
			{
				DWORD curTime = timeGetTime();
				dTime = curTime - prevTime;
				prevTime = curTime;
			}
		}
	}

	App_Shutdown();

    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
LRESULT CALLBACK
WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	static HGLRC	hGLRC = NULL;

    switch ( message )
    {
    case WM_CREATE:
		{
			hGLRC = Wnd_StartupGL( GetDC( hWnd ) );
			timeBeginPeriod( 1 );
			App_Startup( (long)time( NULL ) );
		}
        return 0;

	case WM_CLOSE:
	case WM_QUIT:
		{
			timeEndPeriod( 1 );
			Wnd_ShutdownGL( hGLRC );
			hGLRC = NULL;
		}
		break;

	case WM_SIZE:
		{
			RECT rect;
			if ( GetClientRect( hWnd, &rect ) )
			{
				uint width	= rect.right - rect.left;
				uint height	= rect.bottom - rect.top;

				App_Resize( width, height );
				if ( hGLRC != NULL )
					glViewport( 0, 0, width, height );
			}
		}
		return 0;

	case WM_ERASEBKGND:
		return 1;
		
    case WM_DESTROY:
        PostQuitMessage( 0 );
        return 0;
    }
    return DefWindowProc( hWnd, message, wParam, lParam );
}

#endif //defined( WIN32 )
