#pragma once
#include "DebitAccount.h";
#include "Date.h"

class Card
{
public:

	enum class PaymentSystem { Lisa, MasterBart, HoMiR };

	Card(DebitAccount* debit_account, PaymentSystem payment_system);
	Card(DebitAccount* debit_account, PaymentSystem payment_system, Date expiration_time);

	DebitAccount* get_debit_account() { return debit_account; }
	PaymentSystem get_payment_system() const { return payment_system; }
	Date get_expiration_time() const { return expiration_time; }

	bool set_new_debit_account(DebitAccount* debit_account);

private:
	DebitAccount* debit_account;
	PaymentSystem payment_system;
	Date expiration_time;
};

