/*
Imagine a publishing company which does marketing for book
and audiocassette versions.
 Create a class publication that stores the title (a string)
and price (type float) of a
 publication.From this class derive two classes: book, which
adds a page count(type int),
 and tape, which adds a playing time in minutes(type float).
 Write a program that instantiates the book and tape classes,
allows user to enter data and
 displays the data members.If an exception is caught, replace
all the data member values
 with zero values.
*/

#include <iostream>
#include <cstring> // For strcpy
using namespace std;

// Base class publication
class publication {
protected:
    char title[30];
    float price;

public:
    publication() {
        price = 0.0;
        strcpy(title, " ");
    }

    publication(char t[], float p) {
        strcpy(title, t);
        price = p;
    }
};

// Derived class book from publication
class book : public publication {
    int pagecount;

public:
    book() {
        pagecount = 0;
    }

    book(char t[], float p, int pc) : publication(t, p) {
        pagecount = pc;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Pagecount: " << pagecount << endl;
    }
};

// Derived class tape from publication
class tape : public publication {
    float time;

public:
    tape() {
        time = 0.0;
    }

    tape(char t[], float p, float tim) : publication(t, p) {
        time = tim;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Reading time in minutes: " << time << endl;
    }
};

int main() {
    char title1[30];
    float price1;
    int pagecount, playtime;

    cout << "Enter the book title: ";
    cin >> title1;
    cout << "Enter the book price: ";
    cin >> price1;
    cout << "Enter the book pagecount: ";
    cin >> pagecount;
    cout << "Enter the playing time in minutes: ";
    cin >> playtime;

    try {
        if (price1 > 0) {
            cout << "\n***BOOK DATA***" << endl;
            book b1(title1, price1, pagecount);
            b1.display();

            cout << "\n***TAPE DATA***" << endl;
            tape c1(title1, price1, playtime);
            c1.display();
        } else {
            throw 0;
        }
    } catch (int num_exception) {
        cout << "Exception occurs: Price cannot be negative or zero.\n";
        strcpy(title1, " ");
        book b1(title1, 0, 0);
        b1.display();
        tape c1(title1, 0, 0);
        c1.display();
    }

    return 0;
}
