/*
 * File Name: shape.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "shape.h"
#include <cstring>
#include <iostream>
using namespace std;

static char* copyString(const char* s) {
    if (s == nullptr)
        s = "";
    char* p = new char[strlen(s) + 1];
    strcpy(p, s);
    return p;
}
Shape::Shape(double x, double y, const char* name)
    : origin(x, y), shapeName(copyString(name)) {}
Shape::Shape(const Shape& source)
    : origin(source.origin), shapeName(copyString(source.shapeName)) {}
Shape::~Shape() { delete[] shapeName; }

Shape& Shape::operator=(const Shape& rhs) {
    if (this != &rhs) {
        char* newName = copyString(rhs.shapeName);
        delete[] shapeName;
        shapeName = newName;
        origin = rhs.origin;
    }
    return *this;
}
void Shape::display() const {
    cout << "Shape Name: " << shapeName << '\n';
    origin.display();
}
const Point& Shape::getOrigin() const { return origin; }
const char* Shape::getName() const { return shapeName; }
double Shape::distance(const Shape& first, const Shape& second) {
    return Point::distance(first.origin, second.origin);
}
double Shape::distance(const Shape& other) const {
    return Point::distance(origin, other.origin);
}
void Shape::move(double dx, double dy) {
    origin.setX(origin.getX() + dx);
    origin.setY(origin.getY() + dy);
}
