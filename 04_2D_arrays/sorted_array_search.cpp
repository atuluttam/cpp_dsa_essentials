/*---------------------------------------------------------------------
 *                  code : sorted_array_search
 *               @author :  Atul Uttam
 *          Date Created :  22-01-2023(23:12:46)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;
// btuteforce approach will take O(n^2) time
// if the arra is sorted then we can use binary search tree O(nlog m)

// here in this case we can use a better approch call staircase search since the array is sorted both row wise and column wise

pair<int, int> staircaseSearch(int arr[][6], int rows, int cols, int key)
{
    // if the key is not present return {-1,-1}
    if (key < arr[0][0] or key > arr[rows - 1][cols - 1])
    {
        return {-1, -1};
    }
    int i = 0;
    int j = cols - 1;

    while (i <= rows - 1 and j >= 0)
    {
        if (arr[i][j] == key)
        {
            return {i, j};
        }
        else if (arr[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return {-1, -1};
}

int main()
{
    int arr[][6] = {{1, 2, 3, 4, 5, 6},
                    {7, 8, 9, 10, 11, 12},
                    {13, 14, 15, 16, 17, 18},
                    {19, 20, 21, 22, 23, 24},
                    {25, 26, 27, 28, 29, 30}};
    int rows = 5, cols = 6;
    int key = 28;
    pair<int, int> p = staircaseSearch(arr, rows, cols, key);
    cout << p.first << " " << p.second << "\n";
    return 0;
}
