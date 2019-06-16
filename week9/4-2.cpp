#include<iostream>
#include<string>
using namespace std;

class Pet {
public:
    virtual string speak() const { return "pet!"; }
};
class Dog : public Pet {
public:
    string speak() const { return "dog!"; }
};
int main() {
    Dog ralph;
    Pet* p1 = &ralph;
    Pet& p2 = ralph;
    Pet p3;
    cout << p1->speak() <<endl;
    cout << p2.speak() << endl;
    cout << p3.speak() << endl;
    return 0;
}
