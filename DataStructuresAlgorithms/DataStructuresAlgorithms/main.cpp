#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
	LinkedList* myLinkedList = new LinkedList(4);
	myLinkedList->prepend(3);
	myLinkedList->prepend(2);
	myLinkedList->deleteFirst();
	myLinkedList->deleteFirst();
	myLinkedList->deleteFirst();
	myLinkedList->printList();
	myLinkedList->getLength();
}