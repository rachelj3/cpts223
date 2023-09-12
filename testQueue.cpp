//#pragma once
#include "testQueue.h"

/*************************************************************
* Test ID: testSize()
Unit: queue::size ()
Description: test to determine if queue::size () is working correctly
Test steps:
1. Construct an empty queue object
2. add values to queue
3. see if sizes matches number of values added 
Test data: size = 3
Precondition: queue object is empty
Postcondition: queue object has 3 items
Expected result: queue has three items
Actual result: size did not match 3
Status: failed
Solution to Failure: size was returning a number one higher than accurate
*************************************************************/
void testSize(void)
{
	int testSize = 3;
	queue tester(testSize);
	tester.enqueue(54);
	tester.enqueue(55);
	tester.enqueue(56);
	if (tester.size() == testSize)
	{
		cout << "Size test has passed" << endl;
	}
	else
	{
		cout << "Size test has failed" << endl;
	}
}

/*************************************************************
* Test ID: testIsEmpty()
Unit: queue::isEmpty ()
Description: test to determine if queue::isEmpty () is working correctly
Test steps:
1. Construct an empty queue object
2. call isEmpty test
3. if comes back true, test passed
Test data: size = 3
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: queue comes back as empty
Actual result: queue did not come back as empty
Status: failed
Solution to Failure: function used size(), test passed when size() was fixed
*************************************************************/
void testIsEmpty(void)
{
	bool emptyTester;
	queue tester(3);
	emptyTester = tester.isEmpty();
	if (emptyTester == true)
	{
		cout << "Is Empty test has passed" << endl;
	}
	else
	{
		cout << "Is Empty test has failed" << endl;
	}
}

/*************************************************************
* Test ID: testIsFull()
Unit: queue::isFull ()
Description: test to determine if queue::isFull () is working correctly
Test steps:
1. Construct an empty queue object
2. Add values to queue to fill it
3. call isFull test
4. if comes back true, test passed
Test data: size = 3
Precondition: queue object is full
Postcondition: queue object is full
Expected result: queue comes back as full
Actual result: queue came back as full
Status: passed
Solution to Failure: none needed
*************************************************************/
void testIsFull(void)
{
	bool fullTester;
	queue tester(3);
	tester.enqueue(54);
	tester.enqueue(55);
	tester.enqueue(56);
	fullTester = tester.isFull();
	if (fullTester == true)
	{
		cout << "Is Full test has passed" << endl;
	}
	else
	{
		cout << "If Full test has failed" << endl;
	}
}

/*************************************************************
* Test ID: testDequeueEmpty()
Unit: queue::dequeue ()
Description: test to determine if queue::dequeue () is working correctly on a empty queue
Test steps:
1. Construct an empty queue object
2. call dequeue
3. if size == 0, test passed
Test data: size = 3
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: size comes back as empty
Actual result: size came back as zero
Status: passed
Solution to Failure: none needed
*************************************************************/
void testDequeueEmpty(void)
{
	queue tester(3);
	tester.dequeue();
	if (tester.size() == 0)
	{
		cout << "Dequeue Test on Empty has passed" << endl;
	}
	else
	{
		cout << "Dequeue Test on Empty has failed" << endl;
	}

}

/*************************************************************
* Test ID: testDequeueFull()
Unit: queue::dequeue ()
Description: test to determine if queue::dequeue () is working correctly on a full queue
Test steps:
1. Construct an empty queue object
2. add 3 values to fill queue
3. call dequeue
4. if size == 2, test passed
Test data: size = 3
Precondition: queue object is full
Postcondition: queue object is one less than full
Expected result: size comes back as 2
Actual result: size came back as not 2
Status: failed
Solution to Failure: function used size(), test passed when size() was fixed
*************************************************************/
void testDequeueFull(void)
{
	queue tester(3);
	tester.enqueue(54);
	tester.enqueue(55);
	tester.enqueue(56);
	tester.dequeue();
	if (tester.size() == 2)
	{
		cout << "Dequeue test on Full has passed" << endl;
	}
	else
	{
		cout << "Dequeue test on Full has failed" << endl;
	}
}

/*************************************************************
* Test ID: testEnqueueEmpty()
Unit: queue::enqueue ()
Description: test to determine if queue::enqueue () is working correctly on a empty queue
Test steps:
1. Construct an empty queue object
2. call enqueue
3. if size == 1, test passed
Test data: size = 3
Precondition: queue object is empty
Postcondition: queue object has one object
Expected result: size comes back as one
Actual result: size came back as not one
Status: failed
Solution to Failure: function used size(), test passed when size() was fixed
*************************************************************/
void testEnqueueEmpty(void)
{
	queue tester(3);
	tester.enqueue(55);
	if (tester.size() == 1)
	{
		cout << "Enqueue test on Empty has passed" << endl;
	}
	else
	{
		cout << "Enqueue test on Empty has failed" << endl;
	}
}

/*************************************************************
* Test ID: testEnqueueNotEmpty()
Unit: queue::enqueue ()
Description: test to determine if queue::enqueue () is working correctly on a not empty
Test steps:
1. Construct an empty queue object
2. add 2 values to queue
3. if size == 2, test passed
Test data: size = 3
Precondition: queue object has two values
Postcondition: queue object has two values
Expected result: size comes back as 2
Actual result: size came back as not 2
Status: failed
Solution to Failure: function used size(), test passed when size() was fixed
*************************************************************/
void testEnqueueNotEmpty(void)
{
	queue tester(3);
	tester.enqueue(54);
	tester.enqueue(55);
	if (tester.size() == 2)
	{
		cout << "Enqueue test on not empty has passed" << endl;
	}
	else
	{
		cout << "Enqueue test on not empty has failed" << endl;
	}
}

/*************************************************************
* Test ID: testPeekEmpty()
Unit: queue:: peek ()
Description: test to determine if queue::peek () is working correctly on a empty queue
Test steps:
1. Construct an empty queue object
2. call peek on queue
Test data: size = 3
Precondition: queue object is empty
Postcondition: queue object peek returns nothing
Expected result: peek came back with nothing
Actual result: peek came back with nothing
Status: passed
Solution to Failure: none needed
*************************************************************/
void testPeekEmpty(void)
{
	int testInt = 3;
	queue tester(3);
	if (tester.peek() != testInt)
	{
		cout << "Peek test on empty has passed" << endl;
	}
	else
	{
		cout << "Peek test on empty has failed" << endl;
	}
}

/*************************************************************
* Test ID: testPeekFull()
Unit: queue:: peek ()
Description: test to determine if queue::peek () is working correctly on a full queue
Test steps:
1. Construct an empty queue object
2. add three values to queue
3. call peek and see if value matches first value added
Test data: size = 3
Precondition: queue object is empty
Postcondition: queue object has three values
Expected result: peek came back with expected value
Actual result: peek came back with queue index
Status: failed
Solution to Failure: two issues needed to be fixed. Peek is supposed to return what is at the front of the queue,
* previous function was trying to return rear. Additionally, items were not actually being added to the queue, so their
* values could not actually be returned using the old version of peek
*************************************************************/
void testPeekFull(void)
{
	queue tester(3);
	tester.enqueue(54);
	tester.enqueue(55);
	tester.enqueue(56);
	if (tester.peek() == 54)
	{
		cout << "Peek test on full has passed" << endl;
	}
	else
	{
		cout << "Peek test on full has failed" << endl;
	}
}