#include "DebitAccount.h"

string DebitAccount::get_currency_string() const
{
	if (currency == Currency::RUB)
		return "RUB";
	if (currency == Currency::USD)
		return "USD";
	else
		return "EURO";
}
