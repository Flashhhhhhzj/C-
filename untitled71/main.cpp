#include <iostream>
#include <string>
using namespace std;

// ----------------------- Class to Manage Personal Information -----------------------
class PersonalInfo
{
protected:
    // Data members to store personal details of the employee
    string name;         // Employee's full name
    string ic;           // Employee's identification card (IC) number
    int birthDay;        // Day of the employee's birth
    int birthMonth;      // Month of the employee's birth
    int birthYear;       // Year of the employee's birth

public:
    // Constructor to initialize personal details with default values
    PersonalInfo(string empName = "", string empId = "", int bDay = 0, int bMonth = 0, int bYear = 0)
            : name(empName), ic(empId), birthDay(bDay), birthMonth(bMonth), birthYear(bYear) {}

    // Getter and setter methods for name
    string getName() const { return name; }
    void setName(const string &n) { name = n; }

    // Getter and setter methods for IC number
    string getIc() const { return ic; }
    void setIc(const string &icc) { ic = icc; }

    // Getter and setter methods for birth day
    int getBirthDay() const { return birthDay; }
    void setBirthDay(int day) { birthDay = day; }

    // Getter and setter methods for birth month
    int getBirthMonth() const { return birthMonth; }
    void setBirthMonth(int month) { birthMonth = month; }

    // Getter and setter methods for birth year
    int getBirthYear() const { return birthYear; }
    void setBirthYear(int year) { birthYear = year; }

    // Friend function to input personal information of the employee
    friend void inputPersonalInfo(PersonalInfo &personalInfo);
};

// Function to input and validate personal information of the employee
void inputPersonalInfo(PersonalInfo &personalInfo)
{
    cout << "Input Personal Information:\n";

    // Input employee's full name
    cout << "Your Name: ";
    cin >> personalInfo.name;
    getline(cin, personalInfo.name);

    // Input employee's IC number
    cout << "IC No: ";
    cin >> personalInfo.ic;

    // Input and validate employee's year of birth (must be between 1900 and 2100)
    cout << "Your Date of Birth (Year): ";
    cin >> personalInfo.birthYear;
    while (personalInfo.birthYear < 1900 || personalInfo.birthYear > 2100)
    {
        cout << "Invalid Year. Please enter a valid year (between 1900 and 2100): ";
        cin >> personalInfo.birthYear;
    }

    // Input and validate employee's month of birth (must be between 1 and 12)
    cout << "Your Date of Birth (Month): ";
    cin >> personalInfo.birthMonth;
    while (personalInfo.birthMonth < 1 || personalInfo.birthMonth > 12)
    {
        cout << "Invalid Month. Please enter a valid month (1-12): ";
        cin >> personalInfo.birthMonth;
    }

    // Input and validate employee's day of birth based on the month
    cout << "Your Date of Birth (Day): ";
    cin >> personalInfo.birthDay;
    int MonthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (personalInfo.birthDay < 1 || personalInfo.birthDay > MonthDays[personalInfo.birthMonth])
    {
        cout << "Invalid Day. Please enter a valid day for the month: ";
        cin >> personalInfo.birthDay;
    }
    cout << "+---------------------------------------------------------------+\n";
}

// ----------------------- Class to Manage Service Information -----------------------
class ServiceInfo
{
protected:
    // Data members to store service details of the employee
    int appointDay;      // Day of appointment
    int appointMonth;    // Month of appointment
    int appointYear;     // Year of appointment
    double lastSalary;   // Last drawn salary by the employee
    double allowance;    // Total allowance received by the employee

public:
    // Constructor to initialize service details with default values
    ServiceInfo(int aDay = 0, int aMonth = 0, int aYear = 0, double salary = 0, double allow = 0)
            : appointDay(aDay), appointMonth(aMonth), appointYear(aYear), lastSalary(salary), allowance(allow) {}

    // Getter and setter methods for appointment day
    int getAppointDay() const { return appointDay; }
    void setAppointDay(int day) { appointDay = day; }

    // Getter and setter methods for appointment month
    int getAppointMonth() const { return appointMonth; }
    void setAppointMonth(int month) { appointMonth = month; }

    // Getter and setter methods for appointment year
    int getAppointYear() const { return appointYear; }
    void setAppointYear(int year) { appointYear = year; }

    // Getter and setter methods for last salary
    double getLastSalary() const { return lastSalary; }
    void setLastSalary(double salary) { lastSalary = salary; }

