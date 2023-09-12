// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn


#include "testQueue.h"

// define default capacity of the queue

//// Class for queue
//class queue
//{
//    int* arr;		// array to store queue elements
//    int capacity;	// maximum capacity of the queue
//    int front;		// front points to front element in the queue (if any)
//    int rear;		// rear points to last element in the queue
//    int count;		// current size of the queue
//
//public:
//    queue(int size = SIZE); 	// constructor
//    ~queue();   				// destructor
//
//    void dequeue();
//    void enqueue(int x);
//    int peek();
//    int size();
//    bool isEmpty();
//    bool isFull();
//};
//
//// Constructor to initialize queue
//queue::queue(int size)
//{
//    arr = new int[size];
//    capacity = size;
//    front = 0;
//    rear = -1;
//    count = 0;
//}
//
//// Destructor to free memory allocated to the queue
//queue::~queue()
//{
//    delete arr; // you are not required to test this function;
//    // however, are there issues with it?
//}
//
//// Utility function to remove front element from the queue
//void queue::dequeue()
//{
//    // check for queue underflow
//    if (isEmpty())
//    {
//        cout << "UnderFlow\nProgram Terminated\n";
//        return;
//    }
//
//    cout << "Removing " << arr[front] << '\n';
//
//    front = (front + 1) % capacity;
//    count--;
//}
//
//// Utility function to add an item to the queue
//void queue::enqueue(int item)
//{
//    // check for queue overflow
//    if (isFull())
//    {
//        cout << "OverFlow\nProgram Terminated\n";
//        return;
//    }
//
//    cout << "Inserting " << item << '\n';
//
//    rear = (rear + 1) % capacity;
//    arr[rear] = size();
//    count++;
//}
//
//// Utility function to return front element in the queue
//int queue::peek()
//{
//    if (isEmpty())
//    {
//        cout << "UnderFlow\nProgram Terminated\n";
//        return numeric_limits<int>::min();
//    }
//    return arr[rear];
//}
//
//// Utility function to return the size of the queue
//int queue::size()
//{
//    return count + 1;
//}
//
//// Utility function to check if the queue is empty or not
//bool queue::isEmpty()
//{
//    return (size() == 0);
//}
//
//// Utility function to check if the queue is full or not
//bool queue::isFull()
//{
//    return (capacity = size() - 1);
//}

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

