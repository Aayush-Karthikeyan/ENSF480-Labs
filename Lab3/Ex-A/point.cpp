/*
 * File Name: point.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "point.h"
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int Point::count = 0;
int Point::nextId = 1001;

Point::Point(double x, double y) : ptX(x), ptY(y), id(nextId++) {
    count++;
}
Point::Point(const Point& source)
    : ptX(source.ptX), ptY(source.ptY), id(nextId++) {
    count++;
}
Point::~Point() { count--; }

Point& Point::operator=(const Point& rhs) {
    if (this != &rhs) {
        ptX = rhs.ptX;
        ptY = rhs.ptY;
    }
    // Assignment changes coordinates, but keeps this point's identity.
    return *this;
}
void Point::setX(double x) { ptX = x; }
void Point::setY(double y) { ptY = y; }
double Point::getX() const { return ptX; }
double Point::getY() const { return ptY; }
int Point::getId() const { return id; }
int Point::counter() { return count; }

double Point::distance(const Point& first, const Point& second) {
    double dx = first.ptX - second.ptX;
    double dy = first.ptY - second.ptY;
    return sqrt(dx * dx + dy * dy);
}
double Point::distance(const Point& other) const {
    return distance(*this, other);
}
void Point::display() const {
    ios::fmtflags oldFlags = cout.flags();
    streamsize oldPrecision = cout.precision();
    cout << fixed << setprecision(2);
    cout << "X-coordinate: " << ptX << '\n';
    cout << "Y-coordinate: " << ptY << '\n';
    cout.flags(oldFlags);
    cout.precision(oldPrecision);
}
