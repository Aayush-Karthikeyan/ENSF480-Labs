/*
 * File Name: point.h
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef POINT_H
#define POINT_H

class Point {
private:
    double ptX;
    double ptY;
    int id;
    static int count;
    static int nextId;
public:
    Point(double x, double y);
    Point(const Point& source);
    ~Point();
    Point& operator=(const Point& rhs);
    void display() const;
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    int getId() const;
    static int counter();
    double distance(const Point& other) const;
    static double distance(const Point& first, const Point& second);
};
#endif
