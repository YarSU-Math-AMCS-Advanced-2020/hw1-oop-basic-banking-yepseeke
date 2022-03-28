#pragma once
#pragma once
#include "ATM.h"
#include "Address.h"
#include "Date.h"
#include "Card.h"

class CashTransation
{
public:

	enum class Type { Withdrawal, Replenishing };

	enum class Status { Done, Denied };

	CashTransation(Type type, DebitAccount* debit_account, double amount, Date date, ATM atm);
	CashTransation(Type type, Card* card, double amount, Date date, ATM atm);

	void start();

	Date get_date() const { return date; }
	Status get_status() const { return status; }

private:
	Type type;
	DebitAccount* debit_account;
	double amount;
	Date date;
	Status status;
	ATM atm;
};

