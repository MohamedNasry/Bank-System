#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsUser.h"
#include "Gloabal.h"
#include "clsDate.h"


using namespace std;


class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		
		
		cout <<  "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t   " << Title;

		if (SubTitle != "")
		{
			cout << "\n" << clsUtil::Tabs(6) << SubTitle;
		}

		cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl;
	}

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

