#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <ctime>

void Error(const char* text, int type)
{
	time_t ct = time(0);
	struct tm t = *localtime(&ct);
	t.tm_mon++;
	std::ofstream create("error.log");
	create	<< "Date: " << t.tm_hour << ':' 
			<< t.tm_min / 10 << t.tm_min % 10 << ':' 
			<< t.tm_sec /10 << t.tm_sec % 10 << " | "
			<< t.tm_mday / 10 << t.tm_mday % 10 << '.'
			<< t.tm_mon / 10 << t.tm_mon % 10 << '.'
			<< t.tm_year + 1900 << "\n" << text << "\n"
			<< "Error: " << type;
	exit(type);
}