#include <iostream>

using namespace std;

template<class T>
class MyArray
{
    int size;
    T * data;

  public:
    bool check();

    void sort();

    void display();

    MyArray(int size);

    ~MyArray();
};

template<class T>
MyArray<T>::MyArray(int size) :
    size(size)
{
    data = new T[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> data[i];
    }
}

template<class T>
void MyArray<T>::sort()
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                T temp      = data[j];
                data[j]     = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template<class T>
void MyArray<T>::display()
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        cout << data[i] << " ";
    }
    cout << data[size - 1] << endl;
}

/* 请在这里填写答案 */

template<class T>
MyArray<T>::~MyArray()
{
    delete[] data;
}

template<class T>
bool MyArray<T>::check()
{
    int i;
    for (i = 0; i < size - 1; i++)
        if (data[i] > data[i + 1])
        {
            cout << "ERROR!" << endl;
            return false;
        }
    return true;
}

int main()
{
    MyArray<int> *  pI;
    MyArray<float> *pF;
    MyArray<char> * pC;
    int             ty, size;
    cin >> ty;
    while (ty > 0)
    {
        cin >> size;
        switch (ty)
        {
            case 1:
                pI = new MyArray<int>(size);
                pI->sort();
                pI->check();
                pI->display();
                delete pI;
                break;
            case 2:
                pF = new MyArray<float>(size);
                pF->sort();
                pF->check();
                pF->display();
                delete pF;
                break;
            case 3:
                pC = new MyArray<char>(size);
                pC->sort();
                pC->check();
                pC->display();
                delete pC;
                break;
        }
        cin >> ty;
    }
    return 0;
}
