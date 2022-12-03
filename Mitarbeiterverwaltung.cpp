// Bitte geben Sie die gefragten Input-daten richtig ein.
// Denis Engelhardt

#include <iostream>
#include <string>

using namespace std;

class Date {
    int day;
    int month;
    int year;
public:
    Date(int, int, int);
    Date();

    int get_day();
    int get_month();
    int get_year();
    void print();
    string toString();
};
//Konstruktoren
Date::Date(int day, int month, int year) :day(day),month(month),year(year) {};
Date::Date() :day(0), month(0), year(0) {};
//Getter
int Date::get_day() {
    return day;
}
int Date::get_month() {
    return month;
}
int Date::get_year() {
    return year;
}
//Gibt das Datum in der Konsole aus
void Date::print() {
    cout << get_day() << "." << get_month() << "." << get_year() << endl;
}

string Date::toString() {
    return to_string(get_day()) + "." + to_string(get_month()) + "." + to_string(get_year());
};

class Employee {
    string name;
    string fname;
    Date bday;
    int hdays;
    int takenHdays;
public:
    //Konstruktoren
    Employee(string, string, Date);
    Employee(string, string, Date, int, int);
    Employee();
    //Destruktor
    ~Employee();
    //Getter
    string get_name();
    string get_fname();
    int get_hdays();
    int get_takenHdays();
    Date get_bday();
    //Setter
    void set_takenHdays(int);
    void set_name(string);
    void set_fname(string);
    void set_bday(Date);
    void set_hdays(int);

    bool age_above_50();
    int calc_left_hdays();
};
//Konstruktoren
Employee::Employee(string name, string fname, Date bday) :name(name), fname(fname), bday(bday), takenHdays(0) {
    if (age_above_50()) {
        hdays = 32;
    }
    else
    {
        hdays = 30;
    }
};
Employee::Employee(string name, string fname, Date bday, int hdays, int takenHdays): name(name), fname(fname), bday(bday), hdays(hdays), takenHdays(takenHdays) {};
Employee::Employee() :name(""), fname(""), hdays(30), takenHdays(0) {};
//Destruktor
Employee::~Employee() {
    //cout << "Employee deleted" << endl; 
};
//Getter
string Employee::get_name() {
    return name;
}
string Employee::get_fname() {
    return fname;
}
int Employee::get_hdays() {
    return hdays;
};
int Employee::get_takenHdays() {
    return takenHdays;
}
Date Employee::get_bday() {
    return bday;
}
//Setter
void Employee::set_takenHdays(int TakenHdays) {
    takenHdays = TakenHdays;
}
void Employee::set_name(string Name) {
    name = Name;
};
void Employee::set_fname(string Fname) {
    fname = Fname;
}
void Employee::set_bday(Date Bday) {
    bday = Bday;
}
void Employee::set_hdays(int Hdays) {
    hdays = Hdays;
}


// TODO: Logik anpassen
//Gibt true zurück wenn der Mitarbeiter im Jahr 1971 oder früher geboren wurde, ansonsten false
bool Employee::age_above_50() {
    if (bday.get_year() <= 1971) {
        return true;
    }
    else
    {
        return false;
    }
}
//Gibt die Anzahl der übrig gebliebenen Urlaubstage aus
int Employee::calc_left_hdays() {
    return hdays - takenHdays;
}


class EDatabase {
    Employee database[500];
    unsigned int index = 0;
public:
    Employee get_employee(int);
    void set_employee_at_index(Employee,int);
    void register_employee();
    void print_employee_data();
    unsigned int count_employees();
    void init_rand_employees(unsigned int);
    void delete_employee_at_index(unsigned int);
    int search_with_name(string);
    
};
//Getter
Employee EDatabase::get_employee(int Index) {
    return database[Index];
}

// Fragt nach den Daten für das Anlegen eines Mitarbeiters, setzt die Daten an der Indexposition in der Datenbank und 
// erhöht den Index um 1.
void EDatabase::register_employee() {
    string nametemp;
    string fnametemp;
    int daytemp;
    int monthtemp;
    int yeartemp;

    cout << "Bitte geben Sie den Namen ein: " << endl;
    cin >> nametemp;
    cout << endl;
    cout << "Bitte geben Sie den Familiennamen ein: " << endl;
    cin >> fnametemp;
    cout << endl;
    cout << "Bitte geben Sie den TAG des Geburtstags ein: " << endl;
    cin >> daytemp;
    cout << endl;
    cout << "Bitte geben Sie den MONAT des Geburtstags ein: " << endl;
    cin >> monthtemp;
    cout << endl;
    cout << "Bitte geben Sie das JAHR des Geburtstags ein: " << endl;
    cin >> yeartemp;
    cout << endl;


    database[index].set_name(nametemp);
    database[index].set_fname(fnametemp);
    database[index].set_bday(Date(daytemp, monthtemp, yeartemp));

    if (database[index].age_above_50()) {
        database[index].set_hdays(32);
    }
    else {
        database[index].set_hdays(30);
    }
    
    cout << database[index].get_name() << " " << database[index].get_fname() << " mit dem Geburtstag: "
        << database[index].get_bday().get_day() << "." << database[index].get_bday().get_month()
        << "." << database[index].get_bday().get_year() << " wurde angelegt" << endl << endl;

    index++;
};

