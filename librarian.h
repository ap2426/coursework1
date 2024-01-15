#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <string>
#include <vector>

class Librarian {
private:
    int id;
    std::string name;
    std::string address;
    std::string email;
    int salary;

public:
    
  Librarian(int id, const std::string& name, const std::string& address, const std::string& email, int salary);

  void setid (int id);
   
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setEmail(const std::string& email);
    void setSalary(int salary);

    
    int getid() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;
    int getSalary() const;
};

#endif 
