// File Name: dictionaryList.cpp
// Assignment: Lab 1 Exercise B
// Lab Section: LAB B01
// Completed by: Aayush Karthikeyan (UCID# 30189743), Sarvesh Vettrivelan (UCID# 30242015)
// Submission Date: Sept 14, 2026

#include "dictionaryList.h"
#include <cassert>

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(nullptr), cursorM(nullptr)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
  : sizeM(0), headM(nullptr), cursorM(nullptr)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != nullptr;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const string& datumA)
{
  // Add new node at head?
  if (headM == nullptr || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
  // Overwrite datum at head?
  else if (keyA == headM->keyM) {
    headM->datumM = datumA;
  }
  // Search downstream
  else {
    for (Node *p = headM; p != nullptr; p = p->nextM) {
      if (keyA == p->keyM) {
        p->datumM = datumA;
        cursorM = nullptr;
        return;
      }
    }
        
    Node *p = headM->nextM;
    Node *prev = headM;
        
    while (p != nullptr && keyA > p->keyM) {
      prev = p;
      p = p->nextM;
    }
        
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = nullptr;
}

void DictionaryList::remove(const int& keyA)
{
  cursorM = nullptr;

  if (headM == nullptr || keyA < headM->keyM)
    return;
    
  Node *doomed_node = nullptr;
    
  if (keyA == headM->keyM) {
    doomed_node = headM;
    headM = headM->nextM;
  }
  else {
    Node *before = headM;
    Node *maybe_doomed = headM->nextM;
    while (maybe_doomed != nullptr && keyA > maybe_doomed->keyM) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }
        
    if (maybe_doomed != nullptr && maybe_doomed->keyM == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
    }
  }

  if (doomed_node != nullptr) {
    delete doomed_node;
    sizeM--;
  }
}

void DictionaryList::go_to_first()
{
  cursorM = headM;
}

void DictionaryList::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
  destroy();
}

void DictionaryList::find(const Key& keyA)
{
  for (Node *p = headM; p != nullptr; p = p->nextM) {
    if (keyA == p->keyM) {
      cursorM = p;
      return;
    }
  }
  cursorM = nullptr;
}

void DictionaryList::destroy()
{
  Node *p = headM;
  Node *prev = nullptr;
  while (p != nullptr) {
    prev = p;
    p = p->nextM;
    delete prev;
  }
  headM = nullptr;
  cursorM = nullptr;
  sizeM = 0;
}

void DictionaryList::copy(const DictionaryList& source)
{
  headM = nullptr;
  cursorM = nullptr;
  sizeM = 0;

  if (source.headM == nullptr)
    return;
    
  try {
    headM = new Node(source.headM->keyM, source.headM->datumM, nullptr);
    Node *newest = headM;
    sizeM++;

    if (source.headM == source.cursorM)
      cursorM = newest;

    for (const Node *src = source.headM->nextM; src != nullptr; src = src->nextM) {
      newest->nextM = new Node(src->keyM, src->datumM, nullptr);
      newest = newest->nextM;
      sizeM++;

      if (src == source.cursorM)
        cursorM = newest;
    }
  }
  catch (...) {
    // A failed constructor will not call this object's destructor.
    destroy();
    throw;
  }
}
