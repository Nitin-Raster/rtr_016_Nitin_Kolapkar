//Win32 (Standard) headers 
#include <windows.h>
#include <stdio.h> //input output file read write open
#include <stdlib.h>

//OpenGL related Header Files
#include <gl/GL.h>

//For Perspective and for Sphere
//Not same as GLUT by Mark Killguard
#include <gl/GLU.h> //Backward slash also works but all compilers we use forward slash for linux and Mac and other OS 

//Custom Header Files
#include "OGL.h"

//OpenGL related Libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib") //For Perspective and for Sphere

//MACROS
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable declarations
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

//variables related tp file I/O
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

//Active Window related variable
BOOL gbActiveWindow = FALSE;

//Exit Key-press related
BOOL gbEscapeKeyIsPressed = FALSE;

//OpenGL related Global Variables
HDC ghdc = NULL; // Handle to device context 
HGLRC ghrc = NULL; //Handle to graphics library rendering context

//Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//(local)function declarations
	int initialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);


	// variable declaration
	WNDCLASSEX  wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");
	BOOL bDone = FALSE;


	//code
	//Create Log File
	gpFile = fopen(gszLogFileName, "w");
	if (gpFile == NULL)
	{
		MessageBox(HWND_DESKTOP, TEXT("Log File Creation Failed"), TEXT("File I/O Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program Started successfully\n");
	}

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	//Register Above Class
	RegisterClassEx(&wndclass);



	int xPos = GetSystemMetrics(SM_CXSCREEN) / 2;
	int yPos = GetSystemMetrics(SM_CYSCREEN) / 2;

	//create window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("NKK OGL - Perspective BW Rectangle"), WS_OVERLAPPEDWINDOW, (xPos - (WIN_WIDTH / 2)),
		(yPos - (WIN_HEIGHT / 2)), WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
	ghwnd = hwnd;


	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);


	//initialize
	int result = initialize();
	if (result != 0)
	{
		fprintf(gpFile, "Initialize() Failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "Initialization() successful\n");
	}

	//set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//game loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActiveWindow == TRUE)
			{
				if (gbEscapeKeyIsPressed == TRUE)
				{
					bDone = TRUE;
				}
				//render
				display();
				update();
			}
		}
	}

	//uninitalize
	uninitialize();

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Function Declarations/ Prototype/ Signature
	void toggleFullScreen(void);

	void resize(int, int);
	void uninitialize(void);

	//code
	switch (iMsg)
	{
	case WM_CREATE:
		ZeroMemory((void*)&wpPrev, sizeof(WINDOWPLACEMENT)); //memset();
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;

	case WM_SETFOCUS:
		gbActiveWindow = TRUE;
		break;
	
	case WM_KILLFOCUS:
		gbActiveWindow = FALSE;
		break;

	case WM_ERASEBKGND:
		return(0);

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			gbEscapeKeyIsPressed = TRUE;
			break;
		default:
			break;
		}
		break;

	case WM_CHAR:
		switch (wParam)
		{
		case 'F':
		case 'f':
			if (gbFullScreen == FALSE)
			{
				toggleFullScreen();
				gbFullScreen = TRUE;
			}
			else
			{
				toggleFullScreen();
				gbFullScreen = FALSE;
			}
			break;
		default:
			break;
		}
		break;
	
	case WM_CLOSE:
		uninitialize();
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen(void)
{
	//variable Declarations
	MONITORINFO mi;

	//code
	if (gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			ZeroMemory((void*)&mi, sizeof(MONITORINFO)); //memset
			mi.cbSize = sizeof(MONITORINFO);
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}


int initialize(void)
{
	//Function Declarations
	void printGLInfo(void);
	void resize(int, int);

	//variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

	//Code
	// PIXELFORMATDESCRIPTOR intialization
	ZeroMemory((void*)&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;


	//GetDC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "getDC() failed\n");
		return(-1);
	}

	// get matchingPIXELFORMATINDEX usng hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() failed\n");
		return(-2);
	}

	//Select the PIXELFORMAT OF BOUND INDEX
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() function failed\n");
		return(-3);
	}

	//Create rendering context using ghdc, pfd and chosen PixelFormatIndex
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() function failed\n");
		return(-4);
	}

	//make this rendering context as current context
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() function failed\n");
		return(-5);
	}

	//Printf GL Info
	printGLInfo();

	//From here onwards OpenGL code starts
	//tell OpenGL to choose the color to clear screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //set blue color

	//Warmup resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);
}

