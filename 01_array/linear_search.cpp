#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
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

    int idx = LinearSearch(arr, n, key);
    if (idx == -1)
    {
        cout << "Key is missing"<<endl;
    }
    else
    {
        cout << "The index of the key is: " << idx<<endl;
    }

    return 0;
}
