#include<iostream>
#define maxsize 5

using namespace std;
struct Queue
{
	int a[maxsize];
	int front;
	int rear;
};
typedef struct Queue myQueue;
void push(myQueue *Q, int x) {
	if ( (Q->rear + 1) % maxsize == Q->front) {
		cout << "Queue is full!!" << endl;
		return;
	}

	Q->a[Q->rear] = x;
	Q->rear = (Q->rear + 1) % maxsize;

}
int pop(myQueue *Q) {
	int x;
	if (Q->rear == Q->front ) {
		cout << "Queue is empty!!" << endl;
		return -1;
	}
	x = Q->a[Q->front];
	Q->front = (Q->front + 1) % maxsize;
	return x;

}
void display(myQueue Q) {
	if (Q.front == Q.rear) {
		cout << "QUEUE is empty!!" << endl;
	}
	else if (Q.front < Q.rear) {
		for (int i = Q.front; i < Q.rear; i++) {
			cout << Q.a[i] << " ";
		}
		cout << endl;
	} else {
		for (int i = Q.front; i < maxsize; i++) {
			cout << Q.a[i] << " ";
		}
		for (int i = 0; i < Q.rear; i++)

			cout << Q.a[i] << " ";
		cout << endl;
	}


}

int main() {
	myQueue Q;
	Q.rear = 0;
	Q.front = 0;
	int ch, x;
	while (1) {
		cout << "Choose operation you want to perform :" << endl;
		cout << "***********************MAIN MENU************************" << endl;
		cout << " 1. " << " Push " << endl;
		cout << " 2. " << " Pop " << endl;
		cout << " 3. " << " Display Queue  " << endl;
		cout << " 4. " << " Exit " << endl;

		cin >> ch;
		switch (ch) {
		case 1 :
			cout << "Enter the element you want to push:" << endl;
			cin >> x;
			push(&Q, x);
			break;
		case 2:
			x = pop(&Q);
			cout << "Deleted element is :" << x << endl;
			break;
		case 3:
			display(Q);
			break;
		case 4:
			return 0;

		}
	}

}