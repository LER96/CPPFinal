#ifndef NodeCustomer_H
#define NodeCustomer_H
#include "Customer.h"
class NodeCustomer
{
public:
	NodeCustomer() { _next = NULL; }
	NodeCustomer(const NodeCustomer& orig) { _next = orig._next; _value = orig._value; }
	NodeCustomer(Customer* val, NodeCustomer* next)
	{
		if (next==NULL)
		{
			_next = NULL;
		}
		else
		{
			_next = next;
		}
		_value = val;
	}
	bool HasNext() 
	{
		if (_next!=NULL)
		{
			return true;
		}
		return false;
	}
	NodeCustomer* GetNext() { return _next; }
	Customer* GetValue() { return _value; }
	void SetNext(NodeCustomer* newNext) 
	{
		if (newNext==NULL)
		{
			_next = NULL;
		}
		else
		{
			_next = newNext->_next;
		}
	}
	void SetValue(Customer* val) { _value = val; }
	virtual ~NodeCustomer(){}

private:
	NodeCustomer* _next;
	Customer* _value;
};

#endif // !NodeCustomer_H
