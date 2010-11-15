// Specification file for the DynIntStack class
#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <iostream>
using namespace std;


template <class T>
class DynStack
{
private:
	// Structure for stack nodes
	struct StackNode
	{
		T value;        // Value in the node
		StackNode *next;  // Pointer to the next node
	};
	
	StackNode *top;      // Pointer to the stack top
	
public:
	// Constructor
	DynStack<T>()
	{  top = NULL; }
	
	// Destructor
	~DynStack<T>()
	{
		StackNode *nodePtr, *nextNode;
		
		// Position nodePtr at the top of the stack.
		nodePtr = top;
		
		// Traverse the list deleting each node.
		while (nodePtr != NULL)
		{
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}
	
	
	// Stack operations
	void push(T num)
	{
		StackNode *newNode; // Pointer to a new node
		
		// Allocate a new node and store num there.
		newNode = new StackNode;
		newNode->value = num;
		
		// If there are no nodes in the list
		// make newNode the first node.
		if (isEmpty())
		{
			top = newNode;
			newNode->next = NULL;
		}
		else  // Otherwise, insert NewNode before top.
		{
			newNode->next = top;
			top = newNode;
		}
	}
	
	void pop(T &num)
	{
		StackNode *temp; // Temporary pointer
		
		// First make sure the stack isn't empty.
		if (isEmpty())
		{
			cout << "The stack is empty.\n";
		}
		else  // pop value off top of stack
		{
			num = top->value;
			temp = top->next;
			delete top;
			top = temp;
		}
	}
	
	bool isEmpty()
	{
		bool status;
		
		if (!top)
			status = true;
		else
			status = false;
		
		return status;
	}
}; 

#endif
