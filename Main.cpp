#include "Main.h"

int main()
{
	Individual new_user;
	double amount;
	ATM atm(Address(), "123", 132312, DebitAccount::Currency::RUB);
	//new_user.create_new_individual();

	system("cls");
	new_user.create_debit_account(choose_currency());

	new_user.create_card(new_user.get_debit_account(0), choose_payment_system());
	

	cout << new_user.get_debit_accounts().size();

	cout << "Your balance: " << new_user.get_debit_account(0)->get_balance() << " " << new_user.get_debit_account(0)->get_currency_string() << endl;
	Sleep(1000);
	system("cls");

	cout << "\t\t\t\t\tDepositing cash\nInput your deposit\n";
	cin >> amount;
	CashTransation cash_transcation(CashTransation::Type::Replenishing, new_user.get_card(new_user.get_debit_account(0)), amount, Date(), atm);
	cash_transcation.start();
	system("cls");
	if (cash_transcation.get_status() == CashTransation::Status::Done)
		cout << "Success! Refill for " << amount << " " << new_user.get_debit_account(0)->get_currency_string() << endl;
	else cout << "Error. Try to use another ATM\n\n";

	cout << "Your balance: " << new_user.get_debit_account(0)->get_balance() << " " << new_user.get_debit_account(0)->get_currency_string() << endl;
	Sleep(1000);
	system("cls");

	cout << "\t\t\t\t\tWithdrawing cash\nInput your withdrawal\n";
	cin >> amount;
	cash_transcation = CashTransation(CashTransation::Type::Withdrawal, new_user.get_card(new_user.get_debit_account(0)), amount, Date(), atm);
	cash_transcation.start();
	if (cash_transcation.get_status() == CashTransation::Status::Done)
		cout << "Success! Withdrawal for " << amount << " " << new_user.get_debit_account(0)->get_currency_string() << endl << endl;
	else cout << "Error. Insufficient funds.\n\n";

	cout << "Your balance: " << new_user.get_debit_account(0)->get_balance() << " " << new_user.get_debit_account(0)->get_currency_string() << endl;
	Sleep(1000);
	system("cls");

	user1.create_debit_account(DebitAccount::Currency::RUB);
	user1.get_debit_account(0)->set_balance(5120020.23);

	user2.create_debit_account(DebitAccount::Currency::RUB);
	user2.get_debit_account(0)->set_balance(13202.01);

	user3.create_debit_account(DebitAccount::Currency::RUB);
	user3.get_debit_account(0)->set_balance(2729811.23);

	DebitAccount* to = send_to();
	cout << "Input amount of money you want to send\n";
	cin >> amount;
	Transaction transaction(new_user.get_debit_account(0), to, amount);
	transaction.start();

	if (transaction.get_status() == Transaction::Status::DIFFERENT_CURRENCY)
		cout << "Error. Different currency.\n\n";
	if (transaction.get_status() == Transaction::Status::NOT_ENOUGH_MONEY)
		cout << "Error. Insufficient funds.\n\n";
	if (transaction.get_status() == Transaction::Status::OUT_OF_LIMITS)
		cout << "Error. Out of limits.\n\n";
	if (transaction.get_status() == Transaction::Status::OK)
		cout << "Success. You've send " << amount << " " << new_user.get_debit_account(0)->get_currency_string() << endl << endl;

	cout << "Your balance: " << new_user.get_debit_account(0)->get_balance() << " " << new_user.get_debit_account(0)->get_currency_string() << endl;
	Sleep(1000);
	system("cls");

	if (new_user.close_debit_account(0)) 
		cout << "Your debit account has been closed\n";
	else
		cout << "Error occurred during debit account closure\n";
	Sleep(1000);
	system("cls");
}

int print_menu(vector<string> a, string title)
{
	int key = 0, move;
	int N = a.size();
	while (true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << title;
		for (int i = 0; i < N; i++)
		{
			if (i != key)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << i + 1 << ". " << a[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << i + 1 << ". " << a[i] << endl;
			}
		}
		cout << '\n';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		move = _getch();
		if (move == 27)
		{
			system("cls");
			exit(0);
		}

		if (move == 224) move = _getch();

		if (move == 13)
		{
			system("cls");
			return key + 1;
		}
		else if (move == 72) key = ((key - 1) % N + N) % N;
		else if (move == 80) key = (key + 1) % N;
		system("cls");
	}
	return key;
}

DebitAccount::Currency choose_currency()
{
	vector<string> a = { "RUB", "USD", "EURO" };
	while (true)
	{
		int key = print_menu(a, "\t\t\t\t\tOpening of your deposit account\nChoose currency for your debit account\n");
		switch (key)
		{
		case 1:
		{
			return DebitAccount::Currency::RUB;
			system("cls");
			break;
		}
		case 2:
		{
			return DebitAccount::Currency::USD;
			system("cls");
			break;
		}
		case 3:
		{
			return DebitAccount::Currency::EURO;
			system("cls");
			break;
		}
		default: break;
		}
	}
}

Card::PaymentSystem choose_payment_system()
{
	vector<string> a = { "HoMiR", "Lisa", "MasterBart" };
	while (true)
	{
		int key = print_menu(a, "\t\t\t\t\tCreation of your debit card\nChoose payment system for your card\n");
		switch (key)
		{
		case 1:
		{
			return Card::PaymentSystem::HoMiR;
			system("cls");
			break;
		}
		case 2:
		{
			return Card::PaymentSystem::Lisa;
			system("cls");
			break;
		}
		case 3:
		{
			return Card::PaymentSystem::MasterBart;
			system("cls");
			break;
		}
		default: break;
		}
	}
}

DebitAccount* send_to()
{
	string s1 = user1.get_surname() + " " + user1.get_name() + " " + user1.get_patronymic() + user1.get_birth_date().get_date_string();
	string s2 = user2.get_surname() + " " + user2.get_name() + " " + user2.get_patronymic() + user2.get_birth_date().get_date_string();
	string s3 = user3.get_surname() + " " + user3.get_name() + " " + user3.get_patronymic() + user3.get_birth_date().get_date_string();
	vector<string> a = { s1, s2, s3 };
	while (true)
	{
		int key = print_menu(a, "\t\t\t\t\tSending money\nChoose who do you want to send money\n");
		switch (key)
		{
		case 1:
		{
			return user1.get_debit_account(0);
			system("cls");
			break;
		}
		case 2:
		{
			return user2.get_debit_account(0);
			system("cls");
			break;
		}
		case 3:
		{
			return user3.get_debit_account(0);
			system("cls");
			break;
		}
		default: break;
		}
	}
}

