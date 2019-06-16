#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (2 * r < n)
    {
        sort(arr.begin() + r, arr.end() - r);
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1];

    return 0;
}
