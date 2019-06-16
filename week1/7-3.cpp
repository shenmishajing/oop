#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    for (auto i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        if (m % 2)
        {
            cout << "0 0\n";
        }
        else
        {
            cout << m / 4 << " " << m / 2 << endl;
        }
    }

    return 0;
}
