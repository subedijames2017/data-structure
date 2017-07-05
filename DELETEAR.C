#include<stdio.h>
#include<conio.h>
void deleteitem(int a[100],int *n)
{
int pos,i;
printf("enter position at which you want to delete element");
scanf("%d",&pos);
for(i=pos;i<*n;i++)
{
a[i]=a[i+1];
}
*n=*n-1;
printf("new array is :\n");
for(i=0;i<*n;i++)
{
printf("%d\t",a[i]);
}
void main()
{
int n,a[50];
deleteitem(a[],*n);
printf("enter array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
getch();
}