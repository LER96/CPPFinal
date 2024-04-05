#ifndef NodeCustomer_H
#define NodeCustomer_H
#include "Customer.h"
class NodeCustomer
{
public:
	NodeCustomer()
	{
		_value = nullptr;
		_next = nullptr;
		_front = nullptr;
		_rear = nullptr;
	}
	NodeCustomer(const NodeCustomer& orig) 
	{ 
		_next = orig._next; 
		_value = orig._value; 
		_front = orig._front;
		_rear = orig._rear;
	}
	NodeCustomer(Customer* c)
	{
		_value = c;
		_next = nullptr;
	}

	bool isEmpty()
	{
		return _front = nullptr;
	}
	bool HasNext() 
	{
		if (_next!=NULL)
		{
			return true;
		}
		return false;
	}

	NodeCustomer* GetFront() { return _front; }
	NodeCustomer* GetNext() { return _next; }
	Customer* GetValue() { return _value; }
	void SetNext(NodeCustomer* newNext) 
	{
		if (newNext== nullptr)
		{
			_next = nullptr;
		}
		else
		{
			_next = newNext->_next;
		}
	}
	void RemoveNode(Customer* c)
	{
		NodeCustomer* _previous = nullptr;
		NodeCustomer* _current= _front;
		while (_current->GetValue() != c)
		{
			_previous = _current;
			_current = _current->_next;
		}
		if (_current->HasNext())
		{
			_previous->SetNext(_current->GetNext());
		}
		else
		{
			delete _current;
		}
	}
	void SetValue(Customer* val) { _value = val; }

	void enqueue(Customer* customer)
	{
		NodeCustomer* newNode = new NodeCustomer(customer);
		if (!_front || customer->GetAge()>=65)
		{
			newNode->_next = _front;
			_front = newNode;
		}
		else
		{
			NodeCustomer* _current = _front;
			while (_current->_next && _current->_next->_value->GetAge() >= 65)
			{
				_current = _current->_next;
			}
			newNode ->_next = _current->_next;
			_current->_next = newNode;
		}
	}
	Customer* dequeue() {
		if (!_front) {
			return nullptr;
		}

		NodeCustomer* temp = _front;
		_front = _front->_next;
		if (!_front) 
		{
			_rear = nullptr;
		}

		Customer* customer = temp->_value;
		delete temp;
		return customer;
	}

	virtual ~NodeCustomer(){}

private:
	NodeCustomer* _next;
	Customer* _value;
	NodeCustomer* _front;
	NodeCustomer* _rear;
};

#endif // !NodeCustomer_H
