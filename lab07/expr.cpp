#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Expression
{
public:
    Expression()
    {
        parsed = false;
    }

    Expression(const string &input)
    {
        parse(input);
    }

    void parse(const string &input)
    {
        stringstream ss(input);
        ss >> x >> op >> y;
        if (ss.fail())
        {
            parsed = false;
        }
        else
        {
            parsed = true;
        }
    }

    float eval()
    {
        if (!valid())
        {
            return NAN;
        }

        if (op == '+')
        {
            return x + y;
        }
        else if (op == '-')
        {
            return x - y;
        }
        else if (op == '*')
        {
            return x * y;
        }
        else if (op == '/')
        {
            return x / y;
        }
        else
        {
            return NAN;
        }
    }

    bool valid()
    {
        return parsed;
    }

private:
    float x, y;
    char op;
    bool parsed;
};

int main()
{
    Expression expr("1.5*3");
    if (expr.valid())
    {
        cout << expr.eval() << endl;
    }
    else
    {
        cout << "invalid expression" << endl;
    }
    return 0;
}