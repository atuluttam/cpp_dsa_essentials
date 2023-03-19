/*---------------------------------------------------------------------
 *                  code :  max_profit_wines_top_down
 *               @author :  Atul Uttam
 *          Date Created :  20-03-2023(01:10:24)
 --------------------------------------------------------------------*/

/*Given n wines in a row, with integers denoting the cost of each wine respectively.
 Each year you can sell the first or the last wine in the row. Let the initial profits
 from the wines be P1, P2, P3…Pn. In the Yth year, the profit from the ith wine will be Y*P[i].
 The goal is to calculate the maximum profit that can be earned by selling all the wines.
 */

#include <iostream>
using namespace std;

int wines(int dp[][10], int prices[], int left, int right, int year)
{
    if (left > right)
    {
        return 0;
    }
    // if a state is already filled
    if (dp[left][right] != 0)
    {
        return dp[left][right];
    }
    // recursive case
    int pick_left = year * prices[left] + wines(dp, prices, left + 1, right, year + 1);
    int pick_right = year * prices[right] + wines(dp, prices, left, right - 1, year + 1);

    return dp[left][right] = max(pick_right, pick_left);
}

int main()
{
    int prices[] = {2, 3, 5, 1, 4};
    int n = 5;
    int dp[10][10] = {0};

    cout << wines(dp, prices, 0, n - 1, 1) << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
