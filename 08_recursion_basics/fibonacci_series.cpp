/*---------------------------------------------------------------------
 *                  code : fibonacci_series   
 *               @author :  Atul Uttam     
 *          Date Created :  29-01-2023(12:50:42)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

int fib(int n){
    if (n==1 or n==0)
    {
        return n;
    }
    return fib(n-1)+fib(n-2);
    
}

int main() {
    int n;cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
