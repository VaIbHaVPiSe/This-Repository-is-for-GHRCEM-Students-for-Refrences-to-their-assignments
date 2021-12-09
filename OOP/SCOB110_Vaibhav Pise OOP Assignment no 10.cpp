#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Condition division by zero satisfied!";
    }
    return (a / b);
}

int main()
{
    int x = 9;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}
