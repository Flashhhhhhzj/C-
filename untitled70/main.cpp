#include <iostream>
#include <string>
using namespace std;

// ---------------------Base Class to store and manage basic personal information------------------------------------
class Person {
protected:
    string name;            // Stores the individual's name
    int dayOfBirth;         // Stores the day of birth
    int monthOfBirth;       // Stores the month of birth
    int yearOfBirth;        // Stores the year of birth

public:
    // Method to set basic personal information
    void setBasicInfo(const string &newName, int day, int month, int year) {
        name = newName;             // Assign the new name
        dayOfBirth = day;           // Assign the day of birth
        monthOfBirth = month;       // Assign the month of birth
        yearOfBirth = year;         // Assign the year of birth
    }

    // Method to display basic personal information
    void displayBasicInfo() const {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
    }

    // Getter methods to access protected members
    int getYearOfBirth() const { return yearOfBirth; }
    int getMonthOfBirth() const { return monthOfBirth; }
    int getDayOfBirth() const { return dayOfBirth; }
};

// ---------------------Derived Class to store and manage additional personal information----------------------------
class PersonalInfo : public Person {
private:
    string idCardNo;        // Stores the individual's ID card number

public:
    // Method to set personal information
    void setPersonalInfo(const string &newName, const string &newIdCardNo, int day, int month, int year) {
        setBasicInfo(newName, day, month, year);  // Call base class method to set basic info
        idCardNo = newIdCardNo;                  // Assign the new ID card number
    }

    // Method to display the personal information
    void displayPersonalInfo() const {
        displayBasicInfo();                      // Call base class method to display basic info
        cout << "IC: " << idCardNo << endl;
    }

    // Friend function declaration to allow access to private members for input
    friend void inputPersonalInfo(PersonalInfo &info);
};

// Function to input personal information interactively from the user
void inputPersonalInfo(PersonalInfo &info) {
    string name, idCardNo;
    int day, month, year;

    // Prompt the user to enter name and IC number
    cout << "Input Personal Information:\n  Employee Information\n";
    cout << "    Your Name: ";
    getline(cin, name);          // Read the name including spaces
    cout << "    IC No.: ";
    getline(cin, idCardNo);      // Read the ID card number including spaces

    // Collect and validate the day of birth
    cout << "\n  Your Date of Birth Information\n";
    do {
        cout << "    Day: ";
        cin >> day;
        if (cin.fail() || day < 1 || day > 31) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid Day (1-31)." << endl;
        }
    } while (cin.fail() || day < 1 || day > 31);

    // Collect and validate the month of birth
    do {
        cout << "    Month: ";
        cin >> month;
        if (cin.fail() || month < 1 || month > 12) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid Month (1-12)." << endl;
        }
    } while (cin.fail() || month < 1 || month > 12);

    // Collect and validate the year of birth
    do {
        cout << "    Year: ";
        cin >> year;
        if (cin.fail() || year < 1900 || year > 2024) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid Year (1900-2024)." << endl;
        }
    } while (cin.fail() || year < 1900 || year > 2024);

    // Set the collected information in the PersonalInfo object
    info.setPersonalInfo(name, idCardNo, day, month, year);
}

// ---------------------Derived Class to store and manage service-related information--------------------------------
class ServiceInfo : public Person {
private:
    int dayAppointment;     // Stores the day of appointment
    int monthAppointment;   // Stores the month of appointment
    int yearAppointment;    // Stores the year of appointment
    double lastSalary;      // Stores the last drawn salary
    double totalAllowance;  // Stores the total allowance amount
    int yearOfService;      // Stores the calculated years of service

public:
    // Method to set the service information
    void setServiceInfo(int day, int month, int year, double newLastSalary, double newTotalAllowance) {
        dayAppointment = day;                     // Assign the day of appointment
        monthAppointment = month;                 // Assign the month of appointment
        yearAppointment = year;                   // Assign the year of appointment
        lastSalary = newLastSalary;               // Assign the last salary
        totalAllowance = newTotalAllowance;       // Assign the total allowance
        yearOfService = calculateYearOfService(year); // Calculate the years of service
    }

    // Method to display the service information
    void displayServiceInfo() const {
        cout << "Date of Appointment: " << dayAppointment << "/" << monthAppointment << "/" << yearAppointment << endl;
        cout << "Your Last Salary: " << lastSalary << endl;
        cout << "Total Allowance: " << totalAllowance << endl;
    }

    // Method to calculate the years of service from the appointment year to 2024
    int calculateYearOfService(int startYear) const {
        int currentYear = 2024;
        return currentYear - startYear;
    }

    // Getter methods to access private members
    int getYearAppointment() const { return yearAppointment; }
    int getMonthAppointment() const { return monthAppointment; }
    int getDayAppointment() const { return dayAppointment; }
    double getLastSalary() const { return lastSalary; }

    // Friend function declaration to allow access to private members for input
    friend void inputServiceInfo(ServiceInfo &info);
};

