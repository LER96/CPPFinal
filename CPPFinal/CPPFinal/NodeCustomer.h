#include "Person.h"

class NodeCustomer
{
public:
	NodeCustomer() { _next = NULL; }
	NodeCustomer(const NodeCustomer& orig) { _next = orig._next; _value = orig._value; }
	virtual ~NodeCustomer();
	bool HasNext() {
		if (_next!=NULL)
		{
			return true;
		}
		return false;
	}
	NodeCustomer* GetNext() { return _next; }
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
	Customer* GetValue() { return _value; }
	void SetValue(Customer* val) { _value = val; }

private:
	NodeCustomer* _next;
	Customer* _value;
};
