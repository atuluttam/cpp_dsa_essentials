/*---------------------------------------------------------------------
 *                  code :  longest_increasing-subsequence
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(22:33:54)
 --------------------------------------------------------------------*/

/*Given an integer array nums, return the length of the longest strictly increasing
subsequence.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#include <iostream>
#include <vector>
using namespace std;

// bottom up solution
int LIS(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);

    int len = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(len, dp[i]);
            }
        }
    }
    return len;
}

int main()
{

    vector<int> arr{50, 4, 10, 8, 30, 100};
    cout << LIS(arr) << endl;

    return 0;
}
