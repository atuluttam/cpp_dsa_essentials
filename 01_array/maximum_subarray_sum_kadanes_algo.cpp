#include <iostream>
using namespace std;

// kadane's algo aproach O(n)
int MaximumSubarraySum(int arr[], int n)
{
    int largest = 0;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        largest = max(largest, curr_sum);
        // for (int j = i; j < n; j++)
        // {
        //     int subarray_sum = 0;
        //     for (int k = i; k <= j; k++)
        //     {
        //         subarray_sum += arr[k];
        //     }
        //     largest =  max(largest,subarray_sum);
        // }
    }
    return largest;
}
int main()
{
    int arr[] = {10, 20, 30, -40, 50, -60, 70, -80, -90};
    int n = sizeof(arr) / sizeof(int);

    cout << "largest subarray sum: " << MaximumSubarraySum(arr, n);
    return 0;
}