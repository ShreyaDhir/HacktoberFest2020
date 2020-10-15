#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **top, int data)
{
	struct node *nnode;
	nnode = (struct node *)malloc(sizeof(struct node));
	if(nnode==NULL){
		printf("\nOut of memory");
		exit(0);
	}
	nnode->data = data;
	nnode->next = *top;
	*top = nnode;
}

int pop(struct node **top)
{
	struct node *temp;
	int d;
	if(top == NULL){
		printf("\nStack Underflow");
		exit(0);
	}
	temp = *top;
	d = temp->data;
	*top = (*top)->next;
	free(temp);
	return(d);
}

struct queue{
	struct node *stack1;
	struct node *stack2;
};

void enqueue(struct queue *q, int x){
	push(&q->stack1,x);
}

void dequeue(struct queue *q){
	int x;
	if(q->stack1==NULL && q->stack2==NULL){
		printf("Queue is Empty");
		return;
	}
	if(q->stack2==NULL){
		while(q->stack1!=NULL){
			x = pop(&q->stack1);
			push(&q->stack2,x);
		}
	}
	x = pop(&q->stack2);
	printf("%d\n",x);
}

void display(struct queue *q){
	struct node *curr;
	curr = q->stack2;
	if(curr==NULL){
		printf("Queue is Empty");
		exit(0);
	}
	while(curr!=NULL){
		printf("\t%d", curr->data);
		curr = curr->next;
	}
}

int main(){
	struct queue *q;
	q = (struct queue *)malloc(sizeof(struct queue));
	int l;
	while(l!=4){
		printf("\n1: Insert\t2: Delete\t3: Display\t4: Exit\n");
		printf("Enter: ");
		scanf("%d",&l);
		switch(l){
			case 1:{
				int x;
				printf("\nAdd: ");
				scanf("%d",&x);
				enqueue(q,x);
				break;
			}
			case 2:{
				dequeue(q);
				break;
			}
			case 3:{
				display(q);
				break;
			}
			case 4:{
				printf("\nThank You!!");
				break;
			}
		}
	}
	return 0;
}
