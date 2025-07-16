// Win32 headers

#include<windows.h>
#include<stdio.h>	//std input output - file open, close, read, write
#include<stdlib.h>	// exit(0)
#define _USE_MATH_DEFINES 1
#include<math.h>	// exit(0)

//OpenGL related Header files
#include<gl/GL.h>	
#include<gl/GLU.h>			//GL Utility from microsoft	

// custom header file
#include "OGL.h"

// OpenGL related libraries
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"GLU32.lib")

//Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//Matrix Multi
float identityMatrix[16];
float translationMatrix[16];
float scaleMatrix[16];
float rotationMatrixX[16];
float rotationMatrixY[16];
float rotationMatrixZ[16];


// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global variable declarations // gb : global bool
BOOL gbFullScreen = FALSE;	// Ha win32 SDK cha BOOL aahe with values TRUE , FALSE
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// variables related with file I/O
char gszLogFileName[] = "log.txt";
FILE *gpFile = NULL;


// Active window related variables
BOOL gbActiveWindow = FALSE;

//Exit keypress related
BOOL gbEscapeKeyIsPressed = FALSE;


//openGL related global variables
HDC ghdc = NULL;		//global handle to device context
HGLRC ghrc = NULL;		//global handle to graphics  library rendering context

//Rotation angles
float angleCube = 0.0f;

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declarations
	int initialize(void);
	void display(void);
	void update(void);
	void unintialize(void);

	//Local Variables for centering window
	int screen_width_center;
	int screen_height_center;

	// Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");

	BOOL bDone = FALSE;

	//file create
	gpFile = fopen(gszLogFileName, "w");
	//w - overwrites if file already exists
	
	if (gpFile == NULL)
	{
		MessageBox(NULL,TEXT("Log file creation failed...!!!"),TEXT("ERROR"),MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program started successfully...!!!\n");
	}

	// Window class initiazation

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	// Registration of Window class
	RegisterClassEx(&wndclass);


	screen_width_center = (GetSystemMetrics(SM_CXSCREEN)) / 2;
	screen_height_center = (GetSystemMetrics(SM_CYSCREEN)) / 2;

	// Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
						szAppName, 
						TEXT("Nitin - Colored 3D Cube rotation"), 
						WS_OVERLAPPEDWINDOW |WS_CLIPCHILDREN| WS_CLIPSIBLINGS | WS_VISIBLE, 
						(screen_width_center - (WIN_WIDTH / 2)), //x CW_USEDEFAULT nakoy Screen chya width/2 =  sw/2 = x of the window
						(screen_height_center - (WIN_HEIGHT / 2)), //y CW_USEDEFAULT Nakoy Screen chya Height/2 = sh/2 = y of the window
						WIN_WIDTH,
						WIN_HEIGHT,
						NULL, 
						NULL, 
						hInstance, 
						NULL);

	ghwnd = hwnd;

	//show window
	ShowWindow(hwnd, iCmdShow);

	// paint background of the window
	UpdateWindow(hwnd);

	
	// intialize
	int result = initialize();
	if (result != 0)	//error aleli aahe
	{
		fprintf(gpFile, "Initialize() function failed\n\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "Initialize() function completed successfully\n\n");
	}

	//set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);


	//GAME LOOP
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

				//RENDER
				display();
				
				//update
				update();
			}
		}
	}

	//unintialize
	unintialize();
	return((int)msg.wParam);
}

