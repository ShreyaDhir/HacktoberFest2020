#include<stdio.h>
#include<stdlib.h>
#include"link_list.h"
#include<iostream>
using namespace std;

int main() {
	struct node* head = NULL;
	int ch, x, pos;
	while (1) {
		printf( "\nChoose operation you want to perform :\n");
		printf("\n***********************MAIN MENU************************\n");
		printf(" 1. Insert at Beginning\n");
		printf(" 2. Insert at End\n");
		printf(" 3. Insert After positon\n");
		printf(" 4. Delete a node\n");
		printf(" 5. Display\n");
		printf(" 6. Count Nodes\n");
		printf(" 7. Search a Value\n");
		// printf(" 8. DeleteAtKth\n");
		printf(" 8. Reverse List\n");
		printf(" 9. Sort the List List\n");
		printf(" 10. Exit\n\n");

		cin >> ch;
		switch (ch) {
		case 1 :
			cout << "Enter the element you want to insert at beginning :" << endl;
			cin >> x;
			InsertionAtBegin(head, x);
			printf("The list is :\n");
			display(head);
			break;
		case 2:
			cout << "Enter the element you want to insert at tail:" << endl;
			cin >> x;
			InsertionAtTail(head, x);
			printf("\nThe list is :\n");
			display(head);
			break;
		case 3:
			cout << "Enter the positon after which you want to insert the element:" << endl;
			cin >> pos;
			cout << "Enter the element:" << endl;
			cin >> x;
			InsertionAtPos(head, x, pos);

			display(head);
			break;
		case 4:
			if (head == NULL) {
				printf("The list is empty!!\n");
				break;
			}
			cout << "Enter the element you want to delete :" << endl;
			cin >> x;
			Deletion(head, x);
			printf("\nThe list is :\n");
			display(head);
			break;
		case 5:
			if (head == NULL) {
				printf("The list is empty!!\n");
				break;
			}
			printf("\nThe list is :\n");
			display(head);
			break;
		case 6:
			if (head == NULL) {
				printf("The list is empty!!\n");
				break;
			}
			printf("The number of nodes are : %d\n", count(head));
			break;
		case 7:
			if (head == NULL) {
				printf("The list is empty!!\n");
				break;
			}
			cout << "Enter the element you want to search :" << endl;
			cin >> x;
			search(head, x);
			break;
		case 8:
		{
			if (head == NULL) {
				printf("The list is empty!!\n");
				break;
			}
			struct node* Reverse = Reverse_List(head);
			display(Reverse);
			break;
		}

		case 9:
			printf("\nThe list is :\n");
			display(merge_sort(head));
			break;

		case 10:
			return 0;
		}
	}
}