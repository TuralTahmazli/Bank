#include<iostream>
#include<cassert>
using namespace std;
#include"Debtor.h"
#include"DebtorList.h"
#include"Bank.h"
int main()
{
	Debtor* d1 = new Debtor();
	Debtor* d2 = new Debtor(2000.5, true, 10000.5, "str1", "str2", "str3", "str4", "str5");
	Debtor* d3 = new Debtor();
	Debtor** debtors = new Debtor * [1] {d1};
	DebtorList* debtorsList = new DebtorList(debtors, 1);
	Bank* bank = new Bank("Kapital Bank", debtorsList);
	//bank->getDebtors()->appendDebtor(d2);
	//bank->getDebtors()->printDebtors();
}