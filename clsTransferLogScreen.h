#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"


using namespace std;


class clsTransferLogScreen : protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(15) << left << TransferLogRecord.SrcBalanceAfter;
        cout << "| " << setw(15) << left << TransferLogRecord.DestBalanceAfter;
        cout << "| " << setw(9) << left << TransferLogRecord.UserName;


    }

public:

	static void ShowTransferLogScreen()
	{
        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\t Transfer Log Screen.";
        string SubTitle = "\t  ( " + to_string(vTransferLogRecord.size()) + " ) Record(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        cout << setw(8) << left << "";
        cout << "| " << left << setw(20) << "Date / Time";
        cout << "| " << left << setw(10) << "S.Acc";
        cout << "| " << left << setw(10) << "D.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(15) << "S.Balance";
        cout << "| " << left << setw(15) << "D.Balance";
        cout << "| " << left << setw(9) << "User";

        cout << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Login Users Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;
	}


};

