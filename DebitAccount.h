#pragma once
#include <iostream>

using namespace std;

class DebitAccount
{
public:

	enum class Currency { USD, EURO, RUB };

	DebitAccount(Currency currency = Currency::RUB)
	{
		this->currency = currency;
	}

	double get_balance() const { return balance; }
	Currency get_currency() const { return currency; }
	string get_currency_string() const;

	void increase(double amount) { balance += amount; };
	void decrease(double amount) { balance -= amount; };

	void set_balance(double balance) { this->balance = balance; }
	void set_currency(Currency currency) { this->currency = currency; }

private:
	double balance = 0;
	Currency currency = Currency::RUB;
};

