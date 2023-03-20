#include <iostream>
#include "Node.cpp"
using namespace std;

class LinkedList {

private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList(int value) {
		//create new Node
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	/*if you run the default destructor is just going to delete these items head, tail and length.
	Those nodes are created by a whole other classand the linked list class doesn't know how to delete them.
	So if just run the default destructor for the linked list, these will all be deleted, but all
	of these nodes will remain in memory. So that is why we have to actually write a destructor for the linked list class.*/

	~LinkedList() {
		Node* temp = head;
		while (head) {
			head = head->next;
			delete temp;
			temp = head;
			length--;
		}
	}
	void append(int value) {
		//create new Node
		Node* newNode = new Node(value);
		//add Node to end
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;

		}
		length++;
	}

	void deleteLast()
	{
		if (length <= 0) {
			return;
		}
		Node* temp = head;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else {

			while (temp->next != tail)
			{
				temp = temp->next;
			}
			tail = temp;
			temp = temp->next;
			tail->next = nullptr;
			
		}
		delete temp;
		length--;
	}

	void prepend(int value) {
		Node* newNode = new Node(value);
		//add Node to beginning
		if (length == 0)
		{
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}

	void deleteFirst()
	{
		if (length == 0)
		{
			return;
		}
		Node* temp = head;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete temp;
		length--;
	}
	bool insert(int index, int value) {
		//create new Node

		//insert Node
	}

	void printList()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void getHead() {
		cout << "Head: " << head->value << endl;
	}

	void getTail() {
		cout << "Tail: " << tail->value << endl;
	}

	void getLength() {
		cout << "Length: " << length << endl;
	}
};