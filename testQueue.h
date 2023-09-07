//#pragma once
#include "queue.h"

/*************************************************************
* Function: testSize()
* Description: tests to see if the size function is working
* Initial Error: test failed
* Solution to Error: size was returning a number one higher than accurate
*************************************************************/
void testSize(void);

/*************************************************************
* Function: testIsEmpty()
* Description: tests to see if the isEmpty function is working
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
*************************************************************/
void testIsEmpty(void);

/*************************************************************
* Function: testIsFull()
* Description: tests to see if the IsFull function is working
* Initial Error: test passed
* Solution to Error: none needed
*************************************************************/
void testIsFull(void);

/*************************************************************
* Function: testDequeueEmpty()
* Description: tests to see if the dequeue function is working on an empty queue
* Initial Error: test passed
* Solution to Error: none needed
*************************************************************/
void testDequeueEmpty(void);

/*************************************************************
* Function: testDequeueFull()
* Description: tests to see if the dequeue function is working on an full queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
*************************************************************/
void testDequeueFull(void);

/*************************************************************
* Function: testEnqueueEmpty()
* Description: tests to see if the enqueue function is working on an empty queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
*************************************************************/
void testEnqueueEmpty(void);

/*************************************************************
* Function: testEnqueueNotEmpty()
* Description: tests to see if the enqueue function is working on a not empty queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
*************************************************************/
void testEnqueueNotEmpty(void);

/*************************************************************
* Function: testPeekEmpty()
* Description: tests to see if the peek function is working on an empty queue
* Initial Error: test passed
* Solution to Error: none needed
*************************************************************/
void testPeekEmpty(void);

/*************************************************************
* Function: testPeekFull()
* Description: tests to see if the peek function is working on an full queue
* Initial Error: test failed
* Solution to Error: two issues needed to be fixed. Peek is supposed to return what is at the front of the queue, 
* previous function was trying to return rear. Additionally, items were not actually being added to the queue, so their
* values could not actually be returned using the old version of peek
*************************************************************/
void testPeekFull(void);
