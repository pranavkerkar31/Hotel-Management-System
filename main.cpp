#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct LostItem
{
    int itemId;
    string itemName;
    string description;
    bool isClaimed;
    string claimant;
};

class HotelSystem
{
protected:
    string guest_name;
    string contact_no;
    string ID_proof;
    double room_price;
    string payment;
    string check_in_date;
    string check_out_date;
    string days;
    string tot_price;

public:
    void setGuestDetails()
    {
        cout << "Dear Sir/Madam, which room do you prefer: AC or Non-AC?" << endl;
        cout << "AC Room price is Rs 6000/-" << endl;
        cout << "Non-AC Room price is Rs 4000" << endl;

        string room_choice;
        cout << "Enter your room choice (AC/Non-AC): ";
        cin >> room_choice;

        if (room_choice == "AC")
        {
            room_price = 6000.0;
        }
        else if (room_choice == "Non-AC")
        {
            room_price = 4000.0;
        }
        else
        {
            cout << "Invalid room choice. Defaulting to Non-AC room." << std::endl;
            room_price = 4000.0;
        }

        cout << "How would you like to pay, Sir/Madam?" << endl;
        cout << "If paying by Online payment, specify the method. If by cash, mention 'Cash':";
        cin >> payment;

        cin.ignore();

        cout << "Enter Guest Name: ";
        getline(cin, guest_name);

        cout << "Enter Contact Number: ";
        getline(cin, contact_no);

        cout << "Enter ID Proof: ";
        getline(cin, ID_proof);

        cout << "How many nights would you like to stay?:";
        getline(cin, days);
        if (room_choice == "AC")
        {
            tot_price = to_string(stod(days)*6000);
        }
        else
        {
            tot_price = to_string(stod(days)*4000);
        }

        cout << "Enter Check-in Date and Time: ";
        getline(cin, check_in_date);

        cout << "Enter Check-out Date and Time: ";
        getline(cin, check_out_date);

        // Open a file in append mode to store guest details
        ofstream outFile("guest_details.txt", ios::app);

        if (outFile.is_open())
        {
            // Write guest details to the file
            outFile << "Guest Name: " << guest_name << "\n";
            outFile << "Contact Number: " << contact_no << "\n";
            outFile << "ID Proof: " << ID_proof << "\n";
            outFile << "Check-in Date and Time: " << check_in_date << "\n";
            outFile << "Check-out Date and Time: " << check_out_date << "\n";
            outFile << "Room Price: Rs " << tot_price << "/-\n";
            outFile << "-------------------------\n";

            outFile.close();
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }

        cout << "Great, your room reservation has been recorded" << endl;
    }

    void printDetails()
    {
        cout << "\t\t\t\t\t\t\t\t\t-------Reservation Details---------------" << endl;
        cout << "\nGuest Details:\n";
        cout << "Guest Name: " << guest_name << endl;
        cout << "Contact Number: " << contact_no << endl;
        cout << "ID Proof: " << ID_proof << endl;
        cout << "Check-in Date and Time: " << check_in_date << endl;
        cout << "Check-out Date and Time: " << check_out_date << endl;
        cout << "Room Price: Rs " << tot_price << "/-" << endl;
    }
};

class Facilities
{
public:
    int n;

