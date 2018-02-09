/*
 *	CRUDLinkedList.c
 *  Jason Keane
*/

#include <stdio.h>
#include <stdlib.h>
#include "CRUDLinkedList.h"

int main(int argc, char *argv[])
{
	node *start = NULL;
	int option;

	do {
 		printf("\n\n ***************** MAIN MENU ****************");
 		printf("\n 1: Create a list");
 		printf("\n 2: Display the list");
 		printf("\n 3: Add a node at the beginning");
 		printf("\n 4: Add a node at the end");
 		printf("\n 5: Add a node before a given node");
 		printf("\n 6: Add a node after a given node");
 		printf("\n 7: Delete a node from the beginning");
 		printf("\n 8: Delete a node from the end");
 		printf("\n 9: Delete a given node");
 		printf("\n 10: Delete a node after a given node");
 		printf("\n 11: Delete the entire list");
 		printf("\n 12: Sort the list");
 		printf("\n 13: Sort the list and remove duplicates");
		printf("\n 14: Remove duplicates without sorting the list");
		printf("\n 15: Multiply each element by 10");
		printf("\n 16: Count the non-zero elements");
 		printf("\n\n Enter your option : ");
 		scanf("%d", &option);

 		switch(option) {

 			case 1: start = create_ll(start);
 				printf("\n LINKED LIST CREATED");
 				break;
 			case 2: display(start);
 				break;
 			case 3: start = insert_beg(start);
 				break;
 			case 4: insert_end(start);
 				break;
 			case 5: insert_before(start);
 				break;
 			case 6: insert_after(start);
 				break;
 			case 7: start = delete_beg(start);
 				break;
 			case 8: delete_end(start);
 				break;
 			case 9: start = delete_node(start);
 				break;
 			case 10: delete_after(start);
 				break;
 			case 11: start = delete_list(start);
 				printf("\n LINKED LIST DELETED");
 				break;
 			case 12: sort_list(start);
 				break;
			case 13: start = sortandRemoveDuplicates(start);
				break;
			case 14: start = removeDuplicatesUnsorted(start);
				break;
			case 15: multiplyBy10(start);
				break;
			case 16: countNonZero(start);
				break;
 		}

	} while(option !=17);

return 0;

}
