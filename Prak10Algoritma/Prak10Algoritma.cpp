#include <iostream>
using namespace std;

// Node classs representing a single node in the linked list
class Node {
public:
	int data;
	Node* next;

	Node() {
		next = NULL;
	}
};

// stack class
class Stack {
private:
	Node* top; //pointer to the top node of the stack

public:
	Stack() {
		top = NULL; // intialize the stack whit a null top pointer
	}
	 
	// push operation : insert an element onto the top of the stack
	int push(int value) {
		Node* newNode = new Node(); // 1.Allocate memort for the new node
		newNode->data = value; // 2. assign value
		newNode->next = top; // 3. set the next pointer of the new node to the current top node
		top = newNode; // 4. update the top pointer to the new node
		cout << "push value: " << value << endl;
		return value;
	}

	// pop operation : remove the topmost element form the stack
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty." << endl;
		}
		cout << "Popped value: " << top->data << endl;
		top = top->next; // update the top pointer tto the next node
	}

	//peek/top operation : retreve the value of the topmost elemnt without removing it
	void peek() {
		if (top == NULL) {
			cout << "List is empty." << endl;
		}
		else {
			Node* current = top;
			while (current != NULL) {
				cout << current->data << " " << endl;
				current = current->next;
			}
			cout << endl;
		} //return the value of the top node
	}

	// isempety operation : check if the stack is empety
	bool isEmpty() {
		return top == NULL; // return true if the top pointer is Null, indicating an empety stack
	}

};

int main ()
{
	Stack stack;
	int choice = 0;
	int value;

	while (choice != 5) {
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Peek\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			stack.push(value); // push the entered value onto the stack
			break;
		case 2:
			if (!stack.isEmpty()) {
				stack.pop(); //pop the top element form the stack
			}
			else {
				cout << "stack is empty. Cannot pop." << endl;
			}
			break;

		case 3:
			if (!stack.isEmpty()) {
				stack.peek(); // get the value of the top element
			}
			else {
				cout << "Stack is empty. No top value." << endl;
			}
			break;

		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
			break;

		}
		cout << endl;
	}
	return 0;
}