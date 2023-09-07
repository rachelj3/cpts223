// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn


#include "testQueue.h"

// define default capacity of the queue

//Answers to analysis questions
//1. All declarations and definitions were placed in main. Files should be broken up into .h and .cpp files for readability
//2. Items in the queue were not actually being added. Values were printed, however the values were not being stored
//3. An array was probably not the best structure for this project, a linked list structure using queue principles would be better
//4. Functions were very dependant, using other functions in their defintions. When size() was incorrect, this caused other functions to also be incorrect
//5. Comment blocks on class member functions should be more robust, including things like input/output, pre and post conditions, and update status

// main function
int main()
{
    // call your test functions here!
    testSize();
    testIsEmpty();
    testIsFull();

    testDequeueEmpty();
    testDequeueFull();

    testEnqueueEmpty();
    testEnqueueNotEmpty();

    testPeekEmpty();
    testPeekFull();
    return 0;
}

