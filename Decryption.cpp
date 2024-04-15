#include "Decryption.h"
using namespace std;
string decryptPassword(const string& encryptedPassword, const string& key) {
    string decryptedPassword = encryptedPassword;
    for (size_t i = 0; i < encryptedPassword.size(); ++i) {
        decryptedPassword[i] ^= key[i % key.size()];
    }
    return decryptedPassword;
}
