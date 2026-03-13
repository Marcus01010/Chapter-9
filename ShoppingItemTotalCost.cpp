#include
using namespace std;

class ShoppingItem
{
private:
string item_name;
float price;
int quantity;

public:
void set_item(string name, float prt, int qty)
{
item_name = name;

    if (prt > 0)
    {
        price = prt;
    }
    else
    {
        price = 0;
    }

    if (qty > 0)
    {
        quantity = qty;
    }
    else
    {
        quantity = 0;
    }
}

float get_total_cost()
{
    return price * quantity;
}

void display_bill()
{
    cout << "Item Name: " << item_name << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Cost: " << get_total_cost() << endl;
}
};

int main()
{
ShoppingItem item_1;

item_1.set_item("Milk", 2.5, 4);
item_1.display_bill();

return 0;
}
