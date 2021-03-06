#include <iostream>
#include <conio.h>

using namespace std;

#include "Window.h"
#include "Error.h"

void Pause(int milliseconds, bool &off)
{
	milliseconds += clock();
	while (!off && clock() < milliseconds)
	{
		if (clock() % 200 < 100) cout << "\x1b[?25l";
		else cout << "\x1b[?25h";

		if (_kbhit())
		{
			off = _getch();
		}
		else if (CheckFullScreen()) Error("Don't press F11! You make bug in CMD", 1);
	}
	cout << "\x1b[?25h";
}

void AnimateText(const char str[], bool &off)
{
	int i = 0;
	if (!off) cout << '\a';
	while (!off && str[i] != '\0')
	{
		Pause(10, off); 
		if (!off) cout << str[i++];
	}
}

void Splash()
{
	system("title Intro by PGStudio");
	system("@mode con cols=80 lines=30");

	bool off = 0;
	char str1[] = "       _/_/_/     _/_/_/   _/_/_/ _/_/_/_/_/ _/    _/ _/_/_/   _/_/_/   _/_/\n\0";
	char str2[] = "      _/    _/ _/       _/           _/     _/    _/ _/    _/   _/   _/    _/\n\0";
	char str3[] = "     _/_/_/   _/  _/_/   _/_/       _/     _/    _/ _/    _/   _/   _/    _/\n\0";
	char str4[] = "    _/       _/    _/       _/     _/     _/    _/ _/    _/   _/   _/    _/\n\0";
	char str5[] = "   _/         _/_/_/ _/_/_/       _/       _/_/   _/_/_/   _/_/_/   _/_/\n\n\0";

	cout << "\x1b[2J\x1b[H" << "Starting MS-DOS...";
	Pause(2000, off);
	if (!off) cout << '\n';
	Pause(60, off);
	if (!off) cout << "\nMicrosoft(R) MS-DOS(R) Version 4.01" << endl;
	if (!off) cout << "\t     (C)Copyright Microsoft Corp 1981-1988";
	Pause(1000, off);
	if (!off) cout << '\n';
	Pause(60, off);
	if (!off) cout << "\nC:\\>";
	Pause(2000, off);
	if (!off) cout << 'd';
	Pause(700, off);
	if (!off) cout << 'i';
	Pause(500, off);
	if (!off) cout << 'r';
	Pause(1000, off);
	if (!off) cout << "\n\n Volume in drive C is MS-DOS_4";
	Pause(100, off);
	if (!off) cout << "\n Volume Serial Number is 40B4-7F23";
	Pause(100, off);
	if (!off) cout << "\n Directory of C:\\\n\n";
	Pause(100, off);
	if (!off) cout << "PGSTUDIO       <DIR>         21.04.16   22:03\n";
	Pause(100, off);
	if (!off) cout << "DOS            <DIR>         12.05.20   15:57\n";
	Pause(100, off);
	if (!off) cout << "WINDOWS        <DIR>         14.05.20   12:34\n";
	Pause(100, off);
	if (!off) cout << "COMMAND    COM        54 645 94.05.31    6:22\n";
	Pause(100, off);
	if (!off) cout << "WINA20     386         9 349 94.05.31    6:22\n";
	Pause(100, off);
	if (!off) cout << "LOGO       SYS         5 123 12.05.20   15:57\n";
	Pause(100, off);
	if (!off) cout << "DOC1       TXT         3 758 17.11.30   20:23\n";
	Pause(100, off);
	if (!off) cout << "DOC2       TXT         2 214 18.12.12   12:33\n";
	Pause(100, off);
	if (!off) cout << "PETERGAMES TXT           412 15.01.01   13:11\n";
	Pause(100, off);
	if (!off) cout << "AUTOEXEC   BAT           188 12.05.20   15:57\n";
	Pause(100, off);
	if (!off) cout << "CONFIG     SYS           144 12.05.20   15:57\n";
	Pause(100, off);
	if (!off) cout << "          8 file(s) ";
	Pause(1200, off);
	if (!off) cout << " 24 760 320 bytes free";
	Pause(100, off);
	if (!off) cout << '\n';
	Pause(60, off);
	if (!off) cout << "\nC:\\>";
	Pause(5000, off);
	if (!off) cout << 'c';
	Pause(300, off);
	if (!off) cout << 'd';
	Pause(200, off);
	if (!off) cout << ' ';
	Pause(700, off);
	if (!off) cout << 'p';
	Pause(400, off);
	if (!off) cout << 'g';
	Pause(300, off);
	if (!off) cout << 's';
	Pause(200, off);
	if (!off) cout << 't';
	Pause(400, off);
	if (!off) cout << 'u';
	Pause(200, off);
	if (!off) cout << 'd';
	Pause(350, off);
	if (!off) cout << 'i';
	Pause(300, off);
	if (!off) cout << 'o';
	Pause(500, off);
	if (!off) cout << '\n';
	Pause(60, off);
	if (!off) cout << "\nC:\\PGStudio>";
	Pause(700, off);
	if (!off) cout << 'd';
	Pause(300, off);
	if (!off) cout << 'i';
	Pause(200, off);
	if (!off) cout << 'r';
	Pause(500, off);
	if (!off) cout << "\n.              <DIR>                         \n";
	Pause(100, off);
	if (!off) cout << "..             <DIR>                         \n";
	Pause(100, off);
	if (!off) cout << "LIBRARY    DLL        32 863 21.04.16   14:51\n";
	Pause(100, off);
	if (!off) cout << "PGSTUDIO   EXE         1 645 21.04.16   14:57\n";
	Pause(100, off);
	if (!off) cout << "SETTING    INI           158 21.04.16   20:22\n";
	Pause(100, off);
	if (!off) cout << "README     TXT            45 21.04.16   16:01\n";
	Pause(100, off);
	if (!off) cout << "          4 file(s) ";
	Pause(1200, off);
	if (!off) cout << " 24 760 320 bytes free";
	Pause(100, off);
	if (!off) cout << '\n';
	Pause(60, off);
	if (!off) cout << "\nC:\\PGStudio>";
	Pause(3000, off);
	if (!off) cout << 'p';
	Pause(400, off);
	if (!off) cout << 'g';
	Pause(300, off);
	if (!off) cout << 's';
	Pause(200, off);
	if (!off) cout << 't';
	Pause(400, off);
	if (!off) cout << 'u';
	Pause(200, off);
	if (!off) cout << 'd';
	Pause(350, off);
	if (!off) cout << 'i';
	Pause(300, off);
	if (!off) cout << 'o';
	Pause(500, off);
	if (!off) cout << "\x1b[2J\x1b[H";
	Pause(1000, off);
	if (!off) cout << "\n\n\n\n\n\n\n\n\n\n\n";
	AnimateText(str1, off);
	AnimateText(str2, off);
	AnimateText(str3, off);
	AnimateText(str4, off);
	AnimateText(str5, off);
	Pause(400, off);
	if (!off) cout << "\t\t\t\a  Developed by PGStudio (2021)";
	Pause(500, off);
	if (!off) cout << '\a';
	Pause(2500, off);
	cout << "\a\x1b[2J\x1b[H";
}