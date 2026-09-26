/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "circle.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

Circle::Circle(double x, double y, double r, const char* name)
    : Shape(x, y, name), radius(r) {
    set_radius(r);
}
double Circle::get_radius() const { return radius; }
void Circle::set_radius(double r) {
    if (!isfinite(r) || r < 0) {
        cerr << "Error: radius must be a finite, non-negative value.\n";
        exit(EXIT_FAILURE);
    }
    radius = r;
}
double Circle::area() const { return acos(-1.0) * radius * radius; }
double Circle::perimeter() const { return 2 * acos(-1.0) * radius; }
void Circle::display() const {
    cout << "Circle Name: " << getName() << '\n';
    getOrigin().display();
    cout << "Radius: " << radius << '\n';
    cout << "Area: " << area() << '\n';
    cout << "Perimeter: " << perimeter() << '\n';
}
