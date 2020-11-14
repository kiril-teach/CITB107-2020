#include <iostream>
#include <iomanip>

using namespace std;

// 1 euro value in cents
const int EURO = 100;
// Available currency units
const int UNITS[] = {50*EURO, 20*EURO, 10*EURO, 5*EURO, 2*EURO, EURO, 50, 20, 10, 5, 2, 1};

int main() {
    // Setup `cout` to output floating point numbers with exactly 2 digits after the decimal point.
    cout << fixed << setprecision(2);

    // Declare input variables
    int due, paid;

    // Read input variables from the standard input (i.e. console input)
    cin >> due >> paid;

    // Validate user input - positive numbers
    if (paid <= 0 || due <= 0) {
        cout << "ERR: amounts should be > 0" << endl;
        return -1;
    }

    // Validate user input - paid should be more than the amount due
    if (paid < due) {
        cout << "ERR: paid is less than due" << endl;
        return -2;
    }

    // Calculate the total change
    int change = paid - due;
    cout << "Change: " << change/(float)EURO << endl;

    // Calculate how to return it
    int left = change;
    int idx = 0;
    while (left) {
        int unit = UNITS[idx++];
        int cnt = left / unit;
        if (cnt) {
            cout << cnt << " x " << unit/(float)EURO << endl;
        }
        left = left % unit;
    }

    return 0;
}