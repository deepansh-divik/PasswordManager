#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>

void handlePasswordManagement(const std::string& username);
void savePassword(const std::string& username, const std::string& website, const std::string& password);
std::string retrievePassword(const std::string& username, const std::string& website, const std::string& masterPassword);
void signOut();

#endif // PASSWORDMANAGER_H
