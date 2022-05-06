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

bool ClientBase::create_card(DebitAccount* debit_account, Card::PaymentSystem payment_system)
{
	if (debit_account->get_card_status())
		return false;
	cards.push_back(new Card(debit_account, payment_system));
	debit_account->set_card_status(true);
	return true;
	
}

bool ClientBase::close_debit_account(int account_id)
{
	if (account_id < debit_accounts.size() && account_id >= 0)
	{
		debit_accounts[account_id]->set_limit(INT_MAX);
		DebitAccount debit_account(*debit_accounts[account_id]);
		CashTransation transaction(CashTransation::Type::Withdrawal, debit_accounts[account_id], debit_account.get_balance(), Date(), ATM(Address(),
			"+79128321213", debit_account.get_balance(), debit_account.get_currency()));
		for (int i = 0; i < cards.size(); i++)
			if (cards[i]->get_debit_account() == debit_accounts[account_id])
			{
				delete cards[i];
				cards.erase(cards.begin() + i);
			}
		delete debit_accounts[account_id];
		debit_accounts.erase(debit_accounts.begin() + account_id);
		return true;
	}
	else return false;
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
