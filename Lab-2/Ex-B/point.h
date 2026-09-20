/*
 * File Name: point.h
 * Assignment: Lab 2 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 20, 2026
 */

#ifndef POINT_H
#define POINT_H

class Point {
private:
    int ptX;
    int ptY;
    int id;
	static int count;
	static int nextId; 
	
public:
    Point(int x, int y);
	Point(const Point& ptsrc);
    ~Point();
    Point& operator=(const Point& rhs);

    void display() const;
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;

    static int counter();

    double distance(const Point& otherpt) const;
    static double distance(const Point& p1, const Point& p2);
};

#endif
