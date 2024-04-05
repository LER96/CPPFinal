#include <iostream>
#include "MailBank.h"
int main()
{
    MailBank bank = MailBank("24/04/2024", 8, 20);
    Customer* c = new Customer("Eddie", "03/07/1997", 1);
    Customer* c1 = new Customer("Sidonia", "20/03/1945", 3);

    vector<int> actions = { 1,2,3 };
    Staff s = Staff(actions);
    bank.AssignWorker(s);
    bank.AssignCustomer(c);
    bank.AssignCustomer(c1);

    bank.ManageBank();
}

