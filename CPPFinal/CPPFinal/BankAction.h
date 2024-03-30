#include <string>
using namespace std;

class BankAction
{
public:
	enum Action
	{
		TakeDelivery,
		DeliverMail ,
		PaymentArrange ,
		Buy ,
	};

	string GetActionTypeToString(Action a)
	{
		switch (a)
		{
		case BankAction::TakeDelivery:
			return "Take";
		case BankAction::DeliverMail:
			return "Deliver";
		case BankAction::PaymentArrange:
			return "Pay";
		case BankAction::Buy:
			return "Buy";
		default:
			break;
		}
	}
	string GetAction()
	{
		return _action;
	}
	void SetAction(Action a)
	{
		switch (a)
		{
		case BankAction::TakeDelivery:
			_action= "Take";
			break;
		case BankAction::DeliverMail:
			_action = "Deliver";
			break;
		case BankAction::PaymentArrange:
			_action = "Pay";
			break;
		case BankAction::Buy:
			_action = "Buy";
			break;
		default:
			break;
		}
	}

	bool CompareAction(string s)
	{
		if (s==_action)
		{
			return true;
		}
		return false;
	}

	BankAction();
	~BankAction();

private:
	string _action;
};

