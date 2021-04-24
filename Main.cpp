#include <iostream>

#include "Splash.h"
#include "CalcByPGStudio.h"

using namespace std;

int main()
{
	Splash();
	cout << "\x1b[?25l";
	cout << endl << "Exited with code: " << CalcByPGStudio() << endl << endl;
	system("title Result");
	system("pause");

	return 0;
}