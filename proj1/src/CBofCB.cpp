//
// file:    CBofCB.cpp
// version: 0.2.0
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
    InnerCB m_buffers[m_obCapacity];
    m_obSize = 0;
    m_oldest = 0;
    m_newest = 0;
}

// copy constructor
CBofCB::CBofCB(const CBofCB& other)
{
    *m_buffers = *other.m_buffers;
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
    // check if queue is full
    // if so throw exception
    if (isFull()) {
        throw new overflow_error("Buffer is full");
    }

    // try to store item in queue
    // if overflow, create a new queue and store it in that
    try {
        m_buffers[m_newest]->enqueue(data);
    } catch(overflow_error e1) {
        // create new queue
        m_obSize++;
        m_buffers[m_obSize] = new InnerCB(m_buffers[m_newest]->size() * 2);

        // store data in newest queue
        m_buffers[m_newest]->enqueue(data);

        // calculate new newest index
        m_newest = (m_newest + 1) % m_obCapacity;
    }
}

// remove item from this data structure
int CBofCB::dequeue()
{
    // get data from oldest queue
    int data = m_buffers[m_oldest]->dequeue();

    // check if oldest queue is now empty
    // if so, deallocate it
    if (m_buffers[m_oldest]->isEmpty()) {
        delete m_buffers[m_oldest];
    }

    // return dequeued data
    return data;
}

// returns true if cannot add more items
bool CBofCB::isFull()
{
    return m_buffers[m_newest]->isFull();
} 

// returns true if no items stored in data structure
bool CBofCB::isEmpty()
{
    for (int i = 0; i < m_obSize; i++) {
        if (!m_buffers[i]->isEmpty()) {
            return false;
        }
    }

    return true;
}

// number of items in the data structure as a whole.
// Note: not the number of InnerCB's
int CBofCB::size()
{
    return m_obSize;
}

// overloaded assignment operator
const CBofCB& CBofCB::operator=(const CBofCB& rhs)
{
    // copy object data
    *m_buffers  = *rhs.m_buffers;
    m_obSize    = rhs.m_obSize;
    m_oldest    = rhs.m_oldest;
    m_newest    = rhs.m_newest;
}

// debugging function, prints out contents of data structure
void CBofCB::dump()
{
}


