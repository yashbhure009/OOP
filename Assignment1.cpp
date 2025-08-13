#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    string name;
    string account_type;
    int account_number;
    float balance;
public:
    BankAccount(string name1, string acctype, int accno, float startingbalance = 0.0) {
        name = name1;
        account_type = acctype;
        account_number = accno;
        balance = startingbalance;
    }
    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Amount must be positive." << endl;
        }
    }
    void withdraw(float amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Successfully withdrew $" << amount << endl;
            } else {
                cout << "Insufficient funds. Balance is: $" << balance << endl;
            }
        } else {
            cout << "Invalid withdrawal amount. Amount must be positive." << endl;
        }
    }
    void displayAccountInfo() {
        cout << "\nBank Account Details:" << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};
int main() {
    string name, acctype;
    int number;
    float balance;
    cout << "Enter Customer Name: ";
    getline(cin, name);
    cout << "Enter Account Type: ";
    getline(cin, acctype);
    cout << "Enter Account Number: ";
    cin >> number;
    cout << "Enter Account Balance: $";
    cin >> balance;
    BankAccount account(name, acctype, number, balance);
    int choose;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Display Account Information" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choose;
        switch (choose) {
            case 1:
                account.displayAccountInfo();
                break;
            case 2: {
                float depositAmount;
                cout << "Enter amount to deposit: $";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 3: {
                float withdrawAmount;
                cout << "Enter amount to withdraw: $";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            }
            case 4:
                cout << "Exiting the APP." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choose != 4);

    return 0;
}
