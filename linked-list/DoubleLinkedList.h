#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

template<typename T>
struct DoubleLinkedNode
{
  T value;
  DoubleLinkedNode<T>* before;
  DoubleLinkedNode<T>* next;
};

template<typename T>
struct DoubleLinkedList
{
  private:
    int _size;
    DoubleLinkedNode<T>* _root;
    DoubleLinkedNode<T>* _last;
    virtual DoubleLinkedNode<T>* _at(int index);
  
  public:
    DoubleLinkedList();
    virtual ~DoubleLinkedList();
    virtual bool insert(int index, T);
    virtual bool insert(T);
    virtual T shift();
    virtual T pop();
    virtual T remove(int index);
    virtual T at(int index);
};

template<typename T>
DoubleLinkedNode<T>* DoubleLinkedList<T>::_at(int index)
{
  DoubleLinkedNode<T>* result = nullptr;
  if(index < (_size/2))
  {
    result = _root;
    while(index-- > 0)
      result = result->next;
    
  }
  else
  {
    result = _last;
    index = _size - index;
    while(index-- > 0)
      result = result->before;
  }
  return result;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
  _size = 0;
  _root = nullptr;
  _last = nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
  _size = 0;
  DoubleLinkedNode<T>* ptr;
  while(_root)
  {
    ptr = _root;
    _root = _root->next;
    delete ptr;
    ptr = nullptr;
  }
}

template<typename T>
bool DoubleLinkedList<T>::insert(int index, T value)
{
  if(index < 0 || index >= _size) return false;
  if(index == 0) return insert(value);

  DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>();
  DoubleLinkedNode<T>* ptr;

  node->value = value;
  node->before = nullptr;
  node->next = nullptr;

  ptr = _at(index - 1);
  node->before = ptr;
  node->next = ptr->next;
  ptr->next->before = node;
  ptr->next = node;
  
  _size++;
  if(index == _size-1) _last = node;
  return true;
}

template<typename T>
bool DoubleLinkedList<T>::insert(T value)
{
  DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>();
  node->value = value;
  node->before = node->next = nullptr;

  if(_root)
  {
    _root->before = node;
    node->next = _root;
    _root = node;
  }
  else
  {
    _root = _last = node;
  }
  _size++;
  return true;
}

template<typename T>
T DoubleLinkedList<T>::shift()
{
  DoubleLinkedNode<T>* ptr = _root;
  T result = ptr->value;
  _root = _root->next;
  if(_root) _root->before = nullptr;
  _size--;
  delete ptr;
  if(_size == 0) _root = _last = nullptr;
  return result;
}

template<typename T>
T DoubleLinkedList<T>::pop()
{
  DoubleLinkedNode<T>* ptr = _last;
  T result = ptr->value;
  _last = _last->before;
  if(_last) _last->next = nullptr;
  _size--;
  delete ptr;
  if(_size == 0) _root = _last = nullptr;
  return result;
}

template<typename T>
T DoubleLinkedList<T>::remove(int index)
{
  if(index == 0) return shift();
  if(index == _size-1) return pop();

  DoubleLinkedNode<T>* ptr = _at(index);
  T result = ptr->value;

  if(ptr->before)
    ptr->before->next = ptr->next;
  if(ptr->next)
    ptr->next->before = ptr->before;

  delete ptr;
  if(_size == 0) _root = _last = nullptr;
  return result;
}

template<typename T>
T DoubleLinkedList<T>::at(int index)
{
  DoubleLinkedNode<T>* result = _at(index);
  return result->value;
}

#endif