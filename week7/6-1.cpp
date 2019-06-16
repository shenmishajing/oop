#include <iostream>
#include <string>

using namespace std;

class Animal
{
  protected:
    int age;

  public:
    Animal(int age) :
        age(age) {}
    int getAge() { return age; }
};

class Dog : public Animal
{
  protected:
    string color;

  public:
    Dog(int age, string color) :
        Animal(age),
        color(color) {}
    void showInfor()
    {
        cout << "age:" << age << endl;
        cout << "color:" << color << endl;
    }
};

/* 请在这里填写答案 */

int main()
{
    Animal ani(5);
    cout << "age of ani:" << ani.getAge() << endl;
    Dog dog(5, "black");
    cout << "infor of dog:" << endl;
    dog.showInfor();
}
