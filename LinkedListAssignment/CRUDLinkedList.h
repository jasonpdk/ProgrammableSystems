/*
 *	CRUDLinkedList.h
 *  Jason Keane
*/

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

node *create_ll(node *);
node *display(node *);
node *insert_beg(node *);
node *insert_end( node *);
node *insert_before( node *);
node *insert_after( node *);
node *delete_beg( node *);
node *delete_end( node *);
node *delete_node( node *);
node *delete_after( node *);
node *delete_list( node *);
node *sort_list( node *);
node *sortandRemoveDuplicates(node*);
node *removeDuplicatesUnsorted(node*);
void multiplyBy10(node*);
void countNonZero(node *start);
