//Win32 (Standard) headers 
#include <windows.h>
#include <stdio.h> //input output file read write open
#include <stdlib.h>
#define _USE_MATH_DEFINES 1
#include <math.h>

#define M_PI 3.14159265358979323846


//OpenGL related Header Files
#include <gl/GL.h>

//For Perspective and for Sphere
//Not same as GLUT by Mark Killguard
#include <gl/GLU.h> //Backward slash also works but all compilers we use forward slash for linux and Mac and other OS 

//Custom Header Files
#include "OGL.h"

	//Assignment 10/16
	/* Assignment 10:
	- Combination of assignment 6 (graph paper) +
	assignment 7 + assignment 8 + assignment 9.
	- On startup no output is visible.
	- Triangle, square and circle will be visible on toggle keys
	of ‘t’,’s’,’c’ respectively.
	- Key ‘g’ will toggle graph paper.
	- Key press Zero will clear all output.*/



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

//Assignment 10

BOOL bDrawGrid = FALSE;
BOOL bDrawTriangle = FALSE;
BOOL bDrawSquare = FALSE;
BOOL bDrawCircle = FALSE;

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

//22nd March 3D-Pyramid Changes
// 
//Rotation Angles
GLfloat anglePyramid = 0.0f;
GLfloat angleRectangle = 0.0f;

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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("NKK OGL - Assignment 10/16"), WS_OVERLAPPEDWINDOW, (xPos - (WIN_WIDTH / 2)),
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
		case 'g':
			if (bDrawGrid)
			{
				bDrawGrid = FALSE;
			}
			else
			{
				bDrawGrid = TRUE;
			}
			break;
		case 't':
			if (bDrawTriangle)
			{
				bDrawTriangle = FALSE;
			}
			else
			{
				bDrawTriangle = TRUE;
			}
			break;
		case 's':
			if (bDrawSquare)
			{
				bDrawSquare = FALSE;
			}
			else
			{
				bDrawSquare = TRUE;
			}
			break;
		case 'c':
			if (bDrawCircle)
			{
				bDrawCircle = FALSE;
			}
			else
			{
				bDrawCircle = TRUE;
			}
			break;
		case '0':
			bDrawGrid = FALSE;
			bDrawCircle = FALSE;
			bDrawSquare = FALSE;
			bDrawTriangle = FALSE;
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
	//22nd March 3D Pyramid changes
	//cDepthBits can be set to 24 for android/mobile
	pfd.cDepthBits = 32;


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

	//22nd March 3D Pyramid changes 
	// Below 5 function call
	//Depth Related calls
	//OpenGL la sangtay rand detana/shading kartana smoothness cha vichar kar
	glShadeModel(GL_SMOOTH);

	//in dispaly glclear la gelyavar mazya depth buffer(bits/fragments/pixel) madhe sagalyanchi value 1 ne clear kar
	glClearDepth(1.0f);

	//DEPT TEST enable keli
	glEnable(GL_DEPTH_TEST);

	//ase fragment pass kar jyanchi value clear_depth madhalya 1.0 peksha less or equal asel
	glDepthFunc(GL_LEQUAL); //<=

	//Hint to OpenGL jevha perspective projection mule kahi shapes depth mule vedevakade distail te nicest approach ne correction kar 
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//From here onwards OpenGL code starts
	//tell OpenGL to choose the color to clear screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //set black color

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

	//Jaga Badalane, Dhakalne, is called as Translation

}

