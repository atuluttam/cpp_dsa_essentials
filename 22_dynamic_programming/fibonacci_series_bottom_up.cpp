/*---------------------------------------------------------------------
 *                  code :  fibonacci_series_bottom_up
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(20:10:53)
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int fib(int n)
{
    int dp[n - 1] = {0};

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
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
