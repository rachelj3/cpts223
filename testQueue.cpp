//#pragma once
#include "testQueue.h"

/*************************************************************
* Function: testSize()
* Description: tests to see if the size function is working
* Initial Error: test failed
* Solution to Error: size was returning a number one higher than accurate
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
* Function: testIsEmpty()
* Description: tests to see if the isEmpty function is working
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
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
* Function: testIsFull()
* Description: tests to see if the IsFull function is working
* Initial Error: test passed
* Solution to Error: none needed
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
* Function: testDequeueFull()
* Description: tests to see if the dequeue function is working on an full queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
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
* Function: testDequeueFull()
* Description: tests to see if the dequeue function is working on an full queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
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
* Function: testEnqueueEmpty()
* Description: tests to see if the enqueue function is working on an empty queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
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
* Function: testEnqueueNotEmpty()
* Description: tests to see if the enqueue function is working on a not empty queue
* Initial Error: test failed
* Solution to Error: function used size(), test passed when size() was fixed
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
* Function: testPeekEmpty()
* Description: tests to see if the peek function is working on an empty queue
* Initial Error: test passed
* Solution to Error: none needed
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
* Function: testPeekFull()
* Description: tests to see if the peek function is working on an full queue
* Initial Error: test failed
* Solution to Error: two issues needed to be fixed. Peek is supposed to return what is at the front of the queue,
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