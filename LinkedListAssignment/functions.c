/*
 *	functions.c
 *  Contains the functions for CRUDLinkedList
 *  Jason Keane
*/

#include <stdio.h>
#include <stdlib.h>
#include "CRUDLinkedList.h"


node *create_ll(node *start)
{
	node *new_node, *ptr;
	int num;

	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);

	while(num!= -1) {
 		new_node = (node*)malloc(sizeof(node));
 		new_node -> data=num;

 		if(start==NULL) {
 			new_node -> next = NULL;
 			start = new_node;
 		}
 		else {
 			ptr=start;
 			while(ptr->next!=NULL)
 				ptr=ptr->next;
 			ptr->next = new_node;
 			new_node->next=NULL;
 		}

 	printf("\n Enter the data : ");
 	scanf("%d", &num);
	}

	return start;
}

node *display(node *start)
{
	node *ptr;
	ptr = start;

	while(ptr != NULL) {
 		printf("\t %d", ptr -> data);
 		ptr = ptr -> next;
	}

return start;
}

node *insert_beg(node *start)
{
	node *new_node;
	int num;

	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (node *)malloc(sizeof(node));
	new_node -> data = num;
	new_node -> next = start;
	start = new_node;

	return start;
}

node *insert_end(node *start)
{
	node *ptr, *new_node;
	int num;

	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (node *)malloc(sizeof(node));
	new_node -> data = num;
	new_node -> next = NULL;
	ptr = start;
	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node;

	return start;
}

node *insert_before(node *start)
{
	node *new_node, *ptr, *preptr;
	int num, val;

	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value before which the data has to be inserted : ");
	scanf("%d", &val);
	new_node = (node *)malloc(sizeof(node));
	new_node -> data = num;
	ptr = start;

	while(ptr -> data != val) {
		preptr = ptr;
 		ptr = ptr -> next;
	}

	preptr -> next = new_node;
	new_node -> next = ptr;

	return start;
}

node *insert_after(node *start)
{
	node *new_node, *ptr, *preptr;
	int num, val;

	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after which the data has to be inserted : ");
	scanf("%d", &val);
	new_node = (node *)malloc(sizeof(node));
	new_node -> data = num;
	ptr = start;
	preptr = ptr;

	while(preptr -> data != val) {
 		preptr = ptr;
 		ptr = ptr -> next;
	}

	preptr -> next=new_node;
	new_node -> next = ptr;

	return start;
}

node *delete_beg(node *start)
{
	node *ptr;
	ptr = start;

	start = start -> next;
	free(ptr);

	return start;
}

node *delete_end(node *start)
{
	node *ptr, *preptr;
	ptr = start;

	while(ptr -> next != NULL) {
 		preptr = ptr;
 		ptr = ptr -> next;
	}

	preptr -> next = NULL;
	free(ptr);

	return start;
}

node *delete_node(node *start)
{
	node *ptr, *preptr;
	int val;

	printf("\n Enter the value of the node which has to be deleted : ");
	scanf("%d", &val);
	ptr = start;
	if(ptr -> data == val) {
 		start = delete_beg(start);
 	return start;
	}
	else {
		while(ptr -> data != val) {
 			preptr = ptr;
 			ptr = ptr -> next;
 		}
 		preptr -> next = ptr -> next;
 		free(ptr);
 	return start;
	}
}

node *delete_after(node *start)
{
	node *ptr, *preptr;
	int val;

	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	preptr = ptr;

	while(preptr -> data != val) {
 		preptr = ptr;
 		ptr = ptr -> next;
	}

	preptr -> next=ptr -> next;
	free(ptr);

	return start;
}

node *delete_list(node *start)
{
	node *ptr;

	if(start!=NULL){
 		ptr=start;
 		while(ptr != NULL) {
 			printf("\n %d is to be deleted next", ptr -> data);
 			start = delete_beg(ptr);
			ptr = start;
 		}
	}

return start;
}

node *sort_list(node *start)
{
	node *ptr1, *ptr2;
	int temp;

	ptr1 = start;
	while(ptr1 -> next != NULL) {
 		ptr2 = ptr1 -> next;
 		while(ptr2 != NULL) {
 			if(ptr1 -> data > ptr2 -> data) {
 				temp = ptr1 -> data;
 				ptr1 -> data = ptr2 -> data;
 				ptr2 -> data = temp;
 			}
 		ptr2 = ptr2 -> next;
 		}
 	ptr1 = ptr1 -> next;
 	}

	return start;
}


/* ADDED FUNCTIONS */
/*
 * sortandRemoveDuplicates
 * Sorts the linked list and then removes any duplicates found
*/
node *sortandRemoveDuplicates(node *start)
{
	start = sort_list(start);
	node *ptr, *preptr, *temp;
	ptr = start;
	int index = 0;

	while(ptr->next != NULL)
	{
		if (ptr->data == ptr->next->data) // compare current element with next element
		{
			printf("Duplicate %d found and removed.\n", ptr->data);
			if (index != 0)
			{
				preptr->next = ptr->next;
				temp = ptr->next;
				free(ptr);
				ptr = temp;
			}
			else // if node to be removed is at the beginning
			{
				// remove the element by making start->next point to ptr->next, skipping the duplicate (ptr) and free the memory
				start = ptr->next;
				free(ptr);
				ptr = start; //continue to the next node
			}
		}
		else //if adjacent elements are not duplicates, continue to the next node
		{
			preptr = ptr;
			ptr = ptr->next; //continue to next node
		}
		index++;
	}
	return start;
}

/*
 * removeDuplicatesUnsorted
 * Removes any duplicates found in the linked list without affecting the order.
 * The elements are removed from the beginning of the list if their dublicate is found.
*/
node *removeDuplicatesUnsorted(node *start)
{
	node *ptr, *ptr2, *preptr, *temp;
	ptr = start;
	int index = 0;
	while(ptr != NULL && ptr->next != NULL) // loop through every element in the list
	{
		ptr2 = ptr;
		/* Loop through every element in the list for each element.
		 * The total number of loops will n^2, where n is the number
		 * of elements in the list.
    */
		while(ptr2->next != NULL)
		{
			if (ptr->data == ptr2->next->data)
			{
				printf("Found and removed duplicate %d\n", ptr->data);

				if (index != 0)
				{
					// remove
					preptr->next=ptr->next;
					temp = ptr->next;
					free(ptr);
					ptr=temp;
				}
				else // if duplicate is at the beginning of the list
				{
					start = ptr->next;
					free(ptr);
					ptr = ptr->next;
				}
			}
			ptr2 = ptr2->next;

		}
		preptr = ptr;
		ptr = ptr->next;
		index++;
	}

	return start;
}

/*
 * multiplyBy10
 * Multiplies eachs element of the linked list by 10
*/
void multiplyBy10(node *start)
{
	node *ptr;
	ptr = start;

	while(ptr != NULL)
	{
 		ptr->data *= 10;
 		ptr = ptr -> next;
	}
}

/*
 * countNonZero
 * Counts all of the non-zero elements in the list
*/
void countNonZero(node *start)
{
	node *ptr;
	ptr = start;
	int count = 0;
	while(ptr != NULL)
	{
 		if(ptr->data != 0)
		{
			count++;
		}

 		ptr = ptr -> next; // continue to next node
	}

	printf(" There are %d non-zero elements in the linked list.\n", count);
}
