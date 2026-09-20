/*
 * File Name: shape.h
 * Assignment: Lab 2 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 20, 2026
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape{
private:
	Point origin;
	char* shapeName;

public:
	Shape(int x, int y, const char* name);
	Shape(const Shape& src);
	virtual ~Shape();
	Shape& operator=(const Shape& rhs);
	virtual void display() const;
	
	const Point& getOrigin() const;
	const char* getName() const;
	
	double distance(Shape& other);
	static double distance(Shape& the_shape, Shape& other); 
	void move(double dx, double dy);
	
	
};
#endif
