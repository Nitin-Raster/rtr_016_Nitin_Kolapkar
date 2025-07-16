/*28th June PP Ortho - Shaders */
/*29th June 
* PP programed in 3 parts
* 1. Initialization of all extensions which allow all features of modern opengl to enable by enabling glew (horse keeper: wrangler ): graphics library extension wrangler: we initialize it by glewinit();
* 2. DEAL WITH SHADERS:
	 Programmable Pipeline : madhe Data input/pour karnare je programs ahet te shaders te programable ahet.
*	 Rang/Shader : GPU var run honare shaders
*	 (Graphics Pipeline : OpenCL/Cuda/ComputeShader : Kernel(i.e. shader))
*		1. Placeholder/Passthrough shaders : (empty shaders apan kelet vertex, fragment).
*			i. ShaderObject : (Vertex/Fragment) glCreateShader()
*				ii. Source : glShaderSource();
*					iii. Compile/Convert : glinfolog()
*			
		2. ShaderProgramObject tayar kela
				i. : glAttachShader(); //vertex, fragment shader
*						
*				ii. Link : GPU chya bhashet tayar zala ka he check karayla link kar, infolog() 
					//linking sathi cha 
					//Empty shader craeted here
*					// Data cruncher // object, shape creation, movement, //(40 )lakh vertices asel tar shader tevdhe vela to run honar 
					// tevdhe thread tayar karnar (group karav lagnar : SM (cuda): symmentric multiprocessor)
					// many core(and not multicore) // parallaly run hotat
					// vertex(jevdhe shaders)/tiscillation(jevdhe patches)/geometry
					
*		3. Execute/ Give Data (////varcha Data kasa dyaycha) //Hello world //triangle, shapes
*			Namespaces: to avoid confusion and pollution in class naming and usage  we introduced namespace
*		
* 1. Global declarations
* 2. 
* 3. 
* 4. 
* 
* No Transformation function in PP so we have to use vmath.h 
* vmath cpp madhe asalya mule apalyala OGL.cpp karavi lagnar ahe
* 
* 
*/

//Win32 (Standard) headers 
#include <windows.h>
#include <stdio.h> //input output file read write open
#include <stdlib.h>

//This header must be included before GL.H bcz 
#include <gl/GLEW.h>
//OpenGL related Header Files
#include <gl/GL.h>



/* Commented for Programable Pipeline
////For Perspective and for Sphere
////Not same as GLUT by Mark Killguard
//#include <gl/GLU.h> //Backward slash also works but all compilers we use forward slash for linux and Mac and other OS 
*/

//Custom Header Files
#include "OGL.h"

#include "vmath.h" //for matrix and transofrmation related computations sathi 

using namespace vmath;

//For PP
#pragma comment(lib, "glew32.lib")

//OpenGL related Libraries
#pragma comment(lib, "opengl32.lib")

/*Commented for PP
//#pragma comment(lib, "GLU32.lib") //For Perspective and for Sphere
*/
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

//shader related global variable
GLuint shaderProgramObject = 0;

/*29th June changes declarations START*/

enum
{
	AMC_ATTRIBUTE_POSITION = 0,

};

GLuint vao = 0; //
GLuint vbo_position = 0; //

GLuint mvpMatrixUniform = 0; //

mat4 perspectiveProjectionMatrix;  //vmath::mat4 matrix 4X4

