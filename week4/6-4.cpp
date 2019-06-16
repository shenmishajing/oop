#include <iostream>

using namespace std;

class COMPUTER
{
    int    rank, voltage, volumn, speed;
    double frequency;

  public:
    COMPUTER(int rank, double frequency, int voltage, int volumn, int speed) :
        rank(rank),
        frequency(frequency),
        voltage(voltage),
        volumn(volumn),
        speed(speed)
    {
        cout << "create a CPU!\ncreate a RAM!\ncreate a CDROM!\ncreate a COMPUTER with para!\n";
    }
    COMPUTER() :
        rank(1),
        frequency(2),
        voltage(100),
        volumn(1),
        speed(16)
    {
        cout << "create a CPU!\ncreate a RAM!\ncreate a CDROM!\nno para to create a COMPUTER!\n";
    }
    COMPUTER(COMPUTER& c) :
        rank(c.rank),
        frequency(c.frequency),
        voltage(c.voltage),
        volumn(c.volumn),
        speed(c.speed)
    {
        cout << "create a CPU by copy!\ncreate a RAM by copy!\ncreate a CDROM by copy!\ncreate a COMPUTER by copy!\n";
    }
    ~COMPUTER()
    {
        cout << "destruct a COMPUTER!\ndestruct a CDROM!\ndesturct a RAM!\ndesturct a CPU!\n";
    }
    void showinfo()
    {
        cout << "cpu parameter:\nrank:" << rank << "\nfrequency:" << frequency << "\nvoltage:" << voltage << "\nram parameter:\nvolumn:" << volumn << " GB\ncdrom parameter:\nspeed:" << speed << "\n";
    }
};

/* 请在这里填写答案 */

int main()
{
    COMPUTER cpt1(6, 4.0, 200, 60, 32);    //测试带参数构造
    cout << "cpt1's parameter:" << endl;
    cpt1.showinfo();
    cout << "------------------------------" << endl;
    COMPUTER cpt2;    //测试不带参数构造
    cout << "cpt2's parameter:" << endl;
    cpt2.showinfo();
    cout << "------------------------------" << endl;
    COMPUTER cpt3(cpt1);    //测试复制构造
    cout << "cpt3's parameter:" << endl;
    cpt3.showinfo();
    cout << "------------------------------" << endl;
}