void display(void)
{
	void drawGrid(void);
	void drawCircle(void);
	void drawSquare(void);
	void drawTriangle(void);
	void drawHollowCircle(float centerX, float centerY, float radius);

	//code
	//Clear OpenGL buffers
	//He OGL mazya frame buffer madhlya color buffer la ja ani pratyek bit me dilelya initialize madhil clear color ne clear kar(i.e. BLACK now)
	//glClear(GL_COLOR_BUFFER_BIT ); Before 3D
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //For 3D we add GL_DEPTH_BUFFER_BIT //DEPTH buffer la jaun clear kar je aadhi initialize buffer madhalya 1.0 ne clear kar

	//************************************ PYRAMID *********************************
	//Set Matrix to Model View Mode
	glMatrixMode(GL_MODELVIEW);
	
	//Set it to Identity Matrix
	glLoadIdentity();

	//Translate triangle Backwards by Z (consider Z is depth)
	//glScalef(100.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -6.0f);
	
	//Assignment 10/16
	/* Assignment 10:
	- Combination of assignment 6 (graph paper) +
	assignment 7 + assignment 8 + assignment 9.
	- On startup no output is visible.
	- Triangle, square and circle will be visible on toggle keys
	of ‘t’,’s’,’c’ respectively.
	- Key ‘g’ will toggle graph paper.
	- Key press Zero will clear all output.*/
	
	if (bDrawGrid)
	{
		drawGrid();
	}

	if (bDrawTriangle)
	{
		drawTriangle();
	}

	if (bDrawSquare)
	{
		drawSquare();
	}
	
	if (bDrawCircle)
	{
		glColor3f(1.0f, 1.0f, 0.0f); // Set color to white
		drawHollowCircle(0.0f, 0.0f, 1.0f);
	}

	//glColor3f(1.0f, 1.0f, 0.0f);
	//glLineWidth(1.50f);
	////Draw Hollow Circle
	//glBegin(GL_LINE_STRIP);
	//glVertex3f(1.0f, 1.0f, 0.0f);
	//glVertex3f(-1.0f, 1.0f, 0.0f);
	//glVertex3f(-1.0f, -1.0f, 0.0f);
	//glVertex3f(1.0f, -1.0f, 0.0f);
	//glVertex3f(1.0f, 1.0f, 0.0f);
	//glEnd();


	////************************************ RECTANGLE *********************************
	////Set Matrix to Model View Mode
	////glMatrixMode(GL_MODELVIEW); //Commented Because OpenGL is state machine

	////Need to call glLoadIdentity again
	////Set it to Identity Matrix
	//glLoadIdentity();

	////Translate triangle Backwards by Z (consider Z is depth)
	//glTranslatef(1.5f, 0.0f, -6.0f);

	//glRotatef(angleRectangle, 1.0f, 0.0f, 0.0f);

	//// Rectangle drawing code
	//glBegin(GL_QUADS);	//Co-Ordinates will start anti-clock WISE 
	////OpenGL is State Machine
	//glColor3f(0.0f, 0.0f, 1.0f); //Importance of state machine - One call of color is sufficient to continue the color call for next co-ordinages
	//glVertex3f(1.0f, 1.0f, 0.0f); //Starting from 1st Quadrant // Right top
	//glVertex3f(-1.0f, 1.0f, 0.0f);
	//glVertex3f(-1.0f, -1.0f, 0.0f);
	//glVertex3f(1.0f, -1.0f, 0.0f);
	//glEnd();

	//Swap the buffers
	SwapBuffers(ghdc); //Win32 function call

	//8th March
	//Transformation - Waves, running solder, waving hand, tree 
	//GL_POINTS use karun bakiche 9 shapes can be drawn by transformation
	//Harry potter left varun right la gela tar te sagale POINTS he LEFT varun RIGHT la gele
	//Mhanjech Translate zala/ mhanje halane/Move    //Change in position is translation
	//Rotation mhanje gol phirne					//Change in Angle is rotation
	//Scale mhanje Vadhane/Ghatane					//Change in size is scale

	//Jeff Goldblum - Jurasic park, The Fly(Scientist asto)
	//Mashi chya peshi ani manasachya peshi ek mekan madhe mix houn new shape banato... mahanje 

	//Point/ Thibaka  - only has a position == Vertex
	//Point having position is called as Vertex
	//glVertex3f() is giving position to a point
	//Vector groups/includes(x,y,z) which gives position to a point in Cartesian co-ordinates system

	//A ne B la paise transfer kele tar... bank mhanate ki paise dile... 2nd bank mhante paise milale
	//Computer ha khotya var banavlela aahe :D
	//Ek Satya je nantar asatya tharla (pan to paryant te satya hota... manala hota)  
	//Sarva manya asatya la loka satya samajun ghetat tevha tya asatyala satya mhanun ch consider kela jata

	//Vector ikdun tikde halavayla ji entity tayar keli tyala mhantat Matrix (16 member cha array) (for transformation)

	//Asatoma sadgamaya
	//tamasoma jyotirgamaya
	//Mrityormam amrutam gamayam 

	//Translation Matrix
	//X-rotation Matrix
	//Y- Rotation Matrix
	//Z-rotation Matrix
	//Scale matrix 
	//Orthographic projection Matrix
	//Perspective projection Matrix
	//Camera/View matrix

	//Bramha satyam 
	//Jagan mithya
	//Jivoh brmai ha naparha

	//9th March 2025
	//m1v1 = m2v2
	//Transormation? using matrix  (Transormation It happens in space ani kiti velat gela te time)
	//translation -  point 1 to point 2
	//Rotation - along X axis - rolling on the floor 
	//along y axis - spinning/rotation (revolution is different - earth moving around sun)
	//along z axis - phulbaji 
	// X-Y-Z arbitary rotation/ Tri axial rotation
	//Scale

	//Vel mojayla junya kali - Ghati, Pala, Vipala 
	//Lambi mojayla angula vapartat
	//Deodenom - dudecaductulus - 10

	//vertex has position, to express it we use vector
	
	//Vector object of humanoid/any object/shape
	// 
	//Translation from pont 1 to point 2 (Linear measurement )

	//Rotation - we use Angle/Cone (no linear measurement) spinning & revolution

	//Scale - big/small

	//For position - Vector
	//For Transformation - Matrix

	//Physics madhe fundamental changes kami/halu hotat
	//Chemistry madhe he sagale changes fast hotat

	//Yatra yatra dhumah -- tatra tatra vanhi
	//Nyaymimansa, pratyaksha praman 

	//In OpenGL Matrices are column major //While DeirectX is row major
	//OpenGL right Hand Rule follow karta
	//Co-ordinate Anticlockwise dyave lagtat
	// Matrix are Column major
	
	//In PP there is no Trasnlatef, 
	//******************** 1 *******************************
	// //OpenGL uses Linear array i.e. 0,1,2,...,15 (it is not m[4][4]) 
	//Identity matrix madhe m[0], m[5], m[10], m[15] are 1's rest all are 0

	//********************* 2 ******************************
	//Translation Matrix = Identitiy Matrix + 4th column's m12 = tx, m13 = ty, m14 = tz
	//gltranslatef(0.0f, 0.0f, 3.0f); //for Tz/ z order translation 
	
	//********************* 3 ******************************
	//X Rotation Matrix
	//m[0] = 1, m[5] =cos(Theta), m[6] = sin(Theta), m[9] = -sin(Theta), m[10] = cos(Theta), m[15]

	//********************* 4 ******************************
	//Y Rotation Matrix
	//m[0] = cos(t),m[2] = -sin(t), m[5] = 1, m[8] = sin(t), m[10] = cos(t), m[15] = 1

	//********************* 5 ******************************
	//Z-axis Rotation Matrix
	//m[0] = cos(t), m[1] = sin(t), m[4] = -sin(t), m[5] = cos(t), m[10] = 1, m[15]= 1

	//********************* 6 ******************************
	//Scale Matrix
	//m[0] = sx, m[5] = sy, m[10] = sz, m[15] = 1

	//********************* 7 ******************************
	//Orthographic Projection Matrix (glOrtho(l,r,t,b,n,f,))
	//m[0] = 2/(r - l), m[5] = 2/(t - l), m[10] = -2/(f - n)
	//m[12] = -(r + l)/(r - l), m[13] = -(t + b)/(t - b)
	//m[14] = -(f + n)/(f - n), m[15] = 1
	//In SuperBible the t[12],t[13],t[14] doesnt have -(minus) values but in Redbook it is -(minus)	


	//********************* 7 ******************************
	//Perspective projection matrix (gluPerspective(Fov-Y, aspectRatio, Near, Far) | glFrustum(l,r,t,b,n,f))
	//m[0] = 2n/(r-l), m[5]=2n/(t-b), m[8]=r+l/(r-l), m[9]=t+b/(t-b), 
	//m[10]=-f+n/(f-n), m[11]=1, 
	//m[14]=-2n/(f-n)

	//Windows -  David Solonman, resinowich
	//Mac - Amit Singh
	//Redbook - Official OpenGL programming guide Mason woo
	//Bluebook - OpenGL Super Bible Simon Richrds Jr
	//GreenBook - OpenGL programming for X-Windows - Mark Kilgard
	//Advanced OpenGL programming - Blyth and McReynolds

	//Redbook example 
	//Imagine OpenGL tranformation  by this analogy
	// You want to take picture of group of 10 people 
	//1. Camera adjustment is also an transformation - i.e. Viewing/View tranformation // glMatrixMode(GL_MODELVIEW)
	//2. Camera samor objects halavane is also transformation - Model/Modeling tranformation  //glMatrixMode(GL_MODELVIEW)
	//3. Camera lens adjustment - Projection Transformation  //glOrtho() or gluPerspective() / glFrustum()
	//4. Camera Click is last Transformation - Viewport transformationsasdas  //glviewport()

	//jevha object/model ani view/camera combine hava asta bcz fame madhe 10 loka cover karyche ahet || dancer la camera madhe cover karayche ahe
	//Model - View duality 
	//MODELVIEW madhe View Aadhi karayche ani nantar model - OpenGL rule

	//TRANSFORMATION
	//Object transform hotoy means vertices tranform hot astat
	//vertices nighale -> Model view matrix transf zala ki(Obj to Eye Co-ordinate bantat) -> projection matrix (Clipping co-ordinate)-> 
	//Perspective divide zala ki (NDC normalized device co-ordinate bantat) -> viewport matrix (window co-ordinate bantat )
	//Rasterizer - 2D(Monitor) madhe kelela demo 3D madhe karun dakhavato he Rasterizer karato
	//3D madhla actual co-ordinates 2D madhe convert karne 
	//(x,y,z,w) - Homogenus Co-Ordinates mahntat
	//-1 to 1 range madhe co-ordinates convert karna using x/w, y/w, z/w process is called as NDC karna 
	//(because e.g. 800X600 window madhe basavaycha asta )
	//Rasterizer z chya values pahun tharavto ki e.g. -3 wala pudhe asnar ani -5 wala thoda lamb, 
	//Z cha vapar karto Depth sathi
	//glTranslatef(x,y,z)
	//glrotatef(angle, x,y,z)
	//glscalef(x,y,z)
	
	//22nd March 

	//OpenGL draws there where modelview matrix right now is
	//and translationf(),rotationf(),scalef() functions all operate on model view matrix is
	//At beginning when no transformation is used, model view is located at center of cartesian co-ordinate system, or center of our window
	//but OpenGL's origin is left bottom, (drawing origin is at middel of cartesian system)
	// 
	//gluLookAt() for Camera transformation

	//Transform is nothing but Matrix multiplication
	//Mat Mult is not commutative

	//Rasterizer does Rasterization of vertex data/ geometric premitives (from vertex side) and Post operation pixel  (pixel side) it creates fragments
	// Fragments is entity which is disaneble
	// frame buffer loads fragments
}

