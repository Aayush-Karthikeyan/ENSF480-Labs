/*
 * File Name: curveCut.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */

#ifndef CURVECUT_H
#define CURVECUT_H

#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle {
private:
    void check_dimensions(int width, int length, int curve_radius) const;
    
public:
    CurveCut(int x, int y, int width, int length, int curve_radius, const char* name);
    CurveCut(const CurveCut& other);
    CurveCut& operator=(const CurveCut& rhs);

    virtual void setWidth(int width);
    virtual void setLength(int length);
    virtual void setCurveRadius(int curve_radius);

    virtual int area() const;
    virtual int perimeter() const;
    virtual void display() const;
};
#endif