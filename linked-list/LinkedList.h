#ifndef LinkedList_h
#define LinkedList_h

template <typename T>
struct Node
{
  T value;
  Node<T>* next;
};

template <typename T>
class LinkedList
{
  protected:
    int _size;
    Node<T>* _root;
    virtual Node<T>* _at(int index);

  
  public:
    LinkedList();
    virtual ~LinkedList();

    virtual int size() {return _size; };
    virtual bool insert(int index, T);
    virtual bool insert(T);
    virtual T remove(int index);
    virtual T pop();
    virtual T at(int index);
};

template<typename T>
LinkedList<T>::LinkedList()
{
  _size = 0;
  _root = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  _size = 0;
  Node<T>* tmp = _root;
  while(_root != nullptr)
  {
    tmp = _root;
    _root = _root->next;
    delete tmp;
  }
}

template <typename T>
Node<T>* LinkedList<T>::_at(int index)
{
  Node<T>* result = _root;
  while(index-- > 0)
  {
    result = result->next;
  }
  return result;
}


template<typename T>
bool LinkedList<T>::insert(int index, T value)
{
  if(index <= 0 || index > _size) return insert(value);

  Node<T>* newnode = new Node<T>();
  newnode->value = value;
  newnode->next = nullptr;

  Node<T>* pre = _at(index-1);
  if(pre)
  {
    newnode->next = pre->next;
    pre->next = newnode;
  }
  else
  {
    _root = newnode;
  }

  _size++;
  return true;
}


template<typename T>
bool LinkedList<T>::insert(T value)
{
  /**
   * insert at begin
   */
  Node<T>* newnode = new Node<T>();
  newnode->value = value;
  newnode->next = nullptr;

  if(_root)
  {
    newnode->next = _root;
  }
  _root = newnode;
  
  _size++;
  return true;
}


template<typename T>
T LinkedList<T>::remove(int index)
{
  if(index == 0) return pop();

  Node<T>* beforenode = nullptr;
  Node<T>* deletenode = _root;
  T result;
  while(index--)
  {
    beforenode = deletenode;
    deletenode = deletenode->next;
  }
  result = deletenode->value;
  beforenode->next = deletenode->next;
  delete deletenode;
  _size--;
  return result;
}


template<typename T>
T LinkedList<T>::pop()
{
  T value = _root->value;
  Node<T>* ptr = _root;
  _root = _root->next;
  delete ptr;
  _size--;
  return value;
}


template<typename T>
T LinkedList<T>::at(int index)
{
  Node<T>* nodeptr = _at(index);
  return nodeptr->value;
}

#endif