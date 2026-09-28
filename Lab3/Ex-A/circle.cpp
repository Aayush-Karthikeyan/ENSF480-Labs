/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */

#include "circle.h"
#include <iostream>
#define PI 3.14
using namespace std;

Circle::Circle(int x, int y, int r, const char*name) 
            : Shape(x, y, name), radius(r){}

void Circle::setRadius(int r) {radius = r;}

int Circle::getRadius() const {return radius;}

int Circle::area() const {return (int)(PI * radius * radius);}

int Circle::perimeter() const {return (int)(2 * PI * radius);}

void Circle::display() const {
    cout<<"Circle Name: "<<getName()<<endl;
    getOrigin().display();
    cout<<"Radius: "<<getRadius()<<"\n";
    cout<<"Area: "<< area()<<"\n";
    cout<<"Perimeter: "<< perimeter()<<"\n";
}