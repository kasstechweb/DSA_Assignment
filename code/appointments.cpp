/* ================= 4/6 Appointments Class ========|
Assignment – Borneo Hair Salon                      |
Metric #s: 68848 Mahmoud Kassab                     |
           72099 AMOS DANIEL LEJAU                  |
Description: Borneo Hair Salon System built with C++|
            Manage servces, Appointments and Sales  |
                                                    |
>> Manage Appointments, Read, Insert, Add, Delete   |
and Update                                          |
// ================================================*/

class Appointments: public Services{
    public: 
        void menu(Appointments appts[], Services srvs[]);
        void presets(Appointments appts[]);
        void print_appointments(Appointments appts[], Services srvs[]);
        void list_all_appointments(Appointments appts[], Services srvs[]);
        void add_appointment(Appointments appts[], Services srvs[]);
        void update_appointment(Appointments appts[], Services srvs[]);
        void delete_appointment(Appointments appts[], Services srvs[]);

        void set_appointment(
            string userName, 
            int serviceID,
            string date,
            string time
            );
        string get_appointment_name();
        string get_appointment_date();
        string get_appointment_time();
        int get_appointment_SID();
    
    private:
        int serive_ID;
        string user_name, date, time;
};  // end appointments

void Appointments::menu(Appointments appts[], Services srvs[]){
    int num = 0;
    sep1(30);
    cout << "\t>> /main/Manage appintments/" << endl;
    sep1(30);
    cout << "\t\t1. List all appointments" << endl;
    cout << "\t\t2. Add an appointment" << endl;
    cout << "\t\t3. Update an appintment" << endl;
    cout << "\t\t4. Delete an appointment" << endl;
    cout << "\t\t5. Main menu" << endl;
    cout << "\t\t6. Exit" << endl;

    cin.clear(); cin.sync();
    cout << "\tChoose option: ";
    cin >> num;

    switch(num) {
        case 1:
            sep2();
            this->list_all_appointments(appts, srvs);
            break;
        case 2:
            sep2();
            this->add_appointment(appts, srvs);
            break;
        case 3:
            sep2();
            this->update_appointment(appts, srvs);
            break;
        case 4:
            sep2();
            this->delete_appointment(appts, srvs);
            break;
        case 5:
            sep2();
            cout << endl;
            main_menu();
            break; 
        case 6:
            exit(1);

        default:
            cout << "\n\n\tPlease enter a valid number and try again!...\n";
            sep2();
            this->menu(appts, srvs);
    }
}

void Appointments::set_appointment( string userName,  int serviceID, string d, string t) {
    this->user_name = userName;
    this->serive_ID = serviceID;
    this->date = d;
    this->time = t;
}

string Appointments::get_appointment_name() {
    return this->user_name;
}
string Appointments::get_appointment_date() {
    return this->date;
}
string Appointments::get_appointment_time() {
    return this->time;
}
int Appointments::get_appointment_SID() {
    return this->serive_ID;
}

void Appointments::print_appointments(Appointments appts[], Services srvs[]) {
    cout << "\n\t\tAll Appointments" << endl;
    sep1(80);
    cout << "\t";
    printElement("#", 3);
    printElement("User Name", 20);
    printElement("Service", 20);
    printElement("Date", 15);
    printElement("Time", 10);
    printElement("Price", 10);
    cout << endl;
    sep1(80);
    for(int i = 0; i < data_size; i++) {
        if(appts[i].get_appointment_name() != "") {
            cout << "\t" ;
            printElement(i+1, 3);
            printElement(appts[i].get_appointment_name(), 20);
            printElement(srvs[appts[i].get_appointment_SID()].get_service(), 20);
            printElement(appts[i].get_appointment_date(), 15);
            printElement(appts[i].get_appointment_time(), 10);
            cout << "RM ";
            printElement(srvs[appts[i].get_appointment_SID()].get_service_price(), 10);
            cout << endl;
        }
    }
    cout << endl;
}

// option 1 view all appointments
void Appointments::list_all_appointments(Appointments appts[], Services srvs[]) {
    this->print_appointments(appts, srvs);
    sep2();
    this->menu(appts, srvs);
}

