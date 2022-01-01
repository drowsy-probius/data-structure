#include "iostream"
#include "LinkedList.h"

#define SIZE 10

using namespace std;

int main(void)
{
  int testcase[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  LinkedList<int> list;
  for(int i=0; i<SIZE; i++)
  {
    list.insert(i, testcase[i]);
  }
  for(int i=0; i<SIZE; i++)
  {
    cout << list.at(i) << " ";
  }
  cout << "\n";
  for(int i=0; i<SIZE; i++)
  {
    int value = list.remove(0);
    cout << value << " ";
  }
  cout << "\n";

  return 0;
}