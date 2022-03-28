#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "Client.h"
#include "Individual.h"
#include "Transaction.h"
#include "ATM.h"
#include "CashTransaction.h"

using namespace std;

Individual user1("Bulatkin", "Egor", "Nikolaevich", Individual::Sex(1), Date(6, 25, 1994), Address(), "+79999999999");
Individual user2("Esenin", "Sergei", "Alexandrovich", Individual::Sex(1), Date(10, 3, 1895), Address(), "+72223331123");
Individual user3("Mikhailova", "Ekaterina", "Alexeevna", Individual::Sex(2), Date(2, 8, 1725), Address(), "+72316279021");

int print_menu(vector<string> a, string title);
DebitAccount::Currency choose_currency();
Card::PaymentSystem choose_payment_system();
DebitAccount* send_to();