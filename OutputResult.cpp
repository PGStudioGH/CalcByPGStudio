#include <iostream>
#include <iomanip>

using namespace std;

#include "Characters.h"
#include "Calculate.h"
#include "SystemArray.h"

void OutputResult(char *str, int size, int AddBrackets)
{
	int i = 0;
	bool empty = 0;
	if (!size)
	{
		empty = 1;
		size++;
	}

	char *line = new char[size];
	line[0] = n0;

	if (!empty)
	{
		while (i < size)
		{
			line[i] = str[i];
			i++;
		}

		if (line[size - 1] == lb) addArray(line, size, n0);

		if (line[0] == ms)
		{
			addArrayIndex(line, size, 0, n0);
		}

		i = 1;
		while (i < size)
		{
			if (line[i - 1] == lb && line[i] == ms)
			{
				addArrayIndex(line, size, i, n0);
			}
			i++;
		}

		if (line[size - 1] == mp || line[size - 1] == ad ||
			line[size - 1] == ms || line[size - 1] == pt ||
			line[size - 1] == ds || line[size - 1] == pw)
		{
			removeArray(line, size, size - 1);
		}

		while (line[size - 1] == lb)
		{
			removeArray(line, size, size - 1);
			AddBrackets--;
		}
		if (line[size - 1] == mp || line[size - 1] == ad ||
			line[size - 1] == ms || line[size - 1] == pt ||
			line[size - 1] == ds || line[size - 1] == pw)
		{
			removeArray(line, size, size - 1);
		}

		while (AddBrackets)
		{
			addArray(line, size, rb);
			AddBrackets--;
		}
	}

	addArray(line, size, '\0');
	bool isDivisionByZero = 0;
	double result = Calculate(line, size, isDivisionByZero);
	if (isDivisionByZero)
	{
		cout << "Error! Cannot be divided by zero!";
	}
	else
	{
		cout << setprecision(15) << result;
	}

	delete[] line;
}