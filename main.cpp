
#include <windows.h>
#include <Gl/gl.h>

#include "CRenderer.hpp"
#include "COpenGlEx1.hpp"
#include "COpenGlEx2.hpp"
using namespace Aeglir::LowLevRender;

const char g_szClassName[] = "OpenGlTestClass";

COpenGlEx1 example1;
COpenGlEx2 example2;
static CRenderer &renderer = CRenderer::getInstance(example2);
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{

	switch(msg){
	case WM_CREATE:{

		renderer.init(hwnd);

		break;
	}
	case WM_PAINT:{

		renderer.render();
		break;
	}
	case WM_CLOSE:{

		renderer.deinit();
		DestroyWindow(hwnd);
		break;
	}
	case WM_DESTROY:{

		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd,msg,wparam,lparam);
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,
		int nCmdShow)
{
	WNDCLASSEX wc = {0};
	HWND hwnd;
	MSG Msg = {0};



	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	wc.style = CS_OWNDC;

	if(!RegisterClassEx(&wc)){
		MessageBox(NULL,"Window registration failed","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	 hwnd = CreateWindowEx(
	        WS_EX_CLIENTEDGE,
	        g_szClassName,
	        "The title of my window",
	        WS_OVERLAPPEDWINDOW,
	        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
	        NULL, NULL, hInstance, NULL);

	if(hwnd == NULL){
		MessageBox(NULL,"Window creation failed","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	while(GetMessage(&Msg,NULL,0,0)>0){

		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;


}
