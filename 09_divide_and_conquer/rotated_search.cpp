/*---------------------------------------------------------------------
 *                  code : rotated_search
 *               @author :  Atul Uttam
 *          Date Created :  03-02-2023(02:00:09)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector> 
#include <cstring>
#include <math.h>
using namespace std;

int rotated_search(vector<int> &arr, int key)
{
    int n = arr.size();

    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[start] <= arr[mid])
        {
            if (key >= arr[start] and key <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (key >= arr[mid] and key <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int key;
    cin >> key;
    cout << rotated_search(arr, key)<<endl;
    return 0;
}
