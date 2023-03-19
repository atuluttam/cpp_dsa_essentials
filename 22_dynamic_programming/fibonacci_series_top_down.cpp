/*---------------------------------------------------------------------
 *                  code :  fibonacci_series_top_down
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(20:03:54)
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp)
{
    if (n == 0 or n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << fib(i, dp) << ",";
    }
    cout << endl;
    return 0;
}
