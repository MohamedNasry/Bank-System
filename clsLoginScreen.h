#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Gloabal.h"

class clsLoginScreen :protected clsScreen
{

private:



    static  bool _Login()
    {
        bool LoginFaild = false;

        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";

                cout << "You have " << 3 - FaildLoginCount << " Trial(s) to Login \n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\n\n\nYou are locked after 3 faild trials \n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

            FaildLoginCount++;

        } while (LoginFaild);

        CurrentUser.RegisterLogin();

        clsMainScreen::ShowMainMenue();



        return true;

    }

public:

  

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
