#ifndef BankAction_H
#define BankAction_H
#include <string>
using namespace std;

class BankAction
{
public:
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
	BankAction(int act)
	{
		_action = act;
		switch (_action)
		{
		case 1:
			_timeOfAction = 0.1f;
			break;
		case 2:
			_timeOfAction = 0.2f;
			break;
		case 3:
			_timeOfAction = 0.3f;
			break;
		case 4:
			_timeOfAction = 0.4f;
			break;
		default:
			break;
		}
	}
	~BankAction(){}

private:
	int _action;
	float _timeOfAction;
};

#endif // !BankAction_H

