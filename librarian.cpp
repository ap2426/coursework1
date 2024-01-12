#include "Librarian.h"

// Constructors
Librarian::Librarian(int id, const std::string& name, const std::string& address, const std::string& email, int salary)
    : staffId(id), name(name), address(address), email(email), salary(salary) {}

// Setters
void Librarian::setStaffId(int id) {
    staffId = id;
}

void Librarian::setName(const std::string& name) {
    this->name = name;
}

void Librarian::setAddress(const std::string& address) {
    this->address = address;
}

void Librarian::setEmail(const std::string& email) {
    this->email = email;
}

void Librarian::setSalary(int salary) {
    this->salary = salary;
}

// Getters
int Librarian::getStaffId() const {
    return staffId;
}

std::string Librarian::getName() const {
    return name;
}

std::string Librarian::getAddress() const {
    return address;
}

std::string Librarian::getEmail() const {
    return email;
}

int Librarian::getSalary() const {
    return salary;
}