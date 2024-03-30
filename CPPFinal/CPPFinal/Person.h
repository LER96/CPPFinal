#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include "BankAction.h"

using namespace std;

class Person
{
public:
	enum PersonType
	{
		Customer,
		Staff
	};
	PersonType type;
	Person();
	~Person();

private:
};

class Customer: public Person
{
public:
	string name;
	string dateOfBirth;
	string lineNumber;
	Customer(string _name, string _birth, BankAction action)
	{
		name = _name;
		dateOfBirth = _birth;
		_action = action;
	}
	string GetDateOfBirth()
	{
		return dateOfBirth;
	}

	void SetAge(string _currentDate)
	{

	}

	int GetAge() 
	{
		return _age;
	}

	~Customer();

private:
	BankAction _action;
	int _age;
};


class Staff : public Person
{
public:
	Staff(vector<BankAction> action)
	{
		for (int i = 0; i < action.size(); i++)
		{
			_actions.push_back(action[i]);
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
	void AddAction(BankAction a)
	{
		_actions.push_back(a);
	}
	void RemoveAction(BankAction a)
	{
		for (int i = 0; i < _actions.size(); i++)
		{
			if(a.CompareAction(_actions[i].GetAction()))
			{
				_actions.erase(_actions.begin() + i);
			}
		}
	}
	~Staff();

private:
	vector<BankAction> _actions;
	bool _isWorking;
};


