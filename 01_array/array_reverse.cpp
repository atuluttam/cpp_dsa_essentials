#include <iostream>
using namespace std;

void ReverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start = +1;
        end = -1;
    }
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(int);

    cout << "Before reversal: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    ReverseArray(arr, n);

    cout << "After reversal: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}