// Callback function - OS is going to call this function

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// function declarations
	void toggleFullScreen(void);
	void resize(int, int);
	void unintialize(void);
	
	// code
	switch (iMsg)
	{
	case WM_CREATE:
		ZeroMemory((void *)&wpPrev,sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;

	case WM_SETFOCUS:
		gbActiveWindow = TRUE;
		break;

	case WM_KILLFOCUS:
		gbActiveWindow = FALSE;
		break;

		//optional change for flickering - cosmetic 
	case WM_ERASEBKGND: 
		return(0);
	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			//VK : virtual key code
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
		unintialize();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen(void)
{
	//Variable declarations
	MONITORINFO mi;

	// code
	if (gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
	
		if (dwStyle & WS_OVERLAPPEDWINDOW)	// dwStyle contains WS_OVERLAPPEDWINDOW - bitwise operator
		{
			/* MSDN madhe swatccha lihile aahe ki WINDOWPLACEMENT chya length variable Initialize zala pahije structure vaparaychya adhi And   ekdach ani ekda initialize karava.Mhanun te WM_CREATE madhe intialize kela ahe*/
			/*
			BOOL = GetWindowPlacement(ghwnd, &wpPrev);
			BOOL = GetMonitorInfo(Monitor Handle , Which type monitor)
												,Which type monitor : Monitor chya handle cha address)
			*/
			ZeroMemory((void*)&mi, sizeof(MONITORINFO));

			mi.cbSize = sizeof(MONITORINFO);	// MSDN : initiazlied pahije before using mi but not necesarily ekda
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
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER| SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
		//WS_OVERLAPPED_WINDOW| WS_CLIPSIBLING | WS_VISIBLE
	}
}

int initialize(void)
{
	//Function declarations
	void printGLInfo(void);
	void resize(int, int);

	//variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

	//PIXELFORMATDESCRIPTOR initialization
	ZeroMemory((void *)&pfd,sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;	// z vaparaycha aahe ata aplyala count Depth sathitya bits cha count

	//code
	//get DC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile,"getDC function failed\n\n");
		return(-1);
	}


	//get matching pixel format index using hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat function failed\n\n");
		return(-2);
	}

	//select the pixel format of found index
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile,"SetPixelFormat failed\n\n");
		return(-3);
	}

	//create rendering context using hdc , pfd and chosen pixel format index
	ghrc = wglCreateContext(ghdc);	// bridging API cha function
	if (ghrc == NULL)
	{
		fprintf(gpFile,"wglCreateContext function failed\n\n");
		//fprintf(gpFile, "Initialize() function completed successfully\n\n");
		return(-4);
	}

	//make this rendering context as current context
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent function failed\n\n");
		return(-5);
	}

	//Print GL info
	printGLInfo();

	//from here onwards OpenGL code starts

	//Depth related function calls / code
	glShadeModel(GL_SMOOTH);	// rang detana/ fragment tayar kartana smoothness cha vichar kar
	glClearDepth(1.0f);			// display madhe glclear la gela ki depth buffer madhe ja and saglyanchi value 1 kar
	glEnable(GL_DEPTH_TEST);	//depth test enable keli
	glDepthFunc(GL_LEQUAL);		// L equal mhanaycha, code madhun value test keli jate equal ali tr test pass
								// tya tya fragment la pass kar jya jya fragment chi value 1.0 asel or less tha 1.0f asel <=
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // opengl la hint det ahat - he openGL,  jevha perspective proj mula kahi shapes depth mule vedevakade distil te tu adjust kar nicest appearnce deun


	//Tell opengl to choose the color to clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Define Matrices
	// Identity Matrix
	identityMatrix[0] = 1.0f;
	identityMatrix[1] = 0.0f;
	identityMatrix[2] = 0.0f;
	identityMatrix[3] = 0.0f;
	identityMatrix[4] = 0.0f;
	identityMatrix[5] = 1.0f;
	identityMatrix[6] = 0.0f;
	identityMatrix[7] = 0.0f;
	identityMatrix[8] = 0.0f;
	identityMatrix[9] = 0.0f;
	identityMatrix[10] = 1.0f;
	identityMatrix[11] = 0.0f;
	identityMatrix[12] = 0.0f;
	identityMatrix[13] = 0.0f;
	identityMatrix[14] = 0.0f;
	identityMatrix[15] = 1.0f;

	translationMatrix[0] = 1.0f;
	translationMatrix[1] = 0.0f;
	translationMatrix[2] = 0.0f;
	translationMatrix[3] = 0.0f;
	translationMatrix[4] = 0.0f;
	translationMatrix[5] = 1.0f;
	translationMatrix[6] = 0.0f;
	translationMatrix[7] = 0.0f;
	translationMatrix[8] = 0.0f;
	translationMatrix[9] = 0.0f;
	translationMatrix[10] = 1.0f;
	translationMatrix[11] = 0.0f;
	translationMatrix[12] = 0.0f;
	translationMatrix[13] = 0.0f;
	translationMatrix[14] = -6.0f;
	translationMatrix[15] = 1.0f;

	scaleMatrix[0] = 0.75f;
	scaleMatrix[1] = 0.0f;
	scaleMatrix[2] = 0.0f;
	scaleMatrix[3] = 0.0f;
	scaleMatrix[4] = 0.0f;
	scaleMatrix[5] = 0.75f;
	scaleMatrix[6] = 0.0f;
	scaleMatrix[7] = 0.0f;
	scaleMatrix[8] = 0.0f;
	scaleMatrix[9] = 0.0f;
	scaleMatrix[10] = 0.75f;
	scaleMatrix[11] = 0.0f;
	scaleMatrix[12] = 0.0f;
	scaleMatrix[13] = 0.0f;
	scaleMatrix[14] = 0.0f;
	scaleMatrix[15] = 1.0f;

	//warm up resize
	resize(WIN_WIDTH, WIN_HEIGHT);
	return 0;
}

