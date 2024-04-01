#include "Person.h"
#include "NodeCustomer.h"

class MailBank
{
public:
	MailBank(string curretDate, float open, float close);
	void AssignCustomer(Customer* customer);
	void RemoveCustomer(Customer* customer);
	void AssignWorker(Staff* staff);
	void RemoveWorker(Staff* staff);

	void ManageBank();
	~MailBank();

private:
	string _date;
	float _openHour;
	float _closeHour;
	float _currentTime;
	NodeCustomer* _customerList;
	Staff* _clerk[4];
};

MailBank::MailBank(string currentDate, float open, float close)
{
	_date = currentDate;
	_openHour = open;
	_closeHour = close;
	_currentTime = _openHour;
	_customerList = new NodeCustomer();

}

void MailBank::ManageBank()
{
	//loop of each customer
}

MailBank::~MailBank()
{

}