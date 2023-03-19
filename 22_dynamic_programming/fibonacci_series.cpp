/*---------------------------------------------------------------------
 *                  code :  fibonacci_series
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(19:47:05)
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0 or n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << ",";
    }
    cout << endl;
    return 0;
}
