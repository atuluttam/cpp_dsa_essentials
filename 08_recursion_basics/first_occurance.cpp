/*---------------------------------------------------------------------
 *                  code : first_occurance
 *               @author :  Atul Uttam
 *          Date Created :  30-01-2023(22:45:43)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;
// first occurance of a element
int firstOcc(int arr[], int n, int key)
{
    if (n == 0)
        return -1;
    if (arr[0] == key)
        return 0;
    int temp_idx = firstOcc(arr + 1, n - 1, key);
    if (temp_idx != -1)
        return temp_idx + 1;

    return -1;
}
// last occurrance of a element
int lastOcc(int arr[], int n, int key)
{
    if (n == 0)
        return -1;

    int temp_idx = lastOcc(arr + 1, n - 1, key);
    if (temp_idx == -1)
    {
        if (arr[0] == key)
            return 0;
        else
            return -1;
    }
    else
        return temp_idx + 1;

}

int main()
{
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 8, 9, 12};
    int n = sizeof(arr) / sizeof(int);
    int key = 7;
    cout << firstOcc(arr, n, key) << endl;
    cout << lastOcc(arr, n, key) << endl;
    return 0;
}
