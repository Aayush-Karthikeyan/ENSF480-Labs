// File Name: human.h
// Assignment: Lab 1 Exercise D
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: Sept 14, 2026

#ifndef HUMAN_H
#define HUMAN_H

#include "point.h"

class Human {
private:
    Point location;   // Location of an object of Human on a Cartesian Plane
    char *name;       // Owned, null-terminated name; released by the destructor.
public:
    Human(const char* nam = "", double x = 0.0, double y = 0.0);
    ~Human();
    Human(const Human& src);
    Human& operator=(const Human& rhs);

    // Returned text is valid until the name changes or this Human is destroyed.
    const char* get_name() const;
    void set_name(const char* nam);
    Point get_point() const;
    void display() const;
};

#endif
