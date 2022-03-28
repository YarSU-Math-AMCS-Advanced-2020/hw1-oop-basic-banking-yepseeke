#pragma once
#include <string>

using namespace std;

class Address
{
public:
	Address() {};
	Address(string country, string region, string city, string street, string building, string apartment)
	{
		this->country = country;
		this->region = region;
		this->city = city;
		this->street = street;
		this->building = building;
		this->apartment = apartment;
	}
private:
	string country = "Russia", region = "Moscow", city = "Moscow", street = "Bryanskiy pereulok", building = "1", apartment = "1";
};
