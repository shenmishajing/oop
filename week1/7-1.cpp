#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string str1, str2;
    double h = -1, l = 1000000000000;
    int    n;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        double cost;
        cin >> str >> cost;
        if (cost > h)
        {
            str1 = str;
            h    = cost;
        }

        if (cost < l)
        {
            str2 = str;
            l    = cost;
        }
    }

    printf("highest price: %.1f, ", h);
    cout << str1 << endl;

    printf("lowest price: %.1f, ", l);
    cout << str2 << endl;

    return 0;
}
