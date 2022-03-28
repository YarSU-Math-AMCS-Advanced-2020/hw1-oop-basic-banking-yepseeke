#include "ATM.h"

ATM::ATM(Address address, string number, int balance, DebitAccount::Currency currency)
{
	this->address = address;
	this->number = number;
	this->balance = balance;
	this->currency = currency;
}

void ATM::increase(double amount)
{
	balance += amount;
}

void ATM::decrease(double amount)
{
	balance -= amount;
}
