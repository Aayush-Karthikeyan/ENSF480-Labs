/*
 * File Name: curveCut.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "curveCut.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

CurveCut::CurveCut(double x, double y, double width, double length, double r,
                   const char* name)
    : Shape(x, y, name), Rectangle(x, y, width, length, name),
      Circle(x, y, r, name) {
    check_dimensions(width, length, r);
}
CurveCut::CurveCut(const CurveCut& source)
    : Shape(source), Rectangle(source), Circle(source) {}

CurveCut& CurveCut::operator=(const CurveCut& rhs) {
    if (this != &rhs) {
        // Copy the shared Shape once. The source dimensions are already valid.
        Shape::operator=(rhs);
        Rectangle::set_side_a(rhs.get_side_a());
        Rectangle::set_side_b(rhs.get_side_b());
        Circle::set_radius(rhs.get_radius());
    }
    return *this;
}
void CurveCut::check_dimensions(double width, double length, double r) const {
    if (!isfinite(width) || !isfinite(length) || !isfinite(r) ||
        width < 0 || length < 0 || r < 0 || r > width || r > length) {
        cerr << "Error: CurveCut needs non-negative dimensions and a radius "
             << "no greater than its smaller side.\n";
        exit(EXIT_FAILURE);
    }
}
void CurveCut::set_side_a(double width) {
    check_dimensions(width, get_side_b(), get_radius());
    Rectangle::set_side_a(width);
}
void CurveCut::set_side_b(double length) {
    check_dimensions(get_side_a(), length, get_radius());
    Rectangle::set_side_b(length);
}
void CurveCut::set_radius(double r) {
    check_dimensions(get_side_a(), get_side_b(), r);
    Circle::set_radius(r);
}
double CurveCut::area() const {
    return Rectangle::area() - Circle::area() / 4;
}
double CurveCut::perimeter() const {
    // Two straight sections of length r are replaced by a quarter-circle arc.
    return Rectangle::perimeter() - 2 * get_radius() + Circle::perimeter() / 4;
}
void CurveCut::display() const {
    cout << "CurveCut Name: " << getName() << '\n';
    getOrigin().display();
    cout << "Width: " << get_side_a() << '\n';
    cout << "Length: " << get_side_b() << '\n';
    cout << "Radius of the cut: " << get_radius() << '\n';
}
