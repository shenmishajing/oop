#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int n, cur = 0;
    cin >> n;
    char str[] = "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";

    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < n - i - 1; ++j)
        {
            cout << " ";
        }

        for (auto j = 0; j < 2 * i + 1; ++j)
        {
            cout << str[cur++];
        }
        cout << endl;
    }
}
