/*---------------------------------------------------------------------
 *                  code :  max_profit_wines_bottom_up
 *               @author :  Atul Uttam
 *          Date Created :  20-03-2023(01:50:36)
 --------------------------------------------------------------------*/

/*Given n wines in a row, with integers denoting the cost of each wine respectively.
 Each year you can sell the first or the last wine in the row. Let the initial profits
 from the wines be P1, P2, P3…Pn. In the Yth year, the profit from the ith wine will be Y*P[i].
 The goal is to calculate the maximum profit that can be earned by selling all the wines.
 */

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
using namespace std;

int wines(int prices[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = n * prices[i];
            }
            if (i < j)
            {
                int currYear = n - (j - i);
                int pick_left = currYear * prices[i] + dp[i + 1][j];
                int pick_right = currYear * prices[j] + dp[i][j - 1];

                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][n - 1];
}

int main()
{
    int prices[] = {2, 3, 5, 1, 4};
    int n = 5;

    cout << wines(prices, n) << endl;

    return 0;
}
