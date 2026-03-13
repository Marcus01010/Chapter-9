#include
using namespace std;

enum SlotStatus
{
EMPTY,
OCCUPIED,
RESERVED
};

class WarehouseSystem
{
private:
int shelf_units[4][5];
SlotStatus slot_status[4][5];
int shipped_units_per_day[7];
int total_units_in_warehouse;

public:
void initialize_system()
{
total_units_in_warehouse = 0;

    for (int day_index = 0; day_index < 7; day_index++)
    {
        shipped_units_per_day[day_index] = 0;
    }

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            shelf_units[row][col] = 0;
            slot_status[row][col] = EMPTY;
        }
    }
}

void display_shelf_map()
{
    cout << "\nShelf Map (E=EMPTY, O=OCCUPIED, R=RESERVED)\n";

    for (int row = 0; row < 4; row++)
    {
        cout << "Row " << row + 1 << ": ";

        for (int col = 0; col < 5; col++)
        {
            if (slot_status[row][col] == EMPTY)
            {
                cout << "E ";
            }
            else if (slot_status[row][col] == OCCUPIED)
            {
                cout << "O ";
            }
            else
            {
                cout << "R ";
            }
        }

        cout << endl;
    }
}

void reserve_slot(int row, int col)
{
    if (row < 0 || row >= 4 || col < 0 || col >= 5)
    {
        cout << "Invalid slot position!" << endl;
        return;
    }

    if (slot_status[row][col] == EMPTY)
    {
        slot_status[row][col] = RESERVED;
        cout << "Slot reserved successfully!" << endl;
    }
    else
    {
        cout << "Cannot reserve. Slot is not empty." << endl;
    }
}

void add_stock(int row, int col, int units)
{
    if (row < 0 || row >= 4 || col < 0 || col >= 5)
    {
        cout << "Invalid slot position!" << endl;
        return;
    }

    if (units <= 0)
    {
        cout << "Units must be greater than 0!" << endl;
        return;
    }

    if (slot_status[row][col] == OCCUPIED)
    {
        cout << "Cannot add stock. Slot already occupied!" << endl;
        return;
    }

    shelf_units[row][col] = units;
    slot_status[row][col] = OCCUPIED;
    total_units_in_warehouse += units;

    cout << "Stock added successfully! Units added: " << units << endl;
}

void ship_stock(int row, int col, int units, int day_number)
{
    if (row < 0 || row >= 4 || col < 0 || col >= 5)
    {
        cout << "Invalid slot position!" << endl;
        return;
    }

    if (day_number < 1 || day_number > 7)
    {
        cout << "Invalid day number! Use 1 to 7." << endl;
        return;
    }

    if (units <= 0)
    {
        cout << "Units must be greater than 0!" << endl;
        return;
    }

    if (slot_status[row][col] != OCCUPIED)
    {
        cout << "Cannot ship. Slot is not occupied!" << endl;
        return;
    }

    if (units > shelf_units[row][col])
    {
        cout << "Not enough stock in this slot!" << endl;
        return;
    }

    shelf_units[row][col] -= units;
    total_units_in_warehouse -= units;
    shipped_units_per_day[day_number - 1] += units;

    cout << "Shipped successfully! Units shipped: " << units << endl;

    if (shelf_units[row][col] == 0)
    {
        slot_status[row][col] = EMPTY;
    }
}

void display_weekly_shipping_report()
{
    cout << "\nWeekly Shipping Report\n";

    int total_shipped = 0;

    for (int day_index = 0; day_index < 7; day_index++)
    {
        cout << "Day " << day_index + 1 << " shipped: " << shipped_units_per_day[day_index] << endl;
        total_shipped += shipped_units_per_day[day_index];
    }

    cout << "Total shipped in week: " << total_shipped << endl;
    cout << "Total units currently in warehouse: " << total_units_in_warehouse << endl;
}

void find_best_shipping_day()
{
    int best_day_index = 0;
    int max_shipped = shipped_units_per_day[0];

    for (int day_index = 1; day_index < 7; day_index++)
    {
        if (shipped_units_per_day[day_index] > max_shipped)
        {
            max_shipped = shipped_units_per_day[day_index];
            best_day_index = day_index;
        }
    }

    cout << "Best shipping day: Day " << best_day_index + 1
         << " (shipped " << max_shipped << " units)" << endl;
}
};

int main()
{
WarehouseSystem warehouse;

warehouse.initialize_system();

warehouse.display_shelf_map();

warehouse.reserve_slot(0, 2);
warehouse.add_stock(0, 2, 50);

warehouse.add_stock(1, 1, 30);
warehouse.add_stock(2, 4, 20);

warehouse.ship_stock(0, 2, 10, 1);
warehouse.ship_stock(1, 1, 15, 4);

warehouse.display_shelf_map();
warehouse.display_weekly_shipping_report();
warehouse.find_best_shipping_day();

return 0;
}
