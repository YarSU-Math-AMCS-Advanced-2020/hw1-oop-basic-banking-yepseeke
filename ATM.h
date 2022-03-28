#pragma once
#include "DebitAccount.h"
#include "Address.h"

class ATM
{
public:

	ATM() { this->balance = 10000; this->currency = DebitAccount::Currency::RUB; };
	ATM(Address address, string number, int balance, DebitAccount::Currency currency);

	Address get_address() { return address; }
	string get_number() { return number; }
	double get_balance() { return balance; }
	DebitAccount::Currency get_currency() { return currency; }

	void increase(double amount);
	void decrease(double amount);

private:
	Address address;
	string number;
	double balance = 10000;
	DebitAccount::Currency currency = DebitAccount::Currency::RUB;
};

