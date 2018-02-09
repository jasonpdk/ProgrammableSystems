/*
 *	CRUDLinkedList.h
 *  Jason Keane
*/

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

// Function Prototypes
// Only functions that modify start need return it
node *create_ll(node*);
void display(node*);
node *insert_beg(node*);
void insert_end(node*);
void insert_before(node*);
void insert_after(node*);
node *delete_beg(node*);
void delete_end(node*);
node *delete_node(node*);
void delete_after(node*);
node *delete_list(node*);
void sort_list(node*);
node *sortandRemoveDuplicates(node*);
node *removeDuplicatesUnsorted(node*);
void multiplyBy10(node*);
void countNonZero(node *start);
