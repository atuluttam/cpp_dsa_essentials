/*---------------------------------------------------------------------
 *                  code : subsets
 *               @author :  Atul Uttam
 *          Date Created :  05-02-2023(01:42:51)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

void findSubsets(char *input, char *output, int i, int j)
{
    // base  case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        // if (output[0] == '\0')
        // {
        //     cout << "NULL";
        // }
        cout <<"{"<< output <<"}" <<endl;
        return;
    }
    // rec case
    // include the i_th letter
    output[j] = input[i];
    findSubsets(input, output, i + 1, j + 1);
    // exclude the i_th letter
    findSubsets(input, output, i + 1, j);
}

int main()
{
    char input[100];
    char output[100];

    cin >> input;
    findSubsets(input, output, 0, 0);
    return 0;
}
