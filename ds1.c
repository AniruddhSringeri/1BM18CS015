//this program is intended to work for a single student

#include<stdio.h>
void main()
{
    struct student
    {
        int id,age,marks;
    }s1;

    printf("Enter the student's id no., age, and marks:   \n");
    scanf("%d%d%d",&s1.id,&s1.age,&s1.marks);
    if((s1.age>20)&&(s1.marks>=65)&&(s1.marks<=100))
    printf("The student is eligible.\n");
    else
    printf("The student is ineligible.\n");

}