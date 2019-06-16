#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int    n, m, cur = 0;
    string str;
    cin >> str;

    n = str.length();

    if (n < 4)
    {
        cout << str[0];
        return 0;
    }

    m = n / 4;
    string st[m + 1];

    for (auto i = 0; i <= m; ++i)
    {
        for (auto j = 0; j <= m; ++j)
        {
            st[i].append(" ");
        }
    }

    for (auto i = 0; i < m; ++i)
    {
        st[0][i] = str[cur++];
    }
    for (auto i = 0; i < m; ++i)
    {
        st[i][m] = str[cur++];
    }
    for (auto i = 0; i < m; ++i)
    {
        st[m][m - i] = str[cur++];
    }
    for (auto i = 0; i < m; ++i)
    {
        st[m - i][0] = str[cur++];
    }

    for (auto i = 0; i <= m; ++i)
    {
        for (auto j = 0; j <= m; ++j)
        {
            cout << st[i][j];
        }
        cout << endl;
    }

    return 0;
}
