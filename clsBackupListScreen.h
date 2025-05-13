#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"

using namespace std;

class clsBackupListScreen : protected clsScreen
{
private:
    static void _PrintBackupRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << "| " << setw(16) << left << clsDate::DateToString(Client.Date);

    }

public:

    static void ShowBackupsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pBackupClient))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList("Backup.txt");

        string Title = "\t Backup List Screen.";
        string SubTitle = "\t  ( " + to_string(vClients.size()) + " ) Client(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "| " << left << setw(16) << "Date";
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient& Client : vClients)
            {

                _PrintBackupRecordLine(Client);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

    }
};

