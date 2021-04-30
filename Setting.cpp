#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>

#include "Characters.h"
#include "Credits.h"

using namespace std;

void ChangeSizeWindow(int cols, int lines)
{
	if (cols < 1) cols = 1;
	else if (cols > 999) cols = 999;

	if (lines < 1) lines = 1;
	else if (lines > 99) lines = 99;

	char str[28];
	sprintf_s(str, "@mode con cols=%d lines=%d", cols, lines);
	system(str);
}

void Save(int WIDTH, int HEIGHT, int CURSOR)
{
	if (CURSOR < 0) CURSOR += 256;
	ofstream save("settings.ini");
	save << "[Setting]" << endl;
	save << "WIDTH=" << WIDTH << endl;
	save << "HEIGHT=" << HEIGHT << endl;
	save << "CURSOR=" << CURSOR << endl;
	save.close();
}

void Default(int &WIDTH, int &HEIGHT, char &CURSOR)
{
	WIDTH = 0;
	HEIGHT = 0;
	CURSOR = 178;
	Save(WIDTH, HEIGHT, CURSOR);
}

void Load(int &WIDTH, int &HEIGHT, char &CURSOR)
{
	FILE* file = fopen("settings.ini", "r");
	if (file)
	{
		ifstream load("settings.ini");
		bool width = 0;
		bool height = 0;
		bool cursor = 0;
		char str[256];

		while (!load.eof() && !(width && height && cursor))
		{
			load.getline(str, 256);
			char s[256] = "";
			char* p = strtok(str, " ");
			while (p)
			{
				strcat(s, p);
				p = strtok(NULL, " ");
			}

			if (s[0] != ';' && s[0] != '#' && strchr(s, '='))
			{
				char var[256] = "";
				p = strtok(s, "=");
				strcat(var, p);

				if (!strcmp(var, "WIDTH") && !width)
				{
					p = strtok(NULL, ";#");
					WIDTH = atoi(p);
					width = 1;
				}
				else if (!strcmp(var, "HEIGHT") && !height)
				{
					p = strtok(NULL, ";#");
					HEIGHT = atoi(p);
					height = 1;
				}
				else if (!strcmp(var, "CURSOR") && !cursor)
				{
					p = strtok(NULL, ";#");
					CURSOR = atoi(p);
					cursor = 1;
				}
			}
		}
		load.close();
		fclose(file);

		if (!width) WIDTH = 0;
		else
		{
			if (WIDTH < 0) WIDTH = 0;
			else if (WIDTH > 255) WIDTH = 255;
		}
		if (!height) HEIGHT = 0;
		else
		{
			if (HEIGHT < 0) HEIGHT = 0;
			else if (HEIGHT > 63) HEIGHT = 63;
		}
		if (!cursor) CURSOR = 178;
		else if (-2 < CURSOR && CURSOR < 33) CURSOR = 178;

		Save(WIDTH, HEIGHT, CURSOR);
	}
	else Default(WIDTH, HEIGHT, CURSOR);
}

