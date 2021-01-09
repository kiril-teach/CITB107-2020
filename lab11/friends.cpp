#include <iostream>

using namespace std;

const int MAX = 100;

void makeFriends(int friends[][MAX], int a, int b)
{
    friends[a][b] = friends[b][a] = 1;
}

void checkFriends(int friends[][MAX], int a, int b)
{
    cout << (friends[a][b] ? "yes" : "no") << endl;
}

int main()
{
    string cmd;
    int a, b;

    int friends[MAX][MAX] = {};

    while (cin >> cmd >> a >> b)
    {
        if (cmd == "f")
        {
            makeFriends(friends, a, b);
        }
        else if (cmd == "c")
        {
            checkFriends(friends, a, b);
        }
        else
        {
            cout << "no such command: " << cmd << endl;
        }
    }

    return 0;
}