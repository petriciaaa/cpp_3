#include <iostream>
#include <windows.h>

using namespace std;


class Publication {
protected:
    string title;
    float price;

public:

    void getdata() {
        cout << "Enter title: ";  
        cin >> title;
        cout << "Enter price: ";  
        cin >> price;

    }


    void putdata()  {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};


class Book : public Publication {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter pages: "; cin >> pages;

    }

    void putdata()  {
        Publication::putdata();
        cout << "Pages: " << pages << endl;
    }
};


class Tape : public Publication {
private:
    float time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter time: "; cin >> time;
    }

    void putdata()  {
        Publication::putdata();
        cout << "Time: " << time  << endl;
    }
};


int main() {

    Book book;
    Tape tape;

    book.getdata();
    cout << endl;
    tape.getdata();
    cout << endl;
    book.putdata();
    cout << endl;
    tape.putdata();

    return 0;
}