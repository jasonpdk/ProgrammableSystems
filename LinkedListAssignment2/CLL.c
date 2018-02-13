#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"

int main(void)
{
  node *start = NULL;

  int option;

  do {
    printf("\n\n ***************** MAIN MENU ****************");
		printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Delete the first occurrence of a character");
    printf("\n 4: Delete the last occurrence of a character");
    printf("\n 5: Delete all occurrences of a character");

    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch(option)
    {
      case 1:
        start = create_ll(start);
				break;
      case 2:
        display(start);
        break;
      case 3:
        start = removeFirst(start);
        break;
      case 4:
        start = removeLast(start);
        break;
      case 5:
        start = removeAllOccurrences(start);
        break;
    }
  } while(option != 6);

  return 0;
}
