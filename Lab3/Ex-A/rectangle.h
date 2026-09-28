/*
 * File Name: rectangle.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
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
	
	virtual int area() const override;
	virtual int perimeter() const override; 
	virtual void display() const override;
};
#endif