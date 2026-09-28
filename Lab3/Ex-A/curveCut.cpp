/*
 * File Name: curveCut.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */

#include "curveCut.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

CurveCut::CurveCut(int x, int y, int width, int length, int curve_radius, const char* name) 
    : Shape(x, y, name), Rectangle(x, y, width, length, name), Circle(x, y, curve_radius, name){
        check_dimensions(width, length, curve_radius);
    }

CurveCut::CurveCut(const CurveCut& other) 
    : Shape(other),Rectangle(other), Circle(other) {}

CurveCut& CurveCut::operator=(const CurveCut& rhs) {
    if(this != &rhs){
        Shape::operator=(rhs);
        Rectangle::set_side_a(rhs.get_side_a());
        Rectangle::set_side_b(rhs.get_side_b());
        Circle::setRadius(rhs.getRadius());
    }
    return *this;
}

void CurveCut::check_dimensions(int width, int length, int curve_radius) const {
    if (curve_radius > width || curve_radius > length){
        cout<<"\nCurve Radius cannot be greater than width or length"<<"\n"; 
        exit(EXIT_FAILURE);
    }
}

void CurveCut::setWidth(int width) {
    check_dimensions(width, get_side_b(), getRadius());
    Rectangle::set_side_a(width);
}

void CurveCut::setLength(int length){
    check_dimensions(get_side_a(), length, getRadius());
    Rectangle::set_side_b(length);
}

void CurveCut::setCurveRadius(int curve_radius){
    check_dimensions(get_side_a(), get_side_b(), curve_radius);
    Circle::setRadius(curve_radius);
}

int CurveCut::area() const {return ((Rectangle::area()) - (Circle::area()/4));}

int CurveCut::perimeter() const {return Rectangle::perimeter() - 2*getRadius() + Circle::perimeter()/4;}

void CurveCut::display() const {
    cout << "CurveCut Name: " << getName() << '\n';
    getOrigin().display();
    cout << "Width: " << get_side_a() << '\n';
    cout << "Length: " << get_side_b() << '\n';
    cout << "Radius of the cut: " << getRadius() << '\n';

}