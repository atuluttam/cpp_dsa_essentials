/*---------------------------------------------------------------------
 *                  code : Heap
 *               @author :  Atul Uttam
 *          Date Created :  25-02-2023(17:08:30)
 --------------------------------------------------------------------*/

#include <vector>
using namespace std;

// for node at i: right child at 2i, left child at 2i+1
// for a anode at i, the parent of i will be at i/2

class Heap
{
    vector<int> v;

    void heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;

        int midIdx = i;
        if (left < v.size() and v[left] < v[i])
        {
            midIdx = left;
        }
        if (right < v.size() and v[right] < v[midIdx])
        {
            midIdx = right;
        }
        if (midIdx != i)
        {
            swap(v[i], v[midIdx]);
            heapify(midIdx);
        }
    }

public:
    Heap(int default_size = 10)
    {
        v.reserve(default_size + 1);
        v.push_back(-1);
    };
    // insertion in the heap
    void push(int data)
    {
        // add data to the end of the heap
        v.push_back(data);

        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 and v[idx] < v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
    // return the min data
    int getMin()
    {
        return v[1];
    }
    // remove the min
    void pop()
    {
        // 1. swap first and last element
        int idx = v.size() - 1;
        swap(v[1], v[idx]);
        v.pop_back();
        heapify(1);
    }
    // check empty
    bool empty()
    {
        return v.size() == 1;
    }
};
