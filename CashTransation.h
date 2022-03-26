#pragma once
#include "DebitAccount.h"
#include "Address.h"

class CashTransation
{
public:
	enum class Type { Withdrawal, Replenishing };

	enum class Status { Done, Denied };

	CashTransation(Type type, DebitAccount* debit_account, double amount, Date date,
		Address address, int ATM_number)
	{
		this->type = type;
		this->debit_account = debit_account;
		this->amount = amount;
		this->date = date;
		this->address = address;
		this->ATM_number = ATM_number;
	}

	void start()
	{
		if (type == Type::Withdrawal)
		{
			if (debit_account->get_balance() < amount)
			{
				status = Status::Denied;
				return;
			}
			debit_account->decrease(amount);
			status = Status::Done;
		}
		if (type == Type::Replenishing)
		{
			debit_account->increase(amount);
			status = Status::Done;
		}
	}

private:
	Type type;
	DebitAccount* debit_account;
	double amount;
	Date date;
	Status status;
	Address address;
	int ATM_number;
};

