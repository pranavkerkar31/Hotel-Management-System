#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 
#include <limits>

using namespace std;

struct LostItem
{
    int itemId;
    string itemName;
    string description;
    bool isClaimed;
    string lostDate;
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
            tot_price = to_string(stod(days) * 6000);
        }
        else
        {
            tot_price = to_string(stod(days) * 4000);
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
        cout<<"---------------------------------------------------------------\n";
    }
};

class HotelCabService
{
protected:
    double ratePerKilometer;
    int numPassengers;
    string cabType;

public:
    HotelCabService(double rate) : ratePerKilometer(rate), numPassengers(0), cabType("Unknown") {}

    void useCabService()
    {
        double distance;
        string customerName, contactNumber;

        // Get customer information
        cin.ignore();
        cout << "Enter your name: ";
        getline(cin, customerName);

        cout << "Enter your contact number: ";
        getline(cin, contactNumber);

        // Get and validate distance
        cout << "Enter the distance to travel (in kilometers): ";
        cin >> distance;

        if (cin.fail() || distance <= 0)
        {
            cout << "Invalid input for distance. Please enter a valid numeric value.\n";
            cin.clear();                                              // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            return;
        }

        // Get and validate number of passengers
        cout << "Enter the number of passengers: ";
        cin >> numPassengers;

        if (cin.fail() || numPassengers <= 0)
        {
            cout << "Invalid input for the number of passengers. Please enter a valid numeric value.\n";
            cin.clear();                                              // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            return;
        }

        cin.ignore(); // Consume the newline character left in the buffer

        cout << "Enter the type of cab (e.g., Sedan, SUV, Luxury): ";
        getline(cin, cabType);

        // Calculate cab fare
        double cabFare = calculateCabFare(distance);

        // Generate receipt
        generateReceipt(customerName, contactNumber, distance, cabFare);
    }

private:
    double calculateCabFare(double distance)
    {
        // Additional charge for more passengers and different cab types can be added here
        return distance * ratePerKilometer;
    }

    void generateReceipt(const string &customerName, const string &contactNumber, double distance, double cabFare)
    {
        cout << "\n------------------- CAB SERVICE RECEIPT -------------------\n";
        cout << "Customer Name: " << customerName << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Distance Traveled: " << distance << " kilometers" << endl;
        cout << "Number of Passengers: " << numPassengers << endl;
        cout << "Cab Type: " << cabType << endl;
        cout << "Cab Fare: Rs " << fixed << setprecision(2) << cabFare << "/-" << endl;
        cout << "----------------------------------------------------------\n";
        cout << "Thank you for using our cab service!\n";
    }
};



class Facilities: public HotelCabService
{
public:
 Facilities() : HotelCabService(100.0) {}
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
            cout<<"  4.Hotel Cab Service"<<endl;
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

                case 4: useCabService();
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

    string order;
    int sum = 0;

    cout << "Enter the item number you want to have (enter 0 to finish ordering): ";
    getline(cin, order);

    while (order != "0")
    {
        int itemNumber = stoi(order); // Convert the string to integer

        switch (itemNumber)
        {
        case 1:
            sum += 30;
            cout << "Plain Egg ordered successfully!\n";
            break;
        case 2:
            sum += 245;
            cout << "Bacon and Egg ordered successfully!\n";
            break;
        case 3:
            sum += 99;
            cout << "Muffin ordered successfully!\n";
            break;
        case 4:
            sum += 99;
            cout << "French Toast ordered successfully!\n";
            break;
        case 5:
            sum += 249;
            cout << "Fruit Basket ordered successfully!\n";
            break;
        case 6:
            sum += 69;
            cout << "Cereal ordered successfully!\n";
            break;
        case 7:
            sum += 20;
            cout << "Coffee ordered successfully!\n";
            break;
        case 8:
            sum += 15;
            cout << "Tea ordered successfully!\n";
            break;
        default:
            cout << "Invalid item number. Please enter a valid item number.\n";
            break;
        }

        cout << "Enter the next item number you want to have (enter 0 to finish ordering): ";
        getline(cin, order);
    }

    // Print the final bill
    cout << "Your total bill is Rs" << sum << "/-." << endl;
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
        cout<<"------------------------------------------------"<<endl;
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
        string name, contactDetails;

