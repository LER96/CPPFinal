#include <iostream>
#include "PersonData.h"

int main()
{
    MailBank* bank = new  MailBank("05/02/2024", 8, 20);
    PersonData* pepoleInBank = new PersonData(bank);
    bank->ManageBank();
    while (bank->GetTime()<20)
    {
        if (cin.get() == '\n')
        {
            bank->ManageBank();
        }
    }
}

