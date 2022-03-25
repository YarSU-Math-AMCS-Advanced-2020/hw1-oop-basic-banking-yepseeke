#pragma once
class Date
{
public:
	Date(int month = 1, int day = 1, int year = 1970) { this->month = month; this->day = day; this->year = year; }
private:
	int month, day, year;
};
