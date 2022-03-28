#pragma once
#include <string>

class Date
{
public:
	Date(int month = 1, int day = 1, int year = 1970) { this->month = month; this->day = day; this->year = year; }

	string get_date_string()
	{
		return to_string(month) + '.' + to_string(day) + '.' + to_string(year);
	}

private:
	int month, day, year;
};
