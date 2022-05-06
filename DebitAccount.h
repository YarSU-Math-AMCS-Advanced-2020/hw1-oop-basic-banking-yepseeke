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

	DebitAccount(const DebitAccount &debit_account)
	{
		this->balance = debit_account.balance;
		this->limit = debit_account.limit;
		this->currency = debit_account.currency;
		this->card_status = debit_account.card_status;
	}

	double get_balance() const { return balance; }
	double get_limit() const { return limit; }
	Currency get_currency() const { return currency; }
	string get_currency_string() const;
	bool get_card_status() const { return card_status; }

	void increase(double amount) { balance += amount; };
	void decrease(double amount) { balance -= amount; };


	void set_balance(double balance) { this->balance = balance; }
	void set_limit(double limit) { this->limit = limit; }
	void set_currency(Currency currency) { this->currency = currency; }
	void set_card_status(bool card_status) { this->card_status = card_status; }

private:
	double balance = 0;
	double limit = 10000;
	Currency currency = Currency::RUB;
	bool card_status = false;
};

