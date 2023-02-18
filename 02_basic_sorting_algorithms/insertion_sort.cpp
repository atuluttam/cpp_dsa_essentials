/*---------------------------------------------------------------------
 *                  code : insertion_sort
 *               @author :  Atul Uttam
 *          Date Created :  12-01-2023(01:22:59)
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

void insertionSort(int a[], int n)
{

    for (int i = 0; i <= n - 1; i++)
    {

        int current = a[i];
        int prev = i - 1;
        while (prev >= 0 and a[prev] > current)
        {
            a[prev + 1] = a[prev];
            prev = prev - 1;
        }

        a[prev + 1] = current;
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    insertionSort(arr, n);

    for (auto x : arr)
    {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}
