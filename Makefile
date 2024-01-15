# Makefile for Library Management System

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Targets
EXEC = LibrarySystem
OBJS = main.o book.o member.o librarian.o

# Default target
all: $(EXEC)

# Linking the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compiling source files into object files
main.o: main.cpp book.h member.h librarian.h
	$(CXX) $(CXXFLAGS) -c main.cpp

book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c book.cpp

member.o: member.cpp member.h
	$(CXX) $(CXXFLAGS) -c member.cpp

librarian.o: librarian.cpp librarian.h
	$(CXX) $(CXXFLAGS) -c librarian.cpp

# Cleaning up
clean:
	rm -f $(OBJS) $(EXEC)
