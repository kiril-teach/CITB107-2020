#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    
    float p = (a+b+c)/2;
    float area = sqrt(p*(p-a)*(p-b)*(p-c));

    cout << area << endl;

    return 0;
}