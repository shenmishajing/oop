#include <iostream>
#include <cmath>

using namespace std;

class FS {

    static int gcd(int m, int n) {
        int c = n;
        while (m % n != 0)    //for(;m%n!=0;)
        {
            c = m % n;
            m = n;
            n = c;
        }

        return c;
    }

    static int lcm(int m, int n) {
        return m * n / gcd(m, n);
    }

    static pair<int, int> calculate(int fz, int fm) {
        if (!fz) {
            return pair<int, int>(0, 1);
        }
        int flag = 0;
        if (fz * fm < 0) {
            flag = 1;
        }
        fz = abs(fz);
        fm = abs(fm);
        int g = gcd(fz, fm);
        if (flag) {
            return pair<int, int>(-fz / g, fm / g);
        } else {
            return pair<int, int>(fz / g, fm / g);
        }
    }

public:
    int fz, fm;

    FS(int fz, int fm) : fz(fz), fm(fm) {
        pair<int, int> fs = calculate(fz, fm);
        this->fz = fs.first;
        this->fm = fs.second;
    };

    friend FS operator+(FS first, const FS &second) {
        int l = lcm(first.fm, second.fm);
        first.fz = first.fz * l / first.fm + second.fz * l / second.fm;
        first.fm = l;
        pair<int, int> fs = calculate(first.fz, first.fm);
        first.fz = fs.first;
        first.fm = fs.second;
        return first;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int fz, fm;
        scanf("%dz%dm", &fz, &fm);
        FS first(fz, fm);
        scanf("%dz%dm", &fz, &fm);
        FS second(fz, fm);
        first = first + second;
        cout << first.fz << "z" << first.fm << "m" << endl;
    }
}
