#include
using namespace std;

class PhoneBattery
{
private:
int battery_level;

public:
PhoneBattery()
{
battery_level = 50;
}

void charge(int amount)
{
    if (amount > 0)
    {
        battery_level += amount;

        if (battery_level > 100)
        {
            battery_level = 100;
        }
    }
}

void use_phone(int minutes)
{
    if (minutes > 0)
    {
        battery_level -= minutes;

        if (battery_level < 0)
        {
            battery_level = 0;
        }
    }
}

void display_battery()
{
    cout << "Battery Level: " << battery_level << "%" << endl;
}
};

int main()
{
PhoneBattery phone_1;

phone_1.display_battery();
phone_1.use_phone(20);
phone_1.display_battery();
phone_1.charge(40);
phone_1.display_battery();

return 0;
}

