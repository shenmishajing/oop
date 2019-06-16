#include <iostream>
using namespace std;

/* 请在这里填写答案 */

void Swap(int &a, int &b)
{
    int temp = a;
    a        = b;
    b        = temp;
}

int main()
{
    int a, b;

    cin >> a >> b;

    Swap(a, b);

    cout << a << " " << b << endl;

    return 0;
}
