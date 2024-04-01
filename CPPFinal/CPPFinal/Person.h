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
		Regular,
		Clerck
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
		type = Regular;
	}
	string GetDateOfBirth()
	{
		return dateOfBirth;
	}

	void SetAge(string _currentDate)
	{
		int _currentYear = stoi(_currentDate.substr(6, 9));
		int _birthYear= stoi(dateOfBirth.substr(6, 9));

		_age = _currentYear - _birthYear;
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
	Staff();
	Staff(vector<BankAction> action)
	{
		for (int i = 0; i < action.size(); i++)
		{
			_actions.push_back(action[i]);
		}
		type = Clerck;
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


