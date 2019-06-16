#include <iostream>
#include <string>

using namespace std;

class student
{
  public:
    int    number, height, weight;
    string name;

    student() { number = -1; }
};

int main(int argc, char *argv[])
{
    int     number, height, weight, n;
    string  name;
    student st[10000];

    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        cin >> number >> name >> height >> weight;
        if (st[number].number == -1 || st[number].height < height)
        {
            st[number].number=number;
            st[number].name=name;
            st[number].height=height;
            st[number].weight=weight;
        }
    }


    for (auto i = 0; i < 10000; ++i)
    {
        if (st[i].number != -1)
        {
            printf("%06d",st[i].number);
            cout<<" "<<
                st[i].name<<" "<<
                st[i].height<<" "<<
                st[i].weight<<endl;
        }
    }

    return 0;
}
