//Win32 headers
#include<windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declaration
	WNDCLASSEX  wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");

	//code
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register Above Class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName, TEXT("Nitin Kishor Kolapkar"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}
//RGB(255,0,0) = RED
//RGB(0,255,0) = GREEN
//RGB(0,0,255) = BLUE
//RGB(255,255,0) = YELLOW
//RGB(0,255,255) = Cyan
//RGB(255,0,255) = Magenta
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Local Variable Declarations
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[] = TEXT("Hello World !!!");
	static int iPaintFlag = -1;
	// code
	switch (iMsg)
	{
	case WM_CHAR:
		switch (wParam)
		{
			case 'R':
			case 'r':
				iPaintFlag = 1;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'G':
			case 'g':
				iPaintFlag = 2;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'B':
			case 'b':
				iPaintFlag = 3;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'C':
			case 'c':
				iPaintFlag = 4;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'M':
			case 'm':
				iPaintFlag = 5;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'Y':
			case 'y':
				iPaintFlag = 6;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'W':
			case 'w':
				iPaintFlag = 7;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 'O':
			case 'o':
				iPaintFlag = 8;
				InvalidateRect(hwnd, NULL, TRUE);
				break;

		}

	case WM_PAINT: // 1st Display of Window 2. Deskop WM_PAINT 3. Window Move 4. Window icon 5. Window Mouse 6Window menu pull up, 
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		SetBkColor(hdc, RGB(0, 0, 0));
		if(iPaintFlag == 1) //RED
			SetTextColor(hdc, RGB(255, 0, 0));
		else if(iPaintFlag == 2) //GREEN
			SetTextColor(hdc, RGB(0, 255, 0));
		else if(iPaintFlag == 3) //BLUE
			SetTextColor(hdc, RGB(0, 0, 255));
		else if(iPaintFlag == 4) // Cyan
			SetTextColor(hdc, RGB(0, 255, 255));
		else if(iPaintFlag == 5) // MAGENTA 
			SetTextColor(hdc, RGB(255, 0, 255));
		else if(iPaintFlag == 6) // YELLOW 
			SetTextColor(hdc, RGB(255, 255, 0));
		else if(iPaintFlag == 7) // WHITE
			SetTextColor(hdc, RGB(255, 255, 255));
		else if(iPaintFlag == 8) // WHITE
			SetTextColor(hdc, RGB(255, 165, 0));

		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);	
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
