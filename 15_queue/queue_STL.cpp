/*---------------------------------------------------------------------
 *                  code : queue_STL
 *               @author :  Atul Uttam
 *          Date Created :  19-02-2023(02:08:00)
 --------------------------------------------------------------------*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
