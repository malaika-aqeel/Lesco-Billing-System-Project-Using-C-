#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

string customerName;
string customerId;
string customerType;
int numMeters;

double slabRates[8] = {12.21, 14.53, 31.51, 38.41,
                       41.62, 43.04, 44.18, 49.10};

void registerCustomer();
void displayMenu();
double calculateConsumptionCharges(int units);
double calculateGST(double totalBeforeGST);
double calculateIncomeTax(double totalBeforeGST);
double calculateElectricityDuty(double consumptionCharges);
double calculateFixedCharges(int units);
void calculateNewConnectionCharges();
void displayFinalBill(int units);
void displayCustomerDetails();

void registerCustomer(){
    cout<<"=====Lesco customer registeration===="<<endl;
    cout << "Enter Customer Name   : ";
    cin >> customerName;

    cout << "Enter Customer ID   : ";
    cin >> customerId;

    cout<<"enter type(household press 1, commerical press 2";
    cin>>customerType;

    if(customerType=="1"){
        cout<<"houshold";
    }
    else if(customerType=="2"){
        cout<<"commerical";
    }
    else{
        cout<<"invalid";
    }

    cout << "Number of Meters Already Installed   :(frist press 1 second press 2)";
    cin >> numMeters;

    if(numMeters==1){
        cout<<"1st meter";
    }
    else if(numMeters==2){
        cout<<"2nd meter";
    }
    else{
        cout<<"invalid";
    }
}

void displayMenu(){
    cout << " =====LESCO MAIN MENU ======"<<endl;
    cout << "1. Calculate Monthly Electricity Bill"<<endl;
    cout << "2. Apply for New Electricity Connection"<<endl;
    cout << "3. View Customer Details"<<endl;
    cout << "4. Exit Program"<<endl;
    cout << "Enter your choice: ";
}

double calculateConsumptionCharges(int units){
    double total = 0.0;

    if (units <= 0) {
        return 0.0;
    }
    else if (units <= 100) {
        total = units * slabRates[0];
    }
    else if (units <= 200) {
        total  = 100 * slabRates[0];
        total += (units - 100) * slabRates[1];
    }
    else if (units <= 300) {
        total  = 100 * slabRates[0];
        total += 100 * slabRates[1];
        total += (units - 200) * slabRates[2];
    }
    else if (units <= 400) {
        total  = 100 * slabRates[0];
        total += 100 * slabRates[1];
        total += 100 * slabRates[2];
        total += (units - 300) * slabRates[3];
    }
    else if (units <= 500) {
        total  = 100 * slabRates[0];
        total += 100 * slabRates[1];
        total += 100 * slabRates[2];
        total += 100 * slabRates[3];
        total += (units - 400) * slabRates[4];
    }
    else if (units <= 600) {
        total  = 100 * slabRates[0];
        total += 100 * slabRates[1];
        total += 100 * slabRates[2];
        total += 100 * slabRates[3];
        total += 100 * slabRates[4];
        total += (units - 500) * slabRates[5];
    }
    else if (units <= 700) {
        total  = 100 * slabRates[0];
        total += 100 * slabRates[1];
        total += 100 * slabRates[2];
        total += 100 * slabRates[3];
        total += 100 * slabRates[4];
        total += 100 * slabRates[5];
        total += (units - 600) * slabRates[6];
    }
    else {
        total  = 100 * slabRates[0];
        total += 100 * slabRates[1];
        total += 100 * slabRates[2];
        total += 100 * slabRates[3];
        total += 100 * slabRates[4];
        total += 100 * slabRates[5];
        total += 100 * slabRates[6];
        total += (units - 700) * slabRates[7];
    }

    return total;
}

double calculateGST(double totalBeforeGST) {
    return totalBeforeGST * 0.18;
}

double calculateIncomeTax(double totalBeforeGST) {
    if (customerType == "Household") {
        return totalBeforeGST * 0.10;
    }
    else {
        return totalBeforeGST * 0.15;
    }
}

