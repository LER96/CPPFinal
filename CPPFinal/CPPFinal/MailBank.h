#ifndef MailBank_H
#define MailBank_H
#include "Customer.h"
#include "Staff.h"
#include "NodeCustomer.h"
#include <math.h>
class MailBank
{
public:
	MailBank(string curretDate, float open, float close);
	void AssignCustomer(Customer* customer);
	void RemoveCustomer(Customer* customer);
	void AssignWorker(Staff* staff);
	void RemoveWorker(Staff* staff);
	void Print();
	void ManageBank();
	~MailBank();

private:
	string _date;
	float _openHour;
	float _closeHour;
	float _currentTime;
	int _currentLine;
	NodeCustomer* _customersList;
	vector<Staff> _clercks;
};

MailBank::MailBank(string currentDate, float open, float close)
{
	_date = currentDate;
	_openHour = open;
	_closeHour = close;
	_currentTime = _openHour;
	_customersList = new NodeCustomer();
	ManageBank();

}
void MailBank::ManageBank()
{
	int _counter = 0;
	while (_currentTime < _closeHour)
	{
		_counter++;
		if (_counter > 50000)
		{
			_counter = 0;
			_currentTime += 0.01f;
			Print();
		}
	}
}

void MailBank::Print()
{
	cout << "======================\n" << "Current Time: "<< _currentTime << "|| Date:"+_date << endl;
	cout << "======================" <<  endl;
	/*for (int i = 0; i < _clercks.size(); i++)
	{
		if (_clercks[i].IsWorking())
		{
			cout << "Clerck" + i << " is Working with: " << _clercks[i].GetCurrentCustomer()->GetName() << endl;
		}
		else
		{
			cout << "Clerck" + i << " is available" << endl;
		}
	}*/
	cout << "\n======================\n" << "Current line number: " << _currentLine << endl;
	cout << "======================" << endl;
}


MailBank::~MailBank()
{

}

#endif //!MailBank_H