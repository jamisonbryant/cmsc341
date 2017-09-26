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
#include <iomanip>
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
    // initialize object data
    *m_buffers = new InnerCB[m_obCapacity];
    m_obSize = 0;
    m_oldest = 0;
    m_newest = 0;

    // create first circular buffer
    m_buffers[0] = new InnerCB(10);
    m_obSize++;

    // create rest of circular buffers
    for (int i = 1; i < m_obCapacity; i++) {
        m_buffers[i] = new InnerCB(0);
    }
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
    delete *m_buffers;
}

// add item to this data structure
void CBofCB::enqueue(int data)
{
    // check if all queues are full
    // if so throw exception
    if (isFull()) {
        throw new overflow_error("Buffer is full");
    }

    // try to store item in queue
    // if overflow, create a new queue and store it in that
    try {
        m_buffers[m_newest]->enqueue(data);
    } catch(overflow_error* e1) {
        // calculate new indexes
        int oldCapacity = m_buffers[m_newest]->size();
        m_newest = (m_newest + 1) % m_obCapacity;

        // create new queue
        m_buffers[m_newest] = new InnerCB(oldCapacity * 2);
        m_obSize++;

        // store data in newest queue
        m_buffers[m_newest]->enqueue(data);
    }
}

// remove item from this data structure
int CBofCB::dequeue()
{
    if (isEmpty()) {
        throw new underflow_error("Buffer is empty");
    } else {
        // get data from oldest queue
        int data = m_buffers[m_oldest]->dequeue();

        // check if oldest queue is now empty
        // if so, deallocate it
        // (but only if there is at least one other queue in the buffer)
        if (m_buffers[m_oldest]->isEmpty()) {
            if (m_obSize > 1) {
                delete m_buffers[m_oldest];
                m_obSize--;
            }
            
            //m_oldest = (m_obCapacity + m_oldest - 1) % m_obCapacity;
            m_oldest = (m_oldest + 1) % m_obCapacity;
        }

        // return dequeued data
        return data;
    }
}

// returns true if cannot add more items
bool CBofCB::isFull()
{
    return (m_obSize == m_obCapacity) && m_buffers[m_newest]->isFull();
} 

// returns true if no items stored in data structure
bool CBofCB::isEmpty()
{
    // @hack: this is risky, because if the for loop somehow gets to an
    // uninitialized item in the queue the program will crash. This
    // logic depends on the method returning before that happens, which
    // I'm not sure I can guarantee. We'll see if the tests pass.
    for (int i = 0; i < m_obCapacity; i++) {
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
    int totalSize = 0;

    for (int i = 0; i < m_obSize; i++) {
        totalSize += m_buffers[i]->size(); 
    }

    return totalSize;
}

// overloaded assignment operator
const CBofCB& CBofCB::operator=(const CBofCB& rhs)
{
    for (int i = 0; i < rhs.m_obSize; i++) {
        *m_buffers[i]  = *rhs.m_buffers[i];
    }
    
    // copy rest of object data
    m_obSize    = rhs.m_obSize;
    m_oldest    = rhs.m_oldest;
    m_newest    = rhs.m_newest;
}

// debugging function, prints out contents of data structure
void CBofCB::dump()
{
    if (m_obSize > 0) {
        cout << "CBofCB@" << this << " {" << endl;
        cout << "    size: " << m_obSize << "," << endl;
        cout << "    data: {" << endl;

        for (int i = 0; i < m_obCapacity; i++) {
            cout << "        [" << i << "] ";

            if (i == m_oldest && i != m_newest) {
                cout << "(O)";
            } else if (i == m_newest && i != m_oldest) {
                cout << "(N)";
            } else if (i == m_oldest && i == m_newest) {
                cout << "(B)";
            }  else {
                cout << "(?)";
            }
             
            //m_buffers[i]->dump();     // uncomment for verbose dump
            
            cout << " " << m_buffers[i]->size() << "/" 
                 << m_buffers[i]->capacity();

            if (i < m_obCapacity - 1) cout << "," << endl;
        }

        cout << endl << "    }" << endl;
        cout << "}" << endl;
    } else {
        cout << "CBofCB " << this << " {" << endl;
        cout << "    size: " << m_obSize << "," << endl;
        cout << "    data: { }" << endl;
        cout << "}" << endl;
    }
} 


