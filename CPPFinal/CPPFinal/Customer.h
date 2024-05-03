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
	Customer(string _name, string _birth, char action)
	{
		name = _name;
		dateOfBirth = _birth;
		_action = new BankAction(action);
		_typeString = "null";
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
	BankAction* GetBankAction()
	{
		return _action;
	}
	int GetAge()
	{
		return _age;
	}
	string GetCustomerType()
	{
		if (_age>=65)
		{
			_typeString = "Elder";
		}
		else
		{
			_typeString = "Regular";
		}

		return _typeString;
	}
	bool CompareType(string type)
	{
		if (type ==_typeString)
		{
			return true;
		}
		return false;
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
			lineNumber = "E";
			lineNumber += to_string(line);
		}
		else
		{
			lineNumber = to_string(line);
		}
	}
	~Customer();

private:
	BankAction* _action;
	int _age;
	string _typeString;
};

#endif // !Customer_H