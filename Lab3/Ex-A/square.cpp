/*
 * File Name: square.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "square.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

Square::Square(double x, double y, double sideA, const char* name)
    : Shape(x, y, name), side_a(sideA) {
    set_side_a(sideA);
}
double Square::get_side_a() const { return side_a; }
void Square::set_side_a(double sideA) {
    if (!isfinite(sideA) || sideA < 0) {
        cerr << "Error: side a must be a finite, non-negative value.\n";
        exit(EXIT_FAILURE);
    }
    side_a = sideA;
}
double Square::area() const { return side_a * side_a; }
double Square::perimeter() const { return 4 * side_a; }
void Square::display() const {
    cout << "Square Name: " << getName() << '\n';
    getOrigin().display();
    cout << "Side a: " << side_a << '\n';
    cout << "Area: " << area() << '\n';
    cout << "Perimeter: " << perimeter() << '\n';
}