// option 2 add a new apppointment
void Appointments::add_appointment(Appointments appts[], Services srvs[]) {
    string name, date, time;int serviceID;
    char delim, delim2;
    int day, month, year = 0, hour, minute = 0;

    srvs[0].print_service_list(srvs); // print services list to choose service to appoint

    cout << "\n\tChoose service #: ";
    cin >> serviceID;
    if(!cin.good()) {   // check service not integer
        cout << "\n\t\t Service number is not valid, try again..." << endl;
        this->menu(appts, srvs);
    }else {
        serviceID -= 1;
        // check if service exist
        for(int i = 0; i < data_size; i++) {
            if(i+1 == serviceID && srvs[i].get_service() == "") {
                cout << "\n\t\t Service # not found, try again..." << endl;
                this->menu(appts, srvs);
                break;   
            }
        }
        cin.clear(); cin.sync();
        cout << "\tType user name: ";
        getline(cin, name);
        cout << "\tType appointment date (DD/MM/YYYY): ";
        getline(cin, date);
        // dividing date in day, month and year
        istringstream stm(date) ;
        stm >> day >> delim ;
        stm >> month >> delim ;
        stm >> year ;
        // check date format
        if(day < 1 || month < 1 || year == 0 || year < 1900) {
            cout << "\n\tdate is not in a propper format (DD/MM/YYYY)..." << endl;
            this->menu(appts, srvs);
        }else {
            cout << "\tType appointment time (HH:MM AM/PM): ";
            getline(cin, time);
            // dividing time in hours, minutes
            istringstream ss(time) ;
            ss >> hour >> delim2 ;
            ss >> minute ;
            // check time format
            if(hour < 1 || minute < 1) {
                cout << "\n\tTime is not in a propper format (HH:MM AM/PM)..." << endl;
                this->menu(appts, srvs);
            }else {
               int idx;
                for(int i = 0; i < data_size; i++) {
                    if(appts[i].get_appointment_name() == "") {
                        idx = i;
                        break;
                    }
                }
                appts[idx].set_appointment(name, serviceID, date, time);
                cout << endl;
                cout << "\t\t Adding is successful" << endl;
                sep2();
                this->menu(appts, srvs); 
            }
        }
        
    }
}// end add appointment

void Appointments::update_appointment(Appointments appts[], Services srvs[]) {
    int num;
    string name, date, time;
    char delim, delim2;
    int day, month, year = 0, hour, minute = 0;
    // show list
    this->print_appointments(appts, srvs);
    // get user input
    cout << "\tSelect appointment #: ";
    cin >> num;

    if(!cin.good()) {   // check appointment not integer
        cout << "\n\t\t Appointment number is not valid, try again..." << endl;
        this->menu(appts, srvs);
    }else {
        // check if appointment is found
        for(int i = 0; i < data_size; i++) {
            if(i+1 == num && appts[i].get_appointment_name() == "") {
                cout << "\n\t\t Appointment # not found, try again..." << endl;
                this->menu(appts, srvs);
                break;
            }
        }
        cin.clear(); cin.sync();
        cout << "\tType a new user name: ";
        getline(cin, name);
        cout << "\tType a new date (DD/MM/YYYY): ";
        getline(cin, date);

        // dividing date in day, month and year
        istringstream stm(date) ;
        stm >> day >> delim ;
        stm >> month >> delim ;
        stm >> year ;

        // check date format
        if(day < 1 || month < 1 || year == 0 || year < 1900) {
            cout << "\n\tdate is not in a propper format (DD/MM/YYYY)..." << endl;
            this->menu(appts, srvs);
        }else {
            cout << "\tType a new time (HH:MM AM/PM): ";
            getline(cin, time);

            // dividing time in hours, minutes
            istringstream ss(time) ;
            ss >> hour >> delim2 ;
            ss >> minute ;

            // check time format
            if(hour < 1 || minute < 1) {
                cout << "\n\tTime is not in a propper format (HH:MM AM/PM)..." << endl;
                this->menu(appts, srvs);
            }else {
                // update list
                for(int i = 0; i < data_size; i++) {
                    if(i+1 == num) {
                        appts[i].set_appointment(name, 
                        appts[i].get_appointment_SID(),
                        date,
                        time 
                        );
                        break;
                    }
                }
                cout << endl;
                cout << "\t\t Update is successful" << endl;
                sep2();
                this->menu(appts, srvs);
            }
        }
    }
} // end updating

void Appointments::delete_appointment(Appointments appts[], Services srvs[]) {
    int num;
    // show list
    this->print_appointments(appts, srvs);
    // get user input
    cout << "\tSelect appointment #: ";
    cin >> num;

    if(!cin.good()) {   // check appointment not integer
        cout << "\n\t\t Appointment number is not valid, try again..." << endl;
        this->menu(appts, srvs);
    }else {
        // check if appointment is found
        for(int i = 0; i < data_size; i++) {
            if(i+1 == num && appts[i].get_appointment_name() == "") {
                cout << "\n\t\t Appointment # not found, try again..." << endl;
                this->menu(appts, srvs);
                break;
            }
        }
       // update list
        for(int i = 0; i < data_size; i++) {
            if(i+1 == num) {
                for(int n =i; n < data_size-1; n++) {
                    appts[n].set_appointment(
                        appts[n+1].get_appointment_name(),
                        appts[n+1].get_appointment_SID(),
                        appts[n+1].get_appointment_date(),
                        appts[n+1].get_appointment_time()
                    );
                }
                break;
            }
        }
        cout << endl;
        cout << "\t\t Delete is successful" << endl;
        sep2();
        this->menu(appts, srvs); 
    }

    
}