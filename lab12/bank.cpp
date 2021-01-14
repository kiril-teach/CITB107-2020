#include <iostream>
#include <vector>

using namespace std;

int findAccountIndex(const vector<string> &accounts, const string &acc) {
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i] == acc)
        {
            return i;
        }
    }

    return -1;
}

bool exists(const vector<string> &accounts, const string &acc)
{
    return findAccountIndex(accounts, acc) >= 0;
}

bool openAccount(vector<string> &accounts, vector<int> &balances, const string &acc, int balance, string &err)
{
    if (exists(accounts, acc))
    {
        err = "account already exists";
        return false;
    }
    accounts.push_back(acc);
    balances.push_back(balance);
    return true;
}

bool closeAccount(vector<string> &accounts, vector<int> &balances, const string &acc, string &err) 
{
    if (!exists(accounts, acc)) {
        err = "account does not exist";
        return false;
    }

    int accIdx = findAccountIndex(accounts, acc);
    accounts.erase(accounts.begin() + accIdx);
    balances.erase(balances.begin() + accIdx);
    return true;
}

bool transfer(vector<string> &accounts, vector<int> &balances, const string &sourceAcc, const string &destAcc, int amount, string &err) {
    if (!exists(accounts, sourceAcc)) {
        err = "source account does not exist";
        return false;
    }
    if (!exists(accounts, destAcc)) {
        err = "destination account does not exist";
        return false;
    }


    int sourceAccIdx = findAccountIndex(accounts, sourceAcc);
    int destAccIdx = findAccountIndex(accounts, destAcc);

    if (balances[sourceAccIdx] < amount) {
        err = "insufficient funds in source account";
        return false;
    }

    balances[sourceAccIdx] -= amount;
    balances[destAccIdx] += amount;
    
    return true;
}

void prn(const vector<string> &accounts, const vector<int> &balances)
{
    cerr << "-- DEBUG --" << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        cerr << accounts[i] << ": " << balances[i] << endl;
    }
    cerr << "-----------" << endl;
}

int main()
{
    string cmd;
    string err;

    vector<string> accounts;
    vector<int> balances;

    while (cin >> cmd)
    {
        if (cmd == "open")
        {
            string acc;
            int balance;

            cin >> acc >> balance;
            if (!openAccount(accounts, balances, acc, balance, err))
            {
                cout << "cannot open account: " << err << endl;
            }
        }
        else if (cmd == "close")
        {
            string acc;
            cin >> acc;
            if (!closeAccount(accounts, balances, acc, err)) {
                cout << "cannot close account: " << err << endl;
            }
        }
        else if (cmd == "transfer")
        {
            string sourceAcc, destAcc;
            int amount;
            cin >> sourceAcc >> destAcc >> amount;

            if (!transfer(accounts, balances, sourceAcc, destAcc, amount, err)) {
                cout << "cannot transfer: " << err << endl;
            }
        }
        prn(accounts, balances);
    }

    return 0;
}