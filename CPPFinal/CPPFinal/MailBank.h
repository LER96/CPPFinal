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
	void ManageBank()
	{
		_currentTime += 0.05f;
		Print();

		//if there're any clercks working
		if (_clercks.size() > 0)
		{
			for (int i = 0; i < _clercks.size(); i++)
			{
				for (int pos = 0; pos < _customersList->GetSize(); pos++)
				{
					Customer* _customer = _customersList->CustomerAt(pos);
					if (_clercks[i]->CanAcceptCustomer(_customer))
					{
						_clercks[i]->AssignCustomer(_customer);
						_customersList->RemoveCustomer(_customer);
					}
				}
			}
		}		
	}
	float GetTime() { return _currentTime; }
	~MailBank();

private:
	string _date;
	float _openHour;
	float _closeHour;
	float _currentTime;
	int _currentLine;
	int _counterTime = 0;
	NodeCustomer* _customersList;
	vector<Staff*> _clercks;
};

MailBank::MailBank(string currentDate, float open, float close)
{
	_date = currentDate;
	_openHour = open;
	_closeHour = close;
	_currentTime = _openHour;
	_customersList = new NodeCustomer();
	
}
void MailBank::AssignCustomer(Customer* c)
{
	c->SetAge(_date);
	_customersList->enqueue(c);
}
void MailBank::RemoveCustomer(Customer* c)
{
	_customersList->RemoveCustomer(c);
}
void MailBank::AssignWorker(Staff* staff)
{
	_clercks.push_back(staff);
}
void MailBank::Print()
{
	system("cls");
	cout << "======================\n" << "Current Time: "<< _currentTime << "|| Date:"+_date << endl;
	cout << "======================" <<  endl;
	if (_clercks.size() > 0)
	{
		for (int i = 0; i < _clercks.size(); i++)
		{
			if (_clercks[i]->IsWorking())
			{
				cout << "Clerck" + i << " is Working with: " << _clercks[i]->GetCurrentCustomer()->GetName() << endl;
			}
			else
			{
				cout << "Clerck" + i << " is available" << endl;
			}
		}
	}
	cout << "\n======================\n" << "Current line number: " << _currentLine << endl;
	cout << "======================" << endl;
}
MailBank::~MailBank()
{

}
#endif //!MailBank_H 