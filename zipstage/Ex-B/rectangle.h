/*
 * File Name: rectangle.h
 * Assignment: Lab 2 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 20, 2026
 */
 
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle : public Square {
private:
	int side_b;
public:
	Rectangle(int x, int y, int sideA, int sideB, const char* name);
	int get_side_b() const;
	void set_side_b(int sideB);
	
	virtual int area() const;
	virtual int perimeter() const;
	virtual void display() const;
};
#endif