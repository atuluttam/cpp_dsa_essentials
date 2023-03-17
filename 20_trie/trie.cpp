/*---------------------------------------------------------------------
 *                  code :  trie
 *               @author :  Atul Uttam
 *          Date Created :  17-03-2023(19:58:40)
 --------------------------------------------------------------------*/

#include <iostream>
#include "trie.hpp"
using namespace std;

int main()
{

    string words[] = {"mango", "apple", "man", "appl", "mang", "orange"};
    Trie t;

    // insert into into the trie
    for (auto word : words)
    {
        t.insert(word);
    }

    // searching
    string test;
    cin >> test;
    cout << t.search(test) << endl;
    return 0;
}
