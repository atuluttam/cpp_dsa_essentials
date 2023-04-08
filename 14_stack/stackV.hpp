/*---------------------------------------------------------------------
 *                  code : stackV
 *               @author :  Atul Uttam
 *          Date Created :  18-02-2023(02:18:43)
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
    vector<T> arr;

public:
    void push(T data)
    {
        arr.push_back(data);
    }
    void pop(){
        arr.pop_back();
    }
    T top()
    {
        int lastIdx = arr.size() - 1;
        return arr[lastIdx];
    }
    bool isEmpty()
    {
        return arr.size() == 0;
    }
};
