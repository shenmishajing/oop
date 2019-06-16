#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string str;

    getline(cin, str);

    int flag = 0;

    str[0] = toupper(str[0]);

    for (auto i = 1; i < str.length(); ++i)
    {
        if (str[i] == 'i' && flag && (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '.'))
        {
            str[i] = 'I';
            flag   = 0;
        }
        if (str[i] != 'I' && isupper(str[i]))
        {
            str[i] = tolower(str[i]);
            flag   = 0;
        }
        if (str[i] == '.')
        {
            str[i] = ',';
        }
        if (str[i] == ',' && i != str.length() - 1 && str[i + 1] != ' ')
        {
            str.insert(i + 1, " ");
        }

        if (flag && (str[i] == ' '))
        {
            str.erase(i, 1);
            i--;
            continue;
        }
        if (flag && (str[i] == ',' || str[i] == '.'))
        {
            str.erase(i - 1, 1);
            flag = 0;
            i--;
            continue;
        }
        if (isupper(str[i]) || islower(str[i]))
        {
            flag = 0;
        }
        if (str[i] == ' ')
        {
            flag = 1;
        }
    }

    str[str.length() - 1] = '.';

    cout << str;

    return 0;
}
