/*
 * File Name: circle.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : virtual public Shape {
private:
    double radius;
public:
    Circle(double x, double y, double r, const char* name);
    double get_radius() const;
    virtual void set_radius(double r);
    double area() const override;
    double perimeter() const override;
    void display() const override;
};
#endif
