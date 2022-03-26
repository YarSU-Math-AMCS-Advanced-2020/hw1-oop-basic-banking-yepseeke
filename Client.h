#pragma once
#include <string>
#include <vector>
#include "DebitAccount.h"
#include "Card.h"
#include "Address.h"

using namespace std;

class ClientBase
{
public:
	ClientBase() {};
	ClientBase(Address address, string phone_number);
	
	void create_account(Currency currency);
	void create_card(int account_id, PaymentSystem payment_system, Date expiration_time);

	vector<DebitAccount> get_debit_accounts()
	{
		vector<DebitAccount> t;
		for (int i = 0; i < debit_accounts.size(); i++)
			t.push_back(*debit_accounts[i]);
		return t;
	}

	Address get_address() { return address; }
	string get_phone_number() { return phone_number; }

	void set_address(Address address) { this->address = address; }
	void set_phone_number(string phone_number) { this->phone_number = phone_number; }

private:
	Address address;
	string phone_number;
	vector<DebitAccount*> debit_accounts;
	vector<Card*> cards;
};

