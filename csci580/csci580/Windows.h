#ifndef WINDOWS_H
#define WINDOWS_H
#define WIN32_LEAN_AND_MEAN
#include<windows.h>
class Windows {
public:
	Windows();
	void CreateView();
	int Getvalue();
	int Getvalue2();
	bool Gettemp1();
	bool Gettemp2();
	virtual ~Windows();
private:
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow);

};
#endif

