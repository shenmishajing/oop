#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int type;
    while (cin >> type, type != 0)
    {
        switch (type)
        {
            case 1:
            {
                int fir, sec;
                cin >> fir >> sec;
                cout << abs(fir - sec) << endl;
            }

            break;
            case 2:
            {
                double fir, sec;
                cin >> fir >> sec;
                cout << abs(fir - sec) << endl;
            }

            break;
            case 3:
            {
                double fir1, fir2, fir3, sec1, sec2, sec3;
                cin >> fir1 >> fir2 >> fir3;
                cin >> sec1 >> sec2 >> sec3;
                cout << sqrt(pow((fir1 - sec1), 2) + pow((fir2 - sec2), 2) + pow((fir3 - sec3), 2)) << endl;
            }

            break;

            default:
                break;
        }
    }

    return 0;
}
