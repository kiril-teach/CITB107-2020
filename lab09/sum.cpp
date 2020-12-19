#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

float sum(const vector<float> &numbers)
{
    float n;
    float sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    return sum;
}

vector<float> readInput(istream &in, vector<float> &input)
{
    int cnt;
    cin >> cnt;

    input.resize(cnt);

    for (int i = 0; i < cnt; i++)
    {
        cin >> input[i];
    }

    return input;
}

void writeOutput(ostream &out, const vector<float> input, float result)
{
    cout << "sum(";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i];
        if (i < input.size() - 1)
        {
            cout << ",";
        }
    }
    cout << ")=" << result << endl;
}

int main()
{
    assert(sum({1, 2, 3, 4, 5}) == 15);
    assert(sum({}) == 0);

    vector<float> input;
    readInput(cin, input);

    float result = sum(input);

    writeOutput(cout, input, result);

    return 0;
}