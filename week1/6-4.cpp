#include <iostream>
using namespace std;
const int N = 80;
struct Student
{
    int num;
    int score[4];
};

/* 请在这里填写答案 */

int select(struct Student *st, int n, bool (*s)(const Student &, const Student &))
{
    int cur = 0;
    for (auto i = 1; i < n; ++i)
    {
        if (s(st[cur], st[i]))
        {
            cur = i;
        }
    }
    return st[cur].num;
}
bool s2(const Student &a, const Student &b)
{
    return (a.score[0] + a.score[1] < b.score[0] + b.score[1]) || ((a.score[0] + a.score[1] == b.score[0] + b.score[1]) && (a.num >= b.num));
}
bool s4(const Student &a, const Student &b)
{
    return (a.score[0] + a.score[1] + a.score[2] + a.score[3] < b.score[0] + b.score[1] + b.score[2] + b.score[3]) || ((a.score[0] + a.score[1] + a.score[2] + a.score[3] == b.score[0] + b.score[1] + b.score[2] + b.score[3]) && (a.num >= b.num));
}

int main()
{
    int     i, j, k, n;
    bool    s2(const Student &, const Student &);
    bool    s4(const Student &, const Student &);
    Student st[N];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> st[i].num;
        for (j = 0; j < 4; j++) cin >> st[i].score[j];
    }
    cout << select(st, n, s2) << endl;
    cout << select(st, n, s4) << endl;
}
