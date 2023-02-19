/*---------------------------------------------------------------------
 *                  code : sorted_array_check   
 *               @author :  Atul Uttam     
 *          Date Created :  29-01-2023(16:48:11)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

//first method
bool isSorted(int arr[], int n){
    if(n==1 or n==0) return true;
    if (arr[0] <= arr[1] and isSorted(arr+1,n-1))
    {
        return true;
    }
    return false;
    
}
//second method
bool isSortedTwo(int arr[], int i, int n){
    if (i==n-1) return true;
    if(arr[i]<=arr[i+1] and isSortedTwo(arr,i+1,n))
    {
        return true;
    }
    return false;
    
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,12};
    int n = sizeof(arr)/sizeof(int);
    cout<<isSorted(arr,n)<<endl;
    cout<<isSortedTwo(arr,0,n)<<endl;
    return 0;
}
