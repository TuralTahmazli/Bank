#pragma once
class DebtorList
{
	public:

	DebtorList();
	DebtorList(Debtor** debtors, size_t count);
	~DebtorList();

	size_t getCount();
	Debtor** getDebtors();
	void setDebtors(Debtor** debtors, size_t length);

	void appendDebtor(Debtor* debtor);
	void deleteDebtor(Debtor* debtor);
	void deleteDebtorById(size_t id);
	Debtor* getDebtorById(size_t id);
	void clearDebtors();
	void printDebtors();

	private:

	Debtor** _debtors;
	size_t _count;
};

DebtorList::DebtorList()
{
	setDebtors(nullptr, 0);
}

DebtorList::DebtorList(Debtor** debtors, size_t count)
	:DebtorList()
{
	setDebtors(debtors, count);
}

DebtorList::~DebtorList()
{
	for (size_t i = 0; i < _count; i++)
	{
		delete _debtors[i];
		_debtors[i] = nullptr;
	}
	delete[] _debtors;
	_debtors = nullptr;
}

size_t DebtorList::getCount() { return _count; }

Debtor** DebtorList::getDebtors() { return _debtors; }

void DebtorList::setDebtors(Debtor** debtors, size_t count)
{
	if (debtors)
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < count; j++)
			{
				if (i != j && debtors[i] == debtors[j])
					assert(!"You can't add two or more same debtors in the debtor list");
			}
		}
	if (_debtors)
	{
		for (size_t i = 0; i < count; i++)
		{
			delete _debtors[i];
			_debtors[i] = nullptr;
		}
		delete[] _debtors;
		_debtors = nullptr;
	}
	_debtors = debtors;
	_count = count;
}

void DebtorList::appendDebtor(Debtor* debtor)
{
	if (_debtors == nullptr)
	{
		_debtors = new Debtor * [_count + 1] {debtor};
		return;
	}
	for (size_t i = 0; i < _count; i++)
	{
		if (_debtors[i] == debtor)
			assert(!"Debtor already exits");
	}
	Debtor** debtors = new Debtor * [_count + 1];
	for (size_t i = 0; i < _count; i++)
	{
		debtors[i] = _debtors[i];
	}
	debtors[_count] = debtor;
	_count++;
	delete[] _debtors;
	_debtors = debtors;
}

void DebtorList::deleteDebtor(Debtor* debtor)
{
	if (_debtors == nullptr)
		assert(!"Debtor not exits");
	bool temp = true;
	for (size_t i = 0; i < _count; i++)
	{
		if (_debtors[i] == debtor)
		{
			temp = false;
			delete _debtors[i];
			_debtors[i] = nullptr;
			break;
		}
	}
	if (temp)
		assert(!"Debtor not exits");
	Debtor** debtors = new Debtor * [_count - 1];
	for (size_t i = 0; i < _count - 1; i++)
	{
		if (_debtors[i] == nullptr)
			temp++;
		debtors[i] = _debtors[i + temp];
	}
	_count--;
	delete[] _debtors;
	_debtors = debtors;
}

void DebtorList::deleteDebtorById(size_t id)
{
	if (_debtors == nullptr)
		assert(!"Debtor not exits");
	for (size_t i = 0; i < _count; i++)
	{
		if (_debtors[i]->getId() == id)
			return deleteDebtor(_debtors[i]);
	}
}

Debtor* DebtorList::getDebtorById(size_t id)
{
	if (_debtors == nullptr)
		assert(!"Debtor not exits");
	for (size_t i = 0; i < _count; i++)
	{
		if (_debtors[i]->getId() == id)
			return _debtors[i];
	}
	assert(!"Debtor not exits");
}

void DebtorList::clearDebtors()
{
	if (_debtors == nullptr)
		return;
	for (size_t i = 0; i < _count; i++)
	{
		delete _debtors[i];
		_debtors[i] = nullptr;
	}
	delete[] _debtors;
	_debtors = nullptr;
	_count = 0;
}

void DebtorList::printDebtors()
{
	for (size_t i = 0; i < _count; i++)
	{
		_debtors[i]->printDebtor();
	}
}