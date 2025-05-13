#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsBackupListScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Gloabal.h"
#include "clsCurrencyExchangeMainScreen.h"


using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eBackup = 8, eLoginRegister = 9, eCurrencyExchange = 10, eExit = 11
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 11]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 11, "\t\t\t\t\t\tEnter Number between 1 to 11? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
       // cout << "\nClient List Screen Will be here...\n";

        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }

        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }

        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";

        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";

        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

            system("pause>0");
            return;
        }

        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        //cout << "\nUsers Menue Will be here...\n";
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

            system("pause>0");
            return;
        }
        clsManageUsersScreen::ShowManageUsersScreen();

    }

    static void _ShowBackupListScreen()
    {
        //cout << "\nBackup List Screen will be here...\n";

        clsBackupListScreen::ShowBackupsList();

    }

    //static void _ShowEndScreen()
    //{
    //    cout << "\nEnd Screen Will be here...\n";

    //}

    static void _ShowLoginRegisterScreen()
    {
        //cout << "Login Register will be her " ;

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {

            return;
        }

        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchengeScreen()
    {
        //cout << "\nCurrency Exchange will be her.";

     /*   if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

            system("pause>0");
            return;
        }*/

        clsCurrencyExchangeMainScreen::ShowCurrencyExchange();

    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");

       // clsLoginScreen::ShowLoginScreen(); errore circular refrence because problem the call Stack 

        //then it will go back to main function.
    }

    

    static void _PerfomMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            ShowMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            ShowMainMenue();
            break;

        case enMainMenueOptions::eBackup:
            system("cls");
            _ShowBackupListScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchengeScreen();
            ShowMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]  Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2]  Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3]  Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4]  Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5]  Find Client.\n";
        cout << setw(37) << left << "" << "\t[6]  Transactions.\n";
        cout << setw(37) << left << "" << "\t[7]  Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8]  Show Backup List.\n";
        cout << setw(37) << left << "" << "\t[9]  Login Register.\n";
        cout << setw(37) << left << "" << "\t[10] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[11] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfomMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

