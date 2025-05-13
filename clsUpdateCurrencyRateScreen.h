#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}
	
	static void _UpdateCurrencyRate(clsCurrency& Currency)
	{
		float NewRate;
		cout << "\n\nUpdate Currency Rate: \n";
		cout << "_____________________________\n";
		cout << "\nEnter New Rate : ";
		NewRate = clsInputValidate::ReadFloatNumber();

		Currency.UpdateRate(NewRate);

		cout << "\n\nCurrency Rate update successfully :-)\n";

	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		system("cls");
		_DrawScreenHeader("\tUpdate Rate Screen.");

		cout << "\n\nPlease enter Currency Code : ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n\nCurrrency not found,Enter another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrency(Currency);

		cout << "\n\nAre you sure you want to update the rate of this currency y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			_UpdateCurrencyRate(Currency);
			_PrintCurrency(Currency);
		}

	}


};

