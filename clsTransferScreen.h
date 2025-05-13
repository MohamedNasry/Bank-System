#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsBankClient.h"


using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nClient Card:\n";
		cout << "\n_______________________________\n";
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Acc. Number : " << Client.AccountNumber() << endl;
		cout << "Balance     : " << Client.AccountBalance;
		cout << "\n_______________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadPositiveDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen.");

	

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		
		_PrintClient(SourceClient);

		

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		
		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				
				cout << "\nTransfer done successfully\n";
				
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
	
};

