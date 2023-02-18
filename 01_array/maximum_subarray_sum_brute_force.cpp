#include <iostream>
using namespace std;

// brute force aproach O(n^3)
int LargestSubarraySum(int arr[], int n)
{
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subarray_sum = 0;
            for (int k = i; k <= j; k++)
            {
                subarray_sum += arr[k];
            }
            largest =  max(largest,subarray_sum);
        }
    }
    return largest;
}
int main()
{
    int arr[] = {10, 20, 30, -40, 50, -60, 70, -80, -90};
    int n = sizeof(arr) / sizeof(int);

    cout<<"largest subarray sum: "<< LargestSubarraySum(arr, n);
    return 0;
}