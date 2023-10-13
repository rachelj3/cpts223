

template <class T>
class AVLNode
{
public:
	AVLNode();
	AVLNode(T newData, int newHeight);
	~AVLNode();

	void setData(T newData);
	void setLeftPtr(AVLNode<T>* newLeft);
	void setRightPtr(AVLNode<T>* newRight);
	void setHeight(int newHeight);

	T getData();
	AVLNode<T>* getLeftPtr();
	AVLNode<T>* getRightPtr();
	int getHeight();

private:
	T data;
	AVLNode<T>* leftPtr;
	AVLNode<T>* rightPtr;
	int height;
};

template <class T>
AVLNode<T>::AVLNode()
{
	this->leftPtr = nullptr;
	this->rightPtr = nullptr;
}

template <class T>
AVLNode<T>::AVLNode(T newData, int newHeight)
{
	this->leftPtr = nullptr;
	this->rightPtr = nullptr;
	this->data = newData;
	this->height = newHeight;
}

template <class T>
AVLNode<T>::~AVLNode()
{

}

template <class T>
void AVLNode<T>::setData(T newData)
{
	this->data = newData;
}

template <class T>
void AVLNode<T>::setLeftPtr(AVLNode<T>* newLeft)
{
	this->leftPtr = newLeft;
}

template <class T>
void AVLNode<T>::setRightPtr(AVLNode<T>* newRight)
{
	this->rightPtr = newRight;
}

template <class T>
void AVLNode<T>::setHeight(int newHeight)
{
	this->height = newHeight;
}

template <class T>
T AVLNode<T>::getData()
{
	return this->data;
}

template <class T>
AVLNode<T>* AVLNode<T>::getLeftPtr()
{
	if (this->leftPtr != nullptr)
	{
		return this->leftPtr;
	}
	else
	{
		return nullptr;
	}
}

template <class T>
AVLNode<T>* AVLNode<T>::getRightPtr()
{
	if (this->rightPtr != nullptr)
	{
		return this->rightPtr;
	}
	else
	{
		return nullptr;
	}
}

template <class T>
int AVLNode<T>::getHeight()
{
	return this->height;
}
