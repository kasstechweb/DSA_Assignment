/* ================= 2/6 Functions File ============|
Assignment – Borneo Hair Salon                      |
Metric #s: 68848 Mahmoud Kassab                     |
           72099 AMOS DANIEL LEJAU                  |
Description: Borneo Hair Salon System built with C++|
            Manage servces, Appointments and Sales  |
                                                    |
>> some functions used through the program          |
>> data_size = 10 change to increase array size     |
// ================================================*/

// ===================== Global Array Size =========//
int data_size = 10;

// ============================ Functions ============//
void sep1(int n) { 
    string s(n, '-');
    cout << "\t" << s << endl; 
}

void sep2() { 
    string s(30, '=');
    cout << "\t" << s << endl; 
}

template<typename T> void printElement(T t, const int& width){
    const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}
