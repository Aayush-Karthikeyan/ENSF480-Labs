/*
 * File Name: square.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

// Square and Circle share one Shape subobject inside CurveCut.
class Square : virtual public Shape {
private:
    double side_a;
public:
    Square(double x, double y, double sideA, const char* name);
    double get_side_a() const;
    virtual void set_side_a(double sideA);
    double area() const override;
    double perimeter() const override;
    void display() const override;
};
#endif
