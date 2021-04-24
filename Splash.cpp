#include <iostream>
#include <conio.h>

using namespace std;

void Pause(int milliseconds)
{
	milliseconds += clock();
	while (clock() < milliseconds);
}

void AnimateText(const char str[])
{
	int i = 0;
	cout << '\a';
	while (str[i] != '\0')
	{
		Pause(10);
		cout << str[i++];
	}
}

void Splash()
{
	system("title Intro by PGStudio");
	system("@mode con cols=80 lines=30");

	char str1[] = "       _/_/_/     _/_/_/   _/_/_/ _/_/_/_/_/ _/    _/ _/_/_/   _/_/_/   _/_/\n\0";
	char str2[] = "      _/    _/ _/       _/           _/     _/    _/ _/    _/   _/   _/    _/\n\0";
	char str3[] = "     _/_/_/   _/  _/_/   _/_/       _/     _/    _/ _/    _/   _/   _/    _/\n\0";
	char str4[] = "    _/       _/    _/       _/     _/     _/    _/ _/    _/   _/   _/    _/\n\0";
	char str5[] = "   _/         _/_/_/ _/_/_/       _/       _/_/   _/_/_/   _/_/_/   _/_/\n\n\0";

	cout << "\x1b[2J\x1b[H" << "Starting MS-DOS...";
	Pause(2000);
	cout << '\n';
	Pause(60);
	cout << "\nMicrosoft(R) MS-DOS(R) Version 4.01" << endl;
	cout << "\t     (C)Copyright Microsoft Corp 1981-1988";
	Pause(1000);
	cout << '\n';
	Pause(60);
	cout << "\nC:\\>";
	Pause(2000);
	cout << 'd';
	Pause(700);
	cout << 'i';
	Pause(500);
	cout << 'r';
	Pause(1000);
	cout << "\n\n Volume in drive C is MS-DOS_4";
	cout << "\n Volume Serial Number is 40B4-7F23";
	cout << "\n Directory of C:\\\n\n";
	cout << "PGSTUDIO       <DIR>         21.04.16   22:03\n";
	Pause(60);
	cout << "DOS            <DIR>         12.05.20   15:57\n";
	Pause(60);
	cout << "COMMAND    COM        54 645 94.05.31    6:22\n";
	Pause(60);
	cout << "WINA20     386         9 349 94.05.31    6:22\n";
	Pause(60);
	cout << "CONFIG     SYS           144 12.05.20   15:57\n";
	Pause(60);
	cout << "AUTOEXEC   BAT           188 12.05.20   15:57\n";
	Pause(60);
	cout << "          5 file(s)         64 326 bytes\n";
	Pause(60);
	cout << "                        24 760 320 bytes free";
	Pause(1200);
	cout << '\n';
	Pause(60);
	cout << "\nC:\\>";
	Pause(5000);
	cout << 'c';
	Pause(300);
	cout << 'd';
	Pause(200);
	cout << ' ';
	Pause(700);
	cout << 'p';
	Pause(400);
	cout << 'g';
	Pause(300);
	cout << 's';
	Pause(200);
	cout << 't';
	Pause(400);
	cout << 'u';
	Pause(200);
	cout << 'd';
	Pause(350);
	cout << 'i';
	Pause(300);
	cout << 'o';
	Pause(500);
	cout << '\n';
	Pause(60);
	cout << "\nC:\\PGStudio>";
	Pause(700);
	cout << 'd';
	Pause(300);
	cout << 'i';
	Pause(200);
	cout << 'r';
	Pause(500);
	cout << "\n.              <DIR>                         \n";
	Pause(60);
	cout << "..             <DIR>                         \n";
	Pause(60);
	cout << "LIBRARY    DLL        32 863 21.04.16   15:51\n";
	Pause(60);
	cout << "PGSTUDIO   EXE         1 645 21.04.16   15:57\n";
	Pause(60);
	cout << "          2 file(s)         33 508 bytes\n";
	Pause(60);
	cout << "                        24 760 320 bytes free";
	Pause(1200);
	cout << '\n';
	Pause(60);
	cout << "\nC:\\PGStudio>";
	Pause(3000);
	cout << 'p';
	Pause(400);
	cout << 'g';
	Pause(300);
	cout << 's';
	Pause(200);
	cout << 't';
	Pause(400);
	cout << 'u';
	Pause(200);
	cout << 'd';
	Pause(350);
	cout << 'i';
	Pause(300);
	cout << 'o';
	Pause(200);
	cout << '.';
	Pause(250);
	cout << 'e';
	Pause(150);
	cout << 'x';
	Pause(100);
	cout << 'e';
	Pause(500);
	cout << "\x1b[2J\x1b[H";
	Pause(1000);
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	AnimateText(str1);
	AnimateText(str2);
	AnimateText(str3);
	AnimateText(str4);
	AnimateText(str5);
	Pause(400);
	cout << "\t\t\t\a  Developed by PGStudio (2021)";
	Pause(500);
	cout << '\a';
	Pause(2500);
	cout << "\a\x1b[2J\x1b[H";
}