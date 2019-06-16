#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string fir, string sec)
{
    return fir + sec >= sec + fir;
}

int main(int argc, char const *argv[])
{
    int n;
    while (!(cin >> n).fail())
    {
        vector<string> arr(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), compare);
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}
