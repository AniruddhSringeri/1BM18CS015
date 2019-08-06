#include<stdio.h>
#include<conio.h>
void main()
{
int i;
struct marks
{
float ds, coa, ld, cipe, mp, dm, java, project;
}stud1;
clrscr();
printf("Enter the marks of the student in ds, coa, ld, cipe, mp, dm, java, project:  ");
scanf("%f",&stud1.ds);
scanf("%f",&stud1.coa);
scanf("%f",&stud1.ld);
scanf("%f",&stud1.cipe);
scanf("%f",&stud1.mp);
scanf("%f",&stud1.dm);
scanf("%f",&stud1.java);
scanf("%f",&stud1.project);


printf("The marks list is as follows:\nDS: %f\nCOA: %f\nLD: %f\nCIPE: %f\nMP: %f\nDM: %f\nJava: %f\nProject: %f",stud1.ds,stud1.coa,stud1.ld,stud1.cipe,stud1.mp,stud1.dm,stud1.java,stud1.project);
}