void EDatabase::print_employee_data() {

    for (size_t i = 0; i < count_employees(); i++)
    {
        cout << i << ": " << database[i].get_name() << " " << database[i].get_fname() << " " << database[i].get_bday().toString() 
             << " Hat bereits " << database[i].get_takenHdays() << " Urlaubstage genommen. " << "Urlaubstage uebrig: " << database[i].calc_left_hdays() << endl;
    }
}
// Zählt die registrierten Mitarbeiter und gibt die Anzahl zurück
unsigned int EDatabase::count_employees() {

    int counter = 0;
    unsigned int size = sizeof(database) / sizeof(Employee);
    for (size_t i = 0; i < size; i++)
    {
        if (database[i].get_bday().get_year() != 0) {
            counter++;
        }
    }
    return counter;

    // Alternativ kann man auch einfach den index+1 zurückgeben
}

// Hilfsfunktion: Registriert ,die übergebene Anzahl, mit den x und y als und 1.1.1 als Geburstdatum, in der Datenbank
void EDatabase::init_rand_employees(unsigned int amount) {

    for (size_t i = 0; i < amount; i++)
    {
        database[i].set_name("x");
        database[i].set_fname("y");
        database[i].set_bday(Date(1, 1, 1));
        index++;
    }
}

// Der Mitarbeiter am übergebenen Index wird überschrieben mit dem nachkommenden Mitarbeiter usw.
void EDatabase::delete_employee_at_index(unsigned int Index) {
    for (size_t i = Index; i <= index; i++)
    {
        database[i] = database[i + 1];
    }
    index--;
}
// Sucht die Datenbank nach dem Vornamen ab und gibt den Index des ersten treffers zurück
int EDatabase::search_with_name(string Name) {
    for (size_t i = 0; i < count_employees(); i++)
    {
        if (database[i].get_name() == Name) {
            return i;
        }

    }
    return 0;
}

void EDatabase::set_employee_at_index(Employee Employee, int Index) {
    database[Index] = Employee;
}

void print_menue() {
    cout << endl;
    cout << "[1] Mitarbeiter registrieren." << endl;
    cout << "[2] Mitarbeiter loeschen." << endl;
    cout << "[3] Urlaubstage nehmen." << endl;
    cout << "[4] Resturlaub fuer Mitarbeiter ausgeben." << endl;
    cout << "[5] Alle Mitarbeiter ausgeben." << endl;
    cout << "[6] Anzahl der Mitarbeiter ausgeben." << endl;
    cout << "[7] Nach Mitarbeiter suchen" << endl;
    cout << "[8] Programm beenden." << endl;
    cout << endl;
    cout << "Bitte waehlen Sie eine Funktion: " << endl;

}

bool exitProgram = false;
void start_menu(EDatabase ed) {
    int input = 0;
    int employee_index = 0;
    string empname = " ";
    int numberOfHdays = 0;
    while (!exitProgram) {
        print_menue();
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            ed.register_employee();
            break;
        case 2:
            int temp;
            ed.print_employee_data();
            cout << "Welchen Mitarbeiter wollen sie löschen?" << endl << "Geben Sie den Index an: " << endl;
            cin >> temp;
            ed.delete_employee_at_index(temp);
            cout << "Neue Liste: " << endl << endl;
            ed.print_employee_data();
            cout << "Anzahl der Mitarbeiter: " << ed.count_employees() << endl;
            break;
        case 3:
            cout << "Welcher Mitarbeiter will Urlaub nehmen?" << endl;
            cout << "Geben Sie den Index des Mitarbeiters an: " << endl;
            cin >> employee_index;
            cout << "Wie viele Tage will der Mitarbeiter frei nehmen?" << endl;
            cin >> numberOfHdays;
            //Employee::Employee(string name, string fname, Date bday, int hdays, int takenHdays)
            ed.set_employee_at_index(Employee(
                ed.get_employee(employee_index).get_name(),
                ed.get_employee(employee_index).get_fname(),
                ed.get_employee(employee_index).get_bday(),
                ed.get_employee(employee_index).get_hdays(),
                numberOfHdays),employee_index);

            cout << "Der Mitarbeiter hat " << ed.get_employee(employee_index).get_takenHdays() << " Tage freigenommen." << endl;
            break;
        case 4:
            cout << "Für welchen Mitarbeiter wollen Sie den Resturlaub berechnen? " << endl;
            cout << "Geben Sie den Index an." << endl;
            cin >> employee_index;
            cout << ed.get_employee(employee_index).get_name() << " "<< ed.get_employee(employee_index).get_fname() << " hat noch "
                << ed.get_employee(employee_index).calc_left_hdays() 
                << " Urlaubstage" << endl;
            break;
        case 5:
            ed.print_employee_data();
            break;
        case 6:
            cout << "Anzahl der Mitarbeiter: " << ed.count_employees() << endl;
            break;
        case 7:
            cout << "Geben sie den Namen des Mitarbeiters an, nachdem Sie suchen" << endl;
            cin >> empname;
            cout << "Der Index von " << empname << " lautet: " << ed.search_with_name(empname);
            break;
        case 8:
            exitProgram = true;
            cout << "Programm beendet" << endl << endl;
            break;
        default:
            break;
        }
    }
}

int main()
{
    EDatabase ed;
    start_menu(ed);
    system("pause");
}