#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Book.h"
#include <fstream>
#include <sstream>
#include <string>


TEST_CASE("Book issue details are saved correctly", "[Book]") {
    // Setup - Create a book and issue it
    Book testBook(123, "Test Book", 100, "John", "Doe", "Fiction");
    testBook.setIsIssued(true);

    // Action - Save the issue details
    testBook.saveIssueDetails();

    // Verification
    std::ifstream file("issued_books.txt");
    REQUIRE(file.is_open());

    std::string line;
    std::getline(file, line);
    std::stringstream expectedLine;
    expectedLine << "Book ID: " << 123 << ", Book Name: " << "Test Book" << ", Book Type: " << "Fiction";

    REQUIRE(line == expectedLine.str());

    // Clean up - Remove the test file or its contents
    file.close();
    std::ofstream outFile("issued_books.txt", std::ios::trunc);  // Truncate the file to clean up
    outFile.close();
}
