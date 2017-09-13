//
// file:    CBofCB.cpp
// version: 0.1.0
//
// UMBC CMSC341 Fall 2017 Project 1
//
// Implementation file for a Circular Buffer of Circular Buffers.
// See project description for details.
//
// Written by: Jamison Bryant <jbryant2@umbc.edu>
// Copyright (c) 2017 Jamison Bryant. All rights reserved.
// Licensed under the MIT license.
//

//==============================================================================
// INCLUDES
//==============================================================================

// Local includes
#include "CBofCB.h"
#include "InnerCB.h"

// C++ includes
#include <iostream>
#include <stdexcept>

//==============================================================================
// NAMESPACES
//==============================================================================

using namespace std;

//==============================================================================
// IMPLEMENTATIONS
//==============================================================================

// default constructor
CBofCB::CBofCB()
{
    InnerCB* m_buffers[m_obCapacity];
    int m_obSize;
    int m_oldest;
    int m_newest;
}

// copy constructor
CBofCB::CBofCB(const CBofCB& other)
{
    m_buffers[m_obCapacity] = *other.m_buffers;
    m_obSize = other.m_obSize;
    m_oldest = other.m_oldest;
    m_newest = other.m_newest;
}

// destructor
CBofCB::~CBofCB()
{
}

// add item to this data structure
void CBofCB::enqueue(int data)
{
    m_buffers[m_newest]->enqueue(data);
}

// remove item from this data structure
int CBofCB::dequeue()
{
    return m_buffers[m_oldest]->dequeue();
}

// returns true if cannot add more items
bool CBofCB::isFull()
{
} 

// returns true if no items stored in data structure
bool CBofCB::isEmpty()
{
}

// number of items in the data structure as a whole.
// Note: not the number of InnerCB's
int CBofCB::size()
{
}

// overloaded assignment operator
const CBofCB& CBofCB::operator=(const CBofCB& rhs)
{
    // copy object data
    //m_buffers   = rhs.m_buffers;
    m_obSize    = rhs.m_obSize;
    m_oldest    = rhs.m_oldest;
    m_newest    = rhs.m_newest;
}

// debugging function, prints out contents of data structure
void CBofCB::dump()
{
}


