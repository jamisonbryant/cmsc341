//
// file:    InnerCB.cpp
// version: 0.1.0
//
// UMBC CMSC341 Fall 2017 Project 1
//
// Implementation file for an Inner Circular Buffer.
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

// constructor; default size is 10
InnerCB::InnerCB(int n)
{
    m_buffer = new int[n];
    m_capacity = n;
    m_size = 0;
    m_start = 0;
    m_end = 0;
}

// copy constructor
InnerCB::InnerCB(const InnerCB& other)
{
    // safely copy buffer data
    m_buffer = new int[other.m_capacity];

    for (int i = 0; i < other.m_capacity; i++) {
        m_buffer[i] = other.m_buffer[i];
    }

    // delete other object's buffer
    delete[] other.m_buffer;

    // copy rest of object data
    m_capacity  = other.m_capacity;
    m_size      = other.m_size;
    m_start     = other.m_start;
    m_end       = other.m_end;
}

// destructor
InnerCB::~InnerCB()
{
    delete[] m_buffer;
}

// add item to circular buffer
void InnerCB::enqueue(int data)
{
    // check if queue is full
    // if so throw exception
    if (isFull()) {
        throw new overflow_error("Queue is full"); 
    }

    // store item in queue
    m_buffer[m_end] = data;
    
    // calculate new end index
    // and update queue size
    m_end = (m_end + 1) % m_capacity;
    m_size++;
}

// remove item from circular buffer
int InnerCB::dequeue()
{
    // check if queue is empty
    // if so throw exception
    if (isEmpty()) {
        throw new underflow_error("Queue is empty");
    }

    // remove item from queue
    int data = m_buffer[m_start];
    m_buffer[m_start] = 0;

    // calculate new start index
    // and update queue size
    m_start = (m_start + 1) % m_capacity;
    m_size--;

    // return dequeued item
    return data;
}

// true if no space left in buffer
bool InnerCB::isFull()
{
    // return if size equals capacity
    return (size() == capacity());
} 

// true if buffer holds no items
bool InnerCB::isEmpty()
{
    // return if size equals 0
    return (size() == 0);
}

// return maximum number of items this buffer can hold
int InnerCB::capacity()
{
    // return queue capacity
    return m_capacity;
}

// return number of items currently held in the buffer
int InnerCB::size()
{
    // return queue size 
    return m_size;
}

// overloaded assignment operator
const InnerCB& InnerCB::operator=(const InnerCB& rhs)
{
    // deallocate memory for LHS object
    delete[] m_buffer;
    
    // safely copy buffer data
    m_buffer = new int[rhs.m_capacity];

    for (int i = 0; i < rhs.m_capacity; i++) {
        m_buffer[i] = rhs.m_buffer[i];
    }

    // copy rest of object data
    m_capacity  = rhs.m_capacity;
    m_size      = rhs.m_size;
    m_start     = rhs.m_start;
    m_end       = rhs.m_end;

    // return the object
    return *this;
}

// debugging function; prints out contents
void InnerCB::dump()
{
    if (m_size != 0) {
        cout << "InnerCB@" << this << " { size: " << m_size 
                << "/" << m_capacity << ", data: ";

        for (int i = 0; i < m_capacity; i++) {
            cout << m_buffer[i];
            if (i < m_capacity - 1) cout << ", ";
        }

        cout << " }";
    } else {
        cout << "InnerCB@" << this << " { size: " << m_size 
                << "/" << m_capacity << ", data: null }";
    }
}


