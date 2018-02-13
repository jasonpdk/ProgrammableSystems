typedef struct NODE
{
  char data;
  struct NODE *next;
}node;

node *create_ll(node*);
void display(node*);
node *removeFirst(node*);
node *removeLast(node*);
node *removeAllOccurrences(node*);
