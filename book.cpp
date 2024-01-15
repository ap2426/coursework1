#include "Book.h"
#include <fstream>
#include <sstream>
#include <iostream>


Book::Book(int id, const std::string& name, int pageCount, const std::string& firstName, const std::string& lastName, const std::string& type)
    : bookID(id), bookName(name), pageCount(pageCount), authorFirstName(firstName), authorLastName(lastName), bookType(type) {}


int Book::getBookID() const {
    return bookID;
}

bool Book::getIsIssued() const {
    return isIssued;
}

void Book::setIsIssued(bool issued) {
    isIssued = issued;
}

std::string Book::getBookName() const {
    return bookName;
}

int Book::getPageCount() const {
    return pageCount;
}

std::string Book::getAuthorFirstName() const {
    return authorFirstName;
}

std::string Book::getAuthorLastName() const {
    return authorLastName;
}

std::string Book::getBookType() const {
    return bookType;
}

std::vector<Book> Book::readBooksFromCSV(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return books;
    }

    
    getline(file, line);

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> parsedLine;

        while (getline(ss, item, ',')) {
            parsedLine.push_back(item);
        }

        if (parsedLine.size() == 6) {
            int id = std::stoi(parsedLine[0]);
            int pageCount = std::stoi(parsedLine[2]);
            books.emplace_back(id, parsedLine[1], pageCount, parsedLine[3], parsedLine[4], parsedLine[5]);
        }
    }

    return books;
}
// funton to save isuue book...
void Book::saveIssueDetails() const {
    std::ofstream file("issued_books.txt", std::ios::app);
    if (file.is_open()) {
        file << "Book ID: " << bookID << ", Book Name: " << bookName << ", Book Type: " << bookType << std::endl;
    } else {
        std::cerr << "Unable to open file to save issue details." << std::endl;
    }
    file.close();
}
