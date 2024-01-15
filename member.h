#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    int memberId;
    std::string name;
    std::string address;
    std::string email;

public:
   
    Member(int id, const std::string& name, const std::string& address, const std::string& email);

    

    // Function to save member details to a file
    void saveToFile() const;
};

#endif 
