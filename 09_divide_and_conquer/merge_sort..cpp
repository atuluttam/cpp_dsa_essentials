/*---------------------------------------------------------------------
 *                  code : merge_sort.
 *               @author :  Atul Uttam
 *          Date Created :  01-02-2023(01:25:21)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

// mere join
void merge(vector<int> &array, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;
    while (i <= m and j <= e)
    {
        if (array[i] < array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }
    // copy remaining element from first array
    while (i <= m)
    {
        temp.push_back(array[i++]);
    }
    // copy remaining element from second array
    while (j <= e)
    {
        temp.push_back(array[j++]);
    }
    // copy back the elements from temp to original
    int k = 0;
    for (int idx = s; idx <=e; idx++)
    {
        array[idx] = temp[k++];
    }
    return;
}

// sortin method
void mergeSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // reccurrence relation
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    return merge(arr, s, e);
}
int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size()-1;
    mergeSort(arr, s, e);
    for (int x : arr)
    {
        cout << x << " ,";
    }
    cout << endl;

    return 0;
}
