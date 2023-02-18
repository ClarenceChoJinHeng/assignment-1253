#include <iostream>
#include <string>
using namespace std;

void read_input(int *, int *, int *);
void define_input(int, int, int, int, int *, int *);
void define_name(int, string *, int, string *);
void calc_sum(int *, int, int);
void print_sum(string, int, int, string, int, int, int);

void read_input(int *category, int *type, int *number_of_participants)
{
    cout << "Category 1: 10km Men Open" << endl;
    cout << "Category 2: 10km Women Open" << endl;
    cout << "Category 3: 5km Men Open" << endl;
    cout << "Category 4: 5km Women Open" << endl;
    cout << "Category 5: 5km Family Fun Run Malaysian (2 Adults + 2 Kids 4 Years & above)" << endl;
    cout << "Enter A Number To Select Category (Only 1 To 5): ";
    cin >> *category;

    if (*category < 1 || *category > 5)
    {
        cout << endl;
        cout << "Please Input Number Between 1 to 5 Only" << endl;
    }

    else
    {
        cout << endl;
        cout << "Early Bird: 1" << endl;
        cout << "Normal: 2" << endl;
        cout << "Enter A Number To Select Early Bird or Normal: ";
        cin >> *type;

        if (*type < 1 || *type > 2)
        {
            cout << endl;
            cout << "Please Input Number Between 1 Or 2 Only" << endl;
        }

        else
        {
            cout << endl;
            cout << "Enter Number Of Participants: ";
            cin >> *number_of_participants;
            cout << endl;
        }
    }
}

void define_name(int category, string *name, int type, string *type_name)
{
    if (category == 1)
    {
        *name = "10km Men Open";
    }

    else if (category == 2)
    {
        *name = "10km Women Open";
    }

    else if (category == 3)
    {
        *name = "5km Men Open";
    }

    else if (category == 4)
    {
        *name = "5km Women Open";
    }

    else
    {
        *name = "5km Family Fun Run Malaysian (2 Adults + 2 Kids 4 Years & above)";
    }

    if (type == 1)
    {
        *type_name = "Early Bird";
    }

    else
    {
        *type_name = "Normal";
    }
}

void define_input(int category, int ten_km, int five_km, int type, int *distance, int *fees)
{
    if (category == 1 || category == 2)
    {
        *distance = ten_km;

        if (type == 1)
        {
            *fees = 60;
        }

        else
        {
            *fees = 70;
        }
    }

    else if (category == 3 || category == 4 || category == 5)
    {
        *distance = five_km;

        if (category == 5 && type == 1)
        {
            *fees = 200;
        }

        else if (category == 5 && type == 2)
        {
            *fees = 240;
        }

        else if (category == 3 && category == 4 || type == 1)
        {
            *fees = 50;
        }

        else if (category == 3 && category == 4 || type == 2)
        {
            *fees = 60;
        }
    }
}

void calc_sum(int *sum, int fees, int number_of_participants)
{
    *sum = fees * number_of_participants;
}

void print_sum(string name, int category, int number_of_participants, string type_name, int type, int fees, int sum)
{
    cout << "The Category That You Choose: " << name << " "
         << "(" << category << ")" << endl;
    cout << "Number of participants: " << number_of_participants << endl;
    cout << "The Type That You Choose: " << type_name << " "
         << "(" << type << ")" << endl;
    cout << "One Person Participant Fees: "
         << "RM " << fees << endl;
    cout << "The Total Sum: "
         << "RM " << sum << endl;
}
int main(void)
{
    const int ten_km = 10;
    const int five_km = 5;
    string name, type_name;
    int category, distance, type, number_of_participants, fees, sum;
    read_input(&category, &type, &number_of_participants);
    define_name(category, &name, type, &type_name);
    define_input(category, ten_km, five_km, type, &distance, &fees);
    calc_sum(&sum, fees, number_of_participants); 
    print_sum(name, category, number_of_participants, type_name, type, fees, sum);







    return 0;
}
