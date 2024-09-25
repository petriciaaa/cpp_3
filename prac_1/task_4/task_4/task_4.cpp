#include <iostream>
#include <string>
#include<windows.h>
#include <conio.h>


const unsigned int COST = 50;


class Gate {
    private:
        unsigned int payCars;
        unsigned int noPayCars;
        unsigned int totalCash;
    public:

        Gate() : payCars(0), noPayCars(0), totalCash(0) {}

        void payingCars() {
            payCars++;
            totalCash = payCars * COST;
        }

        void nopayingCars() {
            noPayCars++;
        }

        void showMessage() {
            std::cout << std::endl<<"a Paying cars: " << payCars << std::endl << " No paying cars : " << noPayCars << std::endl << " Total : " << totalCash << std::endl;
        }
};



int main() {

    SetConsoleOutputCP(1251);

    Gate gate;

    char key;

    std::cout << "Enter  1 if you want to pay. " <<std::endl;
    std::cout << "Enter  0 if you dont want to pay. " <<std::endl;
    std::cout << "Press  ESC to cancel. " <<std::endl;

    while (true) {

        key = _getch();

        std::cout << key;
        if (key == '1') {
            gate.payingCars();
        }
        else if (key == '0') {
            gate.nopayingCars();
        }
        else if (key == 27) {
            gate.showMessage();
            break;
        }
    }
    return 0;
}