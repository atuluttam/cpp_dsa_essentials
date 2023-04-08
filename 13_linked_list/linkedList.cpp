/*---------------------------------------------------------------------
 *                  code : linkedList   
 *               @author :  Atul Uttam     
 *          Date Created :  12-02-2023(01:56:06)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include "list.hpp"
using namespace std;

int main() {

    List l; /*this is a static obect resides in main stack and at the end of the 
            program a this will get destroyed and resulting in the calling of the class destructor*/

    l.push_back(12);
    l.push_back(45);
    l.push_front(10);
    l.insert(20,0);
    l.insert(13,2);

    Node* head=l.begin();
    while (head!=nullptr)
    {
        cout<<head->getData()<<"->";
        head=head->next;
    }
    cout<<endl;
    int key;cin>>key;

    cout<<l.recursiveSearch(key)<<endl;

    cout<<endl;

    l.reverse(head);
    while (head!=nullptr)
    {
        cout<<head->getData()<<"->";
        head=head->next;
    }
    cout<<endl;

    return 0;
}
