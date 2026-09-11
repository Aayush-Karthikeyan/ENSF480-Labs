// File Name: point.h
// Assignment: Lab 1 Exercise D
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: Sept 14, 2026

#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;     // x coordinate of a location on Cartesian Plane
    double y;     // y coordinate of a location on Cartesian Plane
public:
    Point(double a = 0.0, double b = 0.0);
    double get_x() const;
    double get_y() const;
    void set_x(double a);
    void set_y(double a);
};

#endif