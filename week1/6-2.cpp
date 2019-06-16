#include <iostream>
using namespace std;

int max(int a, int b);
int min(int a, int b);
int sum(int a, int b);
int compute(int a, int b, int (*func)(int, int));

int main()
{
    int a, b, res;
    cin >> a >> b;
    res = compute(a, b, &max);
    cout << "Max of " << a << " and " << b << " is " << res << endl;
    res = compute(a, b, &min);
    cout << "Min of " << a << " and " << b << " is " << res << endl;
    res = compute(a, b, &sum);
    cout << "Sum of " << a << " and " << b << " is " << res << endl;
    return 0;
}

/* 请在这里填写答案 */
#include <algorithm>
int max(int a, int b)
{
    return std::max(a, b);
}
int min(int a, int b)
{
    return std::min(a, b);
}
int sum(int a, int b)
{
    return a + b;
}
int compute(int a, int b, int (*func)(int, int))
{
    return func(a, b);
}
