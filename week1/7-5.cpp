#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int num[n];
    for (auto i = 0; i < n; ++i)
    {
        cin >> num[i];
    }

    for (auto i = n - 1; i >= 0; --i)
    {
        cout << num[i];
    }

    return 0;
}
