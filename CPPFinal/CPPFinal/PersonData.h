#include <iostream>
#include <fstream>
#include <sstream>
#include "MailBank.h"

class PersonData
{
public:
	PersonData(MailBank* bank);
	~PersonData();
	void InsertCustomerFromFile() // read customers from customers file
	{
        ifstream file("C:/Users/Admin/Documents/GitHub/CPPFinal/Customers.txt");
        //vector<Customer*> customers;

        if (file.is_open()) {
            string line;
            while (getline(file, line)) { 
                istringstream iss(line);
                string name, date;
                char action;

                if (iss >> name >> date >> action) 
                {
                    Customer* customer = new Customer(name, date, action);
                    _bank->AssignCustomer(customer);
                }
            }
            file.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
	}
    void SaveCustomerIntoFile()// when called, the file will be ovrrite with the imformation of the postal office
    {
        ofstream file("C:/Users/Admin/Documents/GitHub/CPPFinal/Customers1.txt");
        file << "";
        if (file.is_open())
        {
            NodeCustomer* customersLeft = _bank->GetCustomersList();
            Node* current = customersLeft->GetFront();
            while (current!=nullptr)
            {
                string name = current->value->GetName();
                string date = current->value->GetDateOfBirth();
                string lineNum = current->value->GetLineNumber();
                char action = current->value->GetBankAction()->GetAction();
                file << name << date << action << "," << lineNum << endl;
                current = current->next;
            }
            file.close();
        }
        
    }
    void InsertWorkersFromFile()//Read workers data from workers file 
    {
        ifstream file("C:/Users/Admin/Documents/GitHub/CPPFinal/Workers.txt");
        vector<Staff*> staff;

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                vector<char> actions;
                istringstream iss(line);
                char action;
                while (iss >> action)
                {
                    if (action != ' ' && action != ',')
                    {
                        actions.push_back(action);
                    }
                }
                //push_back(new Staff(actions));
                _bank->AssignWorker(new Staff(actions));
            }
            file.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    }

private:
    MailBank* _bank;
};

PersonData::PersonData(MailBank* bank)
{
    _bank = bank;
    InsertCustomerFromFile();
    InsertWorkersFromFile();
}
PersonData::~PersonData()
{
}



