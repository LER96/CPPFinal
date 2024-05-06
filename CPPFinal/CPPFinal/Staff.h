#ifndef Staff_H
#define Staff_H
#include "Customer.h"
class Staff
{
public:
	Staff(){}
	Staff(vector<char> actions)
	{
		for (int i = 0; i < actions.size(); i++)
		{
			BankAction* _act = new BankAction(actions[i]);
			_actions.push_back(_act);
		}
	}
	void UpdateWork(float _updateTime)
	{
		_timeToWork = _timeToWork - _updateTime;
		if ( _timeToWork<=0)
		{
			DoneService();
		}
	}
	bool CanAcceptCustomer(Customer* customer)
	{
		if (IsWorking()==false && CanDoAction(customer->GetBankAction()))
		{
			return true;
		}
		return false;
	}
	bool CanDoAction(BankAction* a)
	{
		for (int i = 0; i < _actions.size(); i++)
		{
			if (a->CompareAction(_actions[i]->GetAction()))
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
	float GetWorkingTime() { return _timeToWork; }
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
		_timeToWork = customer->GetBankAction()->GetActionTime();
		_isWorking = true;
	}
	void AddAction(BankAction* a)
	{
		_actions.push_back(a);
	}
	void RemoveAction(BankAction* a)
	{
		for (int i = 0; i < _actions.size(); i++)
		{
			if (a->CompareAction(_actions[i]->GetAction()))
			{
				_actions.erase(_actions.begin() + i);
			}
		}
	}
	~Staff(){}

private:
	Customer* _currentCustomer;
	Customer* _previousCustomer;
	vector<BankAction*> _actions;
	float _timeToWork;
	float _currentWorkTime;
	bool _isWorking;

	void DoneService()
	{
		_timeToWork = 0;
		_previousCustomer = _currentCustomer;
		_currentCustomer = nullptr;
		_isWorking = false;
	}
};

#endif // !Staff_H