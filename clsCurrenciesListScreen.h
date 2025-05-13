#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"


using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
       
	}

public:

    static void ShowCurrenciesList()
    {
        vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();

        string Title = "\tCurrencies List Screen";
        string SubTitle = "\t  ( " + to_string(vCurrencys.size()) + " ) Currency(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\n\t_______________________________________________________";
        cout << "__________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
     
        cout << "\n\t_______________________________________________________";
        cout << "__________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency& Currency : vCurrencys)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "__________________________________________\n" << endl;
    }
};

