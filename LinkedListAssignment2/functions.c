#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"

node *create_ll(node *start)
{
  node *new_node, *ptr;

  char character;
  printf("\n Enter Q to end");
	printf("\n Enter the data : ");
	scanf(" %c", &character);

  while (character != 'Q')
  {
    new_node = (node*)malloc(sizeof(node));
 		new_node->data = character;

    if(start==NULL)
    {
 			new_node->next = NULL;
 			start = new_node;
 		}
    else
    {
      ptr = start;
      // go to end of list
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr->next = new_node;
 			new_node->next = NULL;
    }

    printf("\n Enter the data : ");
 	  scanf(" %c", &character);
  }

  return start;
}

void display(node *start)
{
  node *ptr;
  ptr = start;

  while (ptr != NULL)
  {
    printf("%c\t", ptr->data);
    ptr = ptr->next;
  }
}

node *removeFirst(node *start)
{
  node *ptr, *preptr, *temp;
  char character;
  int index = 0;
  ptr = start;

  printf("\nEnter the character: ");
  scanf(" %c", &character);

  while(ptr != NULL)
  {
    if (ptr->data == character)
    {
      if (index == 0)
      {
        start = ptr->next;
        free(ptr);
        ptr = start;
      }
      else
      {
        preptr->next = ptr->next;
        temp = ptr->next;
        free(ptr);
        ptr = temp;
      }
      break;
    }

    preptr = ptr;
    ptr = ptr->next;

    index++;
  }

  return start;
}

node *removeLast(node *start)
{
  node *ptr, *preptr;
  char character;
  int indexOfLast = 0, index = 0;
  ptr = start;

  printf("\nEnter the character: ");
  scanf(" %c", &character);

  // find index of last
  while(ptr != NULL)
  {
    if (ptr->data == character)
    {
      indexOfLast = index;
    }
    index++;
    ptr = ptr->next;
  }

  // delete the last occurence
  index = 0;
  ptr = start;
  while(ptr != NULL)
  {
    if (index == indexOfLast)
    {
      if (index == 0)
      {
        start = ptr->next;
        free(ptr);
      }
      else
      {
        preptr->next = ptr->next;
        free(ptr);
      }
      break;
    }

    index++;
    preptr = ptr;
    ptr = ptr->next;
  }

  printf("The index of the last occurrence of %c has been deleted.\n", character);
  return start;
}

node *removeAllOccurrences(node *start)
{
  node *ptr, *preptr, *temp;
  char character;
  int index = 0;

  printf("\nEnter the character to delete: ");
  scanf(" %c", &character);

  ptr = start;

  while (ptr != NULL)
  {
    if (ptr->data == character)
    {
      if (index == 0)
      {
        start = ptr->next;
        free(ptr);
        ptr = start;
      }
      else
      {
        preptr->next = ptr->next;
        temp = ptr->next;
        free(ptr);
        ptr = temp;
      }
    }
    else
    {
      preptr = ptr;
      ptr = ptr->next;
    }
    
    index++;
  }

  return start;
}