double calculateElectricityDuty(double consumptionCharges) {
    return consumptionCharges * 0.015;
}

double calculateFixedCharges(int units) {
    if (units <= 300)      return 0.0;
    else if (units <= 400) return 200.0;
    else if (units <= 500) return 400.0;
    else if (units <= 600) return 600.0;
    else if (units <= 700) return 800.0;
    else                   return 1000.0;
}

void calculateNewConnectionCharges() {
    double meterCost, meterCableCost, securityCost;
    double additionalCharges = 0.0;
    double newConnectionCost = 0.0;

    cout << "==New Connection Details=="<<endl;

    cout << "Enter Meter Cost : (Rs) ";
    cin >> meterCost;

    cout << "Enter Meter Cable Cost : (Rs) ";
    cin >> meterCableCost;

    cout << "Enter Security Cost (Rs) ";
    cin >> securityCost;

    if (customerType == "Household") {
        if (numMeters == 1) {
            additionalCharges = 2500.0;
        }
        else {
            additionalCharges = 5000.0;
        }
    }
    else {
        if (numMeters == 1) {
            additionalCharges = 35000.0;
        }
        else {
            additionalCharges = 70000.0;
        }
    }

    int newConnChoice;
    cout << "Applying for a brand new proper connection (1 or 2)"<<endl;
    cout << "Enter choice: ";
    cin >> newConnChoice;

    if (newConnChoice == 1) {
        newConnectionCost = 250000.0;
    }

    double totalCost = meterCost + meterCableCost +securityCost 
	+ additionalCharges +newConnectionCost;

    cout << fixed << setprecision(2);
    cout << "====== NEW CONNECTION CHARGES ======"<<endl;
    cout << "Total Connection Cost  : Rs " << totalCost << endl;
}

void displayFinalBill(int units) {
    double consumptionCharges = calculateConsumptionCharges(units);
    double electricityDuty    = calculateElectricityDuty(consumptionCharges);
    double fixedCharges       = calculateFixedCharges(units);
    double meterRent = 250.0;
    double tvFee = 35.0;

    double subTotal = consumptionCharges + electricityDuty +
                      fixedCharges + meterRent + tvFee;

    double gst = calculateGST(subTotal);
    double incomeTax = calculateIncomeTax(subTotal);

    double totalPayable = subTotal + gst + incomeTax;

    cout << fixed << setprecision(2);
    cout << "========== LESCO ELECTRICITY BILL =========="<<endl;
    cout << "Customer Name  : " << customerName << endl;
    cout << "Customer ID    : " << customerId << endl;
    cout << "Customer Type  : " << customerType << endl;
    cout << "Units Consumed : " << units << endl;

    cout << "Sub Total      : Rs " << subTotal << endl;
    cout << "GST 18%      : Rs " << gst << endl;
    cout << "Income Tax     : Rs " << incomeTax << endl;

    cout << "TOTAL PAYABLE  : Rs " << totalPayable << endl;
}

void displayCustomerDetails() {
    cout << "======== CUSTOMER DETAILS ========"<<endl;
    cout << "Customer Name   : " << customerName << endl;
    cout << "Customer ID     : " << customerId << endl;
    cout << "Customer Type   : " << customerType << endl;
    cout << "Meters Installed: " << numMeters << endl;
}

int main(){
    registerCustomer();

    int choice;

    do{
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            int units;
            cout << "Enter Units Consumed this month  ";
            cin >> units;

            while (units < 0) {
                cout << "Units cannot be negative. Re-entered ";
                cin >> units;
            }

            displayFinalBill(units);
        }
        else if (choice == 2) {
            calculateNewConnectionCharges();
        }
        else if (choice == 3) {
            displayCustomerDetails();
        }
        else if (choice == 4) {
            cout << "Thank you for using LESCO System"<<endl;
        }
        else {
            cout << "Invalid choice! Please enter 1-4"<<endl;
        }

    } while (choice != 4);

    return 0;
}








