#include "Client.h"

ClientBase::ClientBase(Address address, string phone_number)
{
	this->address = address;
	this->phone_number = phone_number;
}

void ClientBase::create_account(Currency currency)
{
	debit_accounts.push_back(new DebitAccount(currency));
}
