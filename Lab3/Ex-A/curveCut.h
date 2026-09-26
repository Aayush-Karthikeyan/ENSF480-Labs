/*
 * File Name: curveCut.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef CURVECUT_H
#define CURVECUT_H
#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle {
private:
    void check_dimensions(double width, double length, double r) const;
public:
    CurveCut(double x, double y, double width, double length, double r,
             const char* name);
    CurveCut(const CurveCut& source);
    CurveCut& operator=(const CurveCut& rhs);
    void set_side_a(double width) override;
    void set_side_b(double length) override;
    void set_radius(double r) override;
    double area() const override;
    double perimeter() const override;
    void display() const override;
};
#endif
