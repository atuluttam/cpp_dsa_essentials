/*---------------------------------------------------------------------
 *                  code : stl_priority_queue   
 *               @author :  Atul Uttam     
 *          Date Created :  25-02-2023(19:40:24)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int marks[] = {90,80,12,13,15,56,94};
    int n = sizeof(marks) / sizeof(int);

    //by default the priority queue is max heap
    priority_queue<int> heap;

    for(int x:marks){
        heap.push(x);
    }

    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }

    return 0;
}
