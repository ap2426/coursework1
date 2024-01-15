#include <iostream>
#include <cstdlib>
#include "Librarian.h"
#include "Member.h"
#include "Book.h"
#include<vector>
#include <fstream>
#include <string>
#include <sstream>


void clearScreen()
{

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}
struct Loan {
    int bookID;
    int memberID;
};

void displayMenu()
{
    std::cout << "----------------" << std::endl;                                 std::cout << "Library Menu:" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "1. Add Member" << std::endl;
    std::cout << "2. Issue Book" << std::endl;
    std::cout << "3. Return Book" << std::endl;
    std::cout << "4. calculate fine" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Enter your choice: ";
}


void addMember()
{
    int memberId;
    std::string name, address, email;
    
    std::cout << "-----------------------" << std::endl;
    std::cout << "Enter Member Details:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Member ID: ";
    std::cin >> memberId;
    std::cin.ignore(); // Clear newline character from the input buffer
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Address: ";
    std::getline(std::cin, address);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    Member member(memberId, name, address, email);
    member.saveToFile();
    std::cout << "-----------------------" << std::endl;
    std::cout << "Member added successfully!" << std::endl;
    std::cout << "-----------------------" << std::endl;
}
void issueBook()
{
    std::vector<Book> books = Book::readBooksFromCSV("library_books.csv");
    
    std::cout << "-----------------------" << std::endl;
    std::cout << "Available Books:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    for (const auto& book : books) {
        if (!book.getIsIssued()) { // Display only books that are not yet issued
            std::cout << "Book ID: " << book.getBookID()
                      << ", Book Name: " << book.getBookName()
                      << ", Author: " << book.getAuthorFirstName() << " " << book.getAuthorLastName()
                      << ", Book Type: " << book.getBookType() << std::endl;
        }
    }

    // Asking the user for the ID of the book to issue
    std::cout << "-----------------------" << std::endl;
    std::cout << "Enter the ID of the book you wish to borrow: ";
    int bookID;
    std::cin >> bookID;
    std::cout << "-----------------------" << std::endl;

    bool found = false;
    for (auto& book : books) {
        if (book.getBookID() == bookID && !book.getIsIssued()) {
            book.setIsIssued(true); 
            found = true;
	    std::cout << "-----------------------" << std::endl;
            std::cout << "Book '" << book.getBookName() << "' has been issued." << std::endl;
	    std::cout << "-----------------------" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Book with ID " << bookID << " not found or already issued." << std::endl;
    }
}
void returnBook(std::vector<Book> &books)
{
  std::cout << "-----------------------" << std::endl;
    std::cout << "Books currently issued:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    for (const auto &book : books)
    {
        if (book.getIsIssued())
        {
            std::cout << "Book ID: " << book.getBookID()
                      << ", Book Name: " << book.getBookName() << std::endl;
        }
    }

    std::cout << "-----------------------" << std::endl;
    std::cout << "Enter the ID of the book you wish to return: ";
    int bookID;
    std::cin >> bookID;
    std::cout << "-----------------------" << std::endl;

    bool found = false;
    for (auto &book : books)
    {
        if (book.getBookID() == bookID && book.getIsIssued())
        {
            book.setIsIssued(false);
            found = true;
            std::cout << "Book '" << book.getBookName() << "' has been returned." << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Book with ID " << bookID << " is not currently issued or does not exist." << std::endl;
    }
}

void returnBook() {
    int bookID;
    std::cout << "Enter the ID of the book to return: ";
    std::cin >> bookID;

    std::ifstream file("issued_books.txt");
    std::string line;
    bool bookFound = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id;
        std::string temp, bookName, bookType;

        iss >> temp >> id;  // Extracting "Book ID:" and the actual ID
        if (id == bookID) {
            // Extracting the rest of the details
            iss >> temp >> bookName >> temp >> bookType;
            std::cout << "Book returned successfully: " << bookName << ", " << bookType << std::endl;
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        std::cout << "Book ID not found." << std::endl;
    }

    file.close();
}

int main()
{
    std::vector<Book> books = Book::readBooksFromCSV ("library_books.csv");   
     std::vector<Member> members; 
    std::vector<Loan> loans;     


    Librarian librarian(0, "", "", "", 0);

    // Ask for details from the user
    int id, salary;
    std::string name, address, email;
    
    std::cout << "-----------------------" << std::endl;
    std::cout << "Enter Librarian Details:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Staff ID: ";
    std::cin >> id;
    std::cin.ignore(); 
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Address: ";
    std::getline(std::cin, address);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Salary: ";
    std::cin >> salary;

    librarian.setid(id);
    librarian.setName(name);
    librarian.setAddress(address);
    librarian.setEmail(email);
    librarian.setSalary(salary);

    clearScreen();

    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            addMember();
           
            break;
        case 2:
            issueBook();
            break;
        case 3:
           returnBook(books);
            break;
        case 4:
	  std::cout << "-----------------------" << std::endl;
	  std::cout << "There is no overdue book righ now." << std:: endl;
	  std::cout << "If there avalible over dur book ,then the fine is 1 pound per day." << std:: endl;
	  std::cout << "-----------------------" << std::endl;
         
            break;
        case 5:
	    std::cout << "-----------------------" << std::endl;
            std::cout << "Exit this system." << std::endl;
	    std::cout << "Thank you!" << std::endl;
	    std::cout << "-----------------------" << std::endl;
            running = false;
            break;
        default:
	  std::cout << "-----------------------" << std::endl;
            std::cout << "Invalid choice, try again." << std::endl;
	    std::cout << "-----------------------" << std::endl;
            break;
        }
        if (running)
        {
            std::cout << "Press Enter to continue...";
            std::cin.ignore(); 
            std::cin.get();    
            clearScreen();
        }
    }

    return 0;
}
