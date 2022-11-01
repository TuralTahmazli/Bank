#pragma once
class Debtor
{
    public:

    Debtor();
    Debtor(double salary, bool hasLatePayment, double debt,const char* name, const char* surname, const char* workAddress, const char* liveAddress, const char* phoneNumber);
    ~Debtor();

    size_t getId();
    double getSalary();
    bool getHasLatePayment();
    double getDebt();
    char* getName();
    char* getSurname();
    char* getWorkAddress();
    char* getLiveAddress(); 
    char* getPhoneNumber();

    void setSalary(double salary);
    void setHasLatePayment(bool hasLatePayment);
    void setDebt(double debt);
    void setName(const char* name);
    void setSurname(const char* surname);
    void setWorkAddress(const char* workAddress);
    void setLiveAddress(const char* liveAddress);
    void setPhoneNumber(const char* phoneNumber);
    void printDebtor();

    private:

    static size_t _staticId;
    size_t _id;
    double _salary;
    bool _hasLatePayment;
    double _debt;
    char* _name;
    char* _surname;
    char* _workAddress;
    char* _liveAddress;
    char* _phoneNumber;
};

size_t Debtor::_staticId = 0;

Debtor::Debtor()
{
    _salary = 0;
    _hasLatePayment = 0;
    _debt = 0;
    _name = nullptr;
    _surname = nullptr;
    _workAddress = nullptr;
    _liveAddress = nullptr;
    _phoneNumber = nullptr;
}

Debtor::Debtor(double salary, bool hasLatePayment, double debt, const char* name, const char* surname, const char* workAddress, const char* liveAddress, const char* phoneNumber)
    :Debtor()
{
    setSalary(salary);
    setHasLatePayment(hasLatePayment);
    setDebt(debt);
    setName(name);
    setSurname(surname);
    setWorkAddress(workAddress);
    setLiveAddress(liveAddress);
    setPhoneNumber(phoneNumber);
}

Debtor::~Debtor()
{
    delete[] _name;
    _name = nullptr;
    delete[] _surname;
    _surname = nullptr;
    delete[] _workAddress;
    _workAddress = nullptr;
    delete[] _liveAddress;
    _liveAddress = nullptr;
    delete[] _phoneNumber;
    _phoneNumber = nullptr;
}

size_t Debtor::getId() { return _id; }
double Debtor::getSalary() { return _salary; }
bool Debtor::getHasLatePayment() { return _hasLatePayment; }
double Debtor::getDebt() { return _debt; }
char* Debtor::getName() { return _name; }
char* Debtor::getSurname() { return _surname; }
char* Debtor::getWorkAddress() { return _workAddress; }
char* Debtor::getLiveAddress() { return _liveAddress; }
char* Debtor::getPhoneNumber() { return _phoneNumber; }

void Debtor::setSalary(double salary)
{
    _salary = salary;
}

void Debtor::setHasLatePayment(bool hasLatePayment)
{
    _hasLatePayment = hasLatePayment;
}

void Debtor::setDebt(double debt)
{
    _debt = debt;
}

void Debtor::setName(const char* name)
{
    if (name == nullptr)
        assert(!"Name can't be null");
    if (_name != nullptr)
        delete[] _name;
    size_t len = strlen(name) + 1;
    _name = new char[len];
    strcpy_s(_name, len, name);
}

void Debtor::setSurname(const char* surname)
{
    if (surname == nullptr)
        assert(!"Surname can't be null");
    if (_surname != nullptr)
        delete[] _surname;
    size_t len = strlen(surname) + 1;
    _surname = new char[len];
    strcpy_s(_surname, len, surname);
}

void Debtor::setWorkAddress(const char* workAddress)
{
    if (workAddress == nullptr)
        assert(!"WorkAddress can't be null");
    if (_workAddress != nullptr)
        delete[] _workAddress;
    size_t len = strlen(workAddress) + 1;
    _workAddress = new char[len];
    strcpy_s(_workAddress, len, workAddress);
}

void Debtor::setLiveAddress(const char* liveAddress)
{
    if (liveAddress == nullptr)
        assert(!"LiveAddress can't be null");
    if (_liveAddress != nullptr)
        delete[] _liveAddress;
    size_t len = strlen(liveAddress) + 1;
    _liveAddress = new char[len];
    strcpy_s(_liveAddress, len, liveAddress);
}

void Debtor::setPhoneNumber(const char* phoneNumber)
{
    if (phoneNumber == nullptr)
        assert(!"PhoneNumber can't be null");
    if (_phoneNumber != nullptr)
        delete[] _phoneNumber;
    size_t len = strlen(phoneNumber) + 1;
    _phoneNumber = new char[len];
    strcpy_s(_phoneNumber, len, phoneNumber);
}

void Debtor::printDebtor()
{
	cout << "===============================" << '\n'; 
	cout << "Salary: " << _salary << '\n';
	cout << "Haslatepayment: " << _hasLatePayment << '\n';
	cout << "Debt: " << _debt << '\n';
	cout << "Name: " << (_name ? _name : "None") << '\n';
	cout << "Surname: " << (_surname ? _surname : "None") << '\n';
	cout << "Workaddress: " << (_workAddress ? _workAddress : "None") << '\n';
	cout << "Liveaddress: " << (_liveAddress ? _liveAddress : "None") << '\n'; 
	cout << "Phonenumber: " << (_phoneNumber ? _phoneNumber : "None") << '\n';
	cout << "===============================" << '\n';
}