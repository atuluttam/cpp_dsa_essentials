/*---------------------------------------------------------------------
 *                  code : counting_sort
 *               @author :  Atul Uttam
 *          Date Created :  12-01-2023(03:10:54)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

void countingSort(int a[], int n)
{
    int largest = -1;

    for (int i = 0; i < n; i++)
    {
        largest = max(largest, a[i]);
    }

    // create a count array/vector
    vector<int> freq(largest + 1, 0);
    // update the frequency array
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    // put back the elements from freq into original array
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            a[j] = i;
            freq[i]--;
            j++;
        }
    }
    return;
}

int main()
{
    int arr[] = {45, 2, 58, 9, 63, 4, 5, 89, 61, 25, 4};
    int n = sizeof(arr) / sizeof(int);
    countingSort(arr, n);

    for (auto x : arr)
    {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}