    // Getter and setter methods for allowance
    double getAllowance() const { return allowance; }
    void setAllowance(double allow) { allowance = allow; }

    // Friend function to input service details of the employee
    friend void inputServiceInfo(ServiceInfo &serviceInfo);
};

// Function to input and validate service details of the employee
void inputServiceInfo(ServiceInfo &serviceInfo)
{
    cout << "Input Service and Wages Information:\n";

    // Input and validate appointment year (must be between 1900 and 2100)
    cout << "Set Appointment Date (Year): ";
    cin >> serviceInfo.appointYear;
    while (serviceInfo.appointYear < 1900 || serviceInfo.appointYear > 2100)
    {
        cout << "Invalid Year. Please enter a valid year (between 1900 and 2100): ";
        cin >> serviceInfo.appointYear;
    }

    // Input and validate appointment month (must be between 1 and 12)
    cout << "Set Appointment Date (Month): ";
    cin >> serviceInfo.appointMonth;
    while (serviceInfo.appointMonth < 1 || serviceInfo.appointMonth > 12)
    {
        cout << "Invalid Month. Please enter a valid month (1-12): ";
        cin >> serviceInfo.appointMonth;
    }

    // Input and validate appointment day based on the month
    cout << "Set Appointment Date (Day): ";
    cin >> serviceInfo.appointDay;
    int MonthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (serviceInfo.appointDay < 1 || serviceInfo.appointDay > MonthDays[serviceInfo.appointMonth])
    {
        cout << "Invalid Day. Please enter a valid day for the month: ";
        cin >> serviceInfo.appointDay;
    }

    cout << "+---------------------------------------------------------------+\n";
    cout << "Set Wages Information:\n";

    // Input employee's latest salary
    cout << "Latest Salary: ";
    cin >> serviceInfo.lastSalary;

    // Input employee's total allowance
    cout << "Total Allowance: ";
    cin >> serviceInfo.allowance;
    cout << "+---------------------------------------------------------------+\n";
}

// ----------------------- Class to Combine Personal and Service Information -----------------------
class EmployeeInfo : public PersonalInfo, public ServiceInfo
{
    // Friend function declaration to display all service details
    friend void displayServiceInfo();

public:
    // Constructor to initialize both personal and service details with default values
    EmployeeInfo(string empName = "", string empId = "", int bDay = 0, int bMonth = 0, int bYear = 0,
                 int aDay = 0, int aMonth = 0, int aYear = 0, double salary = 0, double allow = 0)
            : PersonalInfo(empName, empId, bDay, bMonth, bYear), ServiceInfo(aDay, aMonth, aYear, salary, allow) {}

    // Method to display all the details of the employee
    void displayServiceInfo() const
    {
        cout << "+--------Your Service Information--------+\n";
        cout << "  Name: " << name << "\n";
        cout << "  IC: " << ic << "\n";
        cout << "  Date of Birth: " << birthDay << "/" << birthMonth << "/" << birthYear << "\n";
        cout << "  Date of Appointment: " << appointDay << "/" << appointMonth << "/" << appointYear << "\n";
        cout << "  Your last Salary: RM " << lastSalary << "\n";
        cout << "  Total Allowance: RM " << allowance << "\n";
        cout << "+----------------------------------------+\n";
    }
};

// ----------------------- Function to Check Pension Eligibility -----------------------
bool checkEligible(EmployeeInfo &emp, int pensionDay, int pensionMonth, int pensionYear)
{
    // Calculate years of service and employee's age
    int serviceYears = pensionYear - emp.getAppointYear();
    int serviceMonths = pensionMonth - emp.getAppointMonth();
    int age = pensionYear - emp.getBirthYear();

    // Adjust service years and months if the appointment date hasn't been reached yet in the current year
    if (pensionMonth < emp.getAppointMonth() || (pensionMonth == emp.getAppointMonth() && pensionDay < emp.getAppointDay()))
    {
        serviceYears = serviceYears - 1;
        serviceMonths = serviceMonths + 12;
    }

    // Adjust age if the birthdate hasn't been reached yet in the current year
    if (pensionMonth < emp.getBirthMonth() || (pensionMonth == emp.getBirthMonth() && pensionDay < emp.getBirthDay()))
    {
        age = age - 1;
    }

    cout << "Your service is: " << serviceYears << " years and " << serviceMonths << " months\n";

    // Check eligibility conditions: age must be >= 40 and service years must be >= 10
    if (age >= 40 && serviceYears >= 10)
    {
        cout << "You are eligible for pension.\n";
        return true; // Return true if eligible
    }
    else
    {
        cout << "You are NOT eligible for pension.\n";
        if (age < 40)
            cout << "Your age is below 40: " << age << " years\n";
        if (serviceYears < 10)
            cout << "Your service is less than 10 years: " << serviceYears << " years and " << serviceMonths << " months\n";
        return false; // Return false if not eligible
    }
}

