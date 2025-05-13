#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 ,BackupMode = 3};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkeForDelete = false;
    vector <clsBankClient> _vSaveBackup;
    clsDate _Date;

    struct stTransferLogRecord;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        clsBankClient Client(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

        if (vClientData.size() > 7) // إذا كان هناك تاريخ مخزن
        {
            Client.SetDate(clsDate(vClientData[7])); // تعيين التاريخ المخزن
            
        }

        return Client;
    }

    static string _ConvertClientObjectToLine(clsBankClient& Client, string Seperator = "#//#",bool IsBackup = false)
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        if (IsBackup)
        {
            stClientRecord += Seperator + clsDate::DateToString(Client.Date);
            Client._Mode = enMode::BackupMode;
        }

        return stClientRecord;

    }

    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;

        vector <string> vTransferLogDataLine = clsString::Split(Line, Seperator);

        TransferLogRecord.DateTime = vTransferLogDataLine[0];
        TransferLogRecord.SourceAccountNumber = vTransferLogDataLine[1];
        TransferLogRecord.DestinationAccountNumber = vTransferLogDataLine[2];
        TransferLogRecord.Amount = stod(vTransferLogDataLine[3]);
        TransferLogRecord.SrcBalanceAfter = stod(vTransferLogDataLine[4]);
        TransferLogRecord.DestBalanceAfter = stod(vTransferLogDataLine[5]);
        TransferLogRecord.UserName = vTransferLogDataLine[6];


        return TransferLogRecord;
    }

    static  vector <clsBankClient> _LoadClientsDataFromFile(string FileName = "Clients.txt")
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open(FileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient& C : vClients)
            {
                if (C._MarkeForDelete == false)
                {
                    //we only write records that are not marked for delete.
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  DataLine, string FileName = "Clients.txt")
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }

    }

    string _PrepareTransferLogRegord(clsBankClient DestinationClient, double Amount, string UserName, string Seperator = "#//#")
    {
        string TransferRecord = "";

        TransferRecord += clsDate::GetSystemDateString() + Seperator;
        TransferRecord += AccountNumber() + Seperator;
        TransferRecord += DestinationClient.AccountNumber() + Seperator;
        TransferRecord += to_string(Amount) + Seperator;
        TransferRecord += to_string(AccountBalance) + Seperator;
        TransferRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferRecord += UserName;

        return TransferRecord;
    }

    void _RegisterTransferLog( clsBankClient DestinationClient, double Amount, string UserName)
    {
        string stDataLine = _PrepareTransferLogRegord(DestinationClient, Amount, UserName);

        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    struct stTransferLogRecord
    {
        string DateTime;
        string DestinationAccountNumber;
        string SourceAccountNumber;
        double Amount;
        double SrcBalanceAfter;
        double DestBalanceAfter;
        string UserName;

    };


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    clsDate GetDate()
    {
        return _Date;
    }

    void SetDate(clsDate Date)
    {
        _Date = Date;
    }

    __declspec(property(get = GetDate, put = SetDate)) clsDate Date;

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*
    No UI Related code inside object
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }
    */
    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 
        };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
           
            return enSaveResults::svFaildEmptyObject;
            
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //this will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }
        }
         
                

        

        }



    }

    enum enSaveBackup { svFaildBackup = 0, svBackupSucceeded = 1 };

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
       return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    

    bool Delete()
    {
        vector <clsBankClient> _vClients;

        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkeForDelete = true;

                _SaveCleintsDataToFile(_vClients);
                *this = _GetEmptyClientObject();

                return true;
            }
        }
        return false;
    }

    static vector <clsBankClient> GetClientsList(string FileName = "Clients.txt")
    {
        return _LoadClientsDataFromFile(FileName);
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::_LoadClientsDataFromFile();

        double TotalBalances = 0;

        for (clsBankClient& C : vClients)
        {
            TotalBalances += C.AccountBalance;
        }
        return TotalBalances;
    }

    enSaveBackup SaveBackup()
    {
        this->Date = clsDate();
        _vSaveBackup.push_back(*this);

        _AddDataLineToFile(_ConvertClientObjectToLine(*this, "#//#", true), "Backup.txt");
        if (this->_Mode == enMode::BackupMode)
        {
            return enSaveBackup::svBackupSucceeded;

        }
        else
        {
            return enSaveBackup::svFaildBackup;
        }
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;

        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(DestinationClient, Amount, UserName);

        return true;
    }

    static vector <stTransferLogRecord> GetTransferLogList()
    {
        vector <stTransferLogRecord> vTransferLogRecord;

        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecord TransferLogRecord;

            while (getline(MyFile, Line))
            {
                TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferLogRecord);
            }

            MyFile.close();

        }
        return vTransferLogRecord;
    }

};





