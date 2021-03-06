//Matthew Montada, Class that serves as the solution for Chapter 2 Question 2 1/18/21, Chapter 2 Question 2

#include "stdafx.h"

using namespace std;

/* Creates a node for the linked list */
struct Node
{
	int data;
	struct Node* next;
}; //end of node

/* Function used to print the kth to last element of
the list*/
void printNthFromLast(struct Node *head, int n)
{
	struct Node *main_ptr = head; //initializes the main pointer 
	struct Node *ref_ptr = head; //initializes the referene pointer

	int count = 0; //initializes the value for the count
	if (head != NULL)
	{
		while (count < n)
		{
			if (ref_ptr == NULL)
			{
				printf("%d is greater than the no. of "
					"nodes in list", n); //what will be printed if the count is greater than the no. of nodes in the linked list
				return;
			}
			ref_ptr = ref_ptr->next; //moves the reference pointer
			count++; //increases the count
		} /* End of while*/

		if (ref_ptr == NULL)
		{
			head = head->next; //moves the head node
			if (head != NULL)
				printf("Node no. %d from last is %d ", n, main_ptr->data); //prints the new data and main pointer position
		}
		else
		{
			while (ref_ptr != NULL)
			{
				main_ptr = main_ptr->next; //moves the main pointer if ref_ptr != NULL
				ref_ptr = ref_ptr->next; //moves the reference pointer if it is not equal to NULL
			}
			printf("Node no. %d from last is %d ", n, main_ptr->data); //prints the new data and main pointer position
		} //end of else statement
	} //end of if statement
} //end of void function

//Push Function 
void push(struct Node** head_ref, int new_data)
{
	/* Creates the node for allocating */
	struct Node* new_node = new Node();

	/* Inserts the new data to the new node */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head node to point to the new node */
	(*head_ref) = new_node;
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL; //set the value for the head node
	push(&head, 20); //pushes head node
	push(&head, 4); //pushes head node
	push(&head, 15); //pushes head node
	push(&head, 35); //pushes head node

	printNthFromLast(head, 4); //prints the kth to last element of the list
}

