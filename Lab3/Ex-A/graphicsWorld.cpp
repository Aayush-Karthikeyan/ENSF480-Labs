/*
 * File Name: graphicsWorld.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "graphicsWorld.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "curveCut.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

void GraphicsWorld::run() {
    cout << "Lab 3 by Sarvesh Vettrivelan and Aayush Karthikeyan" << endl;

    cout << "\nTesting functions in class Square:" << endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();

    cout << "\nTesting functions in class Rectangle:" << endl;
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();

    cout << "\nTesting functions in class Circle:" << endl;
    Circle c(3, 5, 9, "CIRCLE C");
    c.display();
    cout << "The area of " << c.getName() << " is: " << c.area() << endl;
    cout << "The perimeter of " << c.getName() << " is: " << c.perimeter() << endl;
    double d = a.distance(c);
    cout << "The distance between rectangle a and circle c is: " << d << endl;

    cout << "\nTesting functions in class CurveCut:" << endl;
    CurveCut rc(6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
    cout << "The area of " << rc.getName() << " is: " << rc.area() << endl;
    cout << "The perimeter of " << rc.getName() << " is: " << rc.perimeter() << endl;
    d = rc.distance(c);
    cout << "The distance between rc and c is: " << d << endl;

    cout << "\nTesting an array of Shape pointers:" << endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &a;
    sh[2] = &c;
    sh[3] = &rc;
    for (int i = 0; i < 4; i++) {
        sh[i]->display();
        cout << "The area of " << sh[i]->getName() << " is: " << sh[i]->area() << endl;
        cout << "The perimeter of " << sh[i]->getName()
             << " is: " << sh[i]->perimeter() << endl << endl;
    }

    cout << "Testing copy constructor in class CurveCut:" << endl;
    CurveCut cc = rc;
    cc.display();
    assert(cc.getName() != rc.getName());
    assert(strcmp(cc.getName(), rc.getName()) == 0);

    cout << "\nTesting assignment operator in class CurveCut:" << endl;
    CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    cc2.display();
    cc2 = cc;
    cc2.display();
    assert(cc2.getName() != cc.getName());
    assert(strcmp(cc2.getName(), cc.getName()) == 0);

    cout << "\nProgram terminated successfully." << endl;
}
