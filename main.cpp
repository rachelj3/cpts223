#include "AVLTree.hpp"


int main(void)
{
	int inOrder[50] = {
		1, 3, 5, 7, 9, 11,
		13, 15, 17, 19, 21,
		23, 25, 27, 29, 31,
		33, 35, 37, 39, 41,
		43, 45, 47, 49, 51,
		53, 55, 57, 59, 61,
		63, 65, 67, 69, 71,
		73, 75, 77, 79, 81,
		83, 85, 87, 89, 91,
		93, 95, 97, 99 };

	int desOrder[50]
	{
		99, 97, 95, 93, 91,
		89, 87, 85, 83, 81,
		79, 77, 75, 73, 71,
		69, 67, 65, 63, 61,
		59, 57, 55, 53, 51,
		49, 47, 45, 43, 41,
		39, 37, 35, 33, 31,
		29, 27, 25, 23, 21,
		19, 17, 15, 13, 11,
		9, 7, 5, 3, 1 };

	int randOrder[50]
	{
		97, 85, 61, 37, 7,
		67, 47, 19, 13, 11,
		75, 43, 35, 17, 3,
		99, 57, 27, 23, 15,
		93, 91, 65, 55, 29,
		89, 45, 33, 25, 21,
		79, 71, 51, 59, 39,
		83, 87, 53, 5, 9,
		69, 49, 31, 41, 95,
		1, 81, 77, 73, 63 };

	

	AVLTree<int> inOrderTree, desOrderTree, randOrderTree;
	int index = 0, height = 0, valid = 5, result = 1, flag = 5;

	//in order tree
	for (index = 0; index < 50; ++index)
	{
		inOrderTree.setRoot(inOrderTree.insert(inOrderTree.getRoot(), inOrder[index]));
	}

	//randOrderTree.inOrderPrintHelper(randOrderTree.getRoot());
	height = inOrderTree.returnHeight(inOrderTree.getRoot());
	std::cout << "In order tree height: " << height << std::endl;
	valid = inOrderTree.validateHelper(inOrderTree.getRoot());
	std::cout << "In order tree validity: " << valid << std::endl;

	for (index = 0; index < 100; ++index)
	{
		flag = inOrderTree.contains(index);
		if (flag == 0 && index % 2 != 0)
		{
			result = 0;
		}
	}
	if (result == 0)
	{
		std::cout << "My In Order tree failed" << std::endl;
	}
	else
	{
		std::cout << "My In Order tree passed" << std::endl;
	}

	//descending order tree
	for (index = 0; index < 50; ++index)
	{
		desOrderTree.setRoot(desOrderTree.insert(desOrderTree.getRoot(), desOrder[index]));
	}
	height = desOrderTree.returnHeight(desOrderTree.getRoot());
	std::cout << "In order tree height: " << height << std::endl;
	valid = desOrderTree.validateHelper(desOrderTree.getRoot());
	std::cout << "In order tree validity: " << valid << std::endl;

	for (index = 0; index < 100; ++index)
	{
		flag = desOrderTree.contains(index);
		if (flag == 0 && index % 2 != 0)
		{
			result = 0;
		}
	}
	if (result == 0)
	{
		std::cout << "My Des Order tree failed" << std::endl;
	}
	else
	{
		std::cout << "My Des Order tree passed" << std::endl;
	}

	//random order
	for (index = 0; index < 50; ++index)
	{
		randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), randOrder[index]));
	}
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 7));
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 97));
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 99));
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 11));
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 29));
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 35));
	randOrderTree.setRoot(randOrderTree.insert(randOrderTree.getRoot(), 85));
	//randOrderTree.inOrderPrint();
	height = randOrderTree.returnHeight(randOrderTree.getRoot());
	std::cout << "In order tree height: " << height << std::endl;
	valid = randOrderTree.validateHelper(randOrderTree.getRoot());
	std::cout << "In order tree validity: " << valid << std::endl;

	//valid = randOrderTree.contains(11);

	for (index = 0; index < 100; ++index)
	{
		flag = randOrderTree.contains(index);
		if (flag == 0 && index % 2 != 0)
		{
			result = 0;
		}
	}
	if (result == 0)
	{
		std::cout << "My Random Order tree failed" << std::endl;
	}
	else
	{
		std::cout << "My Random Order tree passed" << std::endl;
	}
	return 0;
}