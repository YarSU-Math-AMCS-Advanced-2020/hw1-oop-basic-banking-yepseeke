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