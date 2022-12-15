#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int _data) {
		data = _data;
		next = NULL;
	}
};

class Stack
{
public:
	Node* top;

	Stack() {
		top = NULL;
	}

	void push(int _data) {
		Node* node = new Node(_data);

		if (top == NULL) {
			top = node;
			return;
		}

		node->next = top;
		top = node;
	}

	int pop(int& deletedItem) {
		if (top != NULL) {
			Node* temp = top;
			deletedItem = top->data;
			top = top->next;

			delete (temp);
			return 1;
		}

		return 0;
	}

	void display() {
		while (top != NULL) {
			cout << top->data << "   ";
			top = top->next;
		}
	}

	~Stack() {
		while (top != NULL) {
			Node* temp = top;
			delete temp;

			top = top->next;
		}
	}
};

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	int data;
	s.pop(data);

	s.display();

	return 0;
}
