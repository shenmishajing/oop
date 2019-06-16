#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    cout << "year:" << str[0] << str[1] << str[2] << str[3] << endl;
    cout << "department:" << str[4] << str[5] << endl;
    cout << "class:" << str[6] << str[7] << endl;
    return 0;
}
