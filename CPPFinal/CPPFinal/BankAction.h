#ifndef BankAction_H
#define BankAction_H
#include <string>
using namespace std;

class BankAction
{
public:
	BankAction(){}
	BankAction(char act)
	{
		_action = act;
		switch (_action)
		{
		case '1'://Recive Package
			_timeOfAction = 0.1f;
			break;
		case '2'://Deliver Package
			_timeOfAction = 0.3f;
			break;
		case '3': //Payment Arragment
			_timeOfAction = 0.5f;
			break;
		case '4': //Buy Product
			_timeOfAction = 1.0f;
			break;
		default:
			break;
		}
	}
	~BankAction(){}
	char GetAction()
	{
		return _action;
	}
	float GetActionTime()
	{
		return _timeOfAction;
	}
	void SetTimeOfAction(int multiplier)
	{
		_timeOfAction *= multiplier;
	}
	bool CompareAction(char s)
	{
		if (s==_action)
		{
			return true;
		}
		return false;
	}
private:
	char _action;
	float _timeOfAction;
};

#endif // !BankAction_H

