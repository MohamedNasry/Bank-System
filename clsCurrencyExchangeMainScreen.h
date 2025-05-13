#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:

    enum enCurrenciesMainMenueOptions {eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
    eCurrencyCalculator = 4, eMainMenue = 5};

    static short _ReadCurrencyExchangeOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "\t\t\t\t\t\tEnter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchange();
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "\nList Currencies Screen will be her.";

        clsCurrenciesListScreen::ShowCurrenciesList();

    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen will be her.";

        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\nUpdate rate screen will be her.";

        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

    }

    static void _ShowCurrencyCalculatorScreen()
    {
       // cout << "\nCurrency calculator Screen will be her.";

        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesExchangeOptions)
    {
        switch (CurrenciesExchangeOptions)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMainMenue();
            break;
        }
        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMainMenue();
            break;
        }
        case enCurrenciesMainMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMainMenue();
            break;
        }
        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMainMenue();
            break;
        }
        case enCurrenciesMainMenueOptions::eMainMenue:
        {
            //do noting the main screen will handel it :-);
        }
        }
    }


public:

	static void ShowCurrencyExchange()
	{
        system("cls");
		_DrawScreenHeader("  Currency Exchange Main Screen.");
        
        cout << "\n\n\n";

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)_ReadCurrencyExchangeOption());
	}
};

