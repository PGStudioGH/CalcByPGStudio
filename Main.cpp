#include <iostream>

#include "Window.h"
//#include "Splash.h"
#include "CalcByPGStudio.h"

using namespace std;

int main()
{
	system("@mode con cols=61 lines=12");
	createWindow();
	
	//Splash();

	cout << "\a\x1b[2J\x1b[HExited with code: " << CalcByPGStudio() << "\n\n\x1b[?25h";
	system("title cmd.exe");

	return 0;
}