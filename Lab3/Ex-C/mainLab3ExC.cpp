/*
 * File Name: mainLab3ExC.cpp
 * Assignment: Lab 3 Exercise C
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include <cassert>
#include <cstring>
#include <iostream>
#include "lookupTable.h"
#include "customer.h"
using namespace std;

template <class K, class D>
void print(LookupTable<K, D>& lt);

template <class K, class D>
void try_to_find(LookupTable<K, D>& lt, const K& key);

void test_Customer();
void test_String();
void test_integer();

int main() {
    test_Customer();
    test_String();
    test_integer();

    cout << "\nProgram terminated successfully." << endl;
    return 0;
}

template <class K, class D>
void print(LookupTable<K, D>& lt) {
    if (lt.size() == 0)
        cout << "  Table is EMPTY." << endl;
    for (lt.go_to_first(); lt.cursor_ok(); lt.step_fwd()) {
        cout << lt << endl;
    }
}

template <class K, class D>
void try_to_find(LookupTable<K, D>& lt, const K& key) {
    lt.find(key);
    if (lt.cursor_ok())
        cout << "Found key: " << lt << endl;
    else
        cout << "Sorry, I couldn't find key: " << key << " in the table." << endl;
}

void test_Customer() {
    cout << "\nCreating and testing LookupTable<int, Customer>..." << endl;
    LookupTable<int, Customer> lt;

    Customer a("Joe", "Morrison", "11 St. Calgary", "(403)-1111-123333");
    Customer b("Jack", "Lewis", "12 St. Calgary", "(403)-1111-123334");
    Customer c("Tim", "Hardy", "13 St. Calgary", "(403)-1111-123335");
    lt.insert(Pair<int, Customer>(8002, a));
    lt.insert(Pair<int, Customer>(8004, c));
    lt.insert(Pair<int, Customer>(8001, b));
    assert(lt.size() == 3);
    lt.remove(8004);
    assert(lt.size() == 2);
    cout << "\nPrinting table after inserting 3 new keys and 1 removal:" << endl;
    print(lt);

    cout << "\nLet's look up some names:" << endl;
    try_to_find(lt, 8001);
    try_to_find(lt, 8000);

    cout << "\nTesting the iterator:" << endl;
    LookupTable<int, Customer>::Iterator it = lt.begin();
    cout << "The first node contains: " << *it << endl;
    while (!it) {
        cout << ++it << endl;
    }
    assert(!lt.cursor_ok());

    // Test the copy constructor with the cursor at the second node.
    lt.go_to_first();
    lt.step_fwd();
    LookupTable<int, Customer> clt(lt);
    assert(clt.size() == 2);
    assert(strcmp(clt.cursor_datum().getFname(), "Joe") == 0);
    cout << "\nTest copying: keys should be 8001 and 8002" << endl;
    print(clt);
    lt.remove(8002);
    assert(clt.size() == 2);

    clt = lt;
    assert(clt.size() == 1);
    cout << "\nTest assignment operator: key should be 8001" << endl;
    print(clt);

    lt.make_empty();
    assert(lt.size() == 0);
    cout << "\nPrinting table for the last time: table should be empty" << endl;
    print(lt);
    cout << "*** Finished tests on LookupTable<int, Customer> ***" << endl;
}

void test_String() {
    cout << "\nCreating and testing LookupTable<int, Mystring>..." << endl;
    LookupTable<int, Mystring> lt;

    Mystring a("I am an ENSF 480 student.");
    Mystring b("C++ is a powerful language for engineers but it's not easy.");
    Mystring c("Fall 2026");
    lt.insert(Pair<int, Mystring>(8002, a));
    lt.insert(Pair<int, Mystring>(8001, b));
    lt.insert(Pair<int, Mystring>(8004, c));
    assert(lt.size() == 3);
    lt.remove(8004);
    assert(lt.size() == 2);
    cout << "\nPrinting table after inserting 3 new keys and 1 removal:" << endl;
    print(lt);

    cout << "\nLet's look up some strings:" << endl;
    try_to_find(lt, 8001);
    try_to_find(lt, 8000);

    cout << "\nTesting the iterator:" << endl;
    LookupTable<int, Mystring>::Iterator it = lt.begin();
    cout << "The first node contains: " << *it << endl;
    while (!it) {
        cout << ++it << endl;
    }
    assert(!lt.cursor_ok());

    lt.go_to_first();
    lt.step_fwd();
    LookupTable<int, Mystring> clt(lt);
    assert(clt.size() == 2);
    assert(strcmp(clt.cursor_datum().c_str(), "I am an ENSF 480 student.") == 0);
    cout << "\nTest copying: keys should be 8001 and 8002" << endl;
    print(clt);
    lt.remove(8002);
    assert(clt.size() == 2);

    clt = lt;
    assert(clt.size() == 1);
    cout << "\nTest assignment operator: key should be 8001" << endl;
    print(clt);

    lt.make_empty();
    assert(lt.size() == 0);
    cout << "\nPrinting table for the last time: table should be empty" << endl;
    print(lt);
    cout << "*** Finished tests on LookupTable<int, Mystring> ***" << endl;
}

void test_integer() {
    cout << "\nCreating and testing LookupTable<int, int>..." << endl;
    LookupTable<int, int> lt;

    lt.insert(Pair<int, int>(8002, 9999));
    lt.insert(Pair<int, int>(8001, 8888));
    lt.insert(Pair<int, int>(8004, 8888));
    assert(lt.size() == 3);
    lt.remove(8004);
    assert(lt.size() == 2);
    cout << "\nPrinting table after inserting 3 new keys and 1 removal:" << endl;
    print(lt);

    cout << "\nLet's look up some integers:" << endl;
    try_to_find(lt, 8001);
    try_to_find(lt, 8000);

    cout << "\nTesting the iterator:" << endl;
    LookupTable<int, int>::Iterator it = lt.begin();
    while (!it) {
        cout << ++it << endl;
    }
    assert(!lt.cursor_ok());

    lt.go_to_first();
    lt.step_fwd();
    LookupTable<int, int> clt(lt);
    assert(clt.size() == 2);
    assert(clt.cursor_datum() == 9999);
    cout << "\nTest copying: keys should be 8001 and 8002" << endl;
    print(clt);
    lt.remove(8002);
    assert(clt.size() == 2);

    clt = lt;
    assert(clt.size() == 1);
    cout << "\nTest assignment operator: key should be 8001" << endl;
    print(clt);

    lt.make_empty();
    assert(lt.size() == 0);
    cout << "\nPrinting table for the last time: table should be empty" << endl;
    print(lt);
    cout << "*** Finished tests on LookupTable<int, int> ***" << endl;
}
