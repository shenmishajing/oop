#include <iostream>
using namespace std;
template<class T>
T m(T, int);

int main()
{
    int ty, task;
    cin >> ty;
    while (ty != 0)
    {
        cin >> task;
        switch (ty)
        {
            case 1:
                cout << m(0, task) << endl;
                break;
            case 2:
                cout << m(0L, task) << endl;
                break;
            case 3:
                cout << m('0', task) << endl;
                break;
            case 4:
                cout << m(0.1, task) << endl;
        }
        cin >> ty;
    }
    return 0;
}
/* 请在这里填写答案 */
template<class T>
T m(T _, int task)
{
    T a, b;
    cin >> a >> b;
    if (task == 1)
    {
        return max(a, b);
    }
    else
    {
        return min(a, b);
    }
}
