#ifndef _TEST_H_
#define _TEST_H_

/**
 * file: Test.h
 * version: 0.1.0
 * author: Jamison Bryant <jbryant93@umbc.edu>
 * 
 * UMBC CMSC341 Fall 2017 (Chang)
 * Project 2
 *
 * Header file for the Test class. 
 */

class Test
{
public:
    //////////////////////////////////////////////////////////////////////////// 
    // CONSTRUCTORS/DESTRUCTOR
    //////////////////////////////////////////////////////////////////////////// 

    Test();
    ~Test();

    //////////////////////////////////////////////////////////////////////////// 
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////// 

    // Provided tests
    int comptest(void);
    int timetest1(void);
    int timetest2(void);
    int timetest3(void);

    // Custom tests
    int testCopyConstructor(void);
    int testNestedIterators(void);
    int testBracketOperators(void);

private:

    //////////////////////////////////////////////////////////////////////////// 
    // PRIVATE MEMBERS
    //////////////////////////////////////////////////////////////////////////// 

    int testNum = 0;    /**< Number of test being executed */
};

#endif // _TEST_H_
