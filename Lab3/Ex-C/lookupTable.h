/*
 * File Name: lookupTable.h
 * Assignment: Lab 3 Exercise C
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

// Based on the linked lookup table supplied for ENSF 480 Lab 3.
#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <cassert>
#include <cstring>
#include <iostream>
#include <utility>

// Keys need a strict ordering. C-string keys are compared by their contents.
template <class K>
bool lt_less(const K& a, const K& b) { return a < b; }

template <>
inline bool lt_less<const char*>(const char* const& a, const char* const& b) {
    return std::strcmp(a, b) < 0;
}
template <>
inline bool lt_less<char*>(char* const& a, char* const& b) {
    return std::strcmp(a, b) < 0;
}

template <class K, class D> class LookupTable;
template <class K, class D>
std::ostream& operator<<(std::ostream& os, const LookupTable<K, D>& lt);

template <class K, class D>
struct Pair {
    Pair(const K& keyA, const D& datumA) : key(keyA), datum(datumA) {}
    K key;
    D datum;
};

template <class K, class D>
class LT_Node {
    friend class LookupTable<K, D>;
private:
    Pair<K, D> pairM;
    LT_Node<K, D>* nextM;
    LT_Node(const Pair<K, D>& pairA, LT_Node<K, D>* nextA)
        : pairM(pairA), nextM(nextA) {}
};

template <class K, class D>
class LookupTable {
    friend std::ostream& operator<< <K, D>(std::ostream& os,
                                          const LookupTable<K, D>& lt);
public:
    // As in the starter code, iterators use their table's shared cursor.
    class Iterator {
    private:
        LookupTable<K, D>* LT;
    public:
        Iterator() : LT(nullptr) {}
        Iterator(LookupTable<K, D>& x) : LT(&x) {}
        const D& operator*() const;
        // Keep the Exercise C starter behavior: return current data, then advance.
        const D& operator++();
        // The starter's postfix version advances first and requires a next node.
        const D& operator++(int);
        // The supplied interface uses !it to mean that the cursor IS valid.
        int operator!() const;
        void step_fwd();
    };

    LookupTable();
    LookupTable(const LookupTable<K, D>& source);
    LookupTable<K, D>& operator=(const LookupTable<K, D>& rhs);
    ~LookupTable();
    LookupTable<K, D>& begin();
    int size() const;
    int cursor_ok() const;
    const K& cursor_key() const;
    const D& cursor_datum() const;
    // Insert replaces an existing key's datum or adds a new pair in order.
    // Insert and remove always put the cursor in the off-list state.
    void insert(const Pair<K, D>& pairA);
    void remove(const K& keyA);
    void find(const K& keyA);
    void go_to_first();
    void step_fwd();
    void make_empty();
private:
    int sizeM;
    LT_Node<K, D>* headM;
    LT_Node<K, D>* cursorM;
    void destroy();
    void copy(const LookupTable<K, D>& source);
};

template <class K, class D>
LookupTable<K, D>::LookupTable() : sizeM(0), headM(nullptr), cursorM(nullptr) {}

template <class K, class D>
LookupTable<K, D>::LookupTable(const LookupTable<K, D>& source)
    : sizeM(0), headM(nullptr), cursorM(nullptr) {
    copy(source);
}

template <class K, class D>
LookupTable<K, D>& LookupTable<K, D>::operator=(const LookupTable<K, D>& rhs) {
    if (this != &rhs) {
        LookupTable<K, D> temp(rhs);
        std::swap(sizeM, temp.sizeM);
        std::swap(headM, temp.headM);
        std::swap(cursorM, temp.cursorM);
    }
    return *this;
}

template <class K, class D>
LookupTable<K, D>::~LookupTable() { destroy(); }

template <class K, class D>
LookupTable<K, D>& LookupTable<K, D>::begin() {
    go_to_first();
    return *this;
}

template <class K, class D>
int LookupTable<K, D>::size() const { return sizeM; }

template <class K, class D>
int LookupTable<K, D>::cursor_ok() const { return cursorM != nullptr; }

template <class K, class D>
const K& LookupTable<K, D>::cursor_key() const {
    assert(cursor_ok());
    return cursorM->pairM.key;
}

template <class K, class D>
const D& LookupTable<K, D>::cursor_datum() const {
    assert(cursor_ok());
    return cursorM->pairM.datum;
}

template <class K, class D>
void LookupTable<K, D>::insert(const Pair<K, D>& pairA) {
    cursorM = nullptr;
    LT_Node<K, D>* before = nullptr;
    LT_Node<K, D>* after = headM;
    while (after != nullptr && lt_less(after->pairM.key, pairA.key)) {
        before = after;
        after = after->nextM;
    }
    // Neither key is less than the other, so they refer to the same entry.
    if (after != nullptr && !lt_less(pairA.key, after->pairM.key)) {
        after->pairM.datum = pairA.datum;
        return;
    }
    LT_Node<K, D>* node = new LT_Node<K, D>(pairA, after);
    if (before == nullptr)
        headM = node;
    else
        before->nextM = node;
    sizeM++;
}

template <class K, class D>
void LookupTable<K, D>::remove(const K& keyA) {
    cursorM = nullptr;
    LT_Node<K, D>* before = nullptr;
    LT_Node<K, D>* node = headM;
    while (node != nullptr && lt_less(node->pairM.key, keyA)) {
        before = node;
        node = node->nextM;
    }
    if (node == nullptr || lt_less(keyA, node->pairM.key))
        return;
    if (before == nullptr)
        headM = node->nextM;
    else
        before->nextM = node->nextM;
    delete node;
    sizeM--;
}

template <class K, class D>
void LookupTable<K, D>::find(const K& keyA) {
    cursorM = headM;
    while (cursorM != nullptr && lt_less(cursorM->pairM.key, keyA))
        cursorM = cursorM->nextM;
    if (cursorM != nullptr && lt_less(keyA, cursorM->pairM.key))
        cursorM = nullptr;
}

template <class K, class D>
void LookupTable<K, D>::go_to_first() { cursorM = headM; }

template <class K, class D>
void LookupTable<K, D>::step_fwd() {
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

template <class K, class D>
void LookupTable<K, D>::make_empty() { destroy(); }

template <class K, class D>
void LookupTable<K, D>::destroy() {
    while (headM != nullptr) {
        LT_Node<K, D>* old = headM;
        headM = headM->nextM;
        delete old;
    }
    cursorM = nullptr;
    sizeM = 0;
}

template <class K, class D>
void LookupTable<K, D>::copy(const LookupTable<K, D>& source) {
    LT_Node<K, D>* tail = nullptr;
    try {
        for (LT_Node<K, D>* p = source.headM; p != nullptr; p = p->nextM) {
            LT_Node<K, D>* node = new LT_Node<K, D>(p->pairM, nullptr);
            if (tail == nullptr)
                headM = node;
            else
                tail->nextM = node;
            tail = node;
            sizeM++;
            if (p == source.cursorM)
                cursorM = node;
        }
    } catch (...) {
        destroy();
        throw;
    }
}

template <class K, class D>
std::ostream& operator<<(std::ostream& os, const LookupTable<K, D>& lt) {
    if (lt.cursor_ok())
        os << lt.cursor_key() << "  " << lt.cursor_datum();
    else
        os << "Not Found.";
    return os;
}

template <class K, class D>
const D& LookupTable<K, D>::Iterator::operator*() const {
    assert(LT != nullptr && LT->cursor_ok());
    return LT->cursor_datum();
}

template <class K, class D>
const D& LookupTable<K, D>::Iterator::operator++() {
    assert(LT != nullptr && LT->cursor_ok());
    const D& value = LT->cursor_datum();
    LT->step_fwd();
    return value;
}

template <class K, class D>
const D& LookupTable<K, D>::Iterator::operator++(int) {
    assert(LT != nullptr && LT->cursorM != nullptr && LT->cursorM->nextM != nullptr);
    LT->step_fwd();
    return LT->cursor_datum();
}

template <class K, class D>
int LookupTable<K, D>::Iterator::operator!() const {
    return LT != nullptr && LT->cursor_ok();
}

template <class K, class D>
void LookupTable<K, D>::Iterator::step_fwd() {
    assert(LT != nullptr && LT->cursor_ok());
    LT->step_fwd();
}

#endif
