/**
 * file: Test.cpp
 * version: 0.1.0
 * author: Jamison Bryant <jbryant93@umbc.edu>
 *
 * UMBC CMSC341 Fall 2017 (Chang)
 * Project 2
 *
 * Implementation file for the Test class. Contains of all of the test methods
 * defined for the project so that they can be called from main().
 */

 ////////////////////////////////////////////////////////////////////////////////
 // INCLUDES
 ////////////////////////////////////////////////////////////////////////////////

// Project includes
#include "Test.h"
#include "SqList.h"
#include "Int341.h"

// STL includes
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// NAMESPACES
////////////////////////////////////////////////////////////////////////////////

// STL namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS/DESTRUCTOR
////////////////////////////////////////////////////////////////////////////////

Test::Test() { }
Test::~Test() { }

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////////////////////////////////

/**
 * Square list inspector helper (provided - do not modify)
 */
void SqList::inspector()
{
    cout << "\n\n == == == == == == == == == == == == == == == == == == == == == == = \n";
    cout << "SqList::inspector() report\n";
    cout << " == == == == == == == == == == == == == == == == == == == == == == = \n";

    bool errorFound = false;

    int n = numItems();

    list< list<Int341> >::iterator it;


    // calculate total number of items in data structure
    //
    int sum = 0;
    for (it = L.begin(); it != L.end(); it++) {
        sum += it->size();
    }


    // report on size()
    //
    if (n == sum) {
        cout << "numItems() correct\n";
    }
    else {
        errorFound = true;
        cout << "*** numItems() wrong! " << endl
            << "    numItems() = " << n << endl
            << "    sum of sizes = " << sum << endl;
    }


    // special case if no items
    //
    if (L.size() == 0) {
        cout << "Empty SqList, nothing more to check\n";
        return;
    }


    // Run down the outer list and check if there are any
    // of these errors: empty list, list too long, adjacent
    // short lists.
    //
    int prevSize, currSize;
    bool prevIsShort = false;
    bool currIsShort;

    int index = 0;

    for (it = L.begin(); it != L.end(); it++) {

        currSize = it->size();

        if (currSize == 0) {    // empty?
            errorFound = true;
            currIsShort = true;
            cout << "*** Inner list " << index << " empty! " << endl;

        }
        else if (currSize * currSize > 4 * n + 4) {   // too long?
            errorFound = true;
            cout << "*** Inner list " << index << " too long! " << endl
                << "    inner list size  = " << currSize << endl
                << "    sum of sizes = " << n << endl;

        }
        else if (4 * currSize * currSize <= n - 1) {  // too short?
            currIsShort = true;
            if (prevIsShort) {  // adjacent shorts?
                errorFound = true;
                cout << "*** Adjacent short inner lists found! " << endl
                    << "    sum of sizes = " << n << endl
                    << "    inner list " << index - 1 << " has size  = " << prevSize << endl
                    << "    inner list " << index << " has size  = " << currSize << endl;
            }
        }
        else {
            currIsShort = false;
        }
        prevSize = currSize;
        prevIsShort = currIsShort;
        index++;
    }

    if (!errorFound) {
        cout << "No errors found!\n";
    }

    cout << " == == == == == == == == == == == == == == == == == == == == == == = \n";
}

/**
 * Composition test (provided - do not modify)
 */
