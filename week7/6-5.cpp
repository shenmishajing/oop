#include <iostream>
#include <string>

using namespace std;

class Animal {
    int m_nWeightBase;
protected:
    int m_nAgeBase;
public:
    void set_weight(int nWeightBase) {
        m_nWeightBase = nWeightBase;
    }

    int get_weight() {
        return m_nWeightBase;
    }

    void set_age(int nAgeBase) {
        m_nAgeBase = nAgeBase;
    }
};

class Cat : private Animal {
    string m_strName;
public:
    Cat(string strName) : m_strName(strName) {}

    void print_age() {
        cout << m_strName << ", age = " << m_nAgeBase << endl;
    }

    void set_print_age() {
        set_age(5);
        print_age();
    }

    void set_print_weight() {
        set_weight(6);
        cout << m_strName << ", weight = " << get_weight() << endl;
    }
};

/* 请在这里填写答案 */

int main() {
    Cat cat("Persian");     //定义派生类对象cat
    cat.set_print_age();
    cat.set_print_weight(); //派生类对象调用自己的公有函数
    return 0;
}
