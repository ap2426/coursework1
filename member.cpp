#include "Member.h"
#include <fstream>
#include <iostream>


Member::Member(int id, const std::string& name, const std::string& address, const std::string& email)
    : memberId(id), name(name), address(address), email(email) {}

// Save member details to a file
void Member::saveToFile() const {
    std::ofstream file("members.txt", std::ios::app); 
    if (file.is_open()) {
        file << "Member ID: " << memberId << "\n";
        file << "Name: " << name << "\n";
        file << "Address: " << address << "\n";
        file << "Email: " << email << "\n";
        file << "---------------------------------\n";
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}
