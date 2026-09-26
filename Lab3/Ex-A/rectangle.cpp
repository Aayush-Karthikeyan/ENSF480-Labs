/*
 * File Name: rectangle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "rectangle.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

Rectangle::Rectangle(double x, double y, double sideA, double sideB,
                     const char* name)
    : Shape(x, y, name), Square(x, y, sideA, name), side_b(sideB) {
    set_side_b(sideB);
}
double Rectangle::get_side_b() const { return side_b; }
void Rectangle::set_side_b(double sideB) {
    if (!isfinite(sideB) || sideB < 0) {
        cerr << "Error: side b must be a finite, non-negative value.\n";
        exit(EXIT_FAILURE);
    }
    side_b = sideB;
}
double Rectangle::area() const { return get_side_a() * side_b; }
double Rectangle::perimeter() const { return 2 * (get_side_a() + side_b); }
void Rectangle::display() const {
    cout << "Rectangle Name: " << getName() << '\n';
    getOrigin().display();
    cout << "Side a: " << get_side_a() << '\n';
    cout << "Side b: " << side_b << '\n';
    cout << "Area: " << area() << '\n';
    cout << "Perimeter: " << perimeter() << '\n';
}
