/*
 Develop a program in C++ to create a database ofstudent’s information system
containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group,
Contactaddress, Telephone number, Driving license no. and other. Construct
the database with
suitable member functions. Make use of constructor, default constructor,
copy constructor,
destructor, static member functions, friend class, this pointer, inline
code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/



#include<iostream>
#include<string>
using namespace std;

class StudentData;  // Forward declaration of StudentData class

class Student {
    string name;
    int roll_no;
    string cls;
    string division;
    string dob;
    string bloodgroup;
    static int count;

public:
    Student() : name(""), roll_no(0), cls(""), division(""), dob("dd/mm/yyyy"), bloodgroup("") {}  // Default Constructor

    static int getCount() {
        return count;
    }

    void getData(StudentData*);
    void dispData(StudentData*);
};

class StudentData {
    string address;
    long tel_no;
    long dl_no;
    friend class Student;

public:
    StudentData() : address(""), tel_no(0), dl_no(0) {}  // Default Constructor

    void getStudentData() {
        cout << "Enter Contact Address: ";
        cin.ignore();  // Ignore remaining newline character from previous input
        getline(cin, address);
        cout << "Enter Telephone Number: ";
        cin >> tel_no;
        cout << "Enter Driving License Number: ";
        cin >> dl_no;
    }

    void displayStudentData() const {
        cout << "Contact Address: " << address << endl;
        cout << "Telephone Number: " << tel_no << endl;
        cout << "Driving License Number: " << dl_no << endl;
    }
};

int Student::count = 0;

void Student::getData(StudentData* st) {
    cout << "Enter Student Name: ";
    cin.ignore();  // Ignore remaining newline character from previous input
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cin.ignore();  // Ignore remaining newline character from previous input
    cout << "Enter Class: ";
    getline(cin, cls);
    cout << "Enter Division: ";
    getline(cin, division);
    cout << "Enter Date of Birth: ";
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    getline(cin, bloodgroup);
    st->getStudentData();
    count++;
}

void Student::dispData(StudentData* st1) const {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st1->displayStudentData();
}

int main() {
    Student* students[100];
    StudentData* studentData[100];
    int n = 0;
    char ch;

    do {
        students[n] = new Student;
        studentData[n] = new StudentData;
        students[n]->getData(studentData[n]);
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------" << endl;
        students[i]->dispData(studentData[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        delete students[i];
        delete studentData[i];
    }

    return 0;
}
