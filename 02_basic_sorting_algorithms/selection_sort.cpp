/*---------------------------------------------------------------------
 *                  code : selection_sort   
 *               @author :  Atul Uttam     
 *          Date Created :  12-01-2023(01:52:07)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

void selectionSort(int a[], int n){

    for (int pos = 0; pos <= n-2; pos++)
    {
        int current = a[pos];
        int min_position = pos;
        for(int j=pos;j<n;j++){
            if (a[j]<a[min_position])
            {
                min_position =j;
            }
            
        }
        swap(a[min_position], a[pos]);
    }
    

}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    selectionSort(arr, n);

    for (auto x : arr)
    {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}
