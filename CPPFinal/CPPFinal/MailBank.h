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
	void AssignWorker(Staff staff);
	void RemoveWorker(Staff staff);
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
	vector<Staff> _clercks= vector<Staff>();
};

MailBank::MailBank(string currentDate, float open, float close)
{
	_date = currentDate;
	_openHour = open;
	_closeHour = close;
	_currentTime = _openHour;
	_customersList = new NodeCustomer();
	
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
			_currentTime += 0.001f;
			Print();
		}

		//if there're any clercks working
		if (_clercks.size() > 0)
		{
			for (int i = 0; i < _clercks.size(); i++)
			{
				//runs on each 
				NodeCustomer* _customerNode = _customersList->GetFront();
				Customer* _customer = _customerNode->GetValue();
				if (_clercks[i].CanAcceptCustomer(_customer))
				{
					_clercks[i].AssignCustomer(_customer);
				}
				else
				{
					if (_customerNode->GetNext() != nullptr)
					{
						_customerNode = _customerNode->GetNext();
					}
				}
			}
		}

	}

}
void MailBank::AssignCustomer(Customer* c)
{
	_customersList->enqueue(c);
}
void MailBank::RemoveCustomer(Customer* c)
{
	_customersList->RemoveNode(c);
}
void MailBank::AssignWorker(Staff staff)
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
			if (_clercks[i].IsWorking())
			{
				cout << "Clerck" + i << " is Working with: " << _clercks[i].GetCurrentCustomer()->GetName() << endl;
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