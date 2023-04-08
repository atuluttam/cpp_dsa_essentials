/*---------------------------------------------------------------------
 *                  code :  hash_table
 *               @author :  Atul Uttam
 *          Date Created :  17-03-2023(00:27:41)
 --------------------------------------------------------------------*/

#include <iostream>
#include "hash_table.hpp"
using namespace std;

int main()
{

    HashTable<int> h;
    h.insert("coffee", 100);
    h.insert("chai", 120);
    h.insert("soup", 140);
    h.insert("cold_drink", 200);
    h.insert("cold_coffee", 210);
    h.insert("masala_chai", 220);
    h.insert("coke", 300);
    h.insert("redbull", 344);

    h.print();

    string drink;
    cin >> drink;
    int *price = h.search(drink);
    if (price != nullptr)
    {
        cout << "price of " << drink << " is: " << *price << endl;
    }
    else
    {
        cout << "Drink is not available" << endl;
    }

    h["newDrink"] = 500;
    cout << "New drink cost : " << h["newDrink"] << endl;
    h["newDrink"] += 20;

    cout << "New drink updated cost : " << h["newDrink"] << endl;

    return 0;
}
