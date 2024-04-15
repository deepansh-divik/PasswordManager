#include <iostream>
#include <fstream>
#include "LoginSignup.h"
#include "PasswordManager.h"
#include "Encryption.h"
#include "Decryption.h"
using namespace std;
bool registerUser(const string& username, const string& masterPassword) {
    // Check if the user already exists
    ifstream userFile(username + ".txt");
    if (userFile.good()) {
        cerr << "User already exists." << endl;
        return false;
    }
    userFile.close();

    // Create a new user file
    ofstream newUserFile(username + ".txt");
    if (!newUserFile.is_open()) {
        cerr << "Error creating user file." << endl;
        return false;
    }

    // Write master password to the user file
    newUserFile << encryptPassword(masterPassword,"10")<< endl;
    newUserFile.close();

    return true;
}

bool loginUser(const string& username, const string& masterPassword) {
    // Check if the user file exists
    ifstream userFile(username + ".txt");
    if (!userFile.good()) {
        cerr << "User does not exist." << endl;
        return false;
    }

    // Read master password from the user file
    string storedMasterPassword;
    userFile >> storedMasterPassword;
    userFile.close();

    // Check if the entered master password matches the stored master password
    if (decryptPassword(storedMasterPassword,"10") != masterPassword) {
        cerr << "Incorrect master password." << endl;
        return false;
    }

    return true;
}

void handleSignUp() {
    string username, masterPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter master password: ";
    cin >> masterPassword;

    if (registerUser(username, masterPassword)) {
        cout << "Registration successful!" << endl;
    } else {
        cerr << "Registration failed." << endl;
    }
}

void handleLogin() {
    string username, masterPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter master password: ";
    cin >> masterPassword;

    if (loginUser(username, masterPassword)) {
        handlePasswordManagement(username);
    } else {
        cerr << "Login failed." << endl;
    }
}
