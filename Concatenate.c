#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
}*head1, *head2, *l1, *l2, *last;

void createlist1(int n);
void createlist2(int m);
void display();
void concat();
int main()
{
  int n;
  printf("Enter the number of nodes for first list\n");
  scanf("%d",&n);
  createlist1(n);
  printf("Enter the number of nodes for second list\n");
  scanf("%d",&n);
  createlist2(n);
  display();
  concat();
  return 0;
}
 
void createlist1(int n)
{
  struct node *new;
  l1=(struct node*)malloc(sizeof(struct node));
  if(l1==NULL)
    printf("MEMORY NOT ALLOCATED\n");
  else
  {
    printf("Enter the data for 1st node: ");
    scanf("%d",&l1->data);
    l1->next=NULL;
    l1->prev=NULL;
    head1=l1;
    for(int i=0;i<n-1;i++)
    {
     new=(struct node*)malloc(sizeof(struct node)); 
     if(new==NULL)
       printf("MEMORY NOT ALLOCATED\n");
     else
     {
       printf("Enter the data: ");
       scanf("%d",&new->data);
       new->prev=l1;
       l1->next=new;
       l1=l1->next;
     }
    }
    last=l1;
  }
}

void createlist2(int m)
{
  struct node *new;
  l2=(struct node*)malloc(sizeof(struct node));
  if(l2==NULL)
    printf("MEMORY NOT ALLOCATED\n");
  else
  {
    printf("Enter the data for 1st node: ");
    scanf("%d",&l2->data);
    l2->next=NULL;
    l2->prev=NULL;
    head2=l2;
    for(int i=0;i<m-1;i++)
    {
     new=(struct node*)malloc(sizeof(struct node)); 
     if(new==NULL)
       printf("MEMORY NOT ALLOCATED\n");
     else
     {
       printf("Enter the data: ");
       scanf("%d",&new->data);
       new->prev=l2;
       l2->next=new;
       l2=l2->next;
     }
    }
  }
}
void concat()
{
  struct node *ptr, *tmp;
  ptr=head1;
  while(ptr->next!=NULL)
   ptr=ptr->next;
  ptr->next= head2;
  ptr->prev=last;
  tmp=head1;
  printf("The concatenated list:\n");
  while(tmp!=NULL)
  {
    printf("%d\n",tmp->data);
    tmp=tmp->next;
  }
}
  
void display()
{
  struct node *tmp, *temp;
  tmp=head1;
  printf("\nList 1:\n");
  while(tmp!=NULL)
  {
    printf("%d\n",tmp->data);
    tmp=tmp->next;
  }
  printf("\nList 2:\n");
  temp=head2;
  while(temp!=NULL)
  {
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}
  
    
    
    
    
    
    
    


