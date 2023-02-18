#include <iostream>
#include <string>
using namespace std;

void read_input(int *, int *, int *);
void assign_fees(int, int, int *, int[], int *, int[]);
void calc_fees(int, int, int *);
void print_sum(string[], int, int, string[], int, int);

// Define The Categories And Their Names
const string categories[] = {
    " ",
    "10km Men Open",
    "10km Women Open",
    "5km Men Open",
    "5km Women Open",
    "5km Family Fun Run Malaysian (2 Adults + 2 Kids 4 Years & above)"};

// Define The Fees For Each Category
const int fees[] = {50, 60, 70, 200, 240};

// Define The Distances For Each Category
const int distances[] = {5, 10};

// Define The Types And Their Names
const string types[] = {"", "Early Bird", "Normal"};

// Read Input From The User
void read_input(int *category, int *type, int *number_of_participants)
{
    // Print Out The Categories
    for (int i = 1; i <= 5; i++)
    {
        cout << "Category " << i << ": " << categories[i] << endl;
    }

    // Get The Category From The User
    cout << "Enter A Number To Select Category (Only 1 To 5): ";
    cin >> *category;
    cout << endl;

    // Check If The Category Is Valid
    if (*category < 1 || *category > 5)
    {
        cout << "Please input number between 1 to 5 only" << endl;
        return;
    }

    // Print Out The Types
    for (int i = 1; i <= 2; i++)
    {
        cout << types[i] << ": " << i << endl;
    }

    // Get the type from the user
    cout << "Enter a number to select Early Bird or Normal: ";
    cin >> *type;
    cout << endl;

    // Check if the type is valid
    if (*type < 1 || *type > 2)
    {
        cout << "Please input number between 1 or 2 only" << endl;
        return;
    }

    // Get the number of participants
    cout << "Enter number of participants: ";
    cin >> *number_of_participants;
    cout << endl;
}

void assign_fees(int category, int type, int *distance, const int distances[], int *fee, const int fees[])
{
    if (category == 1 || category == 2)
    {
        *distance = distances[1];

        if (type == 1)
        {
            *fee = fees[1];
        }

        else
        {
            *fee = fees[2];
        }
    }

    else if (category == 3 || category == 4)
    {
        *distance = distances[0];

        if (type == 1)
        {
            *fee = fees[0];
        }

        else
        {
            *fee = fees[1];
        }
    }

    else
    {
        *distance = distances[0];

        if (type == 1)
        {
            *fee = fees[3];
        }

        else
        {
            *fee = fees[4];
        }
    }
}

void calc_fees(int number_of_participants, int fee, int *sum)
{
    *sum = number_of_participants * fee;
}

void print_sum(const string categories[], int category, int number_of_participants, const string types[], int type, int sum)
{
    cout << "The Category That You Choose: " << categories[category] << endl;
    cout << "Number Of Participants: " << number_of_participants << endl;
    cout << "The Type That You Choose: " << types[type] << endl;
    cout << "The Total Sum: " << sum << endl;
}

int main(void)
{
    int category, type, distance, number_of_participants, fee, sum;
    read_input(&category, &type, &number_of_participants);
    assign_fees(category, type, &distance, distances, &fee, fees);
    calc_fees(number_of_participants, fee, &sum);
    print_sum(categories, category, number_of_participants, types, type, sum);
    return 0;
}