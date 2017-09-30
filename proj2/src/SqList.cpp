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
#include <string>

////////////////////////////////////////////////////////////////////////////////
// NAMESPACES
////////////////////////////////////////////////////////////////////////////////

// STL namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS/DESTRUCTORS
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Default constructor
 */
SqList::SqList(void)
{
}

/**
 * \brief Parameterized constructor
 */
SqList::SqList(OuterList l)
{
    L = l;
}

/**
 * \brief Copy constructor
 *
 * \details Creates a new `SqList` object from a given object of the same class,
 *          then deallocates the old object.
 */
SqList::SqList(const SqList& rhs)
{
    L = rhs.getList();
}

/**
 * \brief Destructor
 */
SqList::~SqList(void)
{
    //TODO: What needs to be deleted? (anything?)
}

//////////////////////////////////////////////////////////////////////////// 
// OPERATOR OVERLOADS
//////////////////////////////////////////////////////////////////////////// 

/**
 * \brief Assignment operator overload
 *
 * \details Implements assignment logic for the list.
 *
 * \return Pointer to the current object
 */
const SqList& SqList::operator=(const SqList& rhs)
{
    L = rhs.getList();
    return *this;
}

/**
 * \brief Bracket operator overload
 *
 * \details Implements read-write access to a data element in the list located 
 *          at the given index
 *
 * \param[in] pos The index of the data element to return/set
 *
 * \return Address of affected data element
 */
Int341& SqList::operator[](int pos)
{
    Int341 data;

    // Check if requested index is out-of-range (less than 0 or greater than
    // the total number of items in the list). If so, throw an exception.
    if (pos < 0 || pos > numItems()) {
        throw out_of_range(string("Index ") + to_string(pos) + 
            string(" invalid for square list of size ") + 
            to_string(numItems()));
    }

    for (OuterList::const_iterator i = L.begin(); i != L.end(); ++i) {
        // For each inner list, check if the list size is less than the 
        // requested index. If so, decrement the index by the list size and 
        // proceed to check the next inner list.
        if (i->size() < pos) {
            pos -= i->size();
            continue;
        }

        // Once the largest inner list is found that can contain the data
        // at the requested index, advance a new iterator to that index and
        // capture the data contained therein.
        else {
            InnerList::const_iterator j = i->begin();
            advance(j, pos);
            data = *j;
            break;
        }
    }

    return data;
}

//////////////////////////////////////////////////////////////////////////// 
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////// 

void SqList::consolidate(void)
{
    OuterList::const_iterator i;
    InnerList::const_iterator j;
    
    for (i = L.begin(); i != L.end(); ++i) {
        for (j = i->begin(); j != i->end(); ++j) {

        }
    }
}

void SqList::addFirst(const Int341& x)
{
    // Update size count and consolidate the list
    size++;
    consolidate();
}

void SqList::addLast(const Int341& x)
{
    // Update size count and consolidate the list
    size++;
    consolidate();
}

void SqList::add(int pos, const Int341& x)
{
    // Update size count and consolidate the list
    size++;
    consolidate();
}

/**
 * \brief Removes the first data element from the square list.
 *
 * \details Essentially performs a dequeue operation (remove then return). Also
 *          consolidates the list after removal but before returning.
 *
 * \throws out_of_range if the list is empty
 *
 * \return The removed data element
 */
Int341 SqList::removeFirst(void)
{
    if (numItems == 0) throw out_of_range("Cannot remove element from empty list");

    // Update size count and consolidate the list
    size--;
    consolidate();

    return Int341();
}

/**
 * \brief Removes the last data element from the square list.
 *
 * \details Essentially performs a dequeue operation (remove then return). Also
 *          consolidates the list after removal but before returning.
 *
 * \throws out_of_range if the list is empty
 *
 * \return The removed data element
 */
Int341 SqList::removeLast(void)
{
    if (numItems == 0) throw out_of_range("Cannot remove element from empty list");

    // Update size count and consolidate the list
    size--;
    consolidate();

    return Int341();
}

/**
 * \brief Removes the data element at the given position from the square list.
 *
 * \details Essentially performs a dequeue operation (remove then return). Also
 *          consolidates the list after removal but before returning.
 *
 * \param[in] pos Index of data element to remove
 *
 * \throws out_of_range if the list is empty
 *
 * \return The removed data element
 */
Int341 SqList::remove(int pos)
{
    if (numItems == 0) throw out_of_range("Cannot remove element from empty list");

    // Update size count and consolidate the list
    size--;
    consolidate();

    return Int341();
}

/**
 * \brief Returns the index of the first occurrence of `data` in the square list.
 *
 * \param[in] data Data element to search for
 *
 * \return A numeric index at which the first instance of `data` can be found, or
 *         -1 if `data` was not found anywhere in the list.
 */
int SqList::indexOf(const Int341& data)
{
    OuterList::const_iterator i;
    InnerList::const_iterator j;
    int index = 0;
    
    // Iterate over the outer list and each subsequent inner list until the first
    // element containing the desired data is found. Because we are using iterators
    // to traverse the lists we have to keep track of the index.
    for (i = L.begin(); i != L.end(); ++i) {
        for (j = i->begin(); j != i->end(); ++j) {
            if (j->m_data == data.m_data) {
                return index;
            }

            index++;
        }
    }    
    
    return -1;
}

/**
 * \brief Returns the number of items in the list
 *
 * \details Does NOT update the item count member variable `size` before returning,
 *          only returns its latest value. This is because the project requirements
 *          state that the function must run in constant time. A recount would 
 *          violate this requirement. If an exact, on-demand list size is required,
 *          use `countItems()`.
 *
 * \return Number of items in the list
 */
int SqList::numItems(void)
{
    return size;
}

/**
 * \brief Returns the number of items in the list
 *
 * \details Counts the number of items in the list by iteration. Runs in O(n) time.
 *
 * \return Number of items in the list
 */
int SqList::countItems(void)
{
    OuterList::const_iterator i;
    int count = 0;

    for (i = L.begin(); i != L.end(); ++i) {
        count += i->size();
    }

    return count;
}

/**
 * \brief Prints the contents of the square list to stdout.
 */
void SqList::dump(void)
{
}
