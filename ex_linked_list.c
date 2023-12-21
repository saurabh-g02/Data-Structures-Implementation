#include <stdio.h>
#include <linked_list.h>

void print_list(List *l) {
	
	Node *temp = create_node(0);
	temp = l->head;

	while (temp != NULL) {
		printf ("%d ",temp->elt);
		temp = temp->next;
	}
	free (temp);

	printf ("\nGood Job print_list,,, I'm happy now\n");
}

int main (void) {
	
	int k, elt;
	// create list
	elt = 4;
	List *l = build_list(elt);
	printf ("Build Successful... \n");

	printf ("l->head = %p\n",l->head);
	printf ("l->tail = %p\n",l->tail);
	printf ("l->size = %d\n",l->size);

	k = 1; elt = 5;
	insert_at_index(l, k, elt);
	printf ("Successful insert \n");

	print_list(l);

	insert_at_end(l, 6);
	insert_at_end(l, 7);
	insert_at_end(l, 8);
	

	//print list
	print_list(l);
	printf("print_list successful..\n");
	
	k = 2;
	delete_at_index(l, k);
	printf ("delete at index successful...k: %d\n",k);

	print_list(l);
	
	delete_at_end(l);
	printf ("delete at end successful...\n");

	print_list(l);
	
	k = 3;
	printf ("success: search_val(l, %d) :%d \n",k,search_val(l,k));

	elt = 3;
	printf ("success: search_index(l, %d) :%d \n",elt,search_index(l,elt));
	


	return 0;
}
