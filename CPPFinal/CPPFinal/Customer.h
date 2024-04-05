#ifndef Customer_H
#define Customer_H
#include <vector>
#include <iostream>
#include <string>
#include "BankAction.h"

using namespace std;

class Customer
{
public:
	string name;
	string dateOfBirth;
	string lineNumber;
	Customer(string _name, string _birth, int action, string currentDate)
	{
		name = _name;
		dateOfBirth = _birth;
		_action = new BankAction(action);
		SetAge(currentDate);
	}
	string GetDateOfBirth()
	{
		return dateOfBirth;
	}
	string GetLineNumber()
	{
		return lineNumber;
	} 
	string GetName() { return name; }
	int GetAge()
	{
		return _age;
	}
	void SetAge(string _currentDate)
	{
		int _currentYear = stoi(_currentDate.substr(6, 9));
		int _birthYear = stoi(dateOfBirth.substr(6, 9));

		_age = _currentYear - _birthYear;
	}
	void SetLineNumber(int line)
	{
		if (_age >= 65)
		{
			lineNumber = "E" + line;
		}
		else
		{
			lineNumber = "" + line;
		}
	}

	~Customer();

private:
	BankAction* _action;
	int _age;
};

#endif // !Customer_H