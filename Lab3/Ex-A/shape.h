/*
 * File Name: shape.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"

class Shape {
private:
    Point origin;
    char* shapeName;
public:
    Shape(double x, double y, const char* name);
    Shape(const Shape& source);
    virtual ~Shape();
    Shape& operator=(const Shape& rhs);
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const;
    const Point& getOrigin() const;
    const char* getName() const;
    double distance(const Shape& other) const;
    static double distance(const Shape& first, const Shape& second);
    void move(double dx, double dy);
};
#endif