void printGLInfo(void)
{
	//code print openGL info
	fprintf(gpFile, "\n\nOPENGL INFORMATION\n\n");
	fprintf(gpFile, "**************************\n");

	fprintf(gpFile, "OpenGL Vendor   : %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "OpenGL Renderer : %s\n", glGetString(GL_RENDERER));
	fprintf(gpFile, "OpenGL Version  : %s\n", glGetString(GL_VERSION));

	fprintf(gpFile, "**************************\n\n");
}

void resize(int width, int height)
{
	//code
	//if height by accident becomes 0 or <0 then make height 1
	if (height <= 0)
	{
		height = 1;
	}

	//set the viewport
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	//Set Matrix Projection Mode
	glMatrixMode(GL_PROJECTION);	// matrix cha mode projection la thev

	//Set to identity matrix - jya matrix cha mode tu varati set kela projection la tya matrix la identity set kar
	glLoadIdentity();

	//Do Perspective projection

	gluPerspective(45.0f,							//FOV-Y
				   (GLfloat)width/(GLfloat)height,	//aspect ratio
					0.1f,						    //near
					100.0f);						//far
}

void display(void)
{
	//Variable Declarations
	float angle = 0.0f;

	// code
	//clear openGL buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //color ani depth buffer la pan ja ani clear kar me initialize madhe dilelya value la

	//set matrix to model view mode
	glMatrixMode(GL_MODELVIEW);

	//set it to identity matrix
	//Commented on 23rd March
	//glLoadIdentity();
	glLoadMatrixf(identityMatrix);

	//Translate triangle backwords by Z  -- make this change every code
	//glTranslatef(0.0f, 0.0f, -8.0f);
	glMultMatrixf(translationMatrix);
	
	//glScalef(0.75f, 0.75f, 0.75f);
	glMultMatrixf(scaleMatrix);

	//glRotatef(angleCube, 1.0f, 0.0f, 0.0f);	//x rotation
	//glRotatef(angleCube, 0.0f, 1.0f, 0.0f); //y rotation
	//glRotatef(angleCube, 0.0f, 0.0f, 1.0f); //z rotation

	//All angle are expressed in radiance
	angle = angleCube * ( M_PI/ 180.0f);

	//RotationMatrixX
	rotationMatrixX[0] = 1.0f;
	rotationMatrixX[1] = 0.0f;
	rotationMatrixX[2] = 0.0f;
	rotationMatrixX[3] = 0.0f;
	rotationMatrixX[4] = 0.0f;
	rotationMatrixX[5] = cos(angle);
	rotationMatrixX[6] = sin(angle);
	rotationMatrixX[7] = 0.0f;
	rotationMatrixX[8] = 0.0f;
	rotationMatrixX[9] = -sin(angle);
	rotationMatrixX[10] = cos(angle);
	rotationMatrixX[11] = 0.0f;
	rotationMatrixX[12] = 0.0f;
	rotationMatrixX[13] = 0.0f;
	rotationMatrixX[14] = 0.0f;
	rotationMatrixX[15] = 0.0f;

	glMultMatrixf(rotationMatrixX);

	//Y Rotation matrix
	rotationMatrixY[0] = cos(angle);
	rotationMatrixY[1] = 0.0f;
	rotationMatrixY[2] = -sin(angle);
	rotationMatrixY[3] = 0.0f;
	rotationMatrixY[4] = 0.0f;
	rotationMatrixY[5] = 1.0f;
	rotationMatrixY[6] = 0.0f;
	rotationMatrixY[7] = 0.0f;
	rotationMatrixY[8] = sin(angle);
	rotationMatrixY[9] = 0.0f;
	rotationMatrixY[10] = cos(angle);
	rotationMatrixY[11] = 0.0f;
	rotationMatrixY[12] = 0.0f;
	rotationMatrixY[13] = 0.0f;
	rotationMatrixY[14] = 0.0f;
	rotationMatrixY[15] = 1.0f;

	glMultMatrixf(rotationMatrixY);

	rotationMatrixZ[0] = cos(angle);
	rotationMatrixZ[1] = sin(angle);
	rotationMatrixZ[2] = 0.0f;
	rotationMatrixZ[3] = 0.0f;
	rotationMatrixZ[4] = -sin(angle);
	rotationMatrixZ[5] = cos(angle);
	rotationMatrixZ[6] = 0.0f;
	rotationMatrixZ[7] = 0.0f;
	rotationMatrixZ[8] = 0.0f;
	rotationMatrixZ[9] = 0.0f;
	rotationMatrixZ[10] = 1.0f;
	rotationMatrixZ[11] = 0.0f;
	rotationMatrixZ[12] = 0.0f;
	rotationMatrixZ[13] = 0.0f;
	rotationMatrixZ[14] = 0.0f;
	rotationMatrixZ[15] = 1.0f;

	glMultMatrixf(rotationMatrixZ);



	//Pyramid drawing code
	glBegin(GL_QUADS);

	//front face
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);


	//Right face
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	//back face
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f,-1.0f);
	glVertex3f(-1.0f, -1.0f,-1.0f);

	//left face
	glColor3f(0.0f, 1.0f, 1.0f);	//cyan color
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	//top face
	glColor3f(1.0f, 0.0f, 1.0f);	//magenta color
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//bottom face
	glColor3f(1.0f, 1.0f, 0.0f);	//yellow color
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	
	glEnd();


	//swap the buffers
	SwapBuffers(ghdc);
}

void update(void)
{
	angleCube = angleCube + 0.1f;
	if (angleCube >= 360.0f)
	{
		angleCube = angleCube - 360.0f;
	}
}

void unintialize(void)
{
	//Function declarations
	void toggleFullScreen(void);
	
	//code
	
	//if use is exiting in  fullscreen then restore the fullscreen back to normal before exiting
	if (gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}

	//make hdc as current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	//delete the rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//Release the DC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//Destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}
	// close the file
	if (gpFile)
	{
		fprintf(gpFile, "Program terminated successfully...!!!");
		fclose(gpFile);
		gpFile = NULL;
	}
}

/*
Why dwStyle global:
When variable across the msg madhe vachayacha asto
either local static karava or global karava
eg. iPaintFlag

wndProc - reentrance function. tyacha madhe vaprayche variable static or global
*/

/*
File IO is standard input output

getMessage tevhach call hoto jevha user interact karte - nahitar gappa basto
PeekMessage - getmsg sarkha gappa basat nahi. Jar msg nasel tar PeekMessage return karto
*/