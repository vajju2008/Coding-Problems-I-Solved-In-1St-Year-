#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*prev;
	int data;
	struct node*next;
};
struct node*head=NULL,*p,*q,*r;
void create()
{
	int n,i;
	printf("\n Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter Data:");
		scanf("%d",&p->data);
		p->next=NULL;
		if(head==NULL){
			head=p;
			p->prev=NULL;
		}
		else{
			q=head;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
			p->prev=q;
		}
	}
      display();
}
void display()
{
	q=head;
	while(q!=NULL)
	{
		printf("%d",q->data);
		q=q->next;
	}
}
void revTraversing()
{
	p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	while(p!=NULL){
		printf("%d",p->data);
		p=p->prev;
	}
}
void insert_beg()
{
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&p->data);
	if(head==NULL)
	   printf("List is empty\n");
	else{
		p->next=head;
		head=p;
		p->next->prev=p;
		p->prev=NULL;
	}
	display();
}
void insert_end()
{
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&p->data);
	p->next=NULL;
	q=head;
	if(head==NULL)
	   printf("List is empty\n");
	else{
		while(q->next!=NULL)
		q=q->next;
		q->next=p;
		p->prev=q;
	}
	display();
}
void insert_pos()
{
	int pos,i;
	printf("Enter pos:");
	scanf("%d",&pos);
	q=head;
	r=head->next;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&p->data);
	if(head==NULL)
	   printf("List is empty\n");
	else{
		for(i=1;i<pos-1;i++)
		{
			q=q->next;
			r=r->next;
		}
		p->next=r;
		q->next=p;
		p->prev=q;
		r->prev=p;
	}
	display();
}
void delete_beg()
{
	p=head;
	if(head==NULL)
	printf("List is empty\n");
	else{
		p->next->prev=NULL;
		head=p->next;
	}
	free(p);
}
void delete_end()
{
	p=head;
	q=p->next;
	if(head==NULL)
	printf("List is empty\n");
	else{
		while(q->next!=NULL)
		{
			p=p->next;
			q=q->next;
		}
		p->next=NULL;
		free(q);
	}
	display();
}
void delete_pos()
{
	int pos,i;
	printf("Enter pos:");
	scanf("%d",&pos);
	q=head;
	r=head->next;
	if(head==NULL)
	   printf("List is empty\n");
	else{
		for(i=1;i<pos-1;i++)
		{
			q=q->next;
			r=r->next;
		}
		q->next=r->next;
		free(r);
	}
}

	   