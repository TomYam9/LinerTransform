
#define		MAX_LOADSTRING	100;


#include	"stdafx.h"

#include	<windows.h>

//Direct2D
#include	<d2d1.h>
#include	<d2d1helper.h>
#include	<atlbase.h>
#include	<wincodec.h>
#include	<wincodecsdk.h>

TCHAR szTitle[100];
TCHAR szWindowClass[100];



LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
int		WINAPI		WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);




LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	//ウィンドウから送られてくるメッセージを受け取るためのキャッチして処理する関数　コールバック関数　Javaにおけるコールバック関数

	HDC	hdc; //描画に使用するディスプレイ コンテキスト
	PAINTSTRUCT ps; //PAINTSTRUCT構造体には、ウィンドウのクライアント領域の描画に使用できる情報が含まれています.
	RECT rec;


	switch (msg) { //イベントの種類ごとに場合分け


	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);

		SetTextColor(hdc, RGB(0, 255, 255));
		rec.top = 10;
		rec.left = 10;
		rec.right = 290;
		rec.bottom = 100;
		DrawText(hdc, L"使用例 sample\nプリフィックス(&A)", -1, &rec,
			DT_WORDBREAK | DT_CENTER);

		Rectangle(hdc, 100, 100, 700, 700);




		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
			PostQuitMessage(0);
			break;


	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);

	}

	return 0L;

}

ATOM MyRegisterClass(HINSTANCE hInstance) { //自分でレジスタクラスを作る

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	//wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_D2DTEST01));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	//wcex.lpszMenuName = MAKEINTRESOURCE(IDC_D2DTEST01);
	wcex.lpszClassName = szWindowClass;
	//wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	HWND	hWnd;
	MSG		msg; //イベントの種類を指定するメッセージ

	WNDCLASS wc = { //ウィンドウのパラメータを指定する構造体
					CS_CLASSDC,
					WndProc, //コールバック関数の名前登録
					0,
					0,
					hInstance,
					NULL,
					LoadCursor(NULL, IDC_ARROW),
					(HBRUSH)GetStockObject(WHITE_BRUSH),
					NULL,
					szWindowClass
				};

	if (RegisterClass(&wc)==0) { //ウィンドウのクラスの登録

		return FALSE;
	}

	hWnd = CreateWindow( //ウィンドウの生成
		szWindowClass,
		szWindowClass,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd) return FALSE;

	ShowWindow(hWnd, nCmdShow); //ウィンドウの表示
	UpdateWindow(hWnd);
	SetFocus(hWnd);

	while (GetMessage(&msg, NULL, 0 , 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;


}