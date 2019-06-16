#include <iostream>
using namespace std;
const int N = 21;

/* 请在这里填写答案 */

#include <stack>

bool test(int a[N][N], int i, int j)
{
    stack<int> st;
    st.push(i);
    int flag[N];
    for (auto k = 0; k < N; ++k)
    {
        flag[k] = 0;
    }

    flag[i] = -1;

    while (!st.empty())
    {
        if (flag[j] != 0)
        {
            break;
        }
        int c = st.top();
        st.pop();
        flag[c] = 1;
        for (auto k = 0; k < N; ++k)
        {
            if (a[c][k] && !flag[k])
            {
                st.push(k);
            }
        }
    }

    return flag[j] != 0;
}

int main()
{
    int a[N][N] = {0}, n, m, i, j, k;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> j >> k;
        a[j][k] = a[k][j] = 1;
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> j >> k;
        cout << j << '-' << k << ' ';
        if (test(a, j, k))
            cout << "connected" << endl;
        else
            cout << "disconnected" << endl;
    }
    return 0;
}
