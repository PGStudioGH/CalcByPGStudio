#include <iostream>
#include <conio.h>

#include "Window.h"
#include "Setting.h"
#include "Error.h"
#include "Characters.h"
#include "isInput.h"
#include "OutputResult.h"

using namespace std;

int CalcByPGStudio()
{
	cout << "\x1b[?25l";

	int WIDTH = 0, HEIGHT = 0;
	char CURSOR = 0;
	Load(WIDTH, HEIGHT, CURSOR);

	int SIZE_WINDOW = WIDTH + 59;
	int SIZE_FREE_LINE = HEIGHT;
	int SIZE_LINE = SIZE_WINDOW - 4;

	system("title Calculator by PGStudio");
	system("color 07");
	ChangeSizeWindow(SIZE_WINDOW + 2, SIZE_FREE_LINE + 12);

	bool isPoint = 0;
	bool isZero = 0;
	bool Start = 1;
	int i = 0;
	int size = 0;
	int count_left_brackets = 0;
	int count_right_brackets = 0;
	char cin = 0;
	char *str = new char[SIZE_LINE + 1];
	str[SIZE_LINE] = '\0';
	str[i++] = CURSOR;
	while (i < SIZE_LINE) str[i++] = SPACE;

	while (cin != ESC)
	{
		char CanPress[20];
		int AddBrackets = count_left_brackets - count_right_brackets;
		isInput(CanPress, str, size, SIZE_LINE, count_left_brackets, count_right_brackets, isZero, isPoint);

		if (Start)
		{
			string screen = "\x1b[H\x1b[48;2;16;16;192m\x1b[97m";
			screen += rtc;
			for (i = 0; i < 12; i++) screen += hl;
			screen += tc;
			for (i = 0; i < SIZE_WINDOW / 2 - 19; i++) screen += hl;
			screen += " Calculator ";
			for (i = 0; i < SIZE_WINDOW / 2 - 6 + SIZE_WINDOW % 2; i++) screen += hl;
			screen += ltc;
			screen += vl;
			screen += " ESC - exit ";
			screen += vl;
			for (i = 0; i < SIZE_WINDOW - 13; i++) screen += SPACE;
			screen += vl;
			screen += rc;
			for (i = 0; i < 12; i++) screen += hl;
			screen += lbc;
			for (i = 0; i < SIZE_WINDOW - 13; i++) screen += SPACE;

			i = 0;
			while (i++ < SIZE_FREE_LINE / 2 + SIZE_FREE_LINE % 2)
			{
				screen += vl;
				screen += vl;
				for (int j = 0; j < SIZE_WINDOW; j++) screen += SPACE;
			}
			screen += vl;
			screen += vl;
			screen += SPACE;
			screen += rtc;
			for (i = 0; i < SIZE_LINE; i++) screen += hl;
			screen += ltc;
			screen += SPACE;
			screen += vl;
			screen += vl;
			screen += SPACE;
			screen += vl;
			screen += "\x1b[47m\x1b[30m";
			for (i = 0; i < SIZE_LINE; i++) screen += str[i];
			screen += "\x1b[48;2;16;16;192m\x1b[97m";
			screen += vl;
			screen += SPACE;
			screen += vl;
			screen += vl;
			screen += SPACE;
			screen += rbc;
			for (i = 0; i < SIZE_LINE; i++) screen += hl;
			screen += lbc;
			screen += SPACE;

			i = 0;
			while (i++ < SIZE_FREE_LINE / 2)
			{
				screen += vl;
				screen += vl;
				for (int j = 0; j < SIZE_WINDOW; j++) screen += SPACE;
			}
			screen += vl;
			screen += rc;
			for (i = 0; i < SIZE_WINDOW; i++) screen += hl;
			screen += lc;

			i = 0;
			screen += vl;
			screen += " You can write only: ";
			while (CanPress[i] != '\0' && CanPress[i] != SPACE)
			{
				screen += CanPress[i++];
				screen += SPACE;
			}
			for (i = 0; i < SIZE_WINDOW - 49; i++) screen += SPACE;
			screen += vl;
			screen += rc;
			for (i = 0; i < SIZE_WINDOW; i++) screen += hl;
			screen += lc;
			screen += vl;
			screen += " TAB - clear all";
			for (i = 0; i < SIZE_WINDOW - 32; i++) screen += SPACE;
			screen += "ENTER - setting ";
			screen += vl;
			screen += rbc;
			for (i = 0; i < SIZE_WINDOW; i++) screen += hl;
			screen += lbc;
			screen += "\x1b[47m\x1b[30m";
			for (i = 0; i < SIZE_WINDOW + 2; i++) screen += SPACE;
			screen += "\rResult: ";
			cout << screen;
			Start = 0;
		}
		else
		{
			cout << "\r";
			for (i = 0; i < SIZE_WINDOW + 2; i++) cout << SPACE;
			cout << "\r\x1b[" << (7 + SIZE_FREE_LINE / 2) << "A";
			cout << "\x1b[3C" << str;
			cout << "\r\x1b[" << (3 + SIZE_FREE_LINE / 2) << "B";
			cout << "\x1b[2C\x1b[48;2;16;16;192m\x1b[97mYou can write only:";
			i = 0;
			while (CanPress[i] != '\0') cout << ' ' << CanPress[i++];
			cout << "\r\x1b[4B\r\x1b[47m\x1b[30mResult: ";
		}

		OutputResult(str, size, AddBrackets);

		cin = 0;
		bool isInput = 0;
		bool isVisibleCursor = 1;
		clock_t msec = clock() + 100;
		while (!isInput)
		{
			while (!cin)
			{
				if (clock() > msec)
				{
					if (size != SIZE_LINE - AddBrackets)
					{
						isVisibleCursor = !isVisibleCursor;
						if (isVisibleCursor) str[size] = CURSOR;
						else str[size] = SPACE;
						msec = clock() + 100;

						cout << "\r\x1b[" << (7 + SIZE_FREE_LINE / 2) << "A";
						cout << "\x1b[" << size + 3 << 'C' << str[size];
						cout << "\r\x1b[" << (7 + SIZE_FREE_LINE / 2) << "B";
					}
				}

				if (_kbhit()) cin = _getch();
				else if (CheckFullScreen()) Error("Don't press F11! You make bug in CMD", 1);
			}

			i = 0;
			if (cin == SPACE) cin = '\0';
			while (CanPress[i] != '\0' && CanPress[i] != cin) i++;
			
			if (cin == CanPress[i] && cin != '\0') isInput = 1;
			else if (cin == ESC) isInput = 1;
			else if (cin == ENTER) isInput = 1;
			else if (size)
			{
				if (cin == BACKSPACE || cin == TAB) isInput = 1;
				else
				{
					cin = 0;
					cout << '\a';
				}
			}
			else
			{
				cin = 0;
				cout << '\a';
			}
		}
		if (cin != ESC)
		{
			switch (cin)
			{
				case BACKSPACE:
				{
					if (size > 0)
					{
						if (str[size - 1] == n0)
						{
							if (size == 1)
							{
								isZero = 0;
							}
							else if (str[size - 2] == mp || str[size - 2] == ad || str[size - 2] == ms ||
								str[size - 2] == ds || str[size - 2] == pw || str[size - 2] == lb)
							{
								isZero = 0;
							}
						}

						else if (str[size - 1] == pt)
						{
							isPoint = 0;
						}

						else if (str[size - 1] == lb)
						{
							str[SIZE_LINE - AddBrackets] = SPACE;
							count_left_brackets--;
						}

						else if (str[size - 1] == rb)
						{
							int i = size - 2;
							while (i != 0 && !(mp <= str[i] && str[i] <= ds)) i--;

							if (str[i] == pt) isPoint = 1;

							if (str[size - 2] == n0)
							{
								if (str[size - 3] == mp || str[size - 3] == ad || str[size - 3] == ms ||
									str[size - 3] == ds || str[size - 3] == pw || str[size - 3] == lb)
								{
									isZero = 1;
								}
							}

							count_right_brackets--;
							str[SIZE_LINE - AddBrackets - 1] = rb;
						}

						else if (str[size - 1] == mp || str[size - 1] == ad ||
							str[size - 1] == ms || str[size - 1] == ds || str[size - 1] == pw)
						{
							int i = size - 2;
							while (i != 0 && !(mp <= str[i] && str[i] <= ds)) i--;

							if (str[i] == pt) isPoint = 1;

							if (str[size - 2] == n0)
							{
								if (size == 2)
								{
									isZero = 1;
								}
								else if (str[size - 3] == mp || str[size - 3] == ad || str[size - 3] == ms ||
									str[size - 3] == ds || str[size - 3] == pw || str[size - 3] == lb)
								{
									isZero = 1;
								}
							}
						}

						str[--size] = CURSOR;
						if (size + 1 != SIZE_LINE - AddBrackets) str[size + 1] = SPACE;
					}
					break;
				}

				case ENTER:
				{
					Setting(WIDTH, HEIGHT, CURSOR);
					SIZE_WINDOW = WIDTH + 59;
					SIZE_FREE_LINE = HEIGHT;
					SIZE_LINE = SIZE_WINDOW - 4;
					system("title Calculator by PGStudio");
					ChangeSizeWindow(SIZE_WINDOW + 2, SIZE_FREE_LINE + 12);

					Start = 1;
					size = 0;
					i = 0;
					char* new_str = new char[SIZE_LINE + 1];
					new_str[SIZE_LINE] = '\0';
					new_str[i++] = CURSOR;
					while (i < SIZE_LINE) new_str[i++] = SPACE;
					delete[] str;
					str = new_str;
				}

				case TAB:
				{
					count_left_brackets = 0;
					count_right_brackets = 0;
					isPoint = 0;
					isZero = 0;

					for (size = 1; size < SIZE_LINE; size++) str[size] = SPACE;
					str[size = 0] = CURSOR;

					break;
				}

				default:
				{
					if (cin == lb)
					{
						while (isPoint && str[size] != pt)
						{
							if (str[size - 1] == n0)
							{
								str[size--] = SPACE;
							}
							else
							{
								str[size] = SPACE;
								isPoint = 0;
							}
						}

						if (size != 0 && n0 <= str[size - 1] && str[size - 1] <= n9)
						{
							str[size++] = mp;
							str[size++] = cin;
							count_left_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							str[SIZE_LINE - AddBrackets] = rb;
							isPoint = 0;
							isZero = 0;
						}
						else if (size != 0 && str[size - 1] == rb)
						{
							str[size++] = mp;
							str[size++] = cin;
							count_left_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							str[SIZE_LINE - AddBrackets] = rb;
							isPoint = 0;
						}
						else if (size != 0 && str[size - 1] == pt)
						{
							str[size - 1] = mp;
							str[size++] = cin;
							count_left_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							str[SIZE_LINE - AddBrackets] = rb;
							isPoint = 0;
							isZero = 0;
						}
						else
						{
							str[size++] = cin;
							count_left_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							str[SIZE_LINE - AddBrackets] = rb;
							isPoint = 0;
						}
					}

					else if (cin == rb)
					{
						while (isPoint && str[size] != pt)
						{
							if (str[size - 1] == n0)
							{
								str[size--] = SPACE;
							}
							else
							{
								str[size] = SPACE;
								isPoint = 0;
							}
						}

						if (str[size - 1] == lb)
						{
							str[size--] = SPACE;
							str[SIZE_LINE - AddBrackets] = SPACE;
							count_left_brackets--;
							AddBrackets = count_left_brackets - count_right_brackets;
						}
						else if (str[size - 2] == lb && (str[size - 1] == ad || str[size - 1] == ms))
						{
							str[size--] = SPACE;
							str[size--] = SPACE;
							str[SIZE_LINE - AddBrackets] = SPACE;
							count_left_brackets--;
							AddBrackets = count_left_brackets - count_right_brackets;
						}
						else if (str[size - 1] == mp || str[size - 1] == ad ||
							str[size - 1] == ms || str[size - 1] == pt ||
							str[size - 1] == ds || str[size - 1] == pw)
						{
							str[SIZE_LINE - AddBrackets] = SPACE;
							str[size - 1] = cin;
							count_right_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							isPoint = 0;
							isZero = 0;
						}
						else
						{
							str[SIZE_LINE - AddBrackets] = SPACE;
							str[size++] = cin;
							count_right_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							isPoint = 0;
							isZero = 0;
						}
					}

					else if (cin == cm || cin == pt)
					{
						if (cin == cm) cin = pt;

						if (size == 0)
						{
							str[size++] = n0;
							str[size++] = cin;
							isPoint = 1;
							isZero = 1;
						}
						else if (str[size - 1] == mp || str[size - 1] == ad || str[size - 1] == ms || 
							str[size - 1] == ds || str[size - 1] == pw || str[size - 1] == lb)
						{
							str[size++] = n0;
							str[size++] = cin;
							isPoint = 1;
							isZero = 1;
						}
						else if (str[size - 1] == rb)
						{
							str[size++] = mp;
							str[size++] = n0;
							str[size++] = cin;
							isPoint = 1;
							isZero = 1;
						}
						else
						{
							str[size++] = cin;
							isPoint = 1;
						}
					}

					else if (cin == ad || cin == ms)
					{
						while (isPoint && str[size] != pt)
						{
							if (str[size - 1] == n0)
							{
								str[size--] = SPACE;
							}
							else
							{
								str[size] = SPACE;
								isPoint = 0;
							}
						}

						if (str[size - 1] == pt)
						{
							str[size - 1] = cin;
							isZero = 0;
						}
						else
						{
							str[size++] = cin;
							isZero = 0;
						}
					}

					else if (cin == mp || cin == ds || cin == pw)
					{
						while (isPoint && str[size] != pt)
						{
							if (str[size - 1] == n0)
							{
								str[size--] = SPACE;
							}
							else
							{
								str[size] = SPACE;
								isPoint = 0;
							}
						}

						if (str[size - 1] == pt)
						{
							str[size - 1] = cin;
							isZero = 0;
						}
						else
						{
							str[size++] = cin;
							isZero = 0;
						}
					}

					else if (n0 <= cin && cin <= n9)
					{
						if (size != 0 && str[size - 1] == rb)
						{
							if (size + 1 < SIZE_LINE - AddBrackets)
							{
								str[size++] = mp;
								str[size++] = cin;
							}
						}
						else if (isZero && !isPoint)
						{
							str[size++] = pt;
							str[size++] = cin;
							isPoint = 1;
						}
						else if (size < SIZE_LINE - AddBrackets)
						{
							if (!isZero || isPoint)
							{
								str[size++] = cin;
							}
						}

						if (!isPoint && !isZero)
						{
							if (cin == n0)
							{
								if (size == 1)
								{
									isZero = 1;
								}
								else if (str[size - 2] == mp || str[size - 2] == ad || str[size - 2] == ms ||
									str[size - 2] == ds || str[size - 2] == pw || str[size - 2] == lb)
								{
									isZero = 1;
								}
							}
						}
					}

					if (size < SIZE_LINE - AddBrackets) str[size] = CURSOR;
				}
			}
		}
	}
	delete[] str;

	cout << "\a\x1b[40m\x1b[37m\x1b[2J\x1b[H";
	cout << "Thank you for using :-)" << endl;
	return 0;
}