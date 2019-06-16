#include <iostream>
#include <string>

using namespace std;

#include <vector>

class BigInt
{
    vector<int> num;

  public:
    BigInt()
    {
        num.resize(100, 0);
    }

    BigInt(BigInt &bigInt)
    {
        num = bigInt.num;
    }

    friend istream &operator>>(istream &in, BigInt &bigInt)
    {
        string str;
        in >> str;
        for (int i = str.length() - 1; i >= 0; --i)
        {
            bigInt.num[str.length() - 1 - i] = str[i] - '0';
        }

        return in;
    }

    friend ostream &operator<<(ostream &out, const BigInt &bigInt)
    {
        int i = 99;
        while (!bigInt.num[i]) { --i; }
        while (i >= 0)
        {
            out << bigInt.num[i];
            i--;
        }

        return out;
    }

    friend BigInt operator+(BigInt first, const BigInt &second)
    {
        int i = 0;
        while (i < 99)
        {
            first.num[i] += second.num[i];
            first.num[i + 1] += first.num[i] / 10;
            first.num[i] = first.num[i] % 10;
            ++i;
        }
        first.num[99] += second.num[99];
        first.num[99] = first.num[99] % 10;

        return first;
    }
};

/* 请在这里填写答案 */

int main()
{
    BigInt a, b, c;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cin >> a >> b;
    c = a + b;
    cout << a << "+" << b << "=" << c << endl;
    return 0;
}
