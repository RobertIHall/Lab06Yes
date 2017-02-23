#if !defined (STACKLINKED_H)
#define STACKLINKED_H

#include "NextNode.h"

template < class T >
class StackLinked
{
   private:
      NextNode<T>* top;
      int sze;  // number of items in the stack

   public:
      StackLinked();
      ~StackLinked();
      bool isEmpty();
      int size();
      void popAll();
      T* pop();
      void push(T* item);
      T* peek();
};

template < class T >
StackLinked<T>::StackLinked()
{
   top = NULL;
   sze = 0;
}

template < class T >
StackLinked<T>::~StackLinked()
{
   popAll();
}

template < class T >
bool StackLinked<T>::isEmpty()
{
   return sze == 0;
}

template < class T >
int StackLinked<T>::size()
{
   return sze;
}

template < class T >
void StackLinked<T>::popAll()
{
   //loop over the stack, deleting the nodes
   //the actual items are not deleted
   if (sze == 0) return;

   NextNode<T>* curr = top;
   NextNode<T>* prev = NULL;
   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      prev->setNext(NULL);
      delete prev;
   }
}
//pre-conditions: existing stack 
//post-conditions: looks at an item on the top
template < class T >
T* StackLinked<T>::peek()
{
   T* item = NULL;
   //DO THIS
   if(!isEmpty())
   { 
	item = top->getItem();
   }
   return item;
}
//pre-conditions: existing stack and item to be added to stack
//post-conditions: adds said item to the top
template < class T >
void StackLinked<T>::push(T* item)
{
   //DO THIS
	NextNode<T>* node = new NextNode<T>(item);
	node->setNext(top);
	top = node;
	sze++;
}
//pre-conditions: existing stack 
//post-conditions: pops an item off the top
template < class T >
T* StackLinked<T>::pop()
{
   if (sze == 0) return NULL;

   //DO THIS
	T* item = NULL;
   if(!isEmpty())
   {
	NextNode<T>* curr = top;
    NextNode<T>* prev = NULL;
	prev = curr;
    curr = curr->getNext();
    prev->setNext(NULL);
    item = prev->getItem();
	delete prev;
	top = curr;
	
   }
   sze--;
   return item;

}

#endif
