#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

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
    int numbers[MAX];
    int size = 0;
    while (size < MAX)
    {
        if (cin >> numbers[size])
        {
            size++;
        }
        else
        {
            break;
        }
    }

    cout << sum(numbers, size) << endl;

    return 0;
}