#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double x, y, a, b;
    cin >> a >> b >> x >> y;
    cout << "(" << a + x << ", " << b + y << ")\n";
    cout << "(" << a - x << ", " << b - y << ")\n";
    cout << "(" << x << ", " << y << ")\n";
    return 0;
}
