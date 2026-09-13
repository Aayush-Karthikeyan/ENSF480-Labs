// File Name: company.cpp
// Assignment: Lab 1 Exercise C
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: 14/09/2026 23:59

#include <string>
#include <vector>

using namespace std;

class Name{
    string firstName;
    string middleName;
    string lastName;
};

// Class encapsulating calendar date representation
class Date {
private:
    int day;
    int month;
    int year;
};

// Class encapsulating physical address components
class Address {
private:
    string street;
    string city;
    string province;
    string postalCode;
};

// Base class modeling shared human attributes
class Person {
private:
    Name name;
    Address address;
};

// Derived class demonstrating Hierarchy: Employee IS-A Person
class Employee : public Person {
public:
    enum class State {
        ACTIVE,
        SUSPENDED,
        RETIRED,
        FIRED
    };

private:
    Date dateOfBirth;
    State state;
};

// Derived class demonstrating Hierarchy: Customer IS-A Person
class Customer : public Person {
private:
    string phone;
};

// Class representing Company aggregation and composition
class Company {
private:
    string companyName;
    Address companyAddress;
    Date dateEstablished;
    vector<Employee> employees;
    vector<Customer> customers;
};