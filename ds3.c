//using functions
#include<stdio.h>
struct student
{
    int id,age,marks;
};
int Validate(struct student s);
int Qualify(struct student s);
int main()
{
    struct student st[100];
    int n,i;
    printf("Enter number of students:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter id,age,marks of student %d",i+1);
        scanf("%d%d%d",&st[i].id,&st[i].age,&st[i].marks);
        Validate(st[i]);
        if(Qualify(st[i])) printf("Student %d is eligible for admission.\n",i+1);
        else  printf("Student %d is ineligible for admission.\n",i+1);
    }
    return 0;
}

int Validate(struct student s)
{
    if ((s.age>20)&&(s.marks<=0)&&(s.marks<=100)) return 1;
    else return 0;
}

int Qualify(struct student s)
{
    if(Validate(s))
    {
        if(s.marks>=65) return 1;
        else return 0;
    }
    else 
    {
        printf("Invalid data.\n");
        return 0;
    }
}