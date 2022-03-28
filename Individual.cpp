#include "Individual.h"

Individual::Individual(string surname, string name, string patronymic, Sex sex, Date birth_date, Address address, string phone_number)
{
	this->surname = surname;
	this->name = name;
	this->patronymic;
	this->sex = sex;
	this->birth_date = birth_date;
	this->address = address;
	this->phone_number = phone_number;
}

void Individual::create_new_individual()
{
	cout << "Enter information about yourself\n\n";
	cout << "1.Full name:\n";
	cout << "Name\n";
	string name; cin >> name;
	cout << "Surname\n";
	string surname; cin >> surname;
	cout << "Patronymic\n";
	string patronymic; cin >> patronymic;

	cout << "2. Sex\n";
	string s; Individual::Sex sex;
	cout << "Input 'Male', 'Female' or press Enter\n";
	cin >> s;
	if (s == "Male")
		sex = Individual::Sex::MALE;
	else if (s == "Female")
		sex = Individual::Sex::FEMALE;
	else sex = Individual::Sex::UNKNOWN;

	cout << "\n3.Birth date\n";
	cout << "Mounth\n";
	int mounth; cin >> mounth;
	cout << "Day\n";
	int day; cin >> day;
	cout << "Year\n";
	int year; cin >> year;

	cout << "\n4.Address\n";
	cout << "Country\n";
	string country; cin >> country;
	cout << "Region\n";
	string region; cin >> region;
	cout << "City\n";
	string city; cin >> city;
	cout << "Street\n";
	string street; cin >> street;
	cout << "Building\n";
	string building; cin >> building;
	cout << "Apartment\n";
	string apartment; cin >> apartment;

	cout << "5.Phone number\n+7";
	string phone_number; cin >> s;
	s = "+7" + s;

	Individual t(surname, name, patronymic, sex, Date(mounth, day, year), Address(country, region, city, street, building, apartment), phone_number);
	*(this) = t;
}
