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


	//Removing the last item from a Linked List is O(n). Because you have to start at the beginning of the Linked List an iterate through to the end
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


	//Removing the first item from a Linked List is O(1). This is a place where Linked Lists are better than Vectors. Vectors are O(n) when removing the first item because of the reindexing that is required.
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

		if (index<0 || index>length) return false;
		//create new Node
		
		if (index == 0)
		{
			prepend(value);
			return true;
		}
		else if (index == length)
		{
			append(value);
			return true;
		}
		Node* newNode = new Node(index);
		Node* temp = get(index - 1);
		temp->next = newNode;
		newNode->next = temp->next;
		length++;
		return true;
		//insert Node
	}

	void deleteNode(int index)
	{
		if (index < 0 || index >= length)
		{
			return;
		}
		else if (index == 0)
		{
			deleteFirst();
			return;
		}
		else if (index == length - 1)
		{
			deleteLast();
			return;
		}
		Node* temp = get(index);
		Node* pre = get(index-1);
		pre->next = temp->next;
		delete temp;
		length--;
	}

	void reverse()
	{
		Node* temp = head;
		head = tail;
		tail = temp;

		Node* after = temp->next;
		Node* before = nullptr;
		for (int i = 0; i < length; i++)
		{
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
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


	//Finding an item by index in a Linked List is O(n). You have to iterate through the Linked List until you get to the index you are looking for.
	Node* get(int index) {
		if (index < 0 || index >= length)
		{
			return nullptr;
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < length; i++)
			{
				temp = temp->next;
			}
			return temp;
		}
	}

	bool set(int index, int value)
	{
		Node* temp = get(index);
		if (temp)
		{
			temp->value = value;
			return true;
		}
		return false;
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