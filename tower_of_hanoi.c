#include<stdio.h>
void tower_hanoi(int n, char src, char temp, char dest);
int main()
{
	char src,temp,dest;
	int n;
	printf("Enter the names of the three towers:  ");
	scanf("%c",&src);
	scanf("%c",&temp);
	scanf("%c",&dest);
	printf("Enter the number of discs initially to be placed on %c:  ",src);
	scanf("%d",&n);
	tower_hanoi(n,src,temp,dest);
	return 0;
}

void tower_hanoi(int n, char src, char temp, char dest)
{
	if (n==1)
	{
		printf("Move disc %d from %c to %c\n",n,src,dest);
		return;
	}
	tower_hanoi(n-1,src,dest,temp);
	printf("Move disc %d from %c to %c",n,src,dest);
	tower_hanoi(n-1,temp,src,dest);
}