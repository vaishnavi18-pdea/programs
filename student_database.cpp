#include <iostream>
#include <string>
using namespace std;

class Student;

class Display {
public:
    void showData(const Student& student);
};

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicense;
    
    static int studentCount;

public:
    Student()
        : name("Unknown"), rollNumber(0), studentClass("Unknown"),
          division('A'), dateOfBirth("Unknown"), bloodGroup("Unknown"),
          contactAddress("Unknown"), telephoneNumber("Unknown"), drivingLicense("Unknown") {
        studentCount++;
        cout << "Default constructor invoked!" << endl;
    }

    Student(string name, int roll, string cls, char div, string dob,
            string bg, string address, string phone, string license)
        : name(name), rollNumber(roll), studentClass(cls), division(div),
          dateOfBirth(dob), bloodGroup(bg), contactAddress(address),
          telephoneNumber(phone), drivingLicense(license) {
        studentCount++;
        cout << "Parameterized constructor invoked!" << endl;
    }

    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber),
          studentClass(other.studentClass), division(other.division),
          dateOfBirth(other.dateOfBirth), bloodGroup(other.bloodGroup),
          contactAddress(other.contactAddress),
          telephoneNumber(other.telephoneNumber),
          drivingLicense(other.drivingLicense) {
        studentCount++;
        cout << "Copy constructor invoked!" << endl;
    }

    ~Student() {
        studentCount--;
        cout << "Destructor invoked for " << name << endl;
    }

    static int getStudentCount() {
        return studentCount;
    }

    friend class Display;

    void inputData() {
        try {
            cout << "Enter student's name: ";
            cin >> name;

            cout << "Enter roll number: ";
            if (!(cin >> rollNumber)) throw invalid_argument("Invalid roll number!");

            cout << "Enter class: ";
            cin >> studentClass;

            cout << "Enter division: ";
            cin >> division;

            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin >> dateOfBirth;

            cout << "Enter blood group: ";
            cin >> bloodGroup;

            cout << "Enter contact address: ";
            cin.ignore();
            getline(cin, contactAddress);

            cout << "Enter telephone number: ";
            cin >> telephoneNumber;

            cout << "Enter driving license number: ";
            cin >> drivingLicense;

            cout << "Data successfully recorded!\n";
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};

int Student::studentCount = 0;

void Display::showData(const Student& student) {
    cout << "\nStudent Information:" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Class: " << student.studentClass << endl;
    cout << "Division: " << student.division << endl;
    cout << "Date of Birth: " << student.dateOfBirth << endl;
    cout << "Blood Group: " << student.bloodGroup << endl;
    cout << "Contact Address: " << student.contactAddress << endl;
    cout << "Telephone Number: " << student.telephoneNumber << endl;
    cout << "Driving License Number: " << student.drivingLicense << endl;
}

int main() {
    cout << "Initial student count: " << Student::getStudentCount() << endl;

    // Default constructor
    //Student s1;
    Display display;
    //display.showData(s1);

    Student s2("Alice", 101, "10th", 'B', "01/01/2008", "O+", "123 Street", "9876543210", "DL123456");
    display.showData(s2);

    
    //Student s3(s2);
    //display.showData(s3);

    
    Student* s4 = new Student();
    s4->inputData();
    display.showData(*s4);
    delete s4;

    cout << "Final student count: " << Student::getStudentCount() << endl;

    return 0;
