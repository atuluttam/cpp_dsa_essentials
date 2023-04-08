/*---------------------------------------------------------------------
 *                  code : recursively_reverse_stack   
 *               @author :  Atul Uttam     
 *          Date Created :  18-02-2023(02:52:13)       
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
void reverse(stack<int> &s){
    if(s.empty()) return;
    int temp=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // insertAtBottom(s,10);
    reverse(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
