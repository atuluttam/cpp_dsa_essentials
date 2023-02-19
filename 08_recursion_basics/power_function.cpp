/*---------------------------------------------------------------------
 *                  code : power_function
 *               @author :  Atul Uttam
 *          Date Created :  31-01-2023(00:04:28)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

// power function non optimized O(n)
long power(int a, int n)
{
    if (n == 0)
        return 1;
    return a * power(a, n - 1);
}

// power function optimized O(log n)
long fastPower(int a, int n)
{
    if (n == 0)
        return 1;
    long sub_prob = fastPower(a, n/2);
    long sub_prob_sq = sub_prob * sub_prob;
    if (n & 1) //check for even
        return a * sub_prob_sq;
    return sub_prob_sq;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    cout << fastPower(a, n) << endl;
    return 0;
}
