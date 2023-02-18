#include <iostream>
using namespace std;

// prefix aproach O(n^2)
int LargestSubarraySum(int arr[], int n)
{
    // prefix sum array
    int prefix_sum[n] = {0};
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subarray_sum = i > 0 ? prefix_sum[j] - prefix_sum[i - 1] : prefix_sum[j];
            // for (int k = i; k <= j; k++)
            // {
            //     subarray_sum += arr[k];
            // }
            largest = max(largest, subarray_sum);
        }
    }
    return largest;
}
int main()
{
    int arr[] = {10, 20, 30, -40, 50, -60, 70, -80, -90};
    int n = sizeof(arr) / sizeof(int);

    cout << "largest subarray sum: " << LargestSubarraySum(arr, n);
    return 0;
}