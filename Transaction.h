#pragma once
#include "DebitAccount.h"

enum class Status { OK, DIFFERENT_CURRENCY, OUT_OF_LIMITS, NOT_ENOUGH_MONEY};

class Transaction
{
public:
	Transaction(DebitAccount* from, DebitAccount* to, double amount)
	{
		this->from = from;
		this->to = to;
		this->amount = amount;
	}

	Transaction(Card* from, Card* to, double amount)
	{
		this->from = from->get_debit_account();
		this->to = to->get_debit_account();
		this->amount = amount;
	}

	void start()
	{
		if (from->get_balance() < amount)
		{
			status = Status::NOT_ENOUGH_MONEY;
			return;
		}
		if (from->get_currency() != to->get_currency())
		{
			status = Status::DIFFERENT_CURRENCY;
			return;
		}
		from->decrease(amount);
		to->increase(amount);
		status = Status::OK;
	}

	Status get_status()
	{
		return status;
	}

private:
	DebitAccount* from;
	DebitAccount* to;
	Date date;/////
	double amount;
	Status status;
};

