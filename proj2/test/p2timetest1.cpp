// File: p2timetest1.cpp
//
// UMBC Fall 2017 CMSC 341 Project 2
// 
// Timing runs to show expected O(n^(1.5)) running time.
//

#include <iostream> 
#include "SqList.h"
#include "Int341.h"

using namespace std ;

int p2timetest1() {
   SqList S ;
   int n = 15000 ;

   Int341::m_debug = false ;

   // add lots of items
   //
   for (int i=0 ; i < 2*n ; i++) {
     S.addLast(Int341(i)) ;
   }
   for (int i=0 ; i < 2*n ;i++) {
     S.addFirst(Int341(i*i)) ;
   }

   // remove half
   //
   Int341 result ;
   for (int i=0 ; i < n ; i++) {
      result = S.removeFirst() ; 
   }
   for (int i=0 ; i < n ; i++) {
      result = S.removeLast() ; 
   }

   return 0 ;
}
