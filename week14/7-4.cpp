#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (!(cin >> n).fail())
    {
        getchar();
        vector<string> arr;
        string         temp;
        for (size_t i = 0; i < n; i++)
        {
            getline(cin, temp);
            if (!temp.compare("stop"))
            {
                break;
            }
            arr.push_back(temp);
        }
        while (!arr.empty())
        {
            int min = 0;
            for (size_t i = 1; i < arr.size(); i++)
            {
                if (arr[i].length() < arr[min].length())
                {
                    min = i;
                }
            }
            cout << arr[min] << endl;
            arr.erase(arr.begin() + min);
        }
    }

    return 0;
}
