/*
 * File Name: rectangle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */
 
#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(int x, int y, int sideA, int sideB, const char* name)
	: Shape(x, y, name), Square(x, y, sideA, name), side_b(sideB){}

int Rectangle::get_side_b() const{return side_b;}

void Rectangle::set_side_b(int sideB){side_b = sideB;}

int Rectangle::area() const{return get_side_a() * side_b;}

int Rectangle::perimeter() const{return 2 * (get_side_a() + side_b);}

void Rectangle::display() const{
	cout<< "\nRectangle Name: " << getName() << "\n";
	getOrigin().display();
    cout << "Side a: " << get_side_a() << "\n";
    cout << "Side b: " << side_b << "\n";
    cout << "Area: " << area() << "\n";
    cout << "Perimeter: " << perimeter() << endl;
}