#include <cmath>

#include "Characters.h"
#include "SystemArray.h"

double Calculate(const char str[], int length, bool &isDivisionByZero)
{
	int lengthOP = 1;
	int lengthN = 1;
	char *operations = new char[lengthOP];
	double *numbers = new double[lengthN];
	operations[0] = '\0';
	numbers[0] = 0;
	
	int i = 0;
	while (i < length)
	{
		if (n0 <= str[i] && str[i] <= n9) 
		{
			int lengthValue = 1;
			char *value = new char[lengthValue];
			value[0] = str[i++];

			while (i < length && str[i] != ad && 
				str[i] != ms && str[i] != mp && 
				str[i] != ds && str[i] != pw)
			{
				addArray(value, lengthValue, str[i]);
				i++;
			}

			addArray(value, lengthValue, '\0');
			addArray(numbers, lengthN, atof(value));

			delete[] value;
		}

		else if (str[i] == lb) 
		{
			i++;
			int lengthEx = 0;
			int count_left_brackets = 1;
			int count_right_brackets = 0;
			char *Expression = new char[lengthEx];

			while (count_left_brackets > count_right_brackets)
			{
				addArray(Expression, lengthEx, str[i]);

				if (str[i] == lb) count_left_brackets++;
				else if (str[i + 1] == rb) count_right_brackets++;

				i++;
			}

			double value = Calculate(Expression, lengthEx, isDivisionByZero);
			addArray(numbers, lengthN, value);

			delete[] Expression;
			i++;
		}

		else 
		{
			addArray(operations, lengthOP, str[i]);
			i++;
		}
	}

	removeArray(operations, lengthOP, 0);
	removeArray(numbers, lengthN, 0);

	i = 0;
	while (i < lengthOP && (numbers[i + 1] != 0 || operations[i] != ds)) i++;
	if (i < lengthOP)
	{
		if (numbers[i + 1] == 0 && operations[i] == ds) isDivisionByZero = 1;
	}

	if (!isDivisionByZero)
	{
		i = 0;
		while (i < lengthOP) 
		{
			if (operations[i] == pw)
			{
				numbers[i + 1] = pow(numbers[i], numbers[i + 1]);
				removeArray(numbers, lengthN, i);
				removeArray(operations, lengthOP, i);
				i--;
			}
			i++;
		}

		i = 0;
		while (i < lengthOP) 
		{
			if (operations[i] == mp)
			{
				numbers[i + 1] = numbers[i] * numbers[i + 1];
				removeArray(numbers, lengthN, i);
				removeArray(operations, lengthOP, i);
				i--;
			}
			else if (operations[i] == ds)
			{
				numbers[i + 1] = numbers[i] / numbers[i + 1];
				removeArray(numbers, lengthN, i);
				removeArray(operations, lengthOP, i);
				i--;
			}
			i++;
		}

		i = 0;
		while (i < lengthOP) 
		{
			if (operations[i] == ad)
			{
				numbers[i + 1] = numbers[i] + numbers[i + 1];
				removeArray(numbers, lengthN, i);
				removeArray(operations, lengthOP, i);
				i--;
			}
			else if (operations[i] == ms)
			{
				numbers[i + 1] = numbers[i] - numbers[i + 1];
				removeArray(numbers, lengthN, i);
				removeArray(operations, lengthOP, i);
				i--;
			}
			i++;
		}
	}

	double result = numbers[0];

	delete[] operations;
	delete[] numbers;
 
	return result;
}