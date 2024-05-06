#ifndef NodeCustomer_H
#define NodeCustomer_H
#include "Customer.h"

class Node
{
public:
	Customer* value;
	Node* next;
	int position;
	Node(Customer* c)
	{
		value = c;
		next = nullptr;
		position = 0;
	}
	Node* GetNext() { return next; }
	void SetPostion(int pos)
	{
		position = pos;
	}
	int GetPosition() { return position; }
};


class NodeCustomer
{
public:
	NodeCustomer()
	{
		_front = nullptr;
		_rear = nullptr;
	}
	bool isEmpty()
	{
		return _front = nullptr;
	}
	Node* GetFront() { return _front; }
	int GetSize() { return _size; }
	Customer* CustomerAt(int pos)
	{
		Node* current = _front;
		while (current->position!= pos)
		{
			current = current->next;
		}
		return current->value;
	}
	void enqueue(Customer* customer) //Add Customer to last/ first position
	{
		Node* newNode = new Node(customer);
		if (customer->GetAge()>=65 || _front==nullptr)
		{
			newNode->next = _front;
			_front = newNode;
		}
		else
		{
			Node* current = _front;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
		CustomerSize();
	}
	Customer* dequeue() //Remove first Customer
	{
		if (!_front) {
			return nullptr;
		}
		Node* temp = _front;
		_front = _front->next;
		if (!_front) {
			_rear = nullptr;
		}
		Customer* customer = temp->value;
		delete temp;
		CustomerSize();
		return customer;
	} 
	void RemoveCustomer(Customer* customer) // Remove specific customer, can be anywhere in the list
	{
		Node* current = _front;
		Node* prev = nullptr;

		while (current != nullptr && current->value != customer) {
			prev = current;
			current = current->next;
		}

		if (current == nullptr) {
			return;
		}

		if (prev == nullptr) {
			_front = current->next;
		}
		else {
			prev->next = current->next;
		}
		delete current;
		CustomerSize();
	}
	virtual ~NodeCustomer(){}

private:
	Node* _front;
	Node* _rear;
	int _size;
	void CustomerSize()// reorginize the size of the link node, and set position of customer
	{
		Node* current = _front; 
		_size = 0;
		while (current!=nullptr)
		{
			current->SetPostion(_size);
			current = current->next;
			_size++;
		}
	}
};

#endif // !NodeCustomer_H
