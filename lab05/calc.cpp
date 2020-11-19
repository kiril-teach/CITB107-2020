#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

float eval(string expr)
{
    float a, b;
    char op;

    stringstream ss(expr);

    ss >> a >> op >> b;
    if (ss.fail())
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