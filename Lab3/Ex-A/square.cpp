/*
 * File Name: square.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */
 
#include "square.h"
#include <iostream>
using namespace std;

Square::Square(int x, int y, int sideA, const char* name):Shape(x,y,name), side_a(sideA){}

int Square::get_side_a() const{return side_a;}

void Square::set_side_a(int sideA){side_a = sideA;}

int Square::area() const{return side_a * side_a;}

int Square::perimeter() const{return 4 * side_a;}

void Square::display() const{
	cout<< "Square Name: " << getName() << "\n";
	getOrigin().display();
    cout << "Side a: " << side_a << "\n";
    cout << "Area: " << area() << "\n";
    cout << "Perimeter: " << perimeter() << endl;	
}