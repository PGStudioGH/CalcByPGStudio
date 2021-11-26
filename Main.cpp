#include <iostream>

#include "Window.h"
#include "Splash.h"
#include "CalcByPGStudio.h"

using namespace std;

int main()
{
	createWindow();
	
	Splash();

	cout << endl << "Exited with code: " << CalcByPGStudio() << endl << endl << "\x1b[?25h";
	system("title cmd.exe");

	return 0;
}