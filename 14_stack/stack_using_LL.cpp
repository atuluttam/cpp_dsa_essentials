/*---------------------------------------------------------------------
 *                  code : stack_using_LL
 *               @author :  Atul Uttam
 *          Date Created :  18-02-2023(00:43:52)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include "stackll.hpp"
using namespace std;

int main()
{
    Stack<char> s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
