#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    cin >> a >> b;
    while (!cin.fail())
    {
        int max = -100;
        if (a + b < 100 && a + b > max)
        {
            max = a + b;
        }
        if (a - b < 100 && a - b > max)
        {
            max = a - b;
        }
        if (b - a < 100 && b - a > max)
        {
            max = b - a;
        }
        if (a * b < 100 && a * b > max)
        {
            max = a * b;
        }

        cout << max << endl;
        cin >> a >> b;
    }

    return 0;
}
