/*---------------------------------------------------------------------
 *                  code : spiral_print
 *               @author :  Atul Uttam
 *          Date Created :  22-01-2023(17:37:45)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

void spiralPrint(int arr[][6],int rows, int cols){
    
    int startRow = 0;
    int startCol = 0;
    int endRow = rows-1;
    int endCol = cols-1;

    //outerloop (traverse array boundary)
    while (startCol<=endCol and startRow<=endRow)
    {
        //start row
        for (int col = startCol; col <= endCol; col++)
        {
            cout<<arr[startRow][col]<<" ";
        }
        //end col
        for (int row = startRow+1; row <= endRow; row++)
        {
            cout<<arr[row][endCol]<<" ";
        }
        //end row
        for (int col = endCol-1; col >= startCol; col--)
        {
            if (startRow == endRow)
            {
                break;
            }
            cout<<arr[endRow][col]<<" ";
        }
        //startcol
        for (int row = endRow-1; row >= startRow+1; row--)
        {
            if (startCol == endCol)
            {
                break;
            }
            cout<<arr[row][startCol]<<" ";
        }
        startRow++;
        startCol++;
        endRow--;
        endCol--;
        
    }
     
    
}

int main()
{ 
    int arr[][6] = { {1, 2, 3, 4, 5, 6},
                    {7, 8, 9, 10, 11, 12},
                    {13, 14, 15, 16, 17, 18},
                    {19, 20, 21, 22, 23, 24},
                    {25, 26, 27, 28, 29, 30} };
    int rows = 5, cols = 6; 
    spiralPrint(arr,rows,cols);

    return 0;
}