    void access()
    {
        do
        {
            cout << "Assuming Guest has Booked a Room" << endl;
            cout << "Please Enter which facility you want to choose:\n";
            cout << "1. Playground\n";
            cout << "2. Gym\n";
            cout << "3. Pool\n";
            cout << "Enter your choice: ";
            cin >> n;

            switch (n)
            {
            case 1:
                cout << "You have chosen the playground.\n";
                cout << "The playground is open from 6 AM to 10 PM.\n";
                cout << "You can enjoy various games and activities such as cricket, football, badminton, etc.\n";
                break;
            case 2:
                cout << "You have chosen the gym.\n";
                cout << "The gym is open from 5 AM to 11 PM.\n";
                cout << "You can use various equipment and machines such as treadmill, elliptical, dumbbells, etc.\n";
                break;
            case 3:
                cout << "You have chosen the pool.\n";
                cout << "The pool is open from 7 AM to 9 PM.\n";
                cout << "You can swim, relax, or have fun in the pool.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        } while (n != 4);
    }
};

class Meals
{
public:
    void Breakfast_menu()
    {
        cout << "(1) Plain Egg.............Rs30\n"
             << "(2) Bacon and Egg.........Rs245\n"
             << "(3) Muffin.................Rs99\n"
             << "(4) French Toast...........Rs99\n"
             << "(5) Fruit Basket...........Rs249\n"
             << "(6) Cereal.................Rs69\n"
             << "(7) Coffee.................Rs20\n"
             << "(8) Tea....................Rs15\n";
    }

    void Lunch_menu()
    {

        cout << "(1) Chicken Biryani..........Rs200/-\n"
             << "(2) Chicken Gravy............Rs160/-\n"
             << "(3) Paneer Masala............Rs200/-\n"
             << "(4) Roti, Naan...............Rs10/-\n"
             << "(5) Juices...................Rs15/-\n"
             << "(6) Fish Thali...............Rs200/-\n"
             << "(7) Pav Bhaji................Rs140/-\n"
             << "(8) Beer.....................Rs250/-\n";
    }

    void Evening_menu()
    {
        cout << "(1)Pizza-----------------Starting from Rs200/-" << endl;
        cout << "(2Burger-----------------Starting from Rs200/-" << endl;
        cout << "(3)Tea and Coffee-----------------Rs15/-" << endl;
    }

    void Dinner_menu()
    {
        cout << "(1)Chicken Biryani-----------------Rs200only.\n"
             << "(2)Chicken Pulao------------------Rs200 only.\n"
             << "(3)Chinese Rice----------------------Rs170 only.\n"
             << "(4)Chicken Borgir----------------------Rs100 only.\n"
             << "(5)Nawabi Pizza----------------------Rs200 only.\n"
             << "(6)2.5 Litre Coke-------------------Rs50 only." << endl;
    }
    void placeMealOrder()
    {
        int mealChoice;
        Meals meals;

        cout << "Please choose a meal category:\n";
        cout << "1. Breakfast\n";
        cout << "2. Lunch\n";
        cout << "3. Evening Snacks\n";
        cout << "4. Dinner\n";
        cout << "Enter your choice: ";
        cin >> mealChoice;

        cin.ignore();

        switch (mealChoice)
        {
        case 1:
            cout << "\t\t\t\t\t\t\t\t\t\t------Breakfast Menu------\n";
            meals.Breakfast_menu();
            break;

        case 2:
            cout << "\t\t\t\t\t\t\t\t\t\t-------Lunch Menu-------\n";
            meals.Lunch_menu();
            break;

        case 3:
            cout << "\t\t\t\t\t\t\t\t\t\t-------Evening Snacks Menu-------\n";
            meals.Evening_menu();
            break;

        case 4:
            cout << "\t\t\t\t\t\t\t\t\t\t-------Dinner Menu-------\n";
            meals.Dinner_menu();
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            return;
        }

        string ordermeal;
        cout << "Enter the item number you would like to order: ";
        getline(cin, ordermeal);
        cout << "Order placed successfully!\n";
    }
};

class Staff
{
protected:
    string roles;
    string name;
    string working_hours;

public:
    void staff_details()
    {
        cout << "Enter name:";
        getline(cin, name);
        cout << "Enter Role of the Worker:" << endl;
        getline(cin, roles);
        cout << "Enter working hours:" << endl;
        getline(cin, working_hours);
    }

    void printstaff()
    {
        cout << "Staff name:" << name << endl;
        cout << "Staff Role:" << roles << endl;
        cout << "Staff Working Hours:" << working_hours << endl;
    }
};

class Lost
{
private:
    vector<LostItem> lostItems;
    int nextItemId = 1;

public:
    void reportLostItem()
    {
        LostItem newItem;
        newItem.itemId = nextItemId;

        cout << "Enter the name of the lost item: ";
        cin.ignore();
        getline(cin, newItem.itemName);

        cout << "Enter a description of the lost item: ";
        getline(cin, newItem.description);

        newItem.isClaimed = false;
        newItem.claimant = "";

        lostItems.push_back(newItem);
        cout << "Lost item reported. Item ID: " << nextItemId << ", Name: " << newItem.itemName << endl;
        nextItemId++;
        cout << "Don't worry Sir/Madam, will contact you as soon as we get any news..." << endl;
    }
};

int main()
{
    HotelSystem hotel;
    Staff staff;
    Lost lf;
    Meals m;
    int choice;

    cout << "\t\t\t\t\t\t\t\t-------WELCOME SIR/MADAM TO OUR HOTEL------" << endl;

    do
    {
        cout << "Press 1 for Booking a Room" << endl;
        cout << "Press 2 for Knowing the Facilities and their Timings to use" << endl;
        cout << "Press 3 for having Food" << endl;
        cout << "Enter 4 for Staff Management" << endl;
        cout << "Enter 5 for to report a Lost Item" << endl;
        cout << "Enter 6 to Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\t\t\t\t\t\t\t\t\t\t------GOOD EVENING SIR/MADAM------\n";
            hotel.setGuestDetails();
            hotel.printDetails();
            break;

        case 2:
            cout << "\t\t\t\t\t\t\t\t\t\t------FACILITIES------\n";
            Facilities().access();
            break;

        case 3:
            cout << "\t\t\t\t\t\t\t\t\t\t------MEALS------\n";
            m.placeMealOrder();
            break;

        case 4:
            cout << "\t\t\t\t\t\t\t\t\t\t------STAFF DETAILS------\n";
            staff.staff_details();
            staff.printstaff();
            break;

        case 5:
            cout << "\t\t\t\t\t\t\t\t\t\t------Report Lost Items Center------\n";
            cout << " Report a lost item\n";
            lf.reportLostItem();
            break;

        case 6:
            cout << "Exiting the Hotel Management System. Thank you!" << endl;
            break;

        default:
            cout << "Enter correct option.." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
