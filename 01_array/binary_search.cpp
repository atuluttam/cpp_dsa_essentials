#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cout << "Enter key: ";
    cin >> key;

    int idx = BinarySearch(arr, n, key);
    if (idx == -1)
    {
        cout << "Key is missing" << endl;
    }
    else
    {
        cout << "The index of the key is: " << idx << endl;
    }

    return 0;
}
