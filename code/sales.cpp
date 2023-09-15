/* ================= 5/6 Sales Class ===============|
Assignment – Borneo Hair Salon                      |
Metric #s: 68848 Mahmoud Kassab                     |
           72099 AMOS DANIEL LEJAU                  |
Description: Borneo Hair Salon System built with C++|
            Manage servces, Appointments and Sales  |
                                                    |
>> Manage Sales, show weekly and monthly sales      |
// ================================================*/

class Sales: public Appointments {
    public:
        void menu(Appointments appts[], Services srvs[]);
        void get_dates(Appointments appts[], Services srvs[]);
        void set_sales(int d, int m, int y);
        void print_sales(Appointments appts[], Services srvs[], int i, int n);
        void show_weekly_sales(Appointments appts[], Services srvs[]);
        void show_monthly_sales(Appointments appts[], Services srvs[]);
        
        // constructors initialize pointers to NULL
        Sales();
        Sales(Appointments appts[], Services srvs[], int week_num, int month); // constructor to get total sales
    private:
        int *days, *months, *years;
        int appt_length = 0;
        double price = 0.0;
        // }
};

void Sales::menu(Appointments appts[], Services srvs[]) {
    int num = 0;
    sep1(30);
    cout << "\t>> /main/Manage sales/" << endl;
    sep1(30);
    cout << "\t\t1. View weekly sales" << endl;
    cout << "\t\t2. View monthly sales" << endl;
    cout << "\t\t3. Main menu" << endl;
    cout << "\t\t4. Exit" << endl;

    cin.clear(); cin.sync();
    cout << "\tChoose option: ";
    cin >> num;

    switch(num) {
        case 1:
            sep2();
            this->show_weekly_sales(appts, srvs);
            break;
        case 2:
            sep2();
            this->show_monthly_sales(appts, srvs);
            break;
        case 3:
            sep2();
            cout << endl;
            main_menu();
            break; 
        case 4:
            exit(1);

        default:
            cout << "\n\n\tPlease enter a valid number and try again!...\n";
            sep2();
            this->menu(appts, srvs);
    }
}

void Sales::get_dates(Appointments appts[], Services srvs[]) {
    string date;
    int days[data_size], months[data_size], years[data_size];
    double prices[data_size];
    char delim;
    double price = 0.0;
    
    // loop through appointments
    this->days = new int[data_size];
    this->months = new int[data_size];
    this->years = new int[data_size];

    for(int i = 0; i < data_size; i++) {
        if(appts[i].get_appointment_name() != "") {
            date = appts[i].get_appointment_date(); // 1/1/2020
            prices[i] = srvs[appts[i].get_appointment_SID()].get_service_price();
            istringstream stm(date) ;
            stm >> days[i] >> delim ;
            stm >> months[i] >> delim ;
            stm >> years[i] ;
            this->appt_length++;
        }
    }

    for(int i = 0; i < this->appt_length; i++) {
        this->days[i] = days[i];
        this->months[i] = months[i];
        this->years[i] = years[i];
    }
}

void Sales::print_sales(Appointments appts[], Services srvs[],int i, int n) {
    cout << "\t" ;
    printElement(n+1, 3);
    printElement(appts[i].get_appointment_name(), 20);
    printElement(srvs[appts[i].get_appointment_SID()].get_service(), 20);
    printElement(appts[i].get_appointment_date(), 15);
    printElement(appts[i].get_appointment_time(), 10);
    cout << "RM ";
    printElement(srvs[appts[i].get_appointment_SID()].get_service_price(), 10);
    cout << endl;
}

Sales::Sales() {     
    days = NULL;
    months = NULL;
    years = NULL;
}

// constructor will calculate total sales
Sales::Sales(Appointments appts[], Services srvs[], int week_num, int month) {
    double total_sales = 0,n = 0;
    this->get_dates(appts, srvs);
    
    for(int i = 0; i < this->appt_length; i++) {
        if(week_num == 1 && this->months[i] == month && this->days[i] <= 7) {
            this->print_sales(appts, srvs, i, n);
            total_sales += srvs[appts[i].get_appointment_SID()].get_service_price();
            n++;
        }else if(week_num == 2 && this->months[i] == month && this->days[i] <= 14 && this->days[i] > 7) {
            this->print_sales(appts, srvs, i, n);
            total_sales += srvs[appts[i].get_appointment_SID()].get_service_price();
            n++;
        }else if(week_num == 3 && this->months[i] == month && this->days[i] <= 21 && this->days[i] > 14) {
            this->print_sales(appts, srvs, i, n);
            total_sales += srvs[appts[i].get_appointment_SID()].get_service_price();
            n++;
        }else if(week_num == 4 && this->months[i] == month && this->days[i] <= 28 && this->days[i] > 21) {
            this->print_sales(appts, srvs, i, n);
            total_sales += srvs[appts[i].get_appointment_SID()].get_service_price();
            n++;
        }else if(week_num == 5 && this->months[i] == month && this->days[i] > 28) {
            this->print_sales(appts, srvs, i, n);
            total_sales += srvs[appts[i].get_appointment_SID()].get_service_price();
            n++;
        }
    }
    cout << endl;
    
    cout << "\tTotal Sales for this Week: " << total_sales << endl;
    cout << endl;
}

// option 1 shows weekly sales
void Sales::show_weekly_sales(Appointments appts[], Services srvs[]) {
    int month, week_num, n = 0;

    cout << "\n\tType month eg.(1): ";
    cin >> month;

    if(!cin.good()) {   // check month not integer
        cout << "\n\t\t Month number is not valid, try again..." << endl;
        this->menu(appts, srvs);
    }else {
        cout << "\n\tType week number eg.(1): ";
        cin >> week_num;
        if(!cin.good()) {   // check week not integer
            cout << "\n\t\t Week number is not valid, try again..." << endl;
            this->menu(appts, srvs);
        }else {
            sep1(80);
            cout << "\t";
            printElement("#", 3); printElement("User Name", 20); printElement("Service", 20);
            printElement("Date", 15); printElement("Time", 10); printElement("Price", 10);
            cout << endl;
            sep1(80);
            Sales(appts, srvs, week_num, month);
            sep2();
            this->menu(appts, srvs);  
        }
    }
} // end weekly sales

// option 2 show monthly sales
void Sales::show_monthly_sales(Appointments appts[], Services srvs[]) {
    this->get_dates(appts, srvs);
    
    int month, n = 0;
    double total_sales = 0;
    cout << "\n\tType Month eg.(1): ";
    cin >> month;

    if(!cin.good()) {   // check month not integer
        cout << "\n\t\t Month number is not valid, try again..." << endl;
        this->menu(appts, srvs);
    }else {
        sep1(80);
        cout << "\t";
        printElement("#", 3); printElement("User Name", 20); printElement("Service", 20);
        printElement("Date", 15); printElement("Time", 10); printElement("Price", 10);
        cout << endl;
        sep1(80);

        for(int i = 0; i < this->appt_length; i++) {
            if(this->months[i] == month) {
                this->print_sales(appts, srvs, i, n);
                total_sales += srvs[appts[i].get_appointment_SID()].get_service_price();
                n++;
            }
        }
        cout << endl;
        
        cout << "\tTotal Sales for this month: " << total_sales << endl;
        cout << endl;
        sep2();
        this->menu(appts, srvs);
    }    
} // end monthly sales