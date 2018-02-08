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

node *sortandRemoveDuplicates(node *start)
{
	start = sort_list(start);
	node *ptr, *preptr, *temp;
	ptr = start;
	int index = 0;

	while(ptr->next != NULL)
	{
		if (ptr->data == ptr->next->data)
		{
			printf("Duplicate %d found and removed.\n", ptr->data);
			if (index != 0)
			{
				preptr->next = ptr->next;
				temp = ptr->next;
				free(ptr);
				ptr = temp;
			}
			else
			{
				start = ptr->next;
				free(ptr);
				ptr = ptr->next;
			}
		}
		else
		{
			preptr = ptr;
			ptr = ptr->next; //continue to next node
		}
		index++;
	}
	return start;
}

node *removeDuplicatesUnsorted(node *start)
{
	node *ptr, *ptr2, *preptr, *temp;
	ptr = start;
	int index = 0;
	while(ptr != NULL && ptr->next != NULL)
	{
		ptr2 = ptr;
		while(ptr2->next != NULL)
		{
			if (ptr->data == ptr2->next->data)
			{
				printf("Found duplicate %d\n", ptr->data);

				if (index != 0)
				{
					// remove
					preptr->next=ptr->next;
					temp = ptr->next;
					free(ptr);
					ptr=temp;
				}
				else
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

 		ptr = ptr -> next;
	}

	printf(" There are %d non-zero elements in the linked list.\n", count);
}
