#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

bool parse(const string &expr, float &a, float &b, char &op)
{
    stringstream ss(expr);
    ss >> a >> op >> b;
    if (ss.fail())
    {
        return false;
    }
    return true;
}

float eval(const string &expr)
{
    float a, b;
    char op;

    bool ok = parse(expr, a, b, op);
    if (!ok)
    {
        cerr << "ERR: cannot parse expression " << expr << endl;
        return NAN;
    }

    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    else if (op == '/')
    {
        return a / b;
    }
    else
    {
        cerr << "ERR: unrecognized operator " << op << endl;
        return NAN;
    }
}

int main()
{
    string expr;
    while (getline(cin, expr))
    {
        float result = eval(expr);
        if (isnanf(result))
        {
            cout << "evaluation failed" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}