#include<stdio.h>
struct book
{
	char title[25];
	char author[25];
	char subject[25];
	int book_id;
}b;
int main()
{
	struct book *p;
	p=&b;
	scanf("%s\n %s\n %s\n %d",p->title,p->author,p->subject,&p->book_id);
	printf("%s %s %s %d",p->title,p->author,p->subject,p->book_id);
}
