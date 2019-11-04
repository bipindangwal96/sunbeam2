/*
 * main.c
 *
 *  Created on: 09-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include<stdlib.h>
#include"list.h"

enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST, DELLAST,
	DELATPOS, DISPLAY, DISPLAY_REVERSE, REVERSE_LIST };

int menu(void)
{
	int choice;

	printf("SINGLY LINEAR LINKED LIST OPERATIONS\n");
	printf("0. EXIT\n");
	printf("1. ADDLAST\n");
	printf("2. ADDFIRST\n");
	printf("3. ADDATPOS\n");
	printf("4. DELFIRST\n");
	printf("5. DELLAST\n");
	printf("6. DELATPOS\n");
	printf("7. DISPLAY\n");
	printf("8. DISPLAY REVERSE\n");
	printf("9. REVERSE THE LIST\n");


	printf("ENTER THE CHOICE: ");
	scanf("%d", &choice);

	return choice;
}

int main(void)
{
	//printf("sizeof(node_t): %lu bytes\n", sizeof(node_t));
	list_t l1, l2;
	init_list(&l1);
	int pos;
	int choice;
	int data;
	//init_list(&l2);

	while(1)
	{
		choice = menu();
		switch(choice)
		{
		case EXIT:
			free_list(&l1);
			exit(0);
		case ADDLAST:
			printf("enter data: ");
			scanf("%d", &data);
			add_node_at_last_position(&l1, data);
			break;

		case ADDFIRST:
			printf("enter data: ");
			scanf("%d", &data);
			add_node_at_first_position(&l1, data);
			break;
		case ADDATPOS:
			while(1)
			{
				printf("enter the pos: ");
				scanf("%d", &pos);

				if( pos >= 1 && pos <=  l1.cnt + 1 )
					break;

				printf("invalid position !!!\n");
			}

			printf("enter data: ");
			scanf("%d", &data);
			add_node_at_specific_pos(&l1, data, pos);

			break;
		case DELFIRST:
			delete_node_at_first_position(&l1);
			break;

		case DELLAST:
			delete_node_at_last_position(&l1);
			break;

		case DELATPOS:
			while(1)
			{
				printf("enter the pos: ");
				scanf("%d", &pos);

				if( pos >= 1 && pos <=  l1.cnt )
					break;

				printf("invalid position !!!\n");
			}

			delete_node_at_specific_position(&l1, pos);

			break;

		case DISPLAY:
			display_list(&l1);
			break;

		case DISPLAY_REVERSE:
			if( !is_list_empty(&l1))
			{
				printf("list in reverse order is: ");
				display_reverse(&l1, l1.head);
				printf("\n");
			}
			else
				printf("list is empty !!!\n");
			break;

		case REVERSE_LIST:
			reverse_list(&l1);
			break;
		}
	}
	/*
	add_node_at_last_position(&l1,10);
	add_node_at_last_position(&l1,20);
	add_node_at_last_position(&l1,30);
	add_node_at_last_position(&l1,40);
	add_node_at_last_position(&l1,50);
	add_node_at_last_position(&l1,60);
	*/

	/*
	add_node_at_first_position(&l1, 11);
	add_node_at_first_position(&l1, 22);
	add_node_at_first_position(&l1, 33);
	add_node_at_first_position(&l1, 44);
	add_node_at_first_position(&l1, 55);
	add_node_at_first_position(&l1, 66);
	*/

	//display_list(&l1);

	/*
	while(1)
	{
		printf("enter the pos: ");
		scanf("%d", &pos);

		if( pos >= 1 && pos <=  l1.cnt + 1 )
			break;

		printf("invalid position !!!\n");
	}
	*/
	//add_node_at_specific_pos(&l1, 99, pos);

	//add_node_at_first_position(&l1, 5);

	//display_list(&l1);

	/*
	add_node_at_last_position(&l2, 11);
	add_node_at_last_position(&l2, 22);
	add_node_at_last_position(&l2, 33);
	add_node_at_last_position(&l2, 44);
	add_node_at_last_position(&l2, 55);
	display_list(&l2);

	*/
	return 0;
}


