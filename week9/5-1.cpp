#include <iostream>
using namespace std;
class A {
public:

    void f() { cout << "A::f()\n"; }
};
class B: public A {
public:
    void f() {cout << "B::f()\n"; }
};
int main()
{
    B b;
    A &p = b;

    b.f();
    return 0;
}