// ----------------------- Function to Calculate Pension Amount and Gratuity -----------------------
void calculatePensionEstimation(EmployeeInfo &emp, int pensionDay, int pensionMonth, int pensionYear)
{
    // Check eligibility first
    bool isEligible = checkEligible(emp, pensionDay, pensionMonth, pensionYear);
    int monthsOfService;
    if (isEligible) // Only proceed if eligible
    {
        // Calculate total months of service
        monthsOfService = (pensionYear - emp.getAppointYear()) * 12 + (pensionMonth - emp.getAppointMonth());

        // Adjust service months if the pension day is before the appointment day
        if (pensionDay < emp.getAppointDay())
        {
            monthsOfService = monthsOfService - 1;
        }

        // Limit service months to a maximum of 360 (equivalent to 30 years)
        if (monthsOfService > 360)
            monthsOfService = 360;

        // Calculate monthly pension and severance gratuity
        double pension = 0.00167 * monthsOfService * emp.getLastSalary();
        double gratuity = 0.075 * monthsOfService * emp.getLastSalary();

        // Display pension and gratuity amounts
        cout << "Monthly Pension Amount: RM " << pension << endl;
        cout << "Severance Gratuity: RM " << gratuity << endl;
    }
    else
    {
        // If not eligible, do nothing
        return;
    }
}

// ----------------------- Main Function to Run the Pension Eligibility and Calculation App -----------------------
int main()
{
    EmployeeInfo emp;  // Create an instance of EmployeeInfo
    int option;  // Variable to store the user's menu selection
    string check = "no";  // Flag to track if information has been entered

    do
    {
        // Display menu options
        cout << "\n+---------------------------------------------------------------+\n";
        cout << "|          Pension Eligibility and Calculation App (PECA)       |";
        cout << "\n+---------------------------------------------------------------+\n";
        cout << "|1. Input Personal and Service Information                      |\n";
        cout << "|2. Display All Information                                     |\n";
        cout << "|3. Calculate Pension                                           |\n";
        cout << "|4. Exit                                                        |\n";
        cout << "+---------------------------------------------------------------+\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
            case 1:
                // Input personal and service information
                inputPersonalInfo(emp);
                inputServiceInfo(emp);
                check = "yes";  // Set the flag indicating information has been entered
                break;

            case 2:
                // Display employee information
                if (check != "no")
                {
                    emp.displayServiceInfo();
                }
                else
                {
                    cout << "Please enter your personal and service information first (Option 1).\n";
                }
                break;

            case 3:
                // Calculate pension eligibility and amounts
                if (check == "no")
                {
                    cout << "Please enter your personal and service information first (Option 1).\n";
                }
                else
                {
                    // Input and validate pension date
                    int pensionDay, pensionMonth, pensionYear;

                    cout << "Set Pension Date (Year): ";
                    cin >> pensionYear;
                    while (pensionYear < 1900 || pensionYear > 2100)
                    {
                        cout << "Invalid Year. Please enter a valid year (between 1900 and 2100): ";
                        cin >> pensionYear;
                    }

                    cout << "Set Pension Date (Month): ";
                    cin >> pensionMonth;
                    while (pensionMonth < 1 || pensionMonth > 12)
                    {
                        cout << "Invalid Month. Please enter a valid month (1-12): ";
                        cin >> pensionMonth;
                    }

                    cout << "Set Pension Date (Day): ";
                    cin >> pensionDay;
                    int MonthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                    while (pensionDay < 1 || pensionDay > MonthDays[pensionMonth])
                    {
                        cout << "Invalid Day. Please enter a valid day for the month: ";
                        cin >> pensionDay;
                    }

                    // Calculate pension
                    calculatePensionEstimation(emp, pensionDay, pensionMonth, pensionYear);
                }
                break;

            case 4:
                // Exit the application
                cout << "Exiting the program.\n";
                return 0;

            default:
                // Handle invalid menu selection
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (option != 4);  // Repeat until the user chooses to exit

    return 0;
}
