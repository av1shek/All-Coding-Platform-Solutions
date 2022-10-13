// C++ program to find N/K node in a linked list with a O(n) time complexity.
#include <bits/stdc++.h>

/* Structure to create a node of a linked list */
struct Node {
	int data;
	Node* next;
};

/* Function to create a node of a linked list with given data */
Node* newNode(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to find N/K node in the linked list */
Node* fractionalNodes(Node* head, int k)
{
	if (k <= 0 || head == NULL)
		return NULL;

	Node* fractionalNode = NULL;
	
	int i = 0;
	for (Node* temp = head; temp != NULL; temp = temp->next) {

		// For every k nodes, we move N/Kth one
		// step ahead.
		if (i % k == 0) {

			// First time we see a multiple of k
			if (fractionalNode == NULL)
				fractionalNode = head;

			else
				fractionalNode = fractionalNode->next;
		}
		i++;
	}
	return fractionalNode;
}

// A utility function to print a linked list
void printList(Node* node)
{
	while (node != NULL) {
		cout<<node->data;
		node = node->next;
	}
	cout<<endl;
}

/* Driver program to test above function */
int main(void)
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	int k = 2;

	cout<<"List is : ";
	printList(head);

	Node* answer = fractionalNodes(head, k);
	cout<<"Fractional node is : ";
	cout<<answer->data;

	return 0;
}