void drawHollowCircle(float centerX, float centerY, float radius)
{
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount;i++) {
		glVertex2f(
			centerX + (radius * cos(i * twicePi / lineAmount)),
			centerY + (radius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
}


void drawSquare(void)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(1.50f);
	//Draw Hollow Rectangle
	glBegin(GL_LINE_STRIP);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
}

void drawTriangle(void)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(1.50f);
	//Draw Hollow Triangle
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

}

void drawGrid(void)
{
	glLineWidth(1.0f);
	int iTotalLinesCount = 20.0f;
	GLfloat fPointX = 5.0f;
	GLfloat fPointY = -2.0f;
	int iLineCounter = 0;
	GLfloat fCurrentLineCount = 1.0f;
	glColor3f(0.2f, 0.66f, 1.0f);
	//Horizontal Lines
	for (iLineCounter = -iTotalLinesCount; iLineCounter < iTotalLinesCount; iLineCounter = iLineCounter + 1)
	{
		if (iLineCounter == 0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glLineWidth(3.0f);
		}
		else if ((iLineCounter % 5) == 0) //Every 5th Line should be bold
		{
			glColor3f(0.2f, 0.66f, 1.0f);
			glLineWidth(1.5f);
		}
		else
		{
			glColor3f(0.2f, 0.66f, 1.0f);
			glLineWidth(0.50f);
		}
		glBegin(GL_LINES);
		glVertex3f(-fPointX, (GLfloat)fPointY, 0.0f);
		glVertex3f(fPointX, (GLfloat)fPointY, 0.0f);
		glEnd();
		fPointY = fPointY + 0.10f;
	}


	fPointX = -2.0f;
	fPointY = 5.0f;
	//Vertical Line
	for (iLineCounter = -iTotalLinesCount; iLineCounter < iTotalLinesCount; iLineCounter = iLineCounter + 1)
	{
		if (iLineCounter == 0)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
			glLineWidth(3.0f);
		}
		else if ((iLineCounter % 5) == 0) //Every 5th Line should be bold
		{
			glColor3f(0.2f, 0.66f, 1.0f);
			glLineWidth(1.5f);
		}
		else
		{
			glColor3f(0.2f, 0.66f, 1.0f);
			glLineWidth(0.50f);
		}
		glBegin(GL_LINES);
		glVertex3f(fPointX, (GLfloat)-fPointY, 0.0f);
		glVertex3f(fPointX, (GLfloat)fPointY, 0.0f);
		glEnd();
		fPointX = fPointX + 0.10f;
	}
}


