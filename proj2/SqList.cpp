/**
 * file: SqList.cpp
 * version: 0.1.0
 * author: Jamison Bryant <jbryant93@umbc.edu>
 * 
 * UMBC CMSC341 Fall 2017 (Chang)
 * Project 2
 *
 * Implementation file for the SqList (Square List) class. See project 
 * description in README.txt for details.
 */

////////////////////////////////////////////////////////////////////////////////
// INCLUDES
////////////////////////////////////////////////////////////////////////////////

// Project includes
#include "SqList.h"
#include "Int341.h"

// STL includes
#include <list>

////////////////////////////////////////////////////////////////////////////////
// NAMESPACES
////////////////////////////////////////////////////////////////////////////////

// STL namespaces
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS/DESTRUCTORS
////////////////////////////////////////////////////////////////////////////////

SqList::SqList(void)
{
}

SqList::SqList(const SqList& rhs)
{
}

SqList::~SqList(void)
{
}

//////////////////////////////////////////////////////////////////////////// 
// OPERATOR OVERLOADS
//////////////////////////////////////////////////////////////////////////// 

const SqList& SqList::operator=(const SqList& rhs) 
{
    return SqList();
}

Int341& SqList::operator[](int pos)
{
    return Int341();
}

//////////////////////////////////////////////////////////////////////////// 
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////// 

void SqList::consolidate(void)
{
}

void SqList::addFirst(const Int341& x)
{
    
}

void SqList::addLast(const Int341& x)
{
}

void SqList::add(int pos, const Int341& x)
{
}

Int341 SqList::removeFirst(void)
{
    return Int341();
}

Int341 SqList::removeLast(void)
{
    return Int341();
}

Int341 SqList::remove(int pos)
{
    return Int341();
}

int SqList::indexOf(const Int341& data)
{
    return 0;
}

int SqList::numItems(void)
{
    return 0;
}

void SqList::dump(void)
{
}
