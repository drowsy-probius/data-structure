#include "iostream"
#include "DoubleLinkedList.h"

#define SIZE 10

using namespace std;

int main(void)
{
  int test[SIZE] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

  DoubleLinkedList<int> list;

  for(int i=0; i<SIZE; i++)
  {
    list.insert(test[i]);
  }
  for(int i=0; i<SIZE; i++)
  {
    cout << list.shift() << " ";
  } cout << "\n";


  list.insert(10);
  list.insert(11);
  for(int i=2; i<SIZE; i++)
  {
    list.insert(1, test[i]);
  }
  for(int i=0; i<SIZE; i++)
  {
    cout << list.pop() << " ";
  } cout << "\n";


  for(int i=0; i<SIZE; i++)
  {
    list.insert(test[i]);
  }
  for(int i=0; i<SIZE-1; i++)
  {
    cout << list.remove(1) << " ";
  } cout << list.remove(0) << "\n";

  return 0;
}