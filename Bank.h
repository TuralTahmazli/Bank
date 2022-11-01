#pragma once
class Bank
{
	public:

	Bank();
	Bank(const char* name, DebtorList* debtors);
	~Bank();

	DebtorList* getDebtors();
	char* getName();

	void setName(const char* name);
	void setDebtors(DebtorList* debtors);

	void printAllDebtors();
	void printDebtorsDebtGreaterThan(double debt);
	void printDebtorsWithDelays();

	private:

	char* _name;
	DebtorList* _debtors;
};


Bank::Bank()
{
	_name = nullptr;
	_debtors = nullptr;
}

Bank::Bank(const char* name, DebtorList* debtors)
	:Bank()
{
	setName(name);
	setDebtors(debtors);
}

Bank::~Bank()
{
	delete[] _name;
	_name = nullptr;
	delete _debtors;
}

DebtorList* Bank::getDebtors()
{
	return _debtors;
}

char* Bank::getName() { return _name; }

void Bank::setName(const char* name)
{
	if (name == nullptr)
		assert(!"Name can't be null");
	if (_name != nullptr)
		delete[] _name;
	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

void Bank::setDebtors(DebtorList* debtors)
{
	_debtors = new DebtorList(*debtors);
}

inline void Bank::printAllDebtors()
{
	_debtors->printDebtors();
}

inline void Bank::printDebtorsDebtGreaterThan(double debt)
{
	for (size_t i = 0; i < _debtors->getCount(); i++)
	{
		if (debt < _debtors->getDebtors()[i]->getDebt())
			_debtors->getDebtors()[i]->printDebtor();
	}
}

inline void Bank::printDebtorsWithDelays()
{
	for (size_t i = 0; i < _debtors->getCount(); i++)
	{
		if (_debtors->getDebtors()[i]->getHasLatePayment()==true)
			_debtors->getDebtors()[i]->printDebtor();
	}
}