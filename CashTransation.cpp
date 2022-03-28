#include "CashTransaction.h"

CashTransation::CashTransation(Type type, DebitAccount* debit_account, double amount, Date date, ATM atm)
{
	this->type = type;
	this->debit_account = debit_account;
	this->amount = amount;
	this->atm = atm;
}

CashTransation::CashTransation(Type type, Card* card, double amount, Date date, ATM atm)
{
	this->type = type;
	this->debit_account = card->get_debit_account();
	this->amount = amount;
	this->atm = atm;
}

void CashTransation::start()
{
	if (atm.get_currency() != debit_account->get_currency())
	{
		status = Status::Denied;
		return;
	}
	if (type == Type::Withdrawal)
	{
		if (debit_account->get_balance() < amount)
		{
			status = Status::Denied;
			return;
		}
		debit_account->decrease(amount);
		atm.decrease(amount);
		status = Status::Done;
	}
	if (type == Type::Replenishing)
	{
		debit_account->increase(amount);
		atm.increase(amount);
		status = Status::Done;
	}
}
