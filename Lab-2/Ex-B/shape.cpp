/*
 * File Name: shape.cpp
 * Assignment: Lab 2 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 20, 2026
 */

#include "shape.h"
#include <cstring>
#include <iostream>
using namespace std;

static char* copyString(const char* s){
	if (s == nullptr) s = "";
	char* p = new char[strlen(s) + 1];
	strcpy(p, s);
	return p;
}

Shape::Shape(int x, int y, const char* name): origin(x,y){
	shapeName = copyString(name);
}

Shape::Shape(const Shape& src): origin(src.origin){
	shapeName = copyString(src.shapeName);
}

Shape::~Shape(){
	delete[] shapeName;
}

Shape& Shape::operator=(const Shape& rhs){
	if(this != &rhs){
		char* newName = copyString(rhs.shapeName);
		delete[] shapeName;
		shapeName = newName;
		origin = rhs.origin;
	}
	return *this;
}

void Shape::display() const{
	cout<<"Shape Name: "<<shapeName<<endl;
	origin.display();
}
	
const Point& Shape::getOrigin() const{return origin;}

const char* Shape::getName() const {return shapeName;}
	
double Shape::distance(Shape& the_shape, Shape& other){
	return Point::distance(the_shape.origin, other.origin);
}

double Shape::distance(Shape& other){
	return Point::distance(origin, other.origin);
}


void Shape::move(double dx, double dy){
    origin.setX(static_cast<int>(origin.getX() + dx));
    origin.setY(static_cast<int>(origin.getY() + dy));	
}