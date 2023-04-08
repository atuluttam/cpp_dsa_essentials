/*---------------------------------------------------------------------
 *                  code : stl_priority_queue_custom_compare
 *               @author :  Atul Uttam
 *          Date Created :  25-02-2023(19:46:09)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{

    int marks[] = {90, 80, 12, 13, 15, 56, 94};
    int n = sizeof(marks) / sizeof(int);

    // by default the priority queue is max heap
    priority_queue<int, vector<int>, Compare> heap;

    for (int x : marks)
    {
        heap.push(x);
    }

    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }

    return 0;
}
