#include <iostream>
using namespace std;

/* 请在这里填写答案 */

class Student
{
    int no, score;

  public:
    static int count;
    Student(int no, int score) :
        no(no),
        score(score) { count++; }
    Student(Student& c) :
        no(c.no + 1),
        score(c.score) { count++; }
    ~Student() { count--; }
    void display()
    {
        cout << no << (score ? " Pass" : " Fail") << endl;
    }
};

int Student::count = 0;

int main()
{
    const int size = 100;
    int       i, N, no, score;
    Student*  st[size];
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> no;
        if (no > 0)
        {
            cin >> score;
            st[i] = new Student(no, score);
        }
        else
            st[i] = new Student(*st[i - 1]);
    }
    cout << Student::count << " Students" << endl;
    for (i = 0; i < N; i++) st[i]->display();
    for (i = 0; i < N; i++) delete st[i];
    return 0;
}
