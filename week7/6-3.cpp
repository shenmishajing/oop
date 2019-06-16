#include <iostream>
#include <string>

using namespace std;


class Animal {
public:
    void speak() {
        cout << "animal language!" << endl;
    }

};

class Cat : public Animal {
    string m_strName;
public:
    Cat(string m_strName) : m_strName(m_strName) {}

    void print_name() {
        cout << "cat name: " << m_strName << endl;
    }

};

/* 请在这里填写答案 */

int main() {
    Cat cat("Persian"); //定义派生类对象
    cat.print_name();    //派生类对象使用本类成员函数
    cat.speak();    //派生类对象使用基类成员函数
    return 0;
}
