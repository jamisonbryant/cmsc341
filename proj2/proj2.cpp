/**
 * file: proj2.cpp
 * version: 0.1.0
 * author: Jamison Bryant <jbryant93@umbc.edu>
 *
 * UMBC CMSC341 Fall 2017 (Chang)
 * Project 2
 *
 * Driver file for testing the Project 2 square list implementation.
 */

 ////////////////////////////////////////////////////////////////////////////////
 // INCLUDES
 ////////////////////////////////////////////////////////////////////////////////

 // Project includes
#include "Test.h"

// STL includes
#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////////
// NAMESPACES
////////////////////////////////////////////////////////////////////////////////

// STL namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// MAIN METHOD
////////////////////////////////////////////////////////////////////////////////

/**
 * Provides a menu for running project tests
 */
int main()
{
    cout << string(50, '\n');

    cout << "************************************************************************" << endl;
    cout << "CMSC 341 Project 2 Driver File" << endl;
    cout << "By: Jamison Bryant <jbryant93@umbc.edu>" << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    cout << "Available tests:" << endl;
    cout << "    1) Composition test" << endl;
    cout << "    2) Timing test 1" << endl;
    cout << "    3) Timing test 2" << endl;
    cout << "    4) Timing test 3" << endl;
    cout << "    5) Quit" << endl << endl;

    bool chosen = false;
    while (!chosen) {
        int choice = 0;
        cout << "Please choose a test: ";
        cin >> choice;

        Test test;
        switch (choice) {
            case 1:
                // Run composition test
                chosen = true;
                cout << endl << endl << "Running composition test..." << endl;
                cout << string(50, '\n');
                test.comptest();
                break;

            case 2:
                // Run time test 1
                chosen = true;
                cout << endl << endl << "Running time test 1..." << endl;
                cout << string(50, '\n');
                test.timetest1();
                break;

            case 3:
                // Run time test 2
                chosen = true;
                cout << endl << endl << "Running time test 2..." << endl;
                cout << string(50, '\n');
                test.timetest2();
                break;

            case 4:
                // Run time test 3
                chosen = true;
                cout << endl << endl << "Running time test 3..." << endl;
                cout << string(50, '\n');
                test.timetest3();
                break;

            case 5:
                // Exit program
                cout << endl << endl << "Exiting..." << endl;
                chosen = true;
                return 0;

            default:
                // Invalid choice: re-prompt
                cout << "Invalid choice. Please choose again." << endl;
                break;
        }
    }

    return 0;
}

