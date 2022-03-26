#pragma once
#include "DebitAccount.h";
#include "Date.h"

enum class PaymentSystem { Lisa, MasterBart, HoMiR };

class Card
{
public:

	Card(DebitAccount* debit_account, PaymentSystem payment_system)
	{
		this->debit_account = debit_account;
		this->payment_system = payment_system;
	}

	Card(DebitAccount* debit_account, PaymentSystem payment_system, Date expiration_time):Card(debit_account, payment_system)
	{
		this->expiration_time = expiration_time;
	}

	DebitAccount* get_debit_account()
	{
		return debit_account;
	}

private:
	DebitAccount* debit_account;
	PaymentSystem payment_system;
	Date expiration_time;
};

