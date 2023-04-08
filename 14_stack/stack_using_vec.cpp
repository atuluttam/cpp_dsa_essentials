/*---------------------------------------------------------------------
 *                  code : stack_using_vec   
 *               @author :  Atul Uttam     
 *          Date Created :  18-02-2023(02:22:52)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include "stackV.hpp"
using namespace std;

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
