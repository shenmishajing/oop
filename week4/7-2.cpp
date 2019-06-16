#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double x, y, r;
    cin >> r >> x >> y;
    cout << 20 * (x * y - r * r * 3.14159);
    return 0;
}
