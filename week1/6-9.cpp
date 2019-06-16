#include <iostream>

using namespace std;

int    myMax(int a, int b, int c = 0);
double myMax(double a, double b);

int main()
{
    cout << myMax(3, 4) << endl;
    cout << myMax(3, 4, 5) << endl;
    cout << myMax(4.3, 3.4) << endl;
}

#include <algorithm>
int myMax(int a, int b, int c)
{
    return std::max(a, std::max(b, c));
}
double myMax(double a, double b)
{
    return std::max(a, b);
}
