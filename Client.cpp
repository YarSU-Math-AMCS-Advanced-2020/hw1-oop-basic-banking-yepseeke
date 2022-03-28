#include "Client.h"

ClientBase::ClientBase(Address address, string phone_number)
{
	this->address = address;
	this->phone_number = phone_number;
}

void ClientBase::create_debit_account(DebitAccount::Currency currency)
{
	debit_accounts.push_back(new DebitAccount(currency));
}

void ClientBase::create_card(DebitAccount* debit_account, Card::PaymentSystem payment_system)
{
	cards.push_back(new Card(debit_account, payment_system));
}

vector<DebitAccount> ClientBase::get_debit_accounts()
{
	vector<DebitAccount> t;
	for (int i = 0; i < debit_accounts.size(); i++)
		t.push_back(*debit_accounts[i]);
	return t;
}

DebitAccount* ClientBase::get_debit_account(int account_id)
{
	return debit_accounts[account_id];
}

Card* ClientBase::get_card(DebitAccount* debit_account)
{
	for (int i = 0; i < cards.size(); i++)
		if (debit_account == cards[i]->get_debit_account())
			return cards[i];
	return nullptr;
}
