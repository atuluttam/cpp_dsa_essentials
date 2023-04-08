/*---------------------------------------------------------------------
 *                  code : ordered_subsets   
 *               @author :  Atul Uttam     
 *          Date Created :  06-02-2023(01:06:07)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

bool compare(string a,string b){
    if (a.length()==b.length()){
        return a<b; //lexographic
    }
    return a.length()<b.length();
    
}

void findSubsets(char *input, char *output, int i, int j, vector<string> &list)
{
    // base  case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        string temp(output);
        list.push_back(temp);
        return;
    }
    // rec case
    // include the i_th letter
    output[j] = input[i];
    findSubsets(input, output, i + 1, j + 1,list);
    // exclude the i_th letter
    findSubsets(input, output, i + 1, j,list);
}

int main()
{
    char input[100];
    char output[100];

    cin >> input;
    vector<string> list;
    findSubsets(input, output, 0, 0,list);
    sort(list.begin(),list.end(),compare);

    for (auto &i : list)
    {
        cout<<"{"<<i<<"}"<<endl;
    }

    return 0;
}
