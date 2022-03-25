#pragma once
#include "Card.h"

enum class Currency { USD, EURO, RUB };

class DebitAccount
{
public:
	DebitAccount(Currency currency = Currency::RUB)
	{
		this->currency = currency;
	}

	double get_balance() { return balance; }
	Currency get_currency() { return currency; }

	void increase(double amount) { balance += amount; };
	void decrease(double amount) { balance -= amount; };

	void set_balance(double balance) { this->balance = balance; }
	void set_currency(Currency currency) { this->currency = currency; }

private:
	double balance = 0;
	Currency currency;
};

