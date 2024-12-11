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

class Book  {
private:
    Publication publication;
    Sales sales;
    int pages;

public:
    void getdata() {
        publication.getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        sales.getdata();
    }

    void putdata() const {
        publication.putdata();
        cout << "Количество страниц: " << pages << endl;
        sales.putdata();
    }
};

class Tape {
private:
    Publication publication;
    Sales sales;
    float time;
 
public:
    void getdata() {
        publication.getdata();
        cout << "Введите продолжительность: ";
        cin >> time;
        sales.getdata();
    }

    void putdata() const {
        publication.putdata();
        cout << "продолжительность: " << time << endl;
        sales.putdata();
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