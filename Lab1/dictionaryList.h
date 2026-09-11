// File Name: dictionaryList.h
// Assignment: Lab 1 Exercise B
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: 14/09/2026 23:59

#ifndef DICTIONARYLIST_H
#define DICTIONARYLIST_H

#include <string>

typedef int Key;
typedef std::string Datum;

class Node {
    friend class DictionaryList;

private:
    Key keyM;
    Datum datumM;
    Node *nextM;

    Node(const Key& keyA, const Datum& datumA, Node *nextA);
};

// A sorted list of unique keys and their associated data.
class DictionaryList {
public:
    DictionaryList();
    DictionaryList(const DictionaryList& source);
    DictionaryList& operator=(const DictionaryList& rhs);
    ~DictionaryList();

    int size() const;
    int cursor_ok() const;
    // These two accessors require a valid cursor.
    const Key& cursor_key() const;
    Datum& cursor_datum() const;

    // Inserting or removing a key invalidates the cursor.
    void insert(const Key& keyA, const Datum& datumA);
    void remove(const Key& keyA);
    void go_to_first();
    void step_fwd(); // Requires a valid cursor.
    void make_empty();
    void find(const Key& keyA); // Invalidates the cursor if the key is absent.

private:
    int sizeM;
    Node *headM;
    Node *cursorM;

    void destroy();
    // Copies nodes and cursor position into an empty list.
    void copy(const DictionaryList& source);
};

#endif
