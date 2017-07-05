 #include<stdio.h>
 #include<conio.h>
 #include<math.h>
 #include<string.h>
 #include<ctype.h>
 void push(int);
 int pop();
 int vstack[100];
 int tos=-1;
 void push(int val)
 {
 vstack[++tos]=val;
 }
 int pop()
 {
 int n;
 n=vstack[tos--];
 return n;
 }
 void main()
 { int i,res,l,op1,op2,value[100];
char postfix[100],ch; clrscr();
 printf("Enter a valid postfix\n");
gets(postfix);
 l=strlen(postfix);
for(i=0;i<=l-1;i++)
 {
 if(isalpha(postfix[i]))
{
 printf("Enter value of %c ",postfix[i]);
   scanf("%d",&value[i]);
   push(value[i]);
 } else {   ch=postfix[i];
  op2=pop();
  op1=pop();
  switch(ch)
   {     case '+':
    push(op1+op2);
    break;
  case'-':
     push(op1-op2);
   break;
    case'*':
     push(op1*op2);
   break;
       case'/':
    push(op1/op2);
   break;
    case'$':
     push(pow(op1,op2));
  break;
     case'%':
  push(op1%op2);
 break;
 }    } }
 printf("The result is:"); res=pop(); printf("%d", res);
 getch();
 }


