#define _CRT_SECURE_NO_WARNINGS

#if defined( WIN32 )
// Win32 Libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#endif //defined( WIN32 )

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
Wnd_FrameGL()
{
	glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glBegin( GL_QUADS );
	{
		glVertex2f( 0.5f,-0.5f );
		glVertex2f( 0.5f, 0.5f );
		glVertex2f(-0.5f, 0.5f );
		glVertex2f(-0.5f,-0.5f );
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
	long			iSeedRand;

	hWnd = Wnd_CreateWindow( 100, 100, 800, 600 );

	hDC = GetDC( hWnd );
    if ( !hDC )
    {
        MessageBox( NULL, TEXT( "GetDC failed!" ), TEXT( "Error" ), MB_ICONERROR );
        return 0;
    }

	Wnd_SetVSync( hDC, 1 );

	iSeedRand = (long)time(NULL);
	srand( iSeedRand );

#if 0
	App_Resize( g_wndW, g_wndH, g_wndBits );
#endif

    ShowWindow( hWnd, iCmdShow );
    UpdateWindow( hWnd );

	{
		DWORD startTime = timeGetTime();
		DWORD prevTime = startTime;
		DWORD dTime = 0;
		unsigned int prevFPS = ~0;
		while ( Wnd_DoEvents() )
		{
			/*
			if ( !App_Update( dTime ) )
				break;

			if ( App->fps != prevFPS )
			{
				char buf[512];
				_itoa( App->fps, buf, 10 );
				SetWindowTextA( g_wnd, buf );

				prevFPS = App->fps;
			}
			*/

			Wnd_FrameGL();

			SwapBuffers( hDC );

			// calc frame time delta.
			{
				DWORD curTime = timeGetTime();
				dTime = curTime - prevTime;
				prevTime = curTime;
			}
		}
	}
#if 0
	g_done = TRUE;

	WndResize( NULL, NULL );
	App_Shutdown();
#endif

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
#if 0
			WndResize( hwnd, g_wndDC );
			App_Resize( g_wndW, g_wndH, g_wndBits );
#endif
			if ( hGLRC != NULL )
			{
				RECT rect;
				if ( GetClientRect( hWnd, &rect ) )
				{
					glViewport(
						0,
						0,
						rect.right - rect.left,
						rect.bottom - rect.top );
				}
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