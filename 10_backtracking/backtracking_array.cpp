/*---------------------------------------------------------------------
 *                  code : backtracking_array
 *               @author :  Atul Uttam
 *          Date Created :  05-02-2023(00:44:08)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void fillArray(int *arr, int i, int n, int val)
{

    // base case
    if (i == n)
    {
        printArray(arr, n);
        return;
    }
    // recursive case
    arr[i] = val;
    fillArray(arr, i + 1, n, val + 1);
    //backtracking step 
    arr[i] = -1 * arr[i];
}

int main()
{
    int arr[100] = {0};
    int n;
    cin >> n;
    fillArray(arr, 0, n, 1);
    printArray(arr, n);
    return 0;
}
