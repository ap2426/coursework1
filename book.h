
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book {
       

private:
    int bookID;
    std::string bookName;
    int pageCount;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
   ;
bool isIssued; 

public:
    Book(int id, const std::string& name, int pageCount, const std::string& firstName, const std::string& lastName, const std::string& type);
    bool getIsIssued() const;
    void setIsIssued(bool issued);
    
    int getBookID() const;
    std::string getBookName() const;
    int getPageCount() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    std::string getBookType() const;
   void saveIssueDetails() const;

    // Function to read books from a CSV file
    static std::vector<Book> readBooksFromCSV(const std::string& filename);
};

#endif 
