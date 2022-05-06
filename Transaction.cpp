#include "Transaction.h"

Transaction::Transaction(DebitAccount* from, DebitAccount* to, double amount)
{
	this->from = from;
	this->to = to;
	this->amount = amount;
}

Transaction::Transaction(Card* from, Card* to, double amount)
{
	this->from = from->get_debit_account();
	this->to = to->get_debit_account();
	this->amount = amount;
}

void Transaction::start()
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
	if (from->get_limit() <= amount)
	{
		status = Status::OUT_OF_LIMITS;
		return;
	}
	from->decrease(amount);
	to->increase(amount);
	status = Status::OK;
}
