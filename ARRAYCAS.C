#include<stdio.h>
#include<conio.h>
vaoid insertion(int [100],int *);
void deleteitem(int [100],int *);
void traversearray(int [100],int *);
voaid search(int [100],int *);
int main()
{
int a[100],mel,pos,i;
int n;
int choice;
printf("enter the no of element to be inserted");
scanf("%d",&n);
for(i=0;i<n;i++);
{
scanf("%d",&a[i]);
}
while(1)
{
printf("\n-----menu---------");
printf("\n1:insert\n2:delete\n3:traverse\n4:searching\n5:exit\n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
insertitem(a,&n);
break;
case 2:
deleteitem(a,&n);
break 3:
traversearray(a,&n);
break;
case 4:
search(a,&n);
break;
case 5:
exit(1);
break;
deafult:
printf("enter valid choice");
}
}
voidinsertitem(a,&n);
int array,position,value;
clrscr();
printf("enter the location where you wish to enter an element");
scanf("%d",&position);