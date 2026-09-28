/*
 * File Name: circle.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 28, 2026
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape  {
private:
    int radius;

public:
    Circle(int x, int y, int r, const char*name);
    void setRadius(int r);
    int getRadius() const;

    virtual int area() const;
    virtual int perimeter() const;
    virtual void display() const;
    
};
#endif
