#include <iostream>

using namespace std;
const double PI = 3.14;

class Shape {
public:
    virtual double getArea() = 0;

    virtual double getPerim() = 0;
};


class Rectangle : Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}

    double getArea() {
        return w * h;
    }

    double getPerim() {
        return 2 * (w + h);
    }
};

class Circle : Shape {
    double r;
public:
    Circle(double r) : r(r) {}

    double getArea() {
        return PI * r * r;
    }

    double getPerim() {
        return 2 * PI * r;
    }
};

/* ------请在这里填写答案 ------*/

int main() {
    Shape *p;
    int n;
    double w, h, r;
    scanf("%d", &n);
    switch (n) {
        case 1: {
            cin >> w >> h;
            Rectangle rect(w, h);
            cout << "area=" << rect.getArea() << endl;
            cout << "perim=" << rect.getPerim() << endl;
            break;
        }
        case 2: {
            cin >> r;
            Circle c(r);
            cout << "area=" << c.getArea() << endl;
            cout << "perim=" << c.getPerim() << endl;
            break;
        }
    }

    return 0;
}
