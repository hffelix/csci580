#include "stdafx.h"
#include "Windows.h"
#include <stdio.h>
#include <stdlib.h>
HWND textfield,button,TextBox,TextBox2,button2,textfield2;
char szClassName[] = "TextEntry";
char numberEntered[20];
char numberEntered2[20];
int ftagerget,ftagerget2;
bool temp1,temp2;
void Setvalue1(char * a)
{
	ftagerget = atoi(a);
}
void Setvalue2(char * a)
{
	ftagerget2 = atoi(a);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		textfield =CreateWindow(L"STATIC", L"INSIDE LAYER VALUE:", WS_VISIBLE | WS_CHILD, 15, 20, 170, 30, hwnd, NULL, NULL, NULL);
		textfield2 = CreateWindow(L"STATIC", L"OUTSIDE LAYER VALUE:", WS_VISIBLE | WS_CHILD, 15, 120, 170, 30, hwnd, NULL, NULL, NULL);
		button= CreateWindow(L"BUTTON", L"1 LAYER", WS_VISIBLE | WS_CHILD|WS_BORDER, 90, 60, 70, 50, hwnd, (HMENU) 1, NULL, NULL);
		button2 = CreateWindow(L"BUTTON", L"2 LAYERS", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 165, 70, 50, hwnd, (HMENU)2, NULL, NULL);
		TextBox= CreateWindow(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 190, 20, 30, 30, hwnd, NULL, NULL, NULL); 
		TextBox2 = CreateWindow(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 190, 120, 30, 30, hwnd, NULL, NULL, NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case 1:
		{
			int gwtstat = 0;
			gwtstat = GetWindowTextA(TextBox, numberEntered, 20);
			gwtstat = GetWindowTextA(TextBox2, numberEntered2, 20);
			//::MessageBeep(MB_ICONERROR);		FOR DEBUG
			//::MessageBoxA(hwnd, numberEntered, numberEntered, NULL);// FOR DEBUG
			Setvalue1(numberEntered);
			Setvalue2(numberEntered2);
			temp1 = true; temp2 = false;
			DestroyWindow(hwnd);
			break;}
		case 2:
		{
			int gwtstat = 0;
			gwtstat = GetWindowTextA(TextBox, numberEntered, 20);
			gwtstat = GetWindowTextA(TextBox2, numberEntered2, 20);
			//::MessageBeep(MB_ICONERROR);		FOR DEBUG
			//::MessageBoxA(hwnd, numberEntered, numberEntered, NULL);// FOR DEBUG
			Setvalue1(numberEntered);
			Setvalue2(numberEntered2);
			temp1 = false; temp2 = true;
			DestroyWindow(hwnd);
			break;}
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);

	}
}

Windows::Windows()
{
}

void Windows::CreateView() {
	WinMain(GetModuleHandle(0),GetModuleHandle(0),(LPSTR)GetCommandLine(),1);
}

int Windows::Getvalue()
{
	return ftagerget;
}

int Windows::Getvalue2()
{
	return ftagerget2;
}

bool Windows::Gettemp1()
{
	return temp1;
}

bool Windows::Gettemp2()
{
	return temp2;
}





int Windows::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"WndClass";
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"REGISTER FAILED!", L"ERROR", NULL);
		return 1;
	}
	HWND hwnd = CreateWindow(L"WndClass", L"Initial Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 256, 256, NULL, NULL, hInstance, NULL);
	if (!hwnd) {
		MessageBox(NULL, L"WINDOW CREATION FAILED!", L"ERROR", NULL);
		return 1;
	}
	ShowWindow(hwnd, cmdShow);
	UpdateWindow(hwnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
Windows::~Windows()
{
}
