#ifndef BankAction_H
#define BankAction_H
#include <string>
using namespace std;

class BankAction
{
public:
	BankAction(){}
	BankAction(int act)
	{
		_action = act;
		switch (_action)
		{
		case 1:
			_timeOfAction = 3;
			break;
		case 2:
			_timeOfAction = 2;
			break;
		case 3:
			_timeOfAction = 5;
			break;
		case 4:
			_timeOfAction = 4;
			break;
		default:
			break;
		}
	}
	~BankAction(){}
	int GetAction()
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
	bool CompareAction(int s)
	{
		if (s==_action)
		{
			return true;
		}
		return false;
	}

private:
	int _action;
	float _timeOfAction;
};

#endif // !BankAction_H

