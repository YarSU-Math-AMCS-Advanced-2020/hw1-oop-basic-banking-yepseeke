#pragma once
#include "Client.h"
#include "Date.h"

using namespace std;

class Individual : public ClientBase
{
public:
	enum class Sex { MALE, FEMALE, UNKNOWN };

	Individual() {};
	Individual(string surname, string name, string patronymic, Sex sex, Date birth_date, Address address, string phone_number);

	void create_new_individual();

	string get_surname() const { return surname; }
	string get_name() const { return name; }
	string get_patronymic() const { return patronymic; }
	Sex get_set() const { return sex; }
	Date get_birth_date() const { return birth_date; }

	void set_surname(string surname) { this->surname = surname; }
	void set_name(string name) { this->name = name; }
	bool set_patronymic(string patronymic) { this->patronymic = patronymic; }
	void set_sex(Sex sex) { this->sex = sex; }
	void set_birth_date(Date birth_date) { this->birth_date = birth_date; }

private:
	string surname;
	string name;
	string patronymic;
	Sex sex = Sex::UNKNOWN;
	Date birth_date;
};

