#pragma once
#include "Client.h"
#include "Date.h"

class Individual: public ClientBase
{
	enum class Sex { MALE, FEMALE };

private:
	string surname;
	string name;
	string patronymic;
	Sex sex;
	Date birth_date;
};

