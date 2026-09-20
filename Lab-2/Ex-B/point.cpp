/*
 * File Name: point.cpp
 * Assignment: Lab 2 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 20, 2026
 */
 
#include "point.h"
#include <iostream>
#include <cmath> 
#include <iomanip>
using namespace std;

int Point::count = 0;
int Point::nextId = 1001;


Point::Point(int x, int y): ptX(x), ptY(y), id(nextId){
	count++;
}

Point::Point(const Point& ptsrc): ptX(ptsrc.ptX), ptY(ptsrc.ptY), id(nextId++) {
    count++;
}

Point::~Point(){
	count--;
}

Point& Point::operator=(const Point& rhs){
	if (this != &rhs){
		ptX = rhs.ptX;
		ptY = rhs.ptY;
	}
	return *this;
}

void Point::setX(int x){
	ptX = x;
}

void Point::setY(int y){
	ptY = y;
}

int Point::getX() const{
	return ptX;
}

int Point::getY() const{
	return ptY;
}

int Point::counter(){
	return count;
}

double Point::distance(const Point& p1, const Point& p2){
	double xcord = p1.getX() - p2.getX();
	double ycord = p1.getY() - p2.getY();
	return sqrt((xcord * xcord) + (ycord * ycord));	
}


double Point::distance(const Point& otherpt) const{
	return distance(*this, otherpt);	
}


void Point::display() const{
	cout << "X-coordinate: " << fixed << setprecision(2) << ptX << endl;
    cout << "Y-coordinate: " << fixed << setprecision(2) << ptY << endl;
}