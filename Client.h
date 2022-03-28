#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Address.h"
#include "DebitAccount.h"
#include "Card.h"

class ClientBase
{
public:

	ClientBase() {};
	ClientBase(Address address, std::string phone_number);

	void create_debit_account(DebitAccount::Currency currency);
	void create_card(DebitAccount* debit_account, Card::PaymentSystem payment_system);

	vector<DebitAccount> get_debit_accounts();
	DebitAccount* get_debit_account(int account_id);
	Card* get_card(DebitAccount* debit_account);
	Address get_address() const { return address; }
	string get_phone_number() const { return phone_number; }

	void set_address(Address address) { this->address = address; }
	void set_phone_number(string phone_number) { this->phone_number = phone_number; }

protected:
	Address address;
	string phone_number;
	vector<DebitAccount*> debit_accounts;
	vector<Card*> cards;
};

