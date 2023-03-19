/*---------------------------------------------------------------------
 *                  code :  min_coin_change_problem
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(20:16:29)
 --------------------------------------------------------------------*/
/*
Problem: You are given an integer array coins representing coins of different denominations
and an integer amount representing a total amount of money.
Return the minimum number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// bottom up approach
int minCoinChange(int m, vector<int> denoms)
{
    vector<int> dp(m + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        dp[i] = INT_MAX;
        for (int c : denoms)
        {
            if (i - c >= 0 and dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[m] == INT_MAX ? -1 : dp[m];
}
int main()
{
    vector<int> denoms = {1, 5, 7, 10};
    int m = 8;

    cout << minCoinChange(m, denoms) << endl;
    return 0;
}
