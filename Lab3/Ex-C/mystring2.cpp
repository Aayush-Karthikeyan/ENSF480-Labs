/*
 * File Name: mystring2.cpp
 * Assignment: Lab 3 Exercise C
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "mystring2.h"
#include <cassert>
#include <cstring>

Mystring::Mystring() : lengthM(0), charsM(new char[1]) {
    charsM[0] = '\0';
}
Mystring::Mystring(int n) : lengthM(0), charsM(nullptr) {
    assert(n > 0);
    charsM = new char[n];
    charsM[0] = '\0';
}
Mystring::Mystring(const char* s) : lengthM(0), charsM(nullptr) {
    assert(s != nullptr);
    lengthM = static_cast<int>(std::strlen(s));
    charsM = new char[lengthM + 1];
    std::strcpy(charsM, s);
}
Mystring::Mystring(const Mystring& source)
    : lengthM(source.lengthM), charsM(new char[source.lengthM + 1]) {
    std::strcpy(charsM, source.charsM);
}
Mystring::~Mystring() { delete[] charsM; }
Mystring& Mystring::operator=(const Mystring& rhs) {
    if (this != &rhs)
        set_str(rhs.charsM);
    return *this;
}
int Mystring::length() const { return lengthM; }
char Mystring::get_char(int pos) const {
    assert(pos >= 0 && pos < lengthM);
    return charsM[pos];
}
const char* Mystring::c_str() const { return charsM; }
void Mystring::set_char(int pos, char c) {
    assert(pos >= 0 && pos < lengthM && c != '\0');
    charsM[pos] = c;
}
Mystring& Mystring::append(const Mystring& other) {
    int newLength = lengthM + other.lengthM;
    char* tmp = new char[newLength + 1];
    std::strcpy(tmp, charsM);
    std::strcat(tmp, other.charsM);
    delete[] charsM;
    charsM = tmp;
    lengthM = newLength;
    return *this;
}
void Mystring::set_str(const char* s) {
    assert(s != nullptr);
    int newLength = static_cast<int>(std::strlen(s));
    // Copy before deleting so s may refer to part of this string.
    char* tmp = new char[newLength + 1];
    std::strcpy(tmp, s);
    delete[] charsM;
    charsM = tmp;
    lengthM = newLength;
}
bool Mystring::operator<(const Mystring& rhs) const {
    return std::strcmp(charsM, rhs.charsM) < 0;
}
bool Mystring::operator>(const Mystring& rhs) const { return rhs < *this; }
bool Mystring::operator==(const Mystring& rhs) const {
    return std::strcmp(charsM, rhs.charsM) == 0;
}
bool Mystring::operator!=(const Mystring& rhs) const { return !(*this == rhs); }
bool Mystring::operator<=(const Mystring& rhs) const { return !(rhs < *this); }
bool Mystring::operator>=(const Mystring& rhs) const { return !(*this < rhs); }
std::ostream& operator<<(std::ostream& os, const Mystring& s) {
    return os << s.charsM;
}
