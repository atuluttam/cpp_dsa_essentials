/*---------------------------------------------------------------------
 *                  code : stack_STL   
 *               @author :  Atul Uttam     
 *          Date Created :  18-02-2023(02:30:34)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    stack<string> s;
    s.push("Hello ");
    s.push("MY ");
    s.push("Name ");
    s.push("Is ");
    s.push("ATUL ");

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}