/*29th June changes declarations END*/


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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("NKK OGL - PP Perspective BW Triangle with Shaders 6th July"), WS_OVERLAPPEDWINDOW, (xPos - (WIN_WIDTH / 2)),
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
	void uninitialize(void);

	//variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

	//For PP
	GLenum glewResult;

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

	//For PP
	//Initialize GLEW
	glewResult = glewInit();
	if (glewResult != GLEW_OK)
	{
		fprintf(gpFile, "glewInit() function failed\n");
		return(-6);
	}

	//Printf GL Info
	printGLInfo();
	/*SHADERS*/
	/*------------------------------------------------------------------------
	//VERTEX SHADER
	/*
		1. Write Shader source code
		2. Create the Shader Object
		3. Give the souce code to the shader object
		4. Compile the shader
		5. Do shader compilation error checking
	*/
	/*OpenGL Vendor	: Intel
	OpenGL Renderer	: Intel(R) HD Graphics 530
	OpenGL Version	: 4.6.0 - Build 31.0.101.2111
	GLSL Version 4.60 - Build 31.0.101.2111*/
	//Vertex Shader Source code
	//"in Vec4 aPos \n" Vertex(shader) chi property/position ahe... ji vector ahe jyache naav aPos aahe
	//mat4 ha vegala aahe, vmath madhe nahiye 
	const GLchar* vertexShaderSourceCode = //1.06 min 22nd June recording
		"#version 460 core\n" \
		"in vec4 aPos;\n" \
		"uniform mat4 uMVPMatrix;\n" \
		"void main(void)\n" \
		"{\n" \
		"gl_Position = uMVPMatrix * aPos;\n" \
		"}\n";
		// We used \ backslash (escape sequence) 

	//2. Create Shader Object
	GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);

	//3. Give the souce code to the shader object
	//3rd parameter can be array of shadercode 
	//4th param is length of every shader array
	glShaderSource(vertexShaderObject, 1, (const GLchar**)&vertexShaderSourceCode, NULL);

	//4. Compile Shader
	glCompileShader(vertexShaderObject);

	//5. Do shader compilation error checking
	GLint status = 0;
	GLint infoLogLength = 0;
	GLchar* szinfoLog = NULL;

	glGetShaderiv(vertexShaderObject, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		glGetShaderiv(vertexShaderObject, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0)
		{
			szinfoLog = (GLchar*)malloc(infoLogLength * sizeof(GLchar));
			if (szinfoLog != NULL)
			{
				glGetShaderInfoLog(vertexShaderObject, infoLogLength, NULL, szinfoLog);
				fprintf(gpFile, "Vertex Shader Compilation Log = %s\n", szinfoLog);
				free(szinfoLog);
				szinfoLog = NULL;
			}
		}
		uninitialize();
	}
	//End of Vertex Shader
	/*----------------------------------------------------------------------------*/
	
	/*FRAGMENT SHADER*/
	//Fragment is nothing but potential pixel
	//gl_FragColor
	//PP madhe default White color asat nahi
	const GLchar* fragmentShaderSourceCode = // 1.47 in Recording 22nd June 2025
		"#version 460 core\n" \
		"out vec4 FragColor;" \
		"void main(void)\n" \
		"{\n" \
		"FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);" \
		"}\n";
	//2. Create Fragment Shader Object
	GLuint fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

	//3. Give the souce code to the shader object
	glShaderSource(fragmentShaderObject, 1, (const GLchar**)&fragmentShaderSourceCode, NULL);

	//4. Compile Shader
	glCompileShader(fragmentShaderObject);

	//5. Do shader compilation error checking
	status = 0;
	infoLogLength = 0;
	szinfoLog = NULL;
	glGetShaderiv(fragmentShaderObject, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		glGetShaderiv(fragmentShaderObject, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0)
		{
			szinfoLog = (GLchar*)malloc(infoLogLength * sizeof(GLchar));
			if (szinfoLog != NULL)
			{
				glGetShaderInfoLog(fragmentShaderObject, infoLogLength, NULL, szinfoLog);
				fprintf(gpFile, "Fragment Shader Compilation Log = %s\n", szinfoLog);
				free(szinfoLog);
				szinfoLog = NULL;
			}
		}
		uninitialize();
	}
	//END OF FRAGMENT SHADER //
	/*----------------------------------------------------------------------------*/

	/**/
	//Create, Attach Shader Program 
	//1. Create Shader Program Object
	//2. Attach shader objects to shader program objects
	//3. Tell to Link the shader program objects
	//4. Check for Link error log

	//1. Create Shader Program Object
	shaderProgramObject = glCreateProgram();

	glAttachShader(shaderProgramObject, vertexShaderObject);
	glAttachShader(shaderProgramObject, fragmentShaderObject);

	/*Memory mapped IO*/
	/*Bind shader attribute at a certain index in shader to same index in host program
	"in" navachi ek JAGA aahe GPU madhe... */
	/*Vulkun 4.5 nantar aala so syntax madhe layout vaparacha asta ani location manually dyaycha asta so "in Vec4 Pos = 0"*/
	/*OpenGL madhe jo pahila yenar to pahila bananar*/
	glBindAttribLocation(shaderProgramObject, AMC_ATTRIBUTE_POSITION, "aPos"); /*Vulkan : Map->memcpy->unMap */


	glLinkProgram(shaderProgramObject);

	status = 0;
	infoLogLength = 0;
	szinfoLog = NULL;
	glGetProgramiv(shaderProgramObject, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		glGetProgramiv(shaderProgramObject, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0)
		{
			szinfoLog = (GLchar*)malloc(infoLogLength * sizeof(GLchar));
			if (szinfoLog != NULL)
			{
				glGetProgramInfoLog(shaderProgramObject, infoLogLength, NULL, szinfoLog);
				fprintf(gpFile, "Shader Program Link Log = %s\n", szinfoLog);
				free(szinfoLog);
				szinfoLog = NULL;
			}
		}
		uninitialize();
	}
	/*END OF SHADER PROGRAM*/


	/*END OF SHADERS*/
	/*what to do with shader data
	//Next lecture of 28-29th June */

	//29th June 2025 
	/*Get the required uniform location from the shader*/
	mvpMatrixUniform = glGetUniformLocation(shaderProgramObject, "uMVPMatrix");
	/*Jo Data runtime la badalat nahi tyala mhantat attributes(e.g. Positions) 
	Jo Data per frame la badalu shakto/badalto to uniform la dyaycha */
	/*Matrices per frame la badalu shaktat, user per frame la viewport badalu shakto, resize la call janar*/
	
	//29th June 2025 
	// //Provide vertices/vertex position, color, texturecord, and normal etc.
	const GLfloat triangle_position[] =
	{
		0.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f
	}; //In PP no vertex3f, 2f, 

	//29th June 2025 
	// //vertex array object for arrays of vertex attributes
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Position
	glGenBuffers(1, &vbo_position);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_position); //binding point (it can have multiple binding points)
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_position), triangle_position, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL); //(Dhanga)interlived la 0 ha 0 asanar nahiye
	//#define NULL (void*) &0;
	glEnableVertexAttribArray(AMC_ATTRIBUTE_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, 0); //binding point // target point 
	
	//
	glBindVertexArray(0);


	//22nd March 2025 - 3D Pyramid changes 
	// Below 5 function call
	//Depth Related calls
	//OpenGL la sangtay rand detana/shading kartana smoothness cha vichar kar
	//Commented for PP // Part of FFP
	//glShadeModel(GL_SMOOTH);

	//in dispaly glclear la gelyavar mazya depth buffer(bits/fragments/pixel) madhe sagalyanchi value 1 ne clear kar
	glClearDepth(1.0f);

	//DEPT TEST enable keli
	glEnable(GL_DEPTH_TEST);

	//ase fragment pass kar jyanchi value clear_depth madhalya 1.0 peksha less or equal asel
	glDepthFunc(GL_LEQUAL); //<=

	//Commented for PP // Part of FFP
	//Hint to OpenGL jevha perspective projection mule kahi shapes depth mule vedevakade distail te nicest approach ne correction kar 
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//From here onwards OpenGL code starts
	//tell OpenGL to choose the color to clear screen
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //set blue color

	//6th July
	perspectiveProjectionMatrix = mat4::identity(); //this is analogus to FFP's glLoadIdentity()
													 //this is similar to glLoadIdentity in resize()



	//Warmup resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);
}

