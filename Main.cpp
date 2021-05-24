#include <iostream>

#include "Window.h"
#include "Splash.h"
#include "CalcByPGStudio.h"

using namespace std;

int main()
{
	createWindow();
	cout << "\x1b[?25l";

	Splash();

	cout << endl << "Exited with code: " << CalcByPGStudio() << endl << endl;
	system("title Result");
	system("pause");

	return 0;
}