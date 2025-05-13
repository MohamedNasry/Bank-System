#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;


class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenueOptions { eListUser = 1, eAddNewUser = 2 , eDeleteUser = 3 , eUpdateUser = 4 
	, eFindUser = 5 , eShowMainMenue = 6 };

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _ShowListUserScreen()
	{
		//cout << "\nList user screen will be here.\n";

		clsListUsersScreen::ShowUsersList();

	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New user screen will be here.\n";

		clsAddNewUserScreen::ShowAddNewUserScreen();

	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete user screen will be here.\n";

		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate user screen will be here.\n";

		clsUpdateUserScreen::ShowUpdateUserScreen();

	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind user screen will be here.\n";

		clsFindUserScreen::ShowFindUserScreen();

	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\t\t Press any key to go back to Manage Users Menue...";
		system("pause > 0");
		ShowManageUsersScreen();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptions)
	{
		switch (ManageUsersMenueOptions)
		{
		case enManageUsersMenueOptions::eListUser:
		{
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;

		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eShowMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}

		
		}
	}

	
public:

	static void ShowManageUsersScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Manage users screen.");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Screen.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}

};

