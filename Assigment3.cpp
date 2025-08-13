#include<iostream>
#include<string>
using namespace std;

const int MAX_STAFF = 100; 

class Staff {
protected:
    string staffId;
    string name;
    string phoneNumber;
public:
    Staff() : staffId(""), name(""), phoneNumber("") {}
    virtual void accept() {
        cout << "Enter Staff ID: ";
        cin >> staffId;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phoneNumber);
    }
    virtual void disp() {
        cout << "\n---- Staff Details ----\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << staffId << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};

class Teacher : public Staff {
private:
    string subject;
    int experience;
public:
    Teacher() : subject(""), experience(0) {}
    void accept() override {
        Staff::accept();
        cout << "Enter Subject Taught: ";
        getline(cin, subject);
        cout << "Enter Years of Experience: ";
        cin >> experience;
        cin.ignore();
    }
    void disp() override {
        if (staffId.empty()) {
            cout << "No Teacher data available.\n";
            return;
        }
        Staff::disp();
        cout << "\n---- Academics ----\n";
        cout << "Subject: " << subject << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Support : public Staff {
private:
    string aos;
public:
    Support() : aos("") {}
    void accept() override {
        Staff::accept();
        cout << "Enter Area of Support: ";
        getline(cin, aos);
    }
    void disp() override {
        if (staffId.empty()) {
            cout << "No Support Staff data available.\n";
            return;
        }
        Staff::disp();
        cout << "\n---- Support Details ----\n";
        cout << "Area of Support: " << aos << endl;
    }
};

int main() {
    Teacher teachers[MAX_STAFF];
    Support supports[MAX_STAFF];

    int n, m;

    cout << "Enter number of Teachers (max " << MAX_STAFF << "): ";
    cin >> n;
    if (n > MAX_STAFF) n = MAX_STAFF;

    cout << "Enter number of Support Staff (max " << MAX_STAFF << "): ";
    cin >> m;
    if (m > MAX_STAFF) m = MAX_STAFF;

    cin.ignore(); // flush newline

    int choice;
    bool teachersEntered = false, supportsEntered = false;

    do {
        cout << "\n  Staff Management System\n";
        cout << "1. Enter Teacher Details\n";
        cout << "2. Enter Support Staff Details\n";
        cout << "3. Display Teacher Details\n";
        cout << "4. Display Support Staff Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for Teacher " << i + 1 << ":\n";
                    teachers[i].accept();
                }
                teachersEntered = true;
                break;
            case 2:
                for (int i = 0; i < m; i++) {
                    cout << "\nEnter details for Support Staff " << i + 1 << ":\n";
                    supports[i].accept();
                }
                supportsEntered = true;
                break;
            case 3:
                if (!teachersEntered) {
                    cout << "\nNo Teacher data entered yet.\n";
                } else {
                    for (int i = 0; i < n; i++) {
                        cout << "\n--- Teacher " << i + 1 << " ---";
                        teachers[i].disp();
                    }
                }
                break;
            case 4:
                if (!supportsEntered) {
                    cout << "\nNo Support Staff data entered yet.\n";
                } else {
                    for (int i = 0; i < m; i++) {
                        cout << "\n--- Support Staff " << i + 1 << " ---";
                        supports[i].disp();
                    }
                }
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
