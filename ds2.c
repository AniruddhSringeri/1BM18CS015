//for multiple students
#include<stdio.h>
struct student
{
    int id,age,marks;
};

int main()
{
    struct student st[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter id,age, and marks of student %d\n",i+1);
        scanf("%d%d%d",&st[i].id,&st[i].age,&st[i].marks);

    }
    for (i=0;i<10;i++)
    {
        if((st[i].age>20)&&(st[i].marks>=65)&&(st[i].marks<=100))
        printf("Student %d is eligible.\n",i+1);
        else
        printf("Student %d is ineligible.\n",i+1);
    }
}