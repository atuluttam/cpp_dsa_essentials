/*---------------------------------------------------------------------
 *                  code : setters_getters
 *               @author :  Atul Uttam
 *          Date Created :  10-02-2023(16:49:26)
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
    int mrp;
    int sellingPrice;

public:
    void setMrp(int price)
    {
        if (price > 0)
            mrp = price;
    }
    void setSellingPrice (int price){
        if(price>mrp) sellingPrice=mrp;
        else sellingPrice=mrp;
    }
    int getMrp(){
        return mrp;
    }
    int getSellingPrice(){
        return sellingPrice;
    }

};
int main()
{
    Product pen;
    // pen.id=112;
    pen.setMrp(100);
    pen.setSellingPrice(200);
    cout<<" MRP: "<<pen.getMrp()<<endl;
    cout<<" Selling Price: "<<pen.getSellingPrice()<<endl;

    return 0;
}
