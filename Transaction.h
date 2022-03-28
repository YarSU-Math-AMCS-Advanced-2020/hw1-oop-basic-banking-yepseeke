#pragma once
#include "Card.h"
#include "Date.h"

class Transaction
{
public:

	enum class Status { OK, DIFFERENT_CURRENCY, OUT_OF_LIMITS, NOT_ENOUGH_MONEY, UNKNOWN };

	Transaction(DebitAccount* from, DebitAccount* to, double amount);
	Transaction(Card* from, Card* to, double amount);

	void start();

	Date get_date() const { return date; }
	Status get_status() const { return status; }

private:
	DebitAccount* from;
	DebitAccount* to;
	Date date;
	double amount;
	Status status = Status::UNKNOWN;
};