/*---------------------------------------------------------------------
 *                  code : inbuilt_sort_and_comparators   
 *               @author :  Atul Uttam     
 *          Date Created :  12-01-2023(03:00:31)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    int arr[] = {10, 25, 14, 87, 5, 0, 48, 89, 20, 6, 59, 7};
    int n = sizeof(arr) / sizeof(int);

    // sort(arr, arr + n, compare);
    reverse(arr, arr+n); 

    // sort(arr,arr+n, greater<int>());

    for (auto x : arr)
    {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}
