#include <iostream>
#include "LoginSignup.h"
#include "PasswordManager.h"
using namespace std;
int main() {
    string choice;
    cout << "Welcome to the Password Manager!" << endl;
    cout << "1. Sign Up\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == "1") {
        handleSignUp();
    } else if (choice == "2") {
        handleLogin();
    } else {
        cerr << "Invalid choice." << endl;
    }

    return 0;
}
