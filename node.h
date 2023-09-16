
template <class T>
class Node
{
public:
	/*************************************************************
* Function: Node ()
* Description:  default constructor
* Input parameters:none
* Returns: none
*************************************************************/
	Node();

	/*************************************************************
* Function: Node ()
* Description:  construct with parameters
* Input parameters:new term, new def
* Returns: none
*************************************************************/
	Node(T newTerm, T newDef);

	/*************************************************************
* Function: ~Node ()
* Description:  destructor
* Input parameters:none
* Returns: none
*************************************************************/
	~Node();

	/*************************************************************
* Function: getTerm ()
* Description:  returns term
* Input parameters:none
* Returns: term
*************************************************************/
	T getTerm();

	/*************************************************************
* Function: getDef ()
* Description:  returns def
* Input parameters:none
* Returns: def
*************************************************************/
	T getDef();

	/*************************************************************
* Function: getNext ()
* Description:  returns next pointer
* Input parameters:none
* Returns: next
*************************************************************/
	Node<T>* getNext();

	/*************************************************************
* Function: setTerm ()
* Description:  sets term
* Input parameters:newTerm
* Returns: none
*************************************************************/
	void setTerm(T newTerm);

	/*************************************************************
* Function: setDef ()
* Description:  sets def
* Input parameters:newDef
* Returns: none
*************************************************************/
	void setDef(T newDef);

	/*************************************************************
* Function: setNext ()
* Description:  sets next
* Input parameters:newNext
* Returns: none
*************************************************************/
	void setNext(Node<T>* newNext);

private:
	T term;
	T def;
	Node<T>* pNext;
};

/*************************************************************
* Function: Node ()
* Description:  default constructor
* Input parameters:none
* Returns: none
*************************************************************/
template <class T>
Node<T>::Node()
{
	this->def = "";
	this->term = "";
	this->pNext = nullptr;
}

/*************************************************************
* Function: Node ()
* Description:  construct with parameters
* Input parameters:new term, new def
* Returns: none
*************************************************************/
template <class T>
Node<T>::Node(T newTerm, T newDef)
{
	this->term = newTerm;
	this->def = newDef;
	this->pNext = nullptr;
}

/*************************************************************
* Function: ~Node ()
* Description:  destructor
* Input parameters:none
* Returns: none
*************************************************************/
template <class T>
Node<T>::~Node()
{

}

/*************************************************************
* Function: getTerm ()
* Description:  returns term
* Input parameters:none
* Returns: term
*************************************************************/
template <class T>
T Node<T>::getTerm()
{
	return this->term;
}

/*************************************************************
* Function: getDef ()
* Description:  returns def
* Input parameters:none
* Returns: def
*************************************************************/
template <class T>
T Node<T>::getDef()
{
	return this->def;
}

/*************************************************************
* Function: getNext ()
* Description:  returns next pointer
* Input parameters:none
* Returns: next
*************************************************************/
template <class T>
Node<T>* Node<T>::getNext()
{
	return this->pNext;
}

/*************************************************************
* Function: setTerm ()
* Description:  sets term
* Input parameters:newTerm
* Returns: none
*************************************************************/
template <class T>
void Node<T>::setTerm(T newTerm)
{
	this->term = newTerm;
}

/*************************************************************
* Function: setDef ()
* Description:  sets def
* Input parameters:newDef
* Returns: none
*************************************************************/
template <class T>
void Node<T>::setDef(T newDef)
{
	this->def = newDef;
}

/*************************************************************
* Function: setNext ()
* Description:  sets next
* Input parameters:newNext
* Returns: none
*************************************************************/
template <class T>
void Node<T>::setNext(Node<T>* newNext)
{
	this->pNext = newNext;
}