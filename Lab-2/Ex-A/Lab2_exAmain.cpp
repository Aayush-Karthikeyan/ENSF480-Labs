/*
 * File Name: Lab2_exAmain.cpp
 * Assignment: Lab 2 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 20, 2026
 */

#include <assert.h>
#include <iostream>
#include "dictionaryList1.h"

using namespace std;

DictionaryList dictionary_tests();

void print(DictionaryList& dl);

void test_operator_overloading(DictionaryList& dl);

int main()
{
  DictionaryList dl = dictionary_tests();
#if 1
 test_operator_overloading(dl);
#endif
  return 0;
}

DictionaryList dictionary_tests()
{
  
  DictionaryList dl;

  assert(dl.size() == 0);
  cout << "\nPrinting list just after its creation ...\n";
  print(dl);

  // Insert using new keys.
  dl.insert(8001,"Dilbert");
  dl.insert(8002,"Alice");
  dl.insert(8003,"Wally");
  assert(dl.size() == 3);
  cout << "\nPrinting list after inserting 3 new keys ...\n";
  print(dl);
  dl.remove(8002);
  dl.remove(8001);
  dl.insert(8004,"PointyHair");
  assert(dl.size() == 2);
  cout << "\nPrinting list after removing two keys and inserting PointyHair ...\n";
  print(dl);

  // Insert using existing key.
  dl.insert(8003,"Sam");
  assert(dl.size() == 2);
  cout << "\nPrinting list after changing data for one of the keys ...\n";
  print(dl);

  dl.insert(8001,"Allen");
  dl.insert(8002,"Peter");
  assert(dl.size() == 4);
  cout << "\nPrinting list after inserting 2 more keys ...\n";
  print(dl);

  cout << "***----Finished dictionary tests---------------------------***\n\n";
  return dl;
}


void print(DictionaryList& dl)
{
  if (dl.size() == 0)
    cout << "  List is EMPTY.\n";
  for (dl.go_to_first(); dl.cursor_ok(); dl.step_fwd()) {
    cout << "  " << dl.cursor_key();
    cout << "  " << dl.cursor_datum().c_str() << '\n';
  }
}


#if 1
void test_operator_overloading(DictionaryList& dl)
{

    DictionaryList dl2 = dl;
    dl.go_to_first();
    dl.step_fwd();
    dl2.go_to_first();
    // Simce datum is a string object from C++ Libray and most of the operators are
    //overloaded by class string, operators suc as <. >. >=, << works automatically.
    
    cout << "\nTestig a few comparison and insertion operators." << endl;
    
    if(dl.cursor_datum() >= (dl2.cursor_datum()))
       cout << endl << dl.cursor_datum() << " is greater than or equal " << dl2.cursor_datum();
    else
       cout << endl << dl2.cursor_datum() << " is greater than " << dl.cursor_datum();
    
    if(dl.cursor_datum() <= (dl2.cursor_datum()))
        cout << dl.cursor_datum() << " is less than or equal" << dl2.cursor_datum();
    else
        cout << endl << dl2.cursor_datum() << " is less than " << dl.cursor_datum();
    
    if(dl.cursor_datum() != (dl2.cursor_datum()))
        cout << endl << dl.cursor_datum() << " is not equal to " << dl2.cursor_datum();
    else
        cout << endl << dl2.cursor_datum() << " is equal to " << dl.cursor_datum();
    

    if(dl.cursor_datum() > (dl2.cursor_datum()))
        cout << endl << dl.cursor_datum() << " is greater than " << dl2.cursor_datum();
    else
        cout << endl << dl.cursor_datum() << " is not greater than " << dl2.cursor_datum();
    
    if(dl.cursor_datum() < (dl2.cursor_datum()))
        cout << endl << dl.cursor_datum() << " is less than " << dl2.cursor_datum();
    else
        cout << endl << dl.cursor_datum() << " is not less than " << dl2.cursor_datum();
    if(dl.cursor_datum() == (dl2.cursor_datum()))
        cout << endl << dl.cursor_datum() << " is equal to " << dl2.cursor_datum();
    else
        cout << endl << dl.cursor_datum() << " is not equal to " << dl2.cursor_datum();
   cout << endl << "\n Using square bracket [] to access elements of datum objects. ";

    char c = dl.cursor_datum()[1];
    cout << endl << "The socond element of "  << dl.cursor_datum() << " is: " << c;
    
    dl.cursor_datum()[1] = 'o';
    c = dl.cursor_datum()[1];
    cout << endl << "The socond element of "  << dl.cursor_datum() << " is: " << c;

    cout << endl << "\nUsing << to display key/datum pairs in a Dictionary list: \n";
    /* The following line is expected to display the content of the linked list
     * dl2 -- key/datum pairs. It should display:
     *   8001  Allen
     *   8002  Peter
     *   8003  Sam
     *   8004  PointyHair
     */
    cout << dl2;
 
    cout << endl << "\nUsing [] to display the datum only: \n";
    /* The following line is expected to display the content of the linked list
     * dl2 -- datum. It should display:
     *   Allen
     *   Peter
     *   Sam
     *   PointyHair
     */
    
    for(int i =0; i < dl2.size(); i++)
        cout << dl2[i] << endl;
    
    cout << endl << "\nUsing [] to display sequence of charaters in a datum: \n";
    /* The following line is expected to display the characters in the first node
     * of the dictionary. It should display:
     *   A
     *   l
     *   l
     *   e
     *   n
     */
    cout << dl2[0][0] << endl;
    cout << dl2[0][1] << endl;
    cout << dl2[0][2] << endl;
    cout << dl2[0][3] << endl;
    cout << dl2[0][4] << endl;
    
    cout << "\n\n***----Finished tests for overloading operators ----------***\n\n";
}
#endif
