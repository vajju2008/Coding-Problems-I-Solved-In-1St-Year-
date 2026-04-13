#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL,*p,*q,*r,*nn;
void create()
{
	int n,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("Enter node's data:");
		scanf("%d",&nn->data);
		if(head==NULL)
		{
			head=nn;
			nn->next=head;
		}
		else{
			p=head;
			while(p->next!=head)
			p=p->next;
			p->next=nn;
			nn->next=head;
		}
	}
}
void display()
{
	p=head;
	if(head==NULL)
	printf("List is empty\n");
	else{
		do{
			printf("%d->",p->data);
			p=p->next;
		 }
		 while(p!=head)  
	   }printf("%d->",p->data);
	p=p->next;
   }
   printf("head\n");
  }
}
void insert_beg()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter node's data:");
	scanf("%d",&nn->data);
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		p=head;
		while(p->next!=head)
		   p=p->next;
		   nn->next=head;
		   p->next=nn;
		   head=nn;
	}
}
void insert_end()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter node's data:");
	scanf("%d",&nn->data);
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		p=head;
		while(p->next!=head)
		   p=p->next;
		   nn->next=head;
		   p->next=nn;
	}
}
void insert_pos()
{
	int pos;
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
		for(i=1;i<pos-1;i++){
			q=q->next;
			r=r->next;
		}
		p->next=r;
		q->next=p;
	}
	display();
}
void delete_beg()
{
	p=head;q=head;
	if(head==NULL)
	   printf("List is empty\n");
	else{
		while(p->next!=head)
		p=p->next;
		p->next=q->next;
		head=q->next;
		free(q);
	}
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
void main()
{
	int ch;
	do{
		printf("**MENU**");
		printf("1.Create\n 2.Display\n 3.Insert Beg\n 4.Insert End\n 5.Insert Pos\n 6.Delete Beg\n 7.Delete End\n 8.Delete Pos\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			Case 1:Create();break;
			Case 2:Display();break;
			Case 3:Insert Beg();break;
			Case 4:Insert End();break;
			Case 5:Insert Pos();break;
			Case 6:Delete Beg();break;
			Case 7:Delete End();break;
			Case 8:Delete Pos();break;
			default:printf("Wrong Choice\n");
		}
		while(ch<8)
	}
}