void update(void)
{
	//code
	anglePyramid = anglePyramid + 0.09f;
	if (anglePyramid >= 360.0f)
	{
		anglePyramid = anglePyramid - 360.0f;
	}
	anglePyramid = anglePyramid - 0.05f;
	if (anglePyramid <= 360.0f)
	{
		anglePyramid = anglePyramid + 360.0f;
	}
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

//22nd March 2025 3D- Order of translation/
/*
*3D - Pyramid 1st Program
*
* 
*Kartavya -
*hpp/cuda assignment
*OpenGL/cuda interoperability
*OpenGL/openCL interoperability // sin wave
*hpp seminar //15-16 March 
*5 
* translation T0, T1,... T15
* scale S0, S1... S15
* Rotation 3 X1, X2, X3..... X15
* Y1, Y2, Y3..... Y15
* Z1, Z2, Z3,.... Z15
* with indices
* Matrix T[16] = T0, T1
* 
* Why Load Identity is  important?
* 
* OpenGL draws there where right now Modelview matrix is and translationf() scalef() and rotation() function operate(move) on model view matrix
* at beginning no transformation is used model view matrix is located at center/origin of cartesian coordinate system or center of our window but
* OpenGL's origin is Left Bottom
* Drawing origin at center of cartesian system
* 
* 3D Changes
* 1st Change - Change angleTriangle to anglePyramid
* 

* Depth Changes

6 Changes in initialize after glPrintInfo()

* After pfd.cAlphaBits add
* pfd.cDepthBits = 32; //24 for android //8 chya multiple madhe hava //Z -Depth vaparaychi ahe //Color chya equal or khali hava 
* 
* 2.	glclearcolor() chya varati 5 call
*	//Depth Related Code
*	//Rang detan/fragment tayar kartana/ 
*	//glShadeModel(GL_SMOOTH);
*
*	//in dispaly glclear la gelyavar mazya depth buffer(bits/fragments/pixel) madhe sagalyanchi value 1 ne clear kar //zalela nahiye kar asa sangta
*	//glClearDepth(1.0f);
*
*	//DEPT TEST enable keli
*	glEnable(GL_DEPTH_TEST); //GL_DEPTH_FUNC - 
*
*	//ase fragment pass kar jyanchi value clear_depth madhalya 1.0 peksha less or equal asel 
*	//
*	//glDepthFunc(GL_LEQUAL); //<=
*
*	//Hint to OpenGL jevha perspective projection mule kahi shapes depth mule vedevakade distail te nicest approach ne correction kar
*	//
*	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
*/


