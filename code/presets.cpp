/* ==================== 6/6 Presets ================|
Assignment – Borneo Hair Salon                      |
Metric #s: 68848 Mahmoud Kassab                     |
           72099 AMOS DANIEL LEJAU                  |
Description: Borneo Hair Salon System built with C++|
            Manage servces, Appointments and Sales  |
                                                    |
>> presets function to add 5 presets to services and|
Appointments                                        |
// ================================================*/
void Services::presets(Services srvs[]){
    srvs[0].set_service("hair-cutting", 10.5);
    srvs[1].set_service("hair-colouring", 11.0);
    srvs[2].set_service("hairstyling", 20.50);
    srvs[3].set_service("Beard-styling", 15.50);
    srvs[4].set_service("Beared-cutting", 10.50);
}

void Appointments::presets(Appointments appts[]) {
    appts[0].set_appointment("Ali", 0, "1/1/2020", "11:00 AM");
    appts[1].set_appointment("Ahmed", 0, "2/1/2020", "08:00 AM");
    appts[2].set_appointment("John", 1, "3/1/2020", "01:00 PM");
    appts[3].set_appointment("Tom", 2, "10/1/2020", "10:00 PM");
    appts[4].set_appointment("Sam", 2, "15/2/2020", "09:00 PM");
}

