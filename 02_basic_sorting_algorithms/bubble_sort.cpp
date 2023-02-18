/*---------------------------------------------------------------------
 *                  code : bubble_sort
 *               @author :  Atul Uttam
 *          Date Created :  08-01-2023(04:58:58)
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

// sort the elements in increasing order
void bubbleSort(int a[], int n)
{
    for (int times = 1; times <= n - 1; times++)
    {
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);

    for (auto x : arr)
    {
        cout << x << ",";
    }
    cout<<endl;

    return 0;
}
