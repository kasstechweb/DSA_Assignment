/* ================= 1/6 Main File =================|
Assignment – Borneo Hair Salon                      |
Metric #s: 68848 Mahmoud Kassab                     |
           72099 AMOS DANIEL LEJAU                  |
Description: Borneo Hair Salon System built with C++|
            Manage servces, Appointments and Sales  |
                                                    |
>> include main function and main menu              |
// ================================================*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

void main_menu();
using namespace std;

#include "functions.cpp"
#include "services.cpp"
#include "appointments.cpp"
#include "sales.cpp"
#include "presets.cpp"



int main() {
    cout << "\t***Welcome to Borneo Hair Salon***" << endl;
    main_menu();
    
    return 0;
}

void main_menu() {
    int num=0;
    
    sep1(30);
    cout << "\t>> /main/" << endl;
    sep1(30);
    cout << "\t\t1. Manage services" << endl;
    cout << "\t\t2. Manage appointments" << endl;
    cout << "\t\t3. Manage sales" << endl;
    cout << "\t\t4. Exit" << endl;

    cin.clear(); cin.sync();    // cleaing cin
    cout << "\tChoose option: ";
    cin >> num;

    // initializing array of class services and appointments, size is data_size
    Services srvs[data_size];   
    Appointments appts[data_size];  
    Sales sales;

    // loading presets
    srvs[0].presets(srvs);  
    appts[0].presets(appts);

    switch(num) {
        case 1:
            sep2();
            srvs[0].menu(srvs); // loading services menu
            break; 
        case 2:
            sep2();
            appts[0].menu(appts, srvs); // loading appointments menu
            break;
        case 3:
            sep2();
            sales.menu(appts, srvs);    // loading sales menu
            break;
        case 4:
            exit(1);
        default:
            cout << "\n\n\tPlease enter a valid number and try again!...\n";
            cout << endl;
            sep2();
            main_menu();
    }
}