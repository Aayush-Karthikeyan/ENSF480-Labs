/*
 * File Name: mystring2.h
 * Assignment: Lab 3 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class Mystring {
    friend std::ostream& operator<<(std::ostream& os, const Mystring& s);
private:
    int lengthM;
    char* charsM;
public:
    Mystring();
    explicit Mystring(int n);
    Mystring(const char* s);
    Mystring(const Mystring& source);
    ~Mystring();
    Mystring& operator=(const Mystring& rhs);
    int length() const;
    char get_char(int pos) const;
    const char* c_str() const;
    void set_char(int pos, char c);
    Mystring& append(const Mystring& other);
    void set_str(const char* s);
    bool operator<(const Mystring& rhs) const;
    bool operator>(const Mystring& rhs) const;
    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;
    bool operator<=(const Mystring& rhs) const;
    bool operator>=(const Mystring& rhs) const;
};
#endif
