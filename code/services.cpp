/* ================= 3/6 Services Class ============|
Assignment – Borneo Hair Salon                      |
Metric #s: 68848 Mahmoud Kassab                     |
           72099 AMOS DANIEL LEJAU                  |
Description: Borneo Hair Salon System built with C++|
            Manage servces, Appointments and Sales  |
                                                    |
>> Manage Services, Read, Insert, Add, Delete       |
and Update                                          |
// ================================================*/

class Services{
    public:
        void presets(Services srvs[]);
        void menu(Services srvs[]);
        void list_all_services(Services srvs[]);
        void print_service_list(Services srvs[]);
        void add_service(Services srvs[]);
        void update_service(Services srvs[]);
        void delete_service(Services srvs[]);

        void set_service(string service_name, double price);
        string get_service();
        double get_service_price();

    private:
        string service;
        double price;
};



// ========================== Services function ================ //
void Services::menu(Services srvs[]) {
    int num = 0;
    sep1(30);
    cout << "\t>> /main/Manage services/" << endl;
    sep1(30);
    cout << "\t\t1. List all services" << endl;
    cout << "\t\t2. Add a service" << endl;
    cout << "\t\t3. Update a service" << endl;
    cout << "\t\t4. Delete a service" << endl;
    cout << "\t\t5. Main menu" << endl;
    cout << "\t\t6. Exit" << endl;

    cin.clear(); cin.sync();
    cout << "\tChoose option: ";
    cin >> num;

    switch(num) {
        case 1:
            sep2();
            this->list_all_services(srvs);
            break;
        case 2:
            sep2();
            this->add_service(srvs);
            break;
        case 3:
            sep2();
            this->update_service(srvs);
            break;
        case 4:
            sep2();
            this->delete_service(srvs);
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
            this->menu(srvs);
    }
}

void Services::set_service(string service_name, double price) {
    this->service = service_name;
    this->price = price;
}

string Services::get_service() {
    return this->service;
}

double Services::get_service_price() {
    return this->price;
}

void Services::print_service_list(Services srvs[]) {
    cout << "\n\t\tAll Services" << endl;
    sep1(40);
    cout << "\t";
    printElement("#", 3);
    printElement("Name", 20);
    printElement("Price", 10);
    cout << endl;
    sep1(40);
    for(int i = 0; i < data_size; i++) {
        if(srvs[i].get_service() != "") { // get service data from array of object class Services
            cout << "\t" ;
            printElement(i+1, 3);
            printElement(srvs[i].get_service(), 20);
            cout << "RM " ;
            printElement(srvs[i].get_service_price(), 10);
            cout << endl;
        }
    }
    cout << endl;
}

// option 1 view all services, redirect to menu
void Services::list_all_services(Services srvs[]) {
    this->print_service_list(srvs);
    sep2();
    this->menu(srvs);
}

// option 2 add new service
void Services::add_service(Services srvs[]) {
    string name, price;double prc;

    cin.clear(); cin.sync(); // clearing and sync for get line
    cout << "\n\tType service name: ";
    getline(cin, name);
    cout << "\tType service price (1.20): ";
    cin >> prc;

    if(!cin.good()) { // check prc not double
        cout << "\n\t\t Price must be a number" << endl;
        this->menu(srvs); 
    }else {
        int idx;
        for(int i = 0; i < data_size; i++) { // get last indexin srvs array
            if(srvs[i].get_service() == "") {
                idx = i;
                break;
            }
        }
        srvs[idx].set_service(name, prc); // insert in empty index new service
        cout << endl;
        cout << "\t\t Adding is successful" << endl;
        sep2();
        this->menu(srvs); 
    }
}

// option 3 update a service
void Services::update_service(Services srvs[]) {
    int num;
    string name;
    double prc;
    // show list first
    this->print_service_list(srvs);
    // get user input for service number
    cout << "\tSelect service #: ";
    cin >> num;

    if(!cin.good()) {   // check service not integer
        cout << "\n\t\t Service number is not valid, try again..." << endl;
        this->menu(srvs);
    }else {
        // check if service exist
        for(int i = 0; i < data_size; i++) {
            if(i+1 == num && srvs[i].get_service() == "") {
                cout << "\n\t\t Service # not found, try again..." << endl;
                this->menu(srvs);
                break;
                  
            }
        }

        cin.clear(); cin.sync();
        cout << "\tType a new service name: ";
        getline(cin, name);
        cout << "\tType a new service price: ";
        cin >> prc;

        if(!cin.good()) {   // cehck price double
            cout << "\n\t\t Price must be a number" << endl;
            this->menu(srvs); 
        }else {
            // update list
            for(int i = 0; i < data_size; i++) {
                if(i+1 == num && srvs[i].get_service() != "") {
                    srvs[i].set_service(name, prc);
                    break;
                }
            }
            cout << endl;
            cout << "\t\t Update is successful" << endl;
            sep2();
            this->menu(srvs);  
        }
        
    }
    
}

// option 4 delete a service
void Services::delete_service(Services srvs[]) {
    int num;
    // show list
    this->print_service_list(srvs);
    // get user input
    cout << "\tSelect service #: ";
    cin >> num;

    if(!cin.good()) {   // check service not int
        cout << "\n\t\t Service number is not valid, try again..." << endl;
        this->menu(srvs);
    }else {
        // check if service exist
        for(int i = 0; i < data_size; i++) {
            if(i+1 == num && srvs[i].get_service() == "") {
                cout << "\n\t\t Service # not found, try again..." << endl;
                this->menu(srvs);
                break;   
            }
        }
        // delete from list
        for(int i = 0; i < data_size; i++) {
            if(i+1 == num) {
                for(int n =i; n < data_size-1; n++) {
                    srvs[n].set_service(
                        srvs[n+1].get_service(),
                        srvs[n+1].get_service_price()
                    );
                }
                break;
            }
        }
        cout << endl;
        cout << "\t\t Delete is successful" << endl;
        sep2();
        this->menu(srvs);
    }

    
}