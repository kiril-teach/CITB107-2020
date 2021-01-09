#include <iostream>
#include <vector>

using namespace std;

int sum(const int numbers[], int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += numbers[i];
    }
    return s;
}

void print(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;

    int numbers[size];
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    cout << sum(numbers, size) << endl;

    return 0;
}