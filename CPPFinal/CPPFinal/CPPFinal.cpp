#include <iostream>
#include "PersonData.h"

int main()
{
    MailBank* bank = new  MailBank("05/02/2024", 9, 12);
    PersonData* pepoleInBank = new PersonData(bank);
    bank->Print();
    while (bank->GetTime()< bank->GetCloseHour())
    {
        if (cin.get() == '\n')
        {
            bank->ManageBank();
        }
    }
    if (cin.get() == '\n')
    {
        pepoleInBank->SaveCustomerIntoFile();
    }

}

