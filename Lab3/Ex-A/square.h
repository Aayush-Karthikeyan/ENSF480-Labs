/*
 * File Name: square.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */
 
#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : virtual public Shape {
private:
	int side_a;
public:
	Square(int x, int y, int sideA, const char* name);
	int get_side_a() const;
	void set_side_a(int sideA);
	
	virtual int area() const override;
	virtual int perimeter() const override;
	virtual void display() const;
};
#endif
