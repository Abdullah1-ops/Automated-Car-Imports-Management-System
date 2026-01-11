#include <iostream>
#include <iomanip>
using namespace std;

// Function for inspection result
bool inspectionCheck(int accuracy, string condition)
{
    if (accuracy >= 80 && condition != "Junk Car")
        return true;
    else
        return false;
}

int main()
{
    // ---- COMPANY INFO ----
    cout << "\t\tMr Ahad and Mr Abdullah Car Importers Islamabad\n";
    cout << "\t\t\tMake your decisions smart"<<endl;

    cout << fixed << setprecision(2);

    string country = "Germany";
    string company = "Mercedes";
    string model = "W210 (2001)";
    string carType, color, condition;

    int choice;
    double inspectionCost = 200;
    double importCharge = 0;
    double totalCost = 0;

    // ---- CAR TYPE ----
    cout << "Select Car Type:\n";
    cout << "1. Sedan\n";
    cout << "2. SUV\n";
    cout << "3. Hatchback\n";
    cout << "4. Mini Electric Car\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        carType = "Sedan";
        importCharge = 100;
        break;
    case 2:
        carType = "SUV";
        importCharge = 100;
        break;
    case 3:
        carType = "Hatchback";
        importCharge = 80;
        break;
    case 4:
        carType = "Mini Electric Car";
        importCharge = 50;
        break;
    default:
        cout << "Invalid car type.\n";
        return 0;
    }

    // ---- COLOR ----
    string colors[3] = {"Black", "White", "Silver"};
    cout << "\nSelect Car Color:\n";
    for (int i = 0; i < 3; i++)
        cout << i + 1 << ". " << colors[i] << endl;

    cin >> choice;
    if (choice < 1 || choice > 3)
    {
        cout << "Invalid color.\n";
        return 0;
    }
    color = colors[choice - 1];

    // ---- CONDITION ----
    cout << "\nSelect Car Condition:\n";
    cout << "1. Accidental\n";
    cout << "2. Total Genuine\n";
    cout << "3. Junk Car\n";
    cin >> choice;

    if (choice == 1)
        condition = "Accidental";
    else if (choice == 2)
        condition = "Total Genuine";
    else if (choice == 3)
        condition = "Junk Car";
    else
    {
        cout << "Invalid condition.\n";
        return 0;
    }

    // ---- INSPECTION DECISION ----
    string inspectDecision;
    cout << "\nDo you want an inspection of a car? (yes/no): ";
    cin >> inspectDecision;

    if (inspectDecision == "yes" || inspectDecision == "Yes" || inspectDecision == "YES")
    {
        cout << "\nInspection Cost: $200 (Non-refundable)\n";
        cout << "Inspection Time: 2 Days\n";

        int accuracy = 80;
        if (inspectionCheck(accuracy, condition))
        {
            cout << "Inspection Passed (80% Accurate)\n";
            totalCost += inspectionCost; // Add inspection cost
        }
        else
        {
            cout << "Inspection Failed. Car will not be imported.\n";
            return 0;
        }
    }
    else
    {
        cout << "Inspection skipped.\n";
    }

    // ---- COST CALCULATION ----
    double tax = 500, duty = 700, registration = 300, shipping = 500;
    double baseCost = tax + duty + registration + shipping;
    totalCost += baseCost + importCharge;

    // ---- DISCOUNT ----
    cout << "\nNote: You will get a 20% discount if the import year is before 2026.\n";
    int year;
    cout << "Enter Import Year: ";
    cin >> year;

    if (year < 2026)
    {
        totalCost -= totalCost * 0.20;
        cout << "20% Discount Applied\n";
    }
    else
    {
        cout << "No Discount Available\n";
    }

    // ---- SALE VALUE ----
    double saleValue;
    cout << "\nEnter Expected Sale Value: ";
    cin >> saleValue;

    if (saleValue < totalCost)
    {
        cout << "Sale value not good. Car will not be imported.\n";
        return 0;
    }

    // ---- DECISION BEFORE FINAL DETAILS ----
    char decision;
    cout << "\nAfter family discussion, import the car? (y/n): ";
    cin >> decision;

    bool importCar = false;
    if (decision == 'y' || decision == 'Y')
    {
        cout << "\n----- FINAL DECISION -----\n";
        cout << "Final: Car will be imported.\n";
        importCar = true;
    }
    else
    {
        cout << "\n----- FINAL DECISION -----\n";
        cout << "Final: Car will not be imported.\n";
        return 0;
    }

    // ---- CONFIRMATION FROM GERMANY COMPANY (USER 2) ----
    if (importCar)
    {
        string germanReply;
        cout << "\n--- Confirmation from Germany Company ---\n";
        cout << "Ask Germany Company: What are the final details of the car?\n";
        cout << "(Germany Company reply): ";
        cin.ignore(); // clear input buffer
        getline(cin, germanReply);

        if (germanReply == "OK" || germanReply == "ok" || germanReply == "Yeah OK" || germanReply == "yeah ok")
        {
            cout << "Germany Company approved. Press Enter to continue...\n";
            cin.get(); // wait for Enter
        }
        else
        {
            cout << "Germany Company did not approve. Car will not be imported.\n";
            return 0;
        }
    }

    // ---- FINAL DETAILS ----
    if (importCar)
    {
        double *ptrCost = &totalCost;

        cout << "\n----- FINAL CAR DETAILS -----\n";
        cout << "Car Type: " << carType << endl;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Country: " << country << endl;
        cout << "Color: " << color << endl;
        cout << "Condition: " << condition << endl;
        cout << "Arrival Port: Karachi\n";
        cout << "Total Cost: $" << *ptrCost << endl;

        // ---- PAYMENT METHOD ----
        cout << "\nPayment Method:\n";
        cout << "1. Easypaisa\n";
        cout << "2. JazzCash\n";
        cout << "3. Bank Transfer\n";

        int payChoice;
        cout << "\nEnter your preferred payment method (1-3): ";
        cin >> payChoice;

        string selectedPayment;
        if (payChoice == 1)
            selectedPayment = "Easypaisa";
        else if (payChoice == 2)
            selectedPayment = "JazzCash";
        else if (payChoice == 3)
            selectedPayment = "Bank Transfer";
        else
            selectedPayment = "Unknown";

        cout << "\nSelected Payment Method: " << selectedPayment << endl;
        cout << "Advance (50%): $" << (*ptrCost) * 0.50 << endl;
        cout << "Remaining (50%): $" << (*ptrCost) * 0.50 << endl;

        // ---- USER FEEDBACK ----
        string feedback;
        cin.ignore(); // clear input buffer
        cout << "\nUser Feedback:\n";
        cout << "What are your feedbacks about Mr AHAD And Mr ABDULLAH Car Importers Islamabad? ";
        getline(cin, feedback);

        // ---- FINAL MESSAGES ----
        cout << "\nOk, your car will arrive soon. THANK YOU for choosing us.\n";
        cout << "Company is always open for you. Here is our card.\n";
        cout<<"\t\t Mr AHAD AND MR ABDULLAH CAR IMPORTERS ISLAMABAD";
    }

    return 0;
}
