/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
*/

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
class file
{
public:
    int rollno;
    char name[50];

    void accept() {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter rollno:";
        cin >> rollno;
    }

    void display() {
        cout << "Name is :" << name;
        cout << "\n Roll no is:" << rollno;
    }
};

int main() {
    file o[10], o1, o2[10];
    fstream f;
    int i, n;
    clrscr();
    f.open("simple.txt", ios::out);
    cout << "\n How many records you want to display:";
    cin >> n;
    for(i = 0; i < n; i++) {
        o[i].accept();
        f.write((char*)&o[i], sizeof(o[i]));
    }
    o1.accept();
    f.write((char*)&o1, sizeof(o1));
    f.close();
    f.open("simple.txt", ios::in);
    for(i = 0; i < n; i++) {
        f.read((char*)&o2[i], sizeof(o2[i]));
        o2[i].display();
    }
    f.close();
    getch();
    return 0;
}
