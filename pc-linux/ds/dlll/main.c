/*
 * main.c
 *
 *  Created on: 14-Sep-2019
 *      Author: sunbeam
 */

#include"list.h"

int main(void)
{
	list_t l1;


	init_list(&l1);

	add_node_at_last_position(&l1, 10);
	add_node_at_last_position(&l1, 20);
	add_node_at_last_position(&l1, 30);
	add_node_at_last_position(&l1, 40);
	add_node_at_last_position(&l1, 50);
	add_node_at_last_position(&l1, 60);
	add_node_at_last_position(&l1, 70);


	display_list(&l1);

	//add_node_at_first_position(&l1, 5);
	//add_node_at_specific_position(&l1, 99, 4);

	//delete_node_at_first_position(&l1);
	//delete_node_at_last_position(&l1);

	delete_node_at_specific_position(&l1, 5);
	display_list(&l1);

	free_list(&l1);

	return 0;
}


