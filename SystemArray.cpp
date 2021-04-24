void addArray(char *&operations, int &length, char character)
{
	char *temp = new char[length + 1];
	for (int i = 0; i < length; i++) temp[i] = operations[i];
	temp[length++] = character;
	delete[] operations;
	operations = temp;
}

void addArray(double *&numbers, int &length, double value)
{
	double* temp = new double[length + 1];
	for (int i = 0; i < length; i++) temp[i] = numbers[i];
	temp[length++] = value;
	delete[] numbers;
	numbers = temp;
}

void addArrayIndex(char*& str, int& length, int index, char character)
{
	int i = 0;
	char* temp = new char[length + 1];
	while (i < length && i < index)
	{
		temp[i] = str[i];
		i++;
	}
	if (i == index) temp[i++] = character;
	while (i - 1 < length)
	{
		temp[i] = str[i - 1];
		i++;
	}
	length++;
	delete[] str;
	str = temp;
}

void removeArray(char *&operations, int &length, int index)
{
	int i = 0;
	char* temp = new char[length - 1];
	while (i < length && i < index)
	{
		temp[i] = operations[i];
		i++;
	}
	i++;
	while (i < length)
	{
		temp[i - 1] = operations[i];
		i++;
	}
	length--;
	delete[] operations;
	operations = temp;
}

void removeArray(double *& numbers, int &length, int index)
{
	int i = 0;
	double* temp = new double[length - 1];
	while (i < length && i < index)
	{
		temp[i] = numbers[i];
		i++;
	}
	i++;
	while (i < length)
	{
		temp[i - 1] = numbers[i];
		i++;
	}
	length--;
	delete[] numbers;
	numbers = temp;
}