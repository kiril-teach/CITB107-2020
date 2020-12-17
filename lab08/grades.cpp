#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>

using namespace std;

float averagePerLine(istream &numbers)
{
    int n;
    int cnt = 0;
    int sum = 0;
    string noop;
    while (numbers >> n)
    {
        getline(numbers, noop, ',');
        cerr << "DEBUG: n=" << n << endl;
        sum += n;
        cnt++;
    }

    if (cnt == 0)
    {
        return 0;
    }

    return sum / (float)cnt;
}

float averagePerStudent(const string &student, const string &course, string &error)
{
    string path = "lab08/data/";
    path.append(student);
    path.append(".csv");

    cerr << "DEBUG: path=" << path << endl;

    ifstream fin(path);
    if (fin.fail())
    {
        error = "cannot open file";
        return 0;
    }

    string line;
    while (getline(fin, line))
    {
        stringstream values(line);
        string id;
        getline(values, id, ',');
        id = id.substr(0, 7);

        cerr << "DEBUG: id=" << id << endl;

        if (id == course)
        {
            return averagePerLine(values);
        }
    }

    return 0;
}

int test(string input, float expected)
{
    stringstream numbers(input);
    float result = averagePerLine(numbers);
    cerr << "DEBUG: "
         << "test("
         << input
         << ")="
         << result << endl;

    return abs(result - expected) < 0.00000001;
}

int main()
{
    assert(test("6  , 5", 5.5));
    assert(test("6,5", 5.5));
    assert(test("6", 6));
    assert(test("", 0));
    assert(test("5,5", 5));

    string course;
    cin >> course;

    string student;
    float sum = 0;
    int cnt = 0;
    while (cin >> student)
    {
        string err;
        float avg = averagePerStudent(student, course, err);
        cerr << "DEBUG: avg=" << avg << endl;

        if (!err.empty())
        {
            cout << "ERROR: " << err << endl;
            continue;
        }

        sum += avg;
        cnt++;
    }

    cout << sum / cnt;

    return 0;
}