#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    while (true)
    {
        int type;
        cin >> type;
        if (type == -1)
        {
            break;
        }
        switch (type)
        {
            case 1:
            {
                int temp, max;
                cin >> temp;
                max = temp;
                while (temp)
                {
                    if (temp > max)
                    {
                        max = temp;
                    }
                    cin >> temp;
                }
                cout << max << endl;
            }

            break;
            case 2:
            {
                double temp, max;
                cin >> temp;
                max = temp;
                while (temp)
                {
                    if (temp > max)
                    {
                        max = temp;
                    }
                    cin >> temp;
                }
                cout << max << endl;
            }

            break;
            case 3:
            case 4:
            {
                int temp1, temp2, temp3, max1, max2, max3;
                cin >> temp1 >> temp2 >> temp3;
                max1 = temp1;
                max2 = temp2;
                max3 = temp3;
                cin >> temp1;
                while (temp1)
                {
                    cin >> temp2 >> temp3;
                    if ((temp1 > max1) || (temp1 == max1 && (temp2 > max2 || (temp2 == max2 && (temp3 > max3)))))
                    {
                        max1 = temp1;
                        max2 = temp2;
                        max3 = temp3;
                    }
                    cin >> temp1;
                }
                cout << max1 << " " << max2 << " " << max3 << endl;
            }

            break;

            default:
                break;
        }
    }

    return 0;
}
