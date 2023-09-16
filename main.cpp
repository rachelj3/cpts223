#include "wrapper.h"

int main(void)
{
	//ADVANTAGES / DISADVANTAGES LINKED LIST :
	/*
	Advantage: Easily able to insert at front, low time complexity to insert. Easy to delete terms, as links can just be reassigned
	Disadvantage: Not easy to pull random values. In array, random number could be created and used as the index to select a random value. 
	Instead, the linked list had to be traversed in random intervals to procure random values from it.
	*/

	//ADVANTAGES / DISADVANTAGES Arrays :
	/*
	Advantage: Lower time committment to set up, does not require as many functions as linked list. Allowed for random access. In consecutive memmory
	Disadvantage: Inserting values at 0 made for a difficult process, having to traverse to back of array, and then move back to front, sliding each
	item up one slot, as to make room for a new value. This added more time complexity to the project. 
	*/

	srand((unsigned int)time(NULL));
	Wrapper gameWrap;
	gameWrap.playGame();
	return 0;
}
