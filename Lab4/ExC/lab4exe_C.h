/*
 * File Name: lab4exe_C.h
 * Assignment: Lab 4 Exercise C
 * Completed By:
 *      - Aayush Karthikeyan (UCID# 30189743)
 *      - Sarvesh Vettrivelan (UCID# 30242015)
 * Submission Date: Oct. 4, 2026
 */

#ifndef LAB4EXE_C_H
#define LAB4EXE_C_H

#include <string>
using std::string;

// «interface» Moveable
class Moveable {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Moveable() {}
};

// Resizeable (lollipop notation = interface)
class Resizeable {
public:
    virtual void enlarge(int n) = 0;
    virtual void shrink(int n) = 0;
    virtual ~Resizeable() {}
};

// Abstract class (italic name) realizing both interfaces
class Vehicle : public Moveable, public Resizeable {
protected:
    string name;
public:
    Vehicle(string name);
    virtual void move() = 0;
    virtual ~Vehicle() {}
};

// {leaf} -> final: cannot be inherited from
class Car final : public Vehicle {
private:
    int seats;
public:
    void turn();
};

#endif