// Function to input service-related information interactively from the user
void inputServiceInfo(ServiceInfo &info) {
    int day, month, year;
    double lastSalary, totalAllowance;

    // Prompt the user to enter service details including appointment date
    cout << "\nInput Service and Wages Information\n  Service Information\n";
    cout << "    Set Appointment Date\n";

    // Collect and validate the day of appointment
    do {
        cout << "    Day: ";
        cin >> day;
        if (cin.fail() || day < 1 || day > 31) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid Day (1-31)." << endl;
        }
    } while (cin.fail() || day < 1 || day > 31);

    // Collect and validate the month of appointment
    do {
        cout << "    Month: ";
        cin >> month;
        if (cin.fail() || month < 1 || month > 12) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid Month (1-12)." << endl;
        }
    } while (cin.fail() || month < 1 || month > 12);

    // Collect and validate the year of appointment
    do {
        cout << "    Year: ";
        cin >> year;
        if (cin.fail() || year < 1900 || year > 2024) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid Year (1900-2024)." << endl;
        }
    } while (cin.fail() || year < 1900 || year > 2024);

    // Prompt the user to enter wages information
    cout << "\n  Set Wages Information\n";
    cout << "    Latest Salary: ";
    cin >> lastSalary;
    cout << "    Total Allowance: ";
    cin >> totalAllowance;

    // Set the collected information in the ServiceInfo object
    info.setServiceInfo(day, month, year, lastSalary, totalAllowance);
}

// -------------------------Class to handle pension calculation and display related information-----------------------
class PensionCalculator {
private:
    PersonalInfo personalInfo; // Instance of PersonalInfo to store personal data
    ServiceInfo serviceInfo;   // Instance of ServiceInfo to store service data

public:
    // Method to input both personal and service information
    void inputAllInfo() {
        inputPersonalInfo(personalInfo);  // Call to input personal info
        inputServiceInfo(serviceInfo);    // Call to input service info
    }

    // Method to display all information collected
    void displayAllInfo() const {
        personalInfo.displayPersonalInfo(); // Display personal info
        serviceInfo.displayServiceInfo();   // Display service info
    }

    // Method to calculate pension eligibility and amount
    void calculatePension() const {
        int pensionDay, pensionMonth, pensionYear;

        // Prompt the user to enter the intended pension date
        cout << "\nCalculate Pension Estimation:\n";
        displayAllInfo();
        cout << "\n  Enter Date of Pension\n";
        cout << "    Day: ";
        cin >> pensionDay;
        cout << "    Month: ";
        cin >> pensionMonth;
        cout << "    Year: ";
        cin >> pensionYear;

        // Calculate the age of the individual at the time of pension
        int ageYears = pensionYear - personalInfo.getYearOfBirth();
        int ageMonths = pensionMonth - personalInfo.getMonthOfBirth();
        if (ageMonths < 0 || (ageMonths == 0 && pensionDay < personalInfo.getDayOfBirth())) {
            ageYears -= 1;
            ageMonths += 12;
        }

        // Calculate total years and months of service at the time of pension
        int pensionServiceYears = pensionYear - serviceInfo.getYearAppointment();
        int monthDifference = pensionMonth - serviceInfo.getMonthAppointment();
        if (monthDifference < 0) {
            pensionServiceYears -= 1;
            monthDifference += 12;
        }
        int pensionServiceMonths = pensionServiceYears * 12 + monthDifference;

        cout << "\nYour service is: " << pensionServiceYears << " Years and " << monthDifference
             << " months (" << pensionServiceMonths << " months)\n";

        if (pensionServiceYears < 10 || ageYears < 40) {
            cout << "You are NOT eligible for a pension\n";
            if (pensionServiceYears < 10) {
                cout << "Your service is less than 10 years\n";
            }
            if (ageYears < 40) {
                cout << "Your age is below 40: " << ageYears << " years and " << ageMonths << " months\n";
            }
            return;
        }

        double pensionPerMonth = 0.00167 * pensionServiceMonths * serviceInfo.getLastSalary();
        double gratuity = 0.075 * pensionServiceMonths * serviceInfo.getLastSalary();

        cout << "\nYou are eligible for a pension\n";
        cout << "Pension per month: RM " << pensionPerMonth << endl;
        cout << "Gratuity: RM " << gratuity << endl;
    }
};

// -----------------------------Main function to run the pension calculator application--------------------------------
int main() {
    PensionCalculator peca;
    int choice;

    do {
        cout << "\nPension Eligibility and Calculation App (PECA)\n";
        cout << "1. Input Personal and Service Information\n";
        cout << "2. Display All Information\n";
        cout << "3. Calculate Pension\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1:
                peca.inputAllInfo();
                break;
            case 2:
                peca.displayAllInfo();
                break;
            case 3:
                peca.calculatePension();
                break;
            case 4:
                cout << "Exiting the application.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
