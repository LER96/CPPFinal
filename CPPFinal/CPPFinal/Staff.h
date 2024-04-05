#ifndef Staff_H
#define Staff_H
#include "Customer.h"
class Staff
{
public:
	Staff(){}
	Staff(vector<int> action)
	{
		for (int i = 0; i < action.size(); i++)
		{
			BankAction _act = BankAction(action[i]);
			_actions.push_back(_act);
		}
	}
	bool CanDo(BankAction a)
	{
		for (int i = 0; i < _actions.size(); i++)
		{
			if (a.CompareAction(_actions[i].GetAction()))
			{
				return true;
			}
		}
		return false;
	}
	bool IsWorking()
	{
		return _isWorking;
	}
	Customer* GetCurrentCustomer()
	{
		return _currentCustomer;
	}
	Customer* GetPreviousCustomer()
	{
		return _previousCustomer;
	}
	void AssignCustomer(Customer* customer)
	{
		_currentCustomer = customer;
		_isWorking = true;
	}
	void DoneService()
	{
		_previousCustomer = _currentCustomer;
		_currentCustomer = NULL;
		_isWorking = false;
	}
	void AddAction(BankAction a)
	{
		_actions.push_back(a);
	}
	void RemoveAction(BankAction a)
	{
		for (int i = 0; i < _actions.size(); i++)
		{
			if (a.CompareAction(_actions[i].GetAction()))
			{
				_actions.erase(_actions.begin() + i);
			}
		}
	}
	~Staff(){}

private:
	Customer* _currentCustomer;
	Customer* _previousCustomer;
	vector<BankAction> _actions;
	bool _isWorking;
};

#endif // !Staff_H