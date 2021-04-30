#include "Characters.h"

void isInput(char CanPress[], char *str, int size, int SIZE_LINE, int count_left_brackets, int count_right_brackets, bool isZero, bool isPoint)
{
	int count_can = 0;
	CanPress[19] = '\0';

	int AddBrackets = count_left_brackets - count_right_brackets;

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
		CanPress[count_can++] = rb;
	}

	while (CanPress[count_can] != '\0') CanPress[count_can++] = SPACE;
}