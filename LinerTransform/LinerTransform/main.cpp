
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

	//�E�B���h�E���瑗���Ă��郁�b�Z�[�W���󂯎�邽�߂̃L���b�`���ď�������֐��@�R�[���o�b�N�֐��@Java�ɂ�����R�[���o�b�N�֐�

	HDC	hdc; //�`��Ɏg�p����f�B�X�v���C �R���e�L�X�g
	PAINTSTRUCT ps; //PAINTSTRUCT�\���̂ɂ́A�E�B���h�E�̃N���C�A���g�̈�̕`��Ɏg�p�ł����񂪊܂܂�Ă��܂�.
	RECT rec;


	switch (msg) { //�C�x���g�̎�ނ��Ƃɏꍇ����


	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);

		SetTextColor(hdc, RGB(0, 255, 255));
		rec.top = 10;
		rec.left = 10;
		rec.right = 290;
		rec.bottom = 100;
		DrawText(hdc, L"�g�p�� sample\n�v���t�B�b�N�X(&A)", -1, &rec,
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

ATOM MyRegisterClass(HINSTANCE hInstance) { //�����Ń��W�X�^�N���X�����

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
	MSG		msg; //�C�x���g�̎�ނ��w�肷�郁�b�Z�[�W

	WNDCLASS wc = { //�E�B���h�E�̃p�����[�^���w�肷��\����
					CS_CLASSDC,
					WndProc, //�R�[���o�b�N�֐��̖��O�o�^
					0,
					0,
					hInstance,
					NULL,
					LoadCursor(NULL, IDC_ARROW),
					(HBRUSH)GetStockObject(WHITE_BRUSH),
					NULL,
					szWindowClass
				};

	if (RegisterClass(&wc)==0) { //�E�B���h�E�̃N���X�̓o�^

		return FALSE;
	}

	hWnd = CreateWindow( //�E�B���h�E�̐���
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

	ShowWindow(hWnd, nCmdShow); //�E�B���h�E�̕\��
	UpdateWindow(hWnd);
	SetFocus(hWnd);

	while (GetMessage(&msg, NULL, 0 , 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;


}