#include <iostream>
#include <fstream>
#include <sstream>
#include "PasswordManager.h"
#include "Encryption.h"
#include "Decryption.h"
using namespace std;
void handlePasswordManagement(const string& username) {
    string choice;
    while (true) {
        cout << "\nPassword Manager Menu\n";
        cout << "1. Save Password\n2. Retrieve Password\n3. Sign Out\nEnter your choice: ";
        cin >> choice;
        cout<<endl;
        if (choice == "1") {
            string website, password;
            cout << "Enter website: ";
            cin >> website;
            cout << "Enter password: ";
            cin >> password;
            savePassword(username, website, password);
        } else if (choice == "2") {
            string website, masterPassword;
            cout << "Enter website: ";
            cin >> website;
            cout << "Enter master password: ";
            cin >> masterPassword;
            cout<<endl;
            string retrievedPassword = retrievePassword(username, website, masterPassword);
            if (!retrievedPassword.empty()) {
                cout << "Retrieved password: " << retrievedPassword << endl;
            }
        } else if (choice == "3") {
            signOut();
            cout<<endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void savePassword(const string& username, const string& website, const string& password) {
    // Open the user's file in append mode
    ofstream userFile(username + ".txt", ios_base::app);
    if (!userFile.is_open()) {
        cerr << "Error opening user file for saving password." << endl;
        return;
    }

    // Write the website and password to the file
    userFile << website << " " << encryptPassword(password,"10") << endl;

    // Close the file
    userFile.close();

    cout << "Password saved successfully." << endl;
}

string retrievePassword(const string& username, const string& website, const string& masterPassword) {
    // Open the user's file
    ifstream userFile(username + ".txt");
    if (!userFile.is_open()) {
        cerr << "Error opening user file for retrieving password." << endl;
        return "";
    }

    // Search for the website in the file
    string line;
    string retrievedPassword = "";
    while (getline(userFile, line)) {
        istringstream iss(line);
        string storedWebsite, storedPassword;
        if (iss >> storedWebsite >> storedPassword) {
            if (storedWebsite == website) {
                retrievedPassword = decryptPassword(storedPassword,"10");
                break;
            }
        }
    }

    // Close the file
    userFile.close();

    if (retrievedPassword.empty()) {
        cout << "Password for " << website << " not found." << endl;
    }

    return retrievedPassword;
}

void signOut() {
    cout << "You have been signed out." << endl;
}
