#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/**************************** Structures definition *************************************************/
struct Node {
	int elt;
	struct Node *next;
};
typedef struct Node Node;

struct List {
	Node *head;
	Node *tail;
	int size;
};
typedef struct List List;


/****************************** Interface methods for Linked List ***********************************/

// build a Linked List with single value
List *build_list(int);

// insert value at the 'k'th index
void insert_at_index(List *, int, int);

// insert value at the end
void insert_at_end(List *, int);

// delete value at 'k'th index
// k should fall in the interval [0,n-1]
void delete_at_index(List *, int);

// delete value at the end
void delete_at_end(List *);

// search for value by index
// return -1 if the index is out of range
int search_val(List *, int);

// search for index by value
// return -1 if the value is not present in the linked list
int search_index(List *, int);



/************************** Internal methods for Linked List ************************************/

// create a new node, place the parameter as element of the node and return the address to the node
Node *create_node(int elt);


/************************** Internal methods definition *****************************************/

Node *create_node(int elt) {
	Node *newNode = (Node *) malloc (sizeof(Node));
	if(newNode < 0)
		perror("malloc failed to create a node...\n");

	newNode->elt = elt;
	newNode->next = NULL;

	return newNode;
}


/************************* Interface methods definition *****************************************/

List *build_list(int elt) {
	List *l = (List *) malloc (sizeof(List));
	if(l < 0)
		perror("Malloc failed to build list\n");
	
	l->head = create_node(elt);
	l->tail = l->head;
	l->size = 1;
	return l;
}

// k should fall in the interval [0,n-1]
void insert_at_index(List *l, int k, int elt) {
	int i = 0;
	Node *temp = create_node(0);
	Node *prev = create_node(0);
	
	temp = l->head;
	while (i < k) {
		prev = temp;
		temp = temp->next;
		i++;
	}
	Node *newNode = create_node(elt);
	prev->next = newNode;
	newNode->next = temp;
	
	l->tail = l->tail->next;
	l->size += 1;
}

// the earlier tail node will point to the new node and this new node will be the new tail
void insert_at_end(List *l, int elt) {
	if(l < 0)
		perror("Invalid List pointer passed as parameter to insert_at_end()\n");

	l->tail->next = create_node(elt);
	l->tail = l->tail->next;
	l->size += 1;
}

// k should fall in the interval [0,n-1], or else no delete will happen here
void delete_at_index(List *l, int k) {
	if(l < 0)
		perror("Invalid List pointer passed as parameter to insert_at_index()\n");

	if (l->size > 0 && k < (l->size) - 1) {
		int i = 0;
		Node *temp = create_node(0);
		Node *prev = create_node(0);
		temp = l->head;
		while (i < k) {
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
		l->size -= 1;
	}
}

// need to traverse the complete list
void delete_at_end(List *l) {
	if(l < 0)
		perror("Invalid List pointer passed as parameter to delete_at_end()\n");
	
	if (l->size > 0) {

		Node *temp = create_node(0);
		Node *prev = create_node(0);
		temp = l->head;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}

		l->tail = prev;
		l->size -= 1;
		prev->next = NULL;
	}
}

int search_val(List *l, int k) {
	if(l < 0)
		perror("Invalid List pointer passed as parameter to search_val()\n");

	int val;
	if(k == (l->size) -1)
		val = l->tail->elt;
	
	else if(k < (l->size) - 1)
	{
		Node *temp = create_node(0);
		temp = l->head;
		int i = 0;
		while (i < k) {
			temp = temp->next;
			i++;
		}
		val = temp->elt;
	}
	else
		val = -1;

	return val;
}

// return -1 if the value is not present in the linked list
int search_index(List *l, int elt) {
	if(l < 0)
		perror("Invalid List pointer passed as parameter to search_index()\n");
	
	int k = 0;
	Node *temp = create_node(0);
	temp = l->head;

	while (temp->next != NULL && temp->elt != elt) {
		temp = temp->next;
		k++;
	}
	if (k > l->size - 1)
	       k = -1;

	return k;	
}

#endif
