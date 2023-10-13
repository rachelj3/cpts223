#include "AVLNode.hpp"
#include <iostream>

template <class T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void destroyTree(AVLNode<T>* pTree);

	void setRoot(AVLNode<T>* newRoot);
	AVLNode<T>* getRoot();

	int returnHeight(AVLNode<T>* node);
	int heightHelper(AVLNode<T>* pTree);

	AVLNode<T>* insert(AVLNode<T>* pTree, T newValue);
	AVLNode<T>* insertHelper(AVLNode<T>* pTree, T newData);
	int contains(T value);
	int containsHelper(T value, AVLNode<T>* pTree);
	int validate();
	int validateHelper(AVLNode<T>* pTree);

	AVLNode<T>* rotateLeft(AVLNode<T>* node);
	AVLNode<T>* rotateRight(AVLNode<T>* node);
	AVLNode<T>* doubleRotateLeft(AVLNode<T>* node);
	AVLNode<T>* doubleRotateRight(AVLNode<T>* node);

	int returnHeightBalance(AVLNode<T>* node);

	void inOrderPrint();
	void inOrderPrintHelper(AVLNode<T>* node);
private:
	AVLNode<T>* root;
};

template <class T>
AVLTree<T>::AVLTree()
{
	this->root = nullptr;
}

template <class T>
AVLTree<T>::~AVLTree()
{
	destroyTree(this->root);
}

template <class T>
void AVLTree<T>::destroyTree(AVLNode<T>* pTree)
{
	if (pTree == nullptr)
	{
		return;
	}
	destroyTree(pTree->getLeftPtr());
	destroyTree(pTree->getRightPtr());
	delete pTree;
}

template <class T>
void AVLTree<T>::setRoot(AVLNode<T>* newRoot)
{
	this->root = newRoot;
}

template <class T>
AVLNode<T>* AVLTree<T>::getRoot()
{
	return this->root;
}

template <class T>
int AVLTree<T>::returnHeight(AVLNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return node->getHeight();
	}
}

template <class T>
int AVLTree<T>::heightHelper(AVLNode<T>* pTree)
{
	int left = 0, right = 0;
	if (this->root == nullptr)
	{
		return -1;
	}
	else
	{
		left = heightHelper(pTree->getLeftPtr());
		right = heightHelper(pTree->getRightPtr());

		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

template <class T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* pTree, T newValue)
{
	//return insertHelper(this->root, newValue);
	int balance = 0;

	if (pTree == nullptr)
	{
		pTree = new AVLNode<T>(newValue, 1);
		return pTree;
	}

	if (newValue < pTree->getData()) // go left
	{
		pTree->setLeftPtr(insert(pTree->getLeftPtr(), newValue));
	}
	else if (newValue > pTree->getData()) // g0 right
	{
		pTree->setRightPtr(insert(pTree->getRightPtr(), newValue));
	}
	else
	{
		return pTree;
	}

	pTree->setHeight(1 + std::max(returnHeight(pTree->getLeftPtr()), returnHeight(pTree->getRightPtr())));

	balance = returnHeightBalance(pTree);

	if (balance > 1 && newValue < pTree->getLeftPtr()->getData())
	{
		pTree = rotateLeft(pTree);
		return pTree;
	}
	if (balance < -1 && newValue > pTree->getRightPtr()->getData())
	{
		pTree = rotateRight(pTree);
		return pTree;
	}
	if (balance > 1 && newValue > pTree->getLeftPtr()->getData())
	{
		pTree = doubleRotateLeft(pTree);
		return pTree;
	}
	if (balance < -1 && newValue < pTree->getRightPtr()->getData())
	{
		pTree = doubleRotateRight(pTree);
		return pTree;
	}

	return pTree;
}

template <class T>
AVLNode<T>* AVLTree<T>::insertHelper(AVLNode<T>* pTree, T newData)
{
	
}


template <class T>
int AVLTree<T>::contains(T value)
{
	return containsHelper(value, this->root);
}

template <class T>
int AVLTree<T>::containsHelper(T value, AVLNode<T>* pTree)
{
	if (this->root->getData() == value)
	{
		return 1;
	}
	else if (value < pTree->getData() && pTree->getLeftPtr() != nullptr)
	{
		//go left
		if (pTree->getLeftPtr()->getData() == value)
		{
			return 1;
		}
		else
		{
			containsHelper(value, pTree->getLeftPtr());
		}
	}
	else if (value > pTree->getData() && pTree->getRightPtr() != nullptr)
	{
		if (pTree->getRightPtr()->getData() == value)
		{
			return 1;
		}
		else
		{
			containsHelper(value, pTree->getRightPtr());
		}
	}
	else
	{
		return 0;
	}
}


template <class T>
int AVLTree<T>::validate()
{
	int final = 5;
	final = validateHelper(this->root);
	return final;
}

template <class T>
int AVLTree<T>::validateHelper(AVLNode<T>* pTree)
{
	int flag = 0, final = 1;
	if (pTree != nullptr)
	{
		flag = returnHeightBalance(pTree);
		if (flag < -1 || flag > 1)
		{
			final = 0;
		}
		validateHelper(pTree->getLeftPtr());
		validateHelper(pTree->getRightPtr());
	}
	return final;
}


template <class T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* node)
{
	AVLNode<T>* temp = node->getLeftPtr();
	node->setLeftPtr(temp->getRightPtr());
	temp->setRightPtr(node);
	node->setHeight(std::max(returnHeight(node->getLeftPtr()), returnHeight(node->getRightPtr()))+1);
	temp->setHeight(std::max(returnHeight(temp->getLeftPtr()), node->getHeight())+1);
	return temp;
}

template <class T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* node)
{
	AVLNode<T>* temp = node->getRightPtr();
	node->setRightPtr(temp->getLeftPtr());
	temp->setLeftPtr(node);
	node->setHeight(std::max(returnHeight(node->getRightPtr()), returnHeight(node->getLeftPtr())) + 1);
	temp->setHeight(std::max(returnHeight(temp->getRightPtr()), node->getHeight()) + 1);
	return temp;
}

template <class T>
AVLNode<T>* AVLTree<T>::doubleRotateLeft(AVLNode<T>* node)
{
	node = rotateRight(node->getLeftPtr());
	node = rotateLeft(node);
	return node;
}

template <class T>
AVLNode<T>* AVLTree<T>::doubleRotateRight(AVLNode<T>* node)
{
	node = rotateLeft(node->getRightPtr());
	node = rotateRight(node);
	return node;
}

template <class T>
int AVLTree<T>::returnHeightBalance(AVLNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return returnHeight(node->getLeftPtr()) - returnHeight(node->getRightPtr());
	}
}

template <class T>
void AVLTree<T>::inOrderPrint()
{
	inOrderPrintHelper(this->root);
}

template <class T>
void AVLTree<T>::inOrderPrintHelper(AVLNode<T>* node)
{
	if (node != nullptr)
	{
		inOrderPrintHelper(node->getLeftPtr());
		std::cout << node->getData() << std::endl;
		inOrderPrintHelper(node->getRightPtr());
	}
}

