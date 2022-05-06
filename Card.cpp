#include "Card.h"

Card::Card(DebitAccount* debit_account, PaymentSystem payment_system)
{
	this->debit_account = debit_account;
	this->payment_system = payment_system;
}

Card::Card(DebitAccount* debit_account, PaymentSystem payment_system, Date expiration_time) :Card(debit_account, payment_system)
{
	this->expiration_time = expiration_time;
}

bool Card::set_new_debit_account(DebitAccount* debit_account)
{
	if (debit_account->get_card_status())
		return false;
	this->debit_account = debit_account;
	return true;
}