        newItem.itemId = nextItemId;

        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your contact details: ";
        getline(cin, contactDetails);

        cout << "Enter the item you lost: ";
        getline(cin, newItem.itemName);

        cout << "Enter a description of the lost item: ";
        getline(cin, newItem.description);

        cout << "Enter the date the item was lost: ";
        // cin.ignore();
        getline(cin, newItem.lostDate);
        // nextItemId++;

        newItem.isClaimed = false;
        newItem.claimant = "";

        lostItems.push_back(newItem);

        cout << "Lost item reported. Item ID:" << nextItemId << endl;
        cout << "Name:" << name << endl;
        cout << "Contact Details:" << contactDetails << endl;
        cout << "Item:" << newItem.itemName << endl;
        cout<<"Description of the lost item:"<<newItem.description<<endl;
        nextItemId++;

        cout << "Don't worry Sir/Madam, we'll contact you as soon as we get any news..." << endl;
        cout<<"-----------------------------------------------------------------------------------------"<<endl;
    }

    void displayLostItems()
    {

        cout << "------\t\t\t Lost Items ------\n";
        for (const auto &item : lostItems)
        {
            cout << "Item ID: " << item.itemId << endl;
            cout << "Name: " << item.itemName << endl;
            cout << "Description: " << item.description << endl;
            cout << "Lost Date: " << item.lostDate << endl;

            if (item.isClaimed)
            {
                cout << ", Claimed by: " << item.claimant << endl;
            }
            else
            {
                cout << ",Not Claimed" << endl;
                cout<<"---------------------------------------------------\n";
            }
        }
    }
   void claimLostItem()
{
    int itemId;
    cout << "Enter the Item ID you want to claim (enter 0 to exit): ";
    cin >> itemId;

    while (itemId != 0)
    {
        bool itemFound = false;

        for (auto &item : lostItems)
        {
            if (item.itemId == itemId)
            {
                itemFound = true;

                if (!item.isClaimed)
                {
                    cout << "Item claimed successfully!\n";
                    item.isClaimed = true;
                    break; // Exit the loop once the item is claimed
                }
                else
                {
                    cout << "This item has already been claimed.\n";
                    break; // Exit the loop if the item is already claimed
                }
            }
        }

        if (!itemFound)
        {
            cout << "No item with ID " << itemId << " was reported.\n";
        }

        cout << "Enter the next Item ID to claim (enter 0 to exit): ";
        cin >> itemId;
    }
}

};

int main()
{
    HotelCabService cabService(100);
cabService.useCabService();

    HotelSystem h;
    Lost lf;
    Meals m;
    Facilities f;
    int choice;

    cout << "\t\t\t\t\t\t\t\t-------WELCOME SIR/MADAM TO OUR HOTEL------" << endl;

    do
    {
        cout << "Press 1 for Booking a Room" << endl;
        cout << "Press 2 for Knowing the Facilities and their Timings to use" << endl;
        cout << "Press 3 for having Food" << endl;
        cout << "Enter 4 for to report a Lost Item" << endl;
        cout << "Enter 5 to Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "\t\t\t\t\t\t\t\t\t\t------GOOD EVENING SIR/MADAM------\n";
            h.setGuestDetails();
            h.printDetails();
            break;

        case 2:
            cout << "\t\t\t\t\t\t\t\t\t\t------FACILITIES------\n";
            f.access();
      
            break;

        case 3:
            cout << "\t\t\t\t\t\t\t\t\t\t------MEALS------\n";
            m.placeMealOrder();
            break;

        case 4:
            int choice;
            cout << "\n--------------------- Lost and Found System ---------------------\n";
            do
            {
                cout << "1. Report a Lost Item\n";
                cout << "2. Display Lost Items\n";
                cout << "3. Claim a Lost Item\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                cin.ignore(); // Consume the newline character left in the buffer

                switch (choice)
                {
                case 1:
                    lf.reportLostItem();
                    break;

                case 2:
                    lf.displayLostItems();
                    break;

                case 3:
                    lf.claimLostItem();
                    break;

                case 4:
                    cout << "Exiting the Lost and Found System. Thank you!\n";
                    break;

                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }

            } while (choice != 4);
            break;

        case 5:
            cout << "Exiting the Hotel Management System. Thank you!" << endl;
            break;

        default:
            cout << "Enter correct option.." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}