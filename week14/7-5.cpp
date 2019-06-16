#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, w = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        min_heap.push(temp);
    }
    while (min_heap.size() > 1)
    {
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();
        w += a + b;
        min_heap.push(a + b);
    }
    cout << w << endl;

    return 0;
}
