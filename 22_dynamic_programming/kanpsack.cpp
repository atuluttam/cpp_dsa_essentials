/*---------------------------------------------------------------------
 *                  code :  kanpsack
 *               @author :  Atul Uttam
 *          Date Created :  20-03-2023(00:30:50)
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

// top down approach (recurcive)
int knapsack(int wts[], int prices[], int totalItems, int totalWts)
{
    if (totalItems == 0 or totalWts == 0)
    {
        return 0;
    }

    int include = 0, exclude = 0;
    if (wts[totalItems - 1] <= totalWts)
    {
        include = prices[totalItems - 1] + knapsack(wts, prices, totalItems - 1, totalWts - wts[totalItems - 1]);
    }
    exclude = knapsack(wts, prices, totalItems - 1, totalWts);

    return max(include, exclude);
}

// bottom up dp
int knapsackDP(int wts[], int prices[], int totalItems, int totalWts)
{
    vector<vector<int>> dp(totalItems + 1, vector<int>(totalWts + 1, 0));

    for (int n = 1; n <= totalItems; n++)
    {
        for (int w = 1; w <= totalWts; w++)
        {
            int include = 0, exclude = 0;
            if (wts[n - 1] <= w)
            {
                include = prices[n - 1] + dp[n - 1][w - wts[n - 1]];
            }
            exclude = dp[n - 1][w];

            dp[n][w] = max(include, exclude);
        }
    }
    return dp[totalItems][totalWts];
}

int main()
{
    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};

    int totalItems = 4;
    int totalWts = 11;

    cout << knapsack(wts, prices, totalItems, totalWts) << endl;
    cout << knapsackDP(wts, prices, totalItems, totalWts) << endl;

    return 0;
}
