#include <iostream>
#include <windows.h>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Введите название: ";
        cin >> title;
        cout << "Введите цену: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};

class Sales {
protected:
    int sales[3];

public:
    void getdata() {
        cout << "Объем продаж за 3 месяца:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц: " << (i + 1) << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
    
        for (int i = 0; i < 3; ++i) {
            cout << "Продажи в " << (i + 1) << " месце : " << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
private:
    float time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Введите продолжительность: ";
        cin >> time;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "продолжительность: " << time  << endl;
        Sales::putdata();
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Book book;
    Tape tape;

    book.getdata();

    tape.getdata();

    book.putdata();

    tape.putdata();

    return 0;
}