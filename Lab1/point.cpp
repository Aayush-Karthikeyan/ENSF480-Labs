// File Name: point.cpp
// Assignment: Lab 1 Exercise D
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: Sept 14, 2026

#include "point.h"

Point::Point(double a, double b) : x(a), y(b) {}

double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}

void Point::set_x(double a) {
    x = a;
}

void Point::set_y(double a) {
    y = a;
}