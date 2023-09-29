#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	int heightHelperLeft(Node<T>* root)
	{
		if (!root) {
			return -1;
		}
		else {
			return 1 + heightHelperLeft(root->left);
		}
	}

	int heightHelperRight(Node<T>* root)
	{
		if (!root) {
			return -1;
		}
		else {
			return 1 + heightHelperRight(root->right);
		}
	}

	void printLeft(Node<T>* root)
	{
		if (!root) return;
		cout << root->value << ' ';
		printLeft(root->left);
	}

	void printRight(Node<T>* root)
	{
		if (!root) return;
		cout << root->value << ' ';
		printRight(root->right);
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST() {
		//cout << "TODO: Implement Destructor" << endl;
		destroyTree(this->_root);
	}

	void destroyTree(Node<T>* pTree)
	{
		if (pTree == nullptr)
		{
			return;
		}
		destroyTree(pTree->left);
		destroyTree(pTree->right);
		delete pTree;
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder() {
		//cout << "TODO: Implement printLevelOrder" << endl;
		int heightVar = height();
		int index = 0;
		for (index = 1; index < heightVar + 2; ++index)
		{
			printLevelOrderHelper(this->_root, index);
			cout << endl; //printing a newline between levels 
		}
	}

	void printLevelOrderHelper(Node<T>* pTree, int level)
	{
		if (pTree == nullptr)
		{
			return; //cant print if nothing is there
		}
		else if (level != 1) // we are not on the first level of the tree
		{
			//not on first level of tree
			printLevelOrderHelper(pTree->left, level - 1); // go left to print, traverse down to correct layer
			printLevelOrderHelper(pTree->right, level - 1); // go right to print, traverse down to correct layer
		}
		else
		{
			//on on first level of the tree
			//print out the value
			cout << pTree->value << " ";
		}
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath() {
		//cout << "TODO: Implement printMaxPath" << endl;
		//plan
		//use height helper to determine which side of the tree is the longest
		//then print only that side of the tree
		int maxleft, maxright;
		maxleft = heightHelperLeft(this->_root);
		maxright = heightHelperRight(this->_root);
		if (maxleft > maxright)
		{
			printLeft(this->_root);
		}
		else
		{
			printRight(this->_root);
		}
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	bool contains(T value) {
		//cout << "TODO: Implement contains" << endl;
		//return numeric_limits<T>::min();
		return containsHelper(this->_root, value);
		
	}

	bool containsHelper(Node<T>* pTree, T value) {
		if (this->_root->value == value)
		{
			return 1;
		}
		else if (value < pTree->value && pTree->left != nullptr)
		{
			//go left
			if (pTree->left->value == value)
			{
				return 1;
			}
			else
			{
				containsHelper(pTree->left, value);
			}
		}
		else if (value > pTree->value && pTree->right != nullptr)
		{
			if (pTree->right->value == value)
			{
				return 1;
			}
			else
			{
				containsHelper(pTree->right, value);
			}
		}
		else
		{
			return 0;
		}
	}
};

#endif

