/*
 * main.c
 *
 *  Created on: 17-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include<stdlib.h>
#include"bst.h"


//entry point function
int main(void)
{
	bst_t t1;
	//50 20 90 85 10 45 30 100 15 75 95 120 5 50
	init_bst(&t1);

	add_node(&t1, 50);
	add_node(&t1, 20);
	add_node(&t1, 90);
	add_node(&t1, 85);
	add_node(&t1, 10);
	add_node(&t1, 45);
	add_node(&t1, 30);
	add_node(&t1, 100);
	add_node(&t1, 15);
	add_node(&t1, 75);
	add_node(&t1, 95);
	add_node(&t1, 120);
	add_node(&t1, 5);
	add_node(&t1, 50);

	printf("PREORDER  : "); preorder(&t1, t1.root); printf("\n");
	nonrec_preorder(&t1);
	printf("INORDER   : "); inorder(&t1, t1.root); printf("\n");
	nonrec_inorder(&t1);
	printf("POSTORDER : "); postorder(&t1, t1.root); printf("\n");
	nonrec_postorder(&t1);

	return 0;
}

