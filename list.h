#pragma once
#include "node.h"
#include <iostream>

template <class T>
class List
{
public:
	/*************************************************************
* Function: List ()
* Description:  constructor
* Input parameters: none
* Returns: none
*************************************************************/
	List();

	/*************************************************************
* Function: ~List ()
* Description:  destructor
* Input parameters: none
* Returns: none
*************************************************************/
	~List();

	/*************************************************************
* Function: insert ()
* Description:  inserts node into list
* Input parameters: newTerm, newDef
* Returns: none
*************************************************************/
	void insert(T newTerm, T newDef);

	/*************************************************************
* Function: deleteTerm ()
* Description:  delete term from list
* Input parameters: deleteTerm
* Returns: none
*************************************************************/
	void deleteTerm(T deleteTerm);

	/*************************************************************
* Function: printTermByName ()
* Description:  prints term to screen by name
* Input parameters: find term
* Returns: none
*************************************************************/
	void printTermByName(T findTerm);

	/*************************************************************
* Function: printDefByIndex ()
* Description:  prints def to screen by index
* Input parameters:index
* Returns: none
*************************************************************/
	void printDefByIndex(int index);

	/*************************************************************
* Function: printTermByIndex ()
* Description:  prints term to screen by index
* Input parameters:index
* Returns: none
*************************************************************/
	void printTermByIndex(int index);

	/*************************************************************
* Function: printList ()
* Description:  prints whole list
* Input parameters:none
* Returns: none
*************************************************************/
	void printList();

	/*************************************************************
* Function: findDuplicate ()
* Description:  find if term is dupe
* Input parameters:findTerm
* Returns: t/f
*************************************************************/
	bool findDuplicate(T findTerm);


	/*************************************************************
* Function: getpList ()
* Description:  returns pList
* Input parameters:none
* Returns: none
*************************************************************/
	Node<T>* getpList();
private:
	Node<T>* pList;
};

/*************************************************************
* Function: List ()
* Description:  constructor
* Input parameters: none
* Returns: none
*************************************************************/
template <class T>
List<T>::List()
{
	this->pList = nullptr;
}

/*************************************************************
* Function: ~List ()
* Description:  destructor
* Input parameters: none
* Returns: none
*************************************************************/
template <class T>
List<T>::~List()
{
	delete this->pList;
	std::cout << "List has been deleted" << std::endl;
}

/*************************************************************
* Function: insert ()
* Description:  inserts node into list
* Input parameters: newTerm, newDef
* Returns: none
*************************************************************/
template <class T>
void List<T>::insert(T newTerm, T newDef)
{
	Node<T>* pMem = new Node<T>(newTerm, newDef);
	if (this->pList == nullptr) //empty list
	{
		this->pList = pMem;
	}
	else //not an empty list
	{
		pMem->setNext(this->pList);
		this->pList = pMem;
	}
}

/*************************************************************
* Function: deleteTerm ()
* Description:  delete term from list
* Input parameters: deleteTerm
* Returns: none
*************************************************************/
template <class T>
void List<T>::deleteTerm(T deleteTerm)
{
	Node<T>* pTemp = this->pList;
	Node<T>* pGone;
	if (deleteTerm == pTemp->getTerm())
	{
		//delete item is first in list
		this->pList = this->pList->getNext();
		delete pTemp;
	}
	else
	{
		while (pTemp->getNext()->getTerm() != deleteTerm)
		{
			pTemp = pTemp->getNext();
		}
		//we have made it to term before one to be deleted
		pGone = pTemp->getNext();
		pTemp->setNext(pGone->getNext());
		delete pGone;
	}

}

/*************************************************************
* Function: printTermByName ()
* Description:  prints term to screen by name
* Input parameters: find term
* Returns: none
*************************************************************/
template <class T>
void List<T>::printTermByName(T findTerm)
{
	Node<T>* pCur = this->pList;
	while (pCur->getTerm() != findTerm && pCur->getNext() != nullptr)
	{
		pCur = pCur->getNext();
	}
	std::cout << "Defintion: " << pCur->getDef() << std::endl;
}

/*************************************************************
* Function: printDefByIndex ()
* Description:  prints def to screen by index
* Input parameters:index
* Returns: none
*************************************************************/
template <class T>
void List<T>::printDefByIndex(int index)
{
	int interator = 1;
	Node<T>* pCur = this->pList;
	while (interator != index && pCur->getNext() != nullptr)
	{
		pCur = pCur->getNext();
		++interator;
	}
	std::cout << "Definition: " << pCur->getDef() << std::endl;
}

/*************************************************************
* Function: printList ()
* Description:  prints whole list
* Input parameters:none
* Returns: none
*************************************************************/
template <class T>
void List<T>::printList()
{
	Node<T>* pCur = this->pList;
	while (pCur != nullptr)
	{
		std::cout << "Term: " << pCur->getTerm() << "         Definition: " << pCur->getDef() << std::endl;
		pCur = pCur->getNext();
	}
}

/*************************************************************
* Function: findDuplicate ()
* Description:  find if term is dupe
* Input parameters:findTerm
* Returns: t/f
*************************************************************/
template <class T>
bool List<T>::findDuplicate(T findTerm)
{
	Node<T>* pCur = this->pList;
	int flag = 0;
	while (pCur != nullptr)
	{
		if (pCur->getTerm() == findTerm)
		{
			flag = 1;
		}
		pCur = pCur->getNext();
	}
	if (flag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************************
* Function: printTermByIndex ()
* Description:  prints term to screen by index
* Input parameters:index
* Returns: none
*************************************************************/
template <class T>
void List<T>::printTermByIndex(int index)
{
	int interator = 1;
	Node<T>* pCur = this->pList;
	while (interator != index && pCur->getNext() != nullptr)
	{
		pCur = pCur->getNext();
		++interator;
	}
	std::cout << "Term: " << pCur->getTerm() << std::endl;
}



/*************************************************************
* Function: getpList ()
* Description:  returns pList
* Input parameters:none
* Returns: none
*************************************************************/
template <class T>
Node<T>* List<T>::getpList()
{
	return this->pList;
}


