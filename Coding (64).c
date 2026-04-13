#include"stdio.h"
int main(int argc,char *argv[])
{
	int i;
	printf("no of argu is passed %d",argc-1);
	printf("\n argu passed are:");
	for(i=0;i<argc;i++)
	{
		printf(" argu is %s\n",argv[i]);
	}
	return 0;
}