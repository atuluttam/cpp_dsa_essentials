/*---------------------------------------------------------------------
 *                  code : copy_constructor
 *               @author :  Atul Uttam
 *          Date Created :  11-02-2023(01:47:07)
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
    // default copy constructor is present but we are overloading it here
    Product(Product &x)
    {
        id = x.id;
        strcpy(name, x.name);
        mrp = x.mrp;
        sellingPrice = x.sellingPrice;
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
    void showDetails()
    {
        cout << "name:" << name << endl;
        cout << "ID:" << id << endl;
        cout << "mrp:" << mrp << endl;
        cout << "selling price:" << sellingPrice << endl;
        cout<<"-----------------------------------"<<endl;
    }
};
int main()
{
    Product pen1;
    char name[100] = "Perker";
    Product pen2(1, 100, 200, name);

    // copy constructor -->initialization of a object with the copy of a other object of same class
    Product pen3(pen2);

    Product pen4 = pen2; //also a copy constructor

    pen1.showDetails();
    pen2.showDetails();
    pen3.showDetails();
    pen4.showDetails();
    // pen.id=112;
    // pen.setMrp(100);
    // pen.setSellingPrice(200);
    // cout << " MRP: " << pen2.getMrp() << endl;
    // cout << " Selling Price: " << pen2.getSellingPrice() << endl;

    return 0;
}
