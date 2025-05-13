#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:

    static void ShowDeleteClientScreen()
    {
        _DrawScreenHeader("\t Delete Client Screen.");

        string AccountNumber = "";

        cout << "\nPlease enter account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not fount,choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nDo you want to save a backup of the current account y/n? ";
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                clsBankClient::enSaveBackup SaveBackup;
                SaveBackup = Client1.SaveBackup();

                switch (SaveBackup)
                {
                case clsBankClient::enSaveBackup::svBackupSucceeded:
                {
                    cout << "\nBackup of the current account Saved succeeded :-)\n";
                    break;
                }
                case clsBankClient::enSaveBackup::svFaildBackup:
                {
                    cout << "\nError Backup of the current account was not Saved :-C\n";
                    break;
                }
                }

            }

            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }


    }
};