//Print GLInfo
void printGLInfo(void)
{
	//Variable Declarations
	GLint numExtentions, i;

	//code print OpenGL Info
	fprintf(gpFile, "\n\nOPENGL INFORMATION\n\n");
	fprintf(gpFile, "************************\n");
	
	fprintf(gpFile, "OpenGL Vendor	: %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "OpenGL Renderer	: %s\n", glGetString(GL_RENDERER)); //Driver
	fprintf(gpFile, "OpenGL Version	: %s\n", glGetString(GL_VERSION));
	
	//For PP
	fprintf(gpFile, "GLSL Version %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	//Get Number of Extentions //PP
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtentions);
	
	//PP // Print OpenGL Extensions
	for (i = 0; i < numExtentions; i++)
	{
		fprintf(gpFile, "%s\n", glGetStringi(GL_EXTENSIONS, i));
	}


	fprintf(gpFile, "************************\n\n");

}

void resize(int width, int height)
{
	//29th June 2025
	//glMatrixMode(GL_PROJECTION) cha parallel code resize madhe kela ahe

	//code
	//if height by accident becomes 0 or less than 0 make height 1
	if (height <= 0)
	{
		height = 1;
	}

	// set the Viewport
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	perspectiveProjectionMatrix = vmath::perspective(45.0f,					//FOVY Field of View Y = 45 degree
		(GLfloat)width / (GLfloat)height,	//Aspect Ratio this takes care of FOVX
		0.1f,								//Near
		100.0f);
	//commented for perspective
	//if (width <= height)
	//{
	//	orthographicProjectionMatrix = vmath::ortho(-100.0f,
	//		100.0f,
	//		(-100.0f * ((GLfloat)height / width)),
	//		(100.0f * ((GLfloat)height / width)),
	//		-100.0f,
	//		100.0f); //Left, right, Bottom, Top, Near, Far
	//}
	//else
	//{
	//	orthographicProjectionMatrix = vmath::ortho((-100.0f * ((GLfloat)width / height)),
	//		(100.0f * ((GLfloat)width / height)),
	//		-100.0f,
	//		100.0f,
	//		-100.0f,
	//		100.0f);
	//}

	//Commetned for PP
	//Set Matrix Projection Mode
	//glMatrixMode(GL_PROJECTION);

	////Set To Identity Matrix
	//glLoadIdentity();

	//gluPerspective Commetned for PP
	//Do Perspective Projection // gluPerspective is more intuitive
	//gluPerspective(45.0f,					//FOVY Field of View Y = 45 degree
	//	(GLfloat)width / (GLfloat)height,	//Aspect Ratio this takes care of FOVX
	//	0.1f,								//Near
	//	100.0f);							//Far
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

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //For 3D we add GL_DEPTH_BUFFER_BIT //DEPTH buffer la jaun clear kar je aadhi initialize buffer madhalya 1.0 ne clear kar
	
	//22nd June Code
	//Use Shader Program Object
	glUseProgram(shaderProgramObject);
	
	//glMatrixModel(GL_PROJECTION) cha parallel code resize madhe kela ahe
	
	//drawing code
	//transformations 
	mat4 modelViewMatrix = mat4::identity(); //this is analogus to glLoadIdentity in display() for model view matrix
	mat4 modelViewProjectionMatrix = mat4::identity(); //glMatrixMode(GL_MODELVIEW); 
	mat4 translationMatrix = mat4::identity();
	translationMatrix = vmath::translate(0.0f, 0.0f, -4.0f);
	modelViewMatrix = translationMatrix; //glTranslatef(0.0f, 0.0f, -5.0f);

	modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // Order is important

	//send this modelViewProjectionMatrix to shader in uniform
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);
	
	//bind with vao
	glBindVertexArray(vao);
	
	//Draw the vertex arrays
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0); //vao unbind kar

	//Unuse Shader Program Object
	glUseProgram(0);
	SwapBuffers(ghdc); //Win32 function call

	//Before PP  Code
	//code
	//Clear OpenGL buffers
	//He OGL mazya frame buffer madhlya color buffer la ja ani pratyek bit me dilelya initialize madhil clear color ne clear kar(i.e. BLACK now)
	//glClear(GL_COLOR_BUFFER_BIT ); Before 3D
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //For 3D we add GL_DEPTH_BUFFER_BIT //DEPTH buffer la jaun clear kar je aadhi initialize buffer madhalya 1.0 ne clear kar

	//************************************ PYRAMID *********************************
	//Set Matrix to Model View Mode
	//glMatrixMode(GL_MODELVIEW);
	//
	////Set it to Identity Matrix
	//glLoadIdentity();

	
	//Depth



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
	//SwapBuffers(ghdc); //Win32 function call

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
	
	//29th June 2025
	//Free vbo of position
	if (vbo_position)
	{
		glDeleteBuffers(1, &vbo_position);
		vbo_position = 0;
	}

	//Free vao
	if (vao)
	{
		glDeleteVertexArrays(1, &vao);
	}


	//22nd June Lecture
	//Detach, Delete Shader Objects
	//Detach, Delete Shader Programm Objects
	if (shaderProgramObject)
	{
		glUseProgram(shaderProgramObject);
		GLint numShaders = 0;
		glGetProgramiv(shaderProgramObject, GL_ATTACHED_SHADERS, &numShaders);
		if (numShaders > 0)
		{
			GLuint* pShaders = (GLuint*)malloc(numShaders * sizeof(GLuint));
			if (pShaders != NULL)
			{
				glGetAttachedShaders(shaderProgramObject, numShaders, NULL, pShaders);
				for (GLint i = 0; i < numShaders; i++)
				{
					glDetachShader(shaderProgramObject, pShaders[i]);
					glDeleteShader(pShaders[i]);
				}
			}
			free(pShaders);
			pShaders = 0;
		}
		glUseProgram(0);
		glDeleteProgram(shaderProgramObject);
		shaderProgramObject = 0;
	}

	//Check if Shader Program object still there
	//Get number of shaders and continue only if numbers of shaders > 0
	//Create a buffer/array to hold shader objects of obtained size
	//Get shader objects into this buffer and continue only if malloc is succeeded
	//start a loop for obtained number of shaders and inside this loop detach and delete every shader from buffer/array
	//free the buffer/array
	//delete the shader program object

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
* 22nd JUNE 2025
* Shaders -  Used for Geometry... 
* 
*/