int Test::comptest(void)
{
    SqList S;

    Int341::m_debug = false;

    // Use add and remove functions

    for (int i = 0; i < 100; i++) {
        S.addLast(Int341(i));
    }

    for (int i = 0; i < 100; i++) {
        S.addFirst(Int341(i*i));
    }

    Int341 result;
    for (int i = 0; i < 50; i++) {
        result = S.removeFirst();
    }
    for (int i = 0; i < 50; i++) {
        result = S.removeLast();
    }

    S.dump();
    Int341::report();
    S.inspector();

    Int341 answer;

    for (int i = 1; i < 9; i += 7) {
        S.add(i, i*i);
    }

    for (int i = 5; i < 18; i += 3) {
        answer = S.remove(i);
    }

    S.dump();
    Int341::report();
    S.inspector();

    SqList T(S);
    SqList U;
    U = T;

    U.dump();

    for (int i = 0; i < U.numItems(); i++) {
        cout << "U[" << i << "] = " << U[i].m_data << endl;
    }

    for (int i = 0; i < U.numItems(); i += 7) {
        U[i] = 1000 + i;
        cout << "U[" << i << "] = " << U[i].m_data << endl;
    }

    U.dump();
    Int341::report();

    U.inspector();

    return 0;
}

/**
 * Time test 1 (provided - do not modify)
 */
int Test::timetest1(void) 
{
    SqList S;
    int n = 15000;

    Int341::m_debug = false;

    // add lots of items
    for (int i = 0; i < 2 * n; i++) {
        S.addLast(Int341(i));
    }
    for (int i = 0; i < 2 * n; i++) {
        S.addFirst(Int341(i*i));
    }

    // remove half
    Int341 result;
    for (int i = 0; i < n; i++) {
        result = S.removeFirst();
    }
    for (int i = 0; i < n; i++) {
        result = S.removeLast();
    }

    return 0;
}

/**
 * Time test 2 (provided - do not modify)
 */
int Test::timetest2(void) 
{
    SqList S;
    int n = 30000;

    Int341::m_debug = false;

    // add lots of items
    for (int i = 0; i < 2 * n; i++) {
        S.addLast(Int341(i));
    }
    for (int i = 0; i < 2 * n; i++) {
        S.addFirst(Int341(i*i));
    }

    // remove half
    Int341 result;

    for (int i = 0; i < n; i++) {
        result = S.removeFirst();
    }

    for (int i = 0; i < n; i++) {
        result = S.removeLast();
    }

    return 0;
}

/**
 * Time test 3 (provided - do not modify)
 */
int Test::timetest3(void)
{
    SqList S;
    int n = 60000;

    Int341::m_debug = false;

    // add lots of items
    for (int i = 0; i < 2 * n; i++) {
        S.addLast(Int341(i));
    }

    for (int i = 0; i < 2 * n; i++) {
        S.addFirst(Int341(i*i));
    }

    // remove half
    Int341 result;

    for (int i = 0; i < n; i++) {
        result = S.removeFirst();
    }

    for (int i = 0; i < n; i++) {
        result = S.removeLast();
    }

    return 0;
}

/**
 * \brief Tests the functionality of the copy constructor
 *
 * \return 0 if test passes, otherwise 1
 */
int Test::testCopyConstructor(void)
{
    cout << "Running test #" << ++testNum << ": " << __FUNCTION__ << "...";

    SqList s1;
    SqList s2;

    //TODO: Add items to s1's list

    s2 = SqList(s1);

    //TODO: Check if s2's list is identical to s1's

    return 0;
}

/**
 * \brief Tests the functionality of the nested iterators in the consolidate() function
 *
 * \return 0 if test passes, otherwise 1
 */
int Test::testNestedIterators(void)
{
    cout << "Running test #" << ++testNum << ": " << __FUNCTION__ << "...";

    SqList::OuterList l;

    //TODO: Add items to list

    SqList s(l);

    return 0;
}

/**
 * \brief Tests the functionality of the nested iterators in the consolidate() function
 *
 * \return 0 if test passes, otherwise 1
 */
int Test::testBracketOperators(void)
{
    cout << "Running test #" << ++testNum << ": " << __FUNCTION__ << "...";

    SqList l;

    //TODO: Add items to list

    //TODO: Retrieve elements at various specific indices
    if (l[0].m_data != 1) return 1;
    if (l[2].m_data != 2) return 1;
    if (l[4].m_data != 3) return 1;
    if (l[6].m_data != 6) return 1;
    if (l[8].m_data != 9) return 1;

    return 0;
}

