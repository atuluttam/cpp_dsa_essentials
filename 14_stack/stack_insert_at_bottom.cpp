/*---------------------------------------------------------------------
 *                  code : stack_insert_at_bottom   
 *               @author :  Atul Uttam     
 *          Date Created :  18-02-2023(02:40:34)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s,int data){
    //base case
    if(s.empty()) {
        s.push(data);
        return;
    }
    //recursive call
    int temp = s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    insertAtBottom(s,10);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