void Setting(int& WIDTH, int& HEIGHT, char& CURSOR)
{
	system("title Setting");

	int i = 0;
	int select = 0;
	char cin = 0;
	bool Start = 1;

	while (cin != ESC)
	{
		if (Start)
		{
			int SIZE_WINDOW = WIDTH + 59;
			int SIZE_FREE_LINE = HEIGHT;
			ChangeSizeWindow(SIZE_WINDOW + 2, SIZE_FREE_LINE + 12);

			cout << "\x1b[48;2;16;16;192m\x1b[97m\x1b[2J\x1b[H" << rtc;
			for (i = 0; i < 12; i++) cout << hl;
			cout << tc;
			for (i = 0; i < SIZE_WINDOW / 2 - 19; i++) cout << hl;
			cout << " Calculator ";
			for (i = 0; i < SIZE_WINDOW / 2 - 6 + SIZE_WINDOW % 2; i++) cout << hl;
			cout << ltc << endl;

			cout << vl << " ESC - exit " << vl;
			for (i = 0; i < SIZE_WINDOW - 13; i++) cout << SPACE;
			cout << vl << endl << rc;
			for (i = 0; i < 12; i++) cout << hl;
			cout << lbc;
			for (i = 0; i < SIZE_WINDOW - 13; i++) cout << SPACE;

			i = 0;
			while (i < SIZE_FREE_LINE / 2 + SIZE_FREE_LINE % 2)
			{
				cout << vl << endl << vl;
				for (int j = 0; j < SIZE_WINDOW; j++) cout << SPACE;
				i++;
			}
			cout << vl << endl << vl << SPACE << rtc;
			for (i = 0; i < SIZE_WINDOW - 4; i++) cout << hl;
			cout << ltc << SPACE << vl << endl << vl << SPACE << vl;
			cout << "\x1b[47m\x1b[30m";
			for (i = 0; i < SIZE_WINDOW - 4; i++) cout << ul;
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			cout << vl << SPACE << vl << endl << vl << SPACE << rbc;
			for (i = 0; i < SIZE_WINDOW - 4; i++) cout << hl;
			cout << lbc << SPACE;

			i = 0;
			while (i < SIZE_FREE_LINE / 2)
			{
				cout << vl << endl << vl;
				for (int j = 0; j < SIZE_WINDOW; j++) cout << SPACE;
				i++;
			}
			cout << vl << endl << rc;
			for (i = 0; i < 14; i++) cout << hl;
			cout << tc;
			for (i = 0; i < SIZE_WINDOW - 15; i++) cout << hl;
			cout << lc << endl;

			cout << vl << " WIDHT  = ";
			if (select == 0) cout << "\x1b[47m\x1b[30m";
			cout << (WIDTH / 100 ? "" : (WIDTH / 10 ? " " : "  ")) << WIDTH;
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			cout << SPACE << vl << " W - up";
			for (i = 0; i < SIZE_WINDOW - 35; i++) cout << SPACE;
			cout << "A - decrease " << vl << endl;

			cout << vl << " HEIGHT = ";
			if (select == 1) cout << "\x1b[47m\x1b[30m";
			cout << (HEIGHT / 100 ? "" : (HEIGHT / 10 ? " " : "  ")) << HEIGHT;
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			cout << SPACE << vl << " S - down";
			for (i = 0; i < SIZE_WINDOW - 37; i++) cout << SPACE;
			cout << "D - increase " << vl << endl;

			cout << vl << " CURSOR = ";
			if (select == 2) cout << "\x1b[47m\x1b[30m";
			cout << "  " << CURSOR;
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			cout << SPACE << vl << " TAB - default";
			for (i = 0; i < SIZE_WINDOW - 45; i++) cout << SPACE;
			cout << "ENTER - credits " << vl << endl;

			cout << rbc;
			for (i = 0; i < 14; i++) cout << hl;
			cout << bc;
			for (i = 0; i < SIZE_WINDOW - 15; i++) cout << hl;
			cout << lbc << endl;
			cout << "\x1b[47m\x1b[30m";
			for (i = 0; i < SIZE_WINDOW + 2; i++) cout << SPACE;
			cout << "\r\x1b[48;2;16;16;192m\x1b[97m";
			Start = 0;
		}
		else
		{
			cout << "\r\x1b[4A\x1b[11C";
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			if (select == 0) cout << "\x1b[47m\x1b[30m";
			cout << (WIDTH / 100 ? "" : (WIDTH / 10 ? " " : "  ")) << WIDTH;
			cout << "\x1b[3D\x1b[1B";
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			if (select == 1) cout << "\x1b[47m\x1b[30m";
			cout << (HEIGHT / 100 ? "" : (HEIGHT / 10 ? " " : "  ")) << HEIGHT;
			cout << "\x1b[3D\x1b[1B";
			cout << "\x1b[48;2;16;16;192m\x1b[97m";
			if (select == 2) cout << "\x1b[47m\x1b[30m";
			cout << "  " << CURSOR;
			cout << "\r\x1b[2B";
		}

		bool isInput = 0;
		while (!isInput)
		{
			cin = _getch();
			if (cin == c_s || cin == c_S)
			{
				select++;
				if (select == 3) select = 0;
				isInput = 1;
			}
			else if (cin == c_w || cin == c_W)
			{
				select--;
				if (select == -1) select = 2;
				isInput = 1;
			}
			else if (cin == TAB)
			{
				if (WIDTH != 0 || HEIGHT != 0 || CURSOR != (char)178)
				{
					WIDTH = 0;
					HEIGHT = 0;
					CURSOR = 178;
					isInput = 1;
					Start = 1;
				}
				else cout << '\a';
			}
			else if (cin == ENTER)
			{
				Credits();
				system("title Setting");
				isInput = 1;
				Start = 1;
			}
			else if (cin == ESC) isInput = 1;
			else
			{
				if (select == 0)
				{
					if (cin == c_a || cin == c_A)
					{
						WIDTH--;
						if (WIDTH == -1) WIDTH = 255;
						isInput = 1;
						Start = 1;
					}
					else if (cin == c_d || cin == c_D)
					{
						WIDTH++;
						if (WIDTH == 256) WIDTH = 0;
						isInput = 1;
						Start = 1;
					}
					else cout << '\a';
				}
				else if (select == 1)
				{
					if (cin == c_a || cin == c_A)
					{
						HEIGHT--;
						if (HEIGHT == -1) HEIGHT = 63;
						isInput = 1;
						Start = 1;
					}
					else if (cin == c_d || cin == c_D)
					{
						HEIGHT++;
						if (HEIGHT == 64) HEIGHT = 0;
						isInput = 1;
						Start = 1;
					}
					else cout << '\a';
				}
				else if (select == 2)
				{
					if (cin == c_a || cin == c_A)
					{
						CURSOR--;
						if (CURSOR == 32) CURSOR = -2;
						isInput = 1;
					}
					else if (cin == c_d || cin == c_D)
					{
						CURSOR++;
						if (CURSOR == -1) CURSOR = 33;
						isInput = 1;
					}
					else cout << '\a';
				}
			}
		}
	}
	Save(WIDTH, HEIGHT, CURSOR);
}