#include <iostream>
#include <fstream>
#include <sstream>
#include "MailBank.h"

class PersonData
{
public:
	PersonData(MailBank* bank);
	~PersonData();
	void InsertCustomerFromFile()
	{
        ifstream file("C:/Users/Admin/Desktop/Customers.txt");
        vector<Customer*> customers;

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
                    customers.push_back(customer);

                }
            }
            file.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
	}

    void InsertWorkersFromFile()
    {
        ifstream file("C:/Users/Admin/Desktop/Workers.txt");
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



