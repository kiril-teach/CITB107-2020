#include <iostream>
#include <iomanip>

using namespace std;

// 1 euro value in cents
const int EURO = 100;
// Available currency units
const int UNITS[] = {50 * EURO, 20 * EURO, 10 * EURO, 5 * EURO, 2 * EURO, EURO, 50, 20, 10, 5, 2, 1};

bool validateInput(int due, int paid, string &err)
{
    // Validate user input - positive numbers
    if (paid <= 0 || due <= 0)
    {
        err = "amounts should be > 0";
        return false;
    }

    // Validate user input - paid should be more than the amount due
    if (paid < due)
    {
        err = "paid is less than due";
        return false;
    }

    return true;
}

void returnChange(int change)
{
    cout << "Change: " << change / (float)EURO << endl;
    // Calculate how to return it
    int idx = 0;
    while (change)
    {
        int unit = UNITS[idx++];
        int cnt = change / unit;
        if (cnt)
        {
            cout << cnt << " x " << unit / (float)EURO << endl;
        }
        change = change % unit;
    }
}

int main()
{
    cout << fixed << setprecision(2);

    int due, paid;
    string err;

    do
    {
        if (err.length())
        {
            cout << "Invalid input: " << err << endl;
        }
        cin >> due >> paid;
    } while (!validateInput(due, paid, err));

    returnChange(paid - due);

    return 0;
}