#include<stdio.h>
struct node {
	int data;
	struct node* next;
};
typedef struct node mynode;
void InsertionAtBegin(struct node* &head, int x) {
	mynode* p;
	p = (mynode*)malloc(sizeof(mynode));
	if (p != NULL) {
		p->data = x;
		// p->next = NULL; NO NEED
		p->next = head;
		head = p;
	}
}
void InsertionAtTail(struct node* &head, int x) {
	mynode* temp = head;
	mynode* p;
	if (head == NULL) {
		InsertionAtBegin(head, x);
		return;
	}
	p = (mynode*)malloc(sizeof(mynode));
	if (p != NULL) {
		p->data = x;
		p->next = NULL;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = p;

	} else {
		printf("Memory FULL!!\n");
	}

}
int count(mynode* head) {
	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}
void InsertionAtPos(mynode* &head, int x, int pos) {
	int k = 0;
	if (pos <= 0 ) {
		printf("\nEnter a valid positon\n");
		return;
	} else {
		mynode* p;
		p = (mynode*)malloc(sizeof(mynode));
		if (p == NULL) {
			printf("Memory FULL!!\n");
			return;
		}
		p->data = x;
		p->next = NULL;
		mynode * temp = head;
		if (temp == NULL) {
			InsertionAtBegin(head, x);
			return;
		}
		while (temp->next != NULL and k < pos - 1) {
			temp = temp->next;
			k++;
		}
		if (k == pos - 1) {
			p->next = temp->next;
			temp->next = p;
		} else {
			temp->next = p;
		}
	}
}
void display(mynode * head) {
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("\n");
}
void Deletion(mynode* &head, int ele) {
	mynode* temp = head;
	if (temp->data == ele) {
		head = head->next;
		return;
	}
	while (temp != NULL and temp->next != NULL and temp->next->data != ele) {
		temp = temp->next;
	}
	if (temp == NULL or temp->next == NULL) {
		printf("Element NOT found!!\n");
		return;
	}
	if (temp->next->data == ele) {
		mynode* tobedeleted = temp->next;
		temp->next = temp->next->next;
		free(tobedeleted);
		return;
	}

}
void search(mynode* head, int ele) {
	int pos = 0;
	while (head != NULL and head->data != ele) {
		pos++;
		head = head->next;
	}
	if (head != NULL and head->data == ele) {
		printf("The element %d is found at positon %d \n", ele, pos + 1);
	} else {
		printf("Element not found!!\n");
	}
}
mynode* Reverse_List(mynode* head) {
	mynode* prev = NULL;
	mynode* curr = head;
	mynode *n;
	while (curr != NULL) {
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
	return prev;

}
mynode* sort(mynode* a, mynode* b) {
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	if (a->data > b->data) {
		b->next = sort(a, b->next);
		return b;
	} else {
		a->next = sort(a->next, b);
		return a;

	}
}
mynode* merge_sort(mynode *head) {
	if (head == NULL or head->next == NULL)
		return head;
	mynode* head1 = NULL;
	mynode* head2 = NULL;
	mynode* slow = head;
	mynode* fast = head;
	while ( fast->next != NULL and fast->next->next != NULL ) {
		slow = slow->next;
		fast = fast->next->next;
	}
	head2 = slow->next;
	slow->next = NULL;
	head1 = head;
	head1 = merge_sort(head1);
	head2 = merge_sort(head2);
	return sort(head1, head2);


}
