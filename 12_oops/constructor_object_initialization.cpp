/*---------------------------------------------------------------------
 *                  code : constructor_object_initialization
 *               @author :  Atul Uttam
 *          Date Created :  11-02-2023(01:26:13)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

class Product
{
    int id;
    char name[100];
    int mrp;
    int sellingPrice;

public:
    // constructor
    Product()
    {
        cout << "This is inside constructor" << endl;
    }
    // parameterized constructor also constructor overloading
    Product(int id, int mrp, int sellingPrice, char *name)
    {
        this->id = id;
        this->mrp = mrp;
        this->sellingPrice = sellingPrice;
        strcpy(this->name, name);
    }
    void setMrp(int price)
    {
        if (price > 0)
            mrp = price;
    }
    void setSellingPrice(int price)
    {
        if (price > mrp)
            sellingPrice = mrp;
        else
            sellingPrice = mrp;
    }
    int getMrp()
    {
        return mrp;
    }
    int getSellingPrice()
    {
        return sellingPrice;
    }
};
int main()
{
    Product pen1;
    char name[100] = "newname";
    Product pen2(1, 100, 200, name);
    // pen.id=112;
    // pen.setMrp(100);
    // pen.setSellingPrice(200);
    cout << " MRP: " << pen2.getMrp() << endl;
    cout << " Selling Price: " << pen2.getSellingPrice() << endl;

    return 0;
}
