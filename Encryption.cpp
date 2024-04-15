#include "Encryption.h"
using namespace std;
string encryptPassword(const string& password, const string& key) {
    string encryptedPassword = password;
    for (size_t i = 0; i < password.size(); ++i) {
        encryptedPassword[i] ^= key[i % key.size()];
    }
    return encryptedPassword;
}
