/*---------------------------------------------------------------------
 *                  code : backtracking_vector   
 *               @author :  Atul Uttam     
 *          Date Created :  05-02-2023(01:34:43)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void fillArray(vector<int> &arr, int i, int n, int val)
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
    vector<int> arr(100,0);
    int n;
    cin >> n;
    fillArray(arr, 0, n, 1);
    printArray(arr, n);
    return 0;
}
