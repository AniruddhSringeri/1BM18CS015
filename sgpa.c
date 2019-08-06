#include<stdio.h>
#include<conio.h>
int grade(float n);
void main()
{
float SGPA;
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

SGPA=(grade(stud1.ds)*4+grade(stud1.coa)*3+grade(stud1.ld)*3+grade(stud1.cipe)*1+grade(stud1.mp)*4+grade(stud1.dm)*4+grade(stud1.java)*4+grade(stud1.project)*2)/25;
printf("SGPA: %f",SGPA);
getch();

}
int grade(float n)
{
int gp;
if (n>=90)
gp=10;
else if ((n>=75)&&(n<90))
gp=9;
else if ((n<75)&&(n>=60))
gp=8;
else if ((n<60)&&(n>=50))
gp=7;
else if((n<50)&&(n>=40))
gp=6;
else
printf("You have failed");
return gp;
}