//Print GLInfo
void printGLInfo(void)
{
	//code print OpenGL Info
	fprintf(gpFile, "\n\nOPENGL INFORMATION\n\n");
	fprintf(gpFile, "************************\n");
	
	fprintf(gpFile, "OpenGL Vendor	: %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "OpenGL Renderer	: %s\n", glGetString(GL_RENDERER));
	fprintf(gpFile, "OpenGL Version	: %s\n", glGetString(GL_VERSION));

	fprintf(gpFile, "************************\n\n");

}

void resize(int width, int height)
{
	//code
	//if height by accident becomes 0 or less than 0 make height 1
	if (height <= 0)
	{
		height = 1;
	}

	// set the Viewport
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	//Set Matrix Projection Mode
	glMatrixMode(GL_PROJECTION);

	//Set To Identity Matrix
	glLoadIdentity();

	//Do Perspective Projection // gluPerspective is more intuitive
	gluPerspective(45.0f,					//FOVY Field of View Y = 45 degree
		(GLfloat)width / (GLfloat)height,	//Aspect Ratio this takes care of FOVX
		0.1f,								//Near
		100.0f);							//Far
	//glFrustum() function provided by OpenGL in place of gluPerspective
	//glFrustum() is difficult to use (need input : left, right bottom top near far) 
	//FOVY Angle is important, near top and far top with respect to near bottom and far bottom angle is FOVY
	//Similarly FOVX is also important but not used here
	//To Do it with glFrustum() function we need to consider following 
	//(Not Height) H = tan((FOVY/2)/ 180* PI) * near
	//(Not Width)  W = H * Aspect Ratio 
	//glFrustum(-W, W, -H, H, near, far)
	//Eye == View == Camera are same

	//For GLOrtho we have gluOrtho2D(l,r,b,t, -1,1)

	//gluPerspective or GLFrustum cordinates are between -1 to 1
	//NDC Normalised Device Co-ordinartes 
	//OpenGL follows Right Hand Rule - Hand Palm facing the face then, Angtha is X co-ordinate, 1st finger is Y co-ordinate, middle finger pointing your face is +Z Co-ordinate
	//DirectX follows Left Hand Rule

	//Jaga Badalane Dhakalne, is called as Translation
}

void display(void)
{
	//code
	//Clear OpenGL buffers
	glClear(GL_COLOR_BUFFER_BIT);

	//Set Matrix to Model View Mode
	glMatrixMode(GL_MODELVIEW);
	
	//Set it to Identity Matrix
	glLoadIdentity();

	//Translate triangle Backwards by Z (consider Z is )
	glTranslatef(0.0f, 0.0f, -5.0f);

	// Rectangle drawing code
	glBegin(GL_QUADS);	//Co-Ordinates will start anti-clock WISE 
	glVertex3f(1.0f, 1.0f, 0.0f); //Starting from 1st Quadrant // Right top
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

	//Swap the buffers
	SwapBuffers(ghdc); //Win32 function call

}

void update(void)
{
	//code

}

void uninitialize(void)
{
	//Function Declarations
	void toggleFullScreen();

	//code
	// if user exitting in fullscreen then restore full screen back to normal
	if (gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}

	// make hdc as current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}
	
	//Delete the rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// release the dc
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	//close the log file
	if (gpFile)
	{
		fprintf(gpFile, "Program terminated successfully!\n");
		fclose(gpFile);
		gpFile = NULL;
	}

}


