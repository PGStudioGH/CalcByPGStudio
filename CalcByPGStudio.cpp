#include <iostream>
#include <conio.h>
#include <iomanip>

#include "Setting.h"
#include "Characters.h"
#include "SystemArray.h"
#include "Calculate.h"

using namespace std;

int CalcByPGStudio()
{
	int WIDTH = 0, HEIGHT = 0;
	char CURSOR = 0;
	Load(WIDTH, HEIGHT, CURSOR);

	int SIZE_WINDOW = WIDTH + 59;
	int SIZE_FREE_LINE = HEIGHT;
	int SIZE_LINE = SIZE_WINDOW - 4;

	system("title Calculator by PGStudio");
	ChangeSizeWindow(SIZE_WINDOW + 2, SIZE_FREE_LINE + 12);
	ios::sync_with_stdio(false);

	bool isPoint = 0;
	bool isZero = 0;
	bool Start = 1;
	int i = 0;
	int size = 0;
	int count_left_brackets = 0;
	int count_right_brackets = 0;
	char cin = 0;
	char *str = new char[SIZE_LINE];
	str[i++] = CURSOR;
	int temp = SIZE_LINE;
	addArray(str, temp, '\0');
	while (i < SIZE_LINE) str[i++] = ul;

	while (cin != ESC)
	{
		int AddBrackets = count_left_brackets - count_right_brackets;
		int count_can = 0;
		char CanPress[] = "                   \0";

		if (size != 0 && str[size - 1] == rb)
		{
			if (size + 1 < SIZE_LINE - AddBrackets)
			{
				if (!isZero || isPoint)
				{
					int j = 0;
					while (j < 10) CanPress[count_can++] = n0 + j++;
				}
			}
		}
		else if (size < SIZE_LINE - AddBrackets)
		{
			if (isZero && !isPoint)
			{
				if (size + 1 < SIZE_LINE - AddBrackets)
				{
					int j = 0;
					while (j < 10) CanPress[count_can++] = n0 + j++;
				}
			}
			else
			{
				int j = 0;
				while (j < 10) CanPress[count_can++] = n0 + j++;
			}
		}

		if (size != 0 && size + 1 < SIZE_LINE - AddBrackets)
		{
			if (str[size - 1] == pt)
			{
				CanPress[count_can++] = ad;
				CanPress[count_can++] = ms;
			}
			else if (str[size - 1] == lb)
			{
				if (size < SIZE_LINE - AddBrackets)
				{
					CanPress[count_can++] = ms;
				}
			}
			else if (!(str[size - 1] == ad || str[size - 1] == ms ||
				str[size - 1] == mp || str[size - 1] == ds || str[size - 1] == pw))
			{
				if (size < SIZE_LINE - AddBrackets)
				{
					CanPress[count_can++] = ad;
					CanPress[count_can++] = ms;
				}
			}
		}
		else if (size == SIZE_LINE - 1)
		{
			if (str[size - 1] == pt)
			{
				CanPress[count_can++] = ad;
				CanPress[count_can++] = ms;
			}
		}
		else if (size + 1 < SIZE_LINE - AddBrackets)
		{
			CanPress[count_can++] = ms;
		}

		if (size != 0)
		{
			if (size + 1 < SIZE_LINE - AddBrackets)
			{
				if (str[size - 1] == pt)
				{
					CanPress[count_can++] = mp;
					CanPress[count_can++] = ds;
					CanPress[count_can++] = pw;
				}
				else if (str[size - 1] != lb)
				{
					if (!(str[size - 1] == mp || str[size - 1] == ad ||
						str[size - 1] == ms || str[size - 1] == ds ||
						str[size - 1] == pw))
					{
						CanPress[count_can++] = mp;
						CanPress[count_can++] = ds;
						CanPress[count_can++] = pw;
					}
				}
			}
			else if (size == SIZE_LINE - 1)
			{
				if (str[size - 1] == pt)
				{
					CanPress[count_can++] = mp;
					CanPress[count_can++] = ds;
					CanPress[count_can++] = pw;
				}
			}
		}

		if (!isPoint)
		{
			if (size == 0)
			{
				CanPress[count_can++] = pt;
				CanPress[count_can++] = cm;
			}
			else if (str[size - 1] == mp || str[size - 1] == ad || str[size - 1] == ms ||
				 str[size - 1] == ds || str[size - 1] == pw || str[size - 1] == lb)
			{
				if (size + 2 < SIZE_LINE - AddBrackets)
				{
					CanPress[count_can++] = pt;
					CanPress[count_can++] = cm;
				}
			}
			else if (str[size - 1] == rb)
			{
				if (size + 3 < SIZE_LINE - AddBrackets)
				{
					CanPress[count_can++] = pt;
					CanPress[count_can++] = cm;
				}
			}
			else if (size + 1 < SIZE_LINE - AddBrackets)
			{
				CanPress[count_can++] = pt;
				CanPress[count_can++] = cm;
			}
		}

		if (size != 0 && n0 <= str[size - 1] && str[size - 1] <= n9)
		{
			if (size + 3 < SIZE_LINE - AddBrackets)
			{
				CanPress[count_can++] = lb;
			}
		}
		else if (size != 0 && str[size - 1] == rb)
		{
			if (size + 3 < SIZE_LINE - AddBrackets)
			{
				CanPress[count_can++] = lb;
			}
		}
		else if (size + 2 < SIZE_LINE - AddBrackets)
		{
			CanPress[count_can++] = lb;
		}

		if (size + 1 < SIZE_LINE - AddBrackets && count_left_brackets > count_right_brackets)
		{
			CanPress[count_can] = rb;
		}

		if (Start)
		{
			cout << "\x1b[48;2;16;16;192m\x1b[97m" << rtc;
			for (i = 0; i < 12; i++) cout << hl;
			cout << tc;
			for (i = 0; i < SIZE_WINDOW / 2 - 19; i++) cout << hl;
			cout << " Calculator ";
			for (i = 0; i < SIZE_WINDOW / 2 - 6 + SIZE_WINDOW % 2; i++) cout << hl;
			cout << ltc << endl;

			cout << vl << " ESC - exit " << vl;
			for (i = 0; i < SIZE_WINDOW - 13; i++) cout << SPACE;
			cout << vl << endl;
			cout << rc;
			for (i = 0; i < 12; i++) cout << hl;
			cout << lbc;
			for (i = 0; i < SIZE_WINDOW - 13; i++) cout << SPACE;

			i = 0;
			while (i++ < SIZE_FREE_LINE / 2 + SIZE_FREE_LINE % 2)
			{
				cout << vl << endl << vl;
				for (int j = 0; j < SIZE_WINDOW; j++) cout << SPACE;
			}
			cout << vl << endl << vl << SPACE;

			cout << rtc;
			for (i = 0; i < SIZE_LINE; i++) cout << hl;
			cout << ltc << SPACE;
			cout << vl << endl << vl << SPACE << vl;
			cout << "\x1b[47m\x1b[30m" << str << "\x1b[48;2;16;16;192m\x1b[97m";
			cout << vl << SPACE << vl << endl << vl << SPACE << rbc;
			for (i = 0; i < SIZE_LINE; i++) cout << hl;
			cout << lbc << SPACE;

			i = 0;
			while (i++ < SIZE_FREE_LINE / 2)
			{
				cout << vl << endl << vl;
				for (int j = 0; j < SIZE_WINDOW; j++) cout << SPACE;
			}
			cout << vl << endl << rc;
			for (i = 0; i < SIZE_WINDOW; i++) cout << hl;
			cout << lc << endl;

			i = 0;
			cout << vl << " You can write only:";
			while (CanPress[i] != '\0') cout << ' ' << CanPress[i++];
			for (i = 0; i < SIZE_WINDOW - 58; i++) cout << SPACE;
			cout << vl << endl << rc;
			for (i = 0; i < SIZE_WINDOW; i++) cout << hl;
			cout << lc << endl << vl << " TAB - clear all";
			for (i = 0; i < SIZE_WINDOW - 32; i++) cout << SPACE;
			cout << "ENTER - setting " << vl << endl << rbc;
			for (i = 0; i < SIZE_WINDOW; i++) cout << hl;
			cout << lbc << endl;
			cout << "\x1b[47m\x1b[30m";
			for (i = 0; i < SIZE_WINDOW + 2; i++) cout << SPACE;
			cout << "\rResult: ";
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


		i = 0;
		int new_size = size;
		int count_brackets = AddBrackets;
		if (!new_size) new_size++;
		char* line = new char[new_size];
		line[0] = n0;
		while (i < size)
		{
			line[i] = str[i];
			i++;
		}

		if (line[new_size - 1] == lb) addArray(line, new_size, n0);

		if (line[0] == ms)
		{
			addArrayIndex(line, new_size, 0, n0);
		}

		i = 1;
		while (i < new_size)
		{
			if (line[i - 1] == lb && line[i] == ms)
			{
				addArrayIndex(line, new_size, i, n0);
			}
			i++;
		}

		if (line[new_size - 1] == mp || line[new_size - 1] == ad ||
			line[new_size - 1] == ms || line[new_size - 1] == pt ||
			line[new_size - 1] == ds || line[new_size - 1] == pw)
		{
			removeArray(line, new_size, new_size - 1);
		}

		while (line[new_size - 1] == lb)
		{
			removeArray(line, new_size, new_size - 1);
			count_brackets--;
		}
		if (line[new_size - 1] == mp || line[new_size - 1] == ad ||
			line[new_size - 1] == ms || line[new_size - 1] == pt ||
			line[new_size - 1] == ds || line[new_size - 1] == pw)
		{
			removeArray(line, new_size, new_size - 1);
		}

		while (count_brackets)
		{
			addArray(line, new_size, rb);
			count_brackets--;
		}

		addArray(line, new_size, '\0');
		bool isDivisionByZero = 0;
		double result = Calculate(line, new_size, isDivisionByZero);
		if (isDivisionByZero)
		{
			cout << "Error! Cannot be divided by zero!";
		}
		else
		{
			cout << setprecision(15) << result;
		}
		delete[] line;

		bool isInput = 0;
		while (!isInput)
		{
			cin = _getch();

			i = 0;
			if (cin == SPACE) cin = '\0';
			while (CanPress[i] != '\0' && CanPress[i] != cin) i++;
			
			if (cin == CanPress[i] && cin != '\0') isInput = 1;
			else if (cin == ESC) isInput = 1;
			else if (cin == ENTER) isInput = 1;
			else if (size)
			{
				if (cin == BACKSPACE || cin == TAB) isInput = 1;
				else cout << '\a';
			}
			else cout << '\a';
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
							str[SIZE_LINE - AddBrackets] = ul;
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
						if (size + 1 != SIZE_LINE - AddBrackets) str[size + 1] = ul;
					}
					break;
				}

				case ENTER:
				{
					Setting(WIDTH, HEIGHT, CURSOR);
					SIZE_WINDOW = WIDTH + 59;
					SIZE_FREE_LINE = HEIGHT;
					SIZE_LINE = SIZE_WINDOW - 4;
					ChangeSizeWindow(SIZE_WINDOW + 2, SIZE_FREE_LINE + 12);

					Start = 1;
					size = 0;
					i = 0;
					char* new_str = new char[SIZE_LINE];
					new_str[i++] = CURSOR;
					int temp = SIZE_LINE;
					addArray(new_str, temp, '\0');
					while (i < SIZE_LINE) new_str[i++] = ul;
					delete[] str;
					str = new_str;
				}

				case TAB:
				{
					count_left_brackets = 0;
					count_right_brackets = 0;
					isPoint = 0;
					isZero = 0;

					for (size = 1; size < SIZE_LINE; size++) str[size] = ul;
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
								str[size--] = ul;
							}
							else
							{
								str[size] = ul;
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
								str[size--] = ul;
							}
							else
							{
								str[size] = ul;
								isPoint = 0;
							}
						}

						if (str[size - 1] == lb)
						{
							str[size--] = ul;
							str[SIZE_LINE - AddBrackets] = ul;
							count_left_brackets--;
							AddBrackets = count_left_brackets - count_right_brackets;
						}
						else if (str[size - 2] == lb && (str[size - 1] == ad || str[size - 1] == ms))
						{
							str[size--] = ul;
							str[size--] = ul;
							str[SIZE_LINE - AddBrackets] = ul;
							count_left_brackets--;
							AddBrackets = count_left_brackets - count_right_brackets;
						}
						else if (str[size - 1] == mp || str[size - 1] == ad ||
							str[size - 1] == ms || str[size - 1] == pt ||
							str[size - 1] == ds || str[size - 1] == pw)
						{
							str[SIZE_LINE - AddBrackets] = ul;
							str[size - 1] = cin;
							count_right_brackets++;
							AddBrackets = count_left_brackets - count_right_brackets;
							isPoint = 0;
							isZero = 0;
						}
						else
						{
							str[SIZE_LINE - AddBrackets] = ul;
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
								str[size--] = ul;
							}
							else
							{
								str[size] = ul;
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
								str[size--] = ul;
							}
							else
							{
								str[size] = ul;
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