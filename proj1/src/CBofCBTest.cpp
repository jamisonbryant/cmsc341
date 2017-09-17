#include "CBofCB.h"
#include <iostream>

using namespace std;

int main()
{
    CBofCB cb;

    // Stage 1: Add 5 numbers
    cb.enqueue(1);
    cb.enqueue(2);
    cb.enqueue(3);
    cb.enqueue(4);
    cb.enqueue(5);
    cb.dump();

    // Stage 2: Add 7 more numbers
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.dump();
    
    // Stage 3: Remove 2 numbers
    cb.dequeue();
    cb.dequeue();
    cb.dump();

    // Stage 4: Add a shitload more numbers
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.enqueue(20);
    cb.enqueue(19);
    cb.enqueue(18);
    cb.enqueue(17);
    cb.enqueue(16);
    cb.enqueue(15);
    cb.enqueue(14);
    cb.dump();
 

    return 0;
}
