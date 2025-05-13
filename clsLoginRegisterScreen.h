#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord User)
    {

        cout << setw(8) << left << "" << "| " << setw(33) << left << User.Date;
        cout << "| " << setw(21) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(15) << left << User.Permissions;


    }

public:

    static void ShowLoginRegisterScreen()
    {

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Regester List Screen";
        string SubTitle = "\t  ( " + to_string(vLoginRegisterRecord.size()) + " ) Client(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "";
        cout << "| " << left << setw(33) << "Date / Time";
        cout << "| " << left << setw(21) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(15) << "Permissions";
       
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Login Users Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

