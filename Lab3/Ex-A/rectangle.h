/*
 * File Name: rectangle.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "square.h"

class Rectangle : public Square {
private:
    double side_b;
public:
    Rectangle(double x, double y, double sideA, double sideB, const char* name);
    double get_side_b() const;
    virtual void set_side_b(double sideB);
    double area() const override;
    double perimeter() const override;
    void display() const override;
};
#endif
