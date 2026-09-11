// File Name: human.cpp
// Assignment: Lab 1 Exercise D
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: Sept 14, 2026

#include "human.h"
#include <cstring>
#include <iostream>

using namespace std;

Human::Human(const char* nam, double x, double y)
    : location(x, y), name(nullptr)
{
    set_name(nam == nullptr ? "" : nam);
}

Human::~Human() {
    delete[] name;
}

Human::Human(const Human& src)
    : location(src.location), name(new char[strlen(src.name) + 1])
{
    strcpy(this->name, src.name);
}

Human& Human::operator=(const Human& rhs) {
    if (this != &rhs) {
        set_name(rhs.name);
        location = rhs.location;
    }
    return *this;
}

const char* Human::get_name() const {
    return name;
}

void Human::set_name(const char* nam) {
    if (nam == nullptr) return;
    // Copy first: nam may point into the current name buffer.
    char *new_name = new char[strlen(nam) + 1];
    strcpy(new_name, nam);
    delete[] name;
    name = new_name;
}

Point Human::get_point() const {
    return location;
}

void Human::display() const {
    cout << "Human Name: " << name << "\nHuman Location: "
         << location.get_x() << " ,"
         << location.get_y() << ".\n" << endl;
}
