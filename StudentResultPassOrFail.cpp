#include
using namespace std;

class Student
{
private:
string student_name;
int marks;

public:
void set_student_data(string name, int m)
{
student_name = name;

    if (m >= 0 && m <= 100)
    {
        marks = m;
    }
    else
    {
        marks = 0;
    }
}

bool is_pass()
{
    return marks >= 40;
}

void display_result()
{
    cout << "Student Name: " << student_name << endl;
    cout << "Marks: " << marks << endl;
    cout << "Result: " << (is_pass() ? "PASS" : "FAIL") << endl;
}
};

int main()
{
Student student_1;

student_1.set_student_data("Asha", 55);
student_1.display_result();

return 0;
}
