//*library books management system*//
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
//code to declare function prototype//
void insertbookdata(void);
void insertuserdata(void);
void displaybookdata();
void displayuserdata();
void updatebookdata(int);
void deletebookdata(int);
void updateuserdata(int);
void deleteuserdata(int);
void searchdata(void);
int checkbookno(int);
int checkuserid(int);
int findlastbookno(void);
int findlastuserid(void);	 
//code to declare the file pointer//
FILE *fp,*fp1;
//code to design structure//
struct library
{
int bn;
char title[200];
char name[30];
char section[30];
int id;
int day1,month1,year1;
int day2,month2,year2;
char sub[100];
float price;
int nob;
int contno;
char adress[30];
char author[100];
char publisher[100];
};
//code to declare structure variable//
struct library b;
//code to declare main function//
main()
{ 
	js:
char username[30];
char password[30];
int choice;
int bn,id,j=0;
printf("\n\t\t\tenter username:");
scanf("%s",username);
printf("\n\t\t\tenter password:");
scanf("%s",password);
system("cls");
if(strcmp(username,"james")==0)
     if(strcmp(password,"messi")==0)
{
	j=1;
}
if(j==1)
	while(1)
	{
printf("\n\n\t--------------------------------------------------");
printf("\n\n\t|************************************************|");
printf("\n\n\t|-----welcome in libraray management system------|");
printf("\n\n\t|************************************************|");
printf("\n\n\t|------------------MENU--------------------------|");
printf("\n\n\t|*************************************************");
printf("\n\t\t1.insert book record");    
printf("\t\t\t2.insert user record");
printf("\n\t\t3.display book record");
printf("\t\t\t4.display user record");
printf("\n\t\t5.update book record");
printf("\t\t\t6.update user record");
printf("\n\t\t7.delete book record");
printf("\t\t\t8.delete user record");
printf("\n\t\t9.search record");
printf("\t\t\t\t10.quit");
  

printf("\n\tenter your choice between 1 to 10:-");
scanf("%d",&choice);
switch(choice)
{
	case 1:
	insertbookdata();
	break;
	case 2:
	insertuserdata();
	break;
	case 3:
	displaybookdata();
	break;
	case 4:
	displayuserdata();
	break;
	case 5:
	printf("enter the book number you want to update");
	scanf("%d",&bn);
	updatebookdata(bn);
	break;
	case 6:
	printf("enter the user id you want to update");
	scanf("%d",&id);
	updateuserdata(id);
	break;	
	case 7:
	printf("enter the book number you want to delete");
	scanf("%d",&bn);
	deletebookdata(bn);
	break;
	case 8:
	printf("enter the user id you want to delete");
	scanf("%d",&id);
	deleteuserdata(id);
	break;	
	case 9:
	searchdata();
	break;
	case 10:
	exit(0);
	default:
	printf("\n\t\tsorry!!!!!you entered an invalid choice;");
	printf("\nplease, enter the valid choice between 1 to 10:-");
}
}
else{
	printf("\n\tyou entered wrong informataion\n");
	printf("\n\tpleasw enter right information\n");
	getch();
	goto js;
}
}
//code to declare function defination
void insertbookdata()
{
char next='y';
int duplicatebookno=0,lastbookno;
while(next=='y'||next=='Y')
{
    aa:
printf("\n enter the book no:-");
scanf("%d",&b.bn);
//code to call functin to check the book has been repeated or not
duplicatebookno=checkbookno(b.bn);
if(duplicatebookno==1)
{
	printf("\n\nthe book no which you just typed  is already exist in the data file!!!!!");
	printf("n\nenter the unique book no!!!" );
	lastbookno=findlastbookno();
	printf("\n\nthe last book no is %d:",lastbookno);
	goto aa;
}
	fflush(stdin);
	printf("\enter the title of the book:-");
	gets(b.title);
	printf("enter the subject of the book :-");
	gets(b.sub);
	printf("enter the price of the book:-");
	scanf("%f",&b.price);
	printf("enter the no of the boook:-");
	scanf("%d",&b.nob);
	fflush(stdin);
	printf("\n enter the author of the book:-");
	gets(b.author);
	printf("\nenter the publisher of the book:-");
	gets(b.publisher);
	fp=fopen("Book.dat","a");
	if(fp==NULL)
	{
	printf("file creation errror has occure!!");
	}
	else
	{
	fwrite(&b,sizeof(b),1,fp);
	fclose(fp);
	printf("DO YOU WANT TO KEEP THE THE RECORD OF ANOTHER BOOK(Y/N)?");
	next=getche();
    }
}
}
void insertuserdata()
{
	char next1='y';
int duplicateuserid=0,lastuserid;
while(next1=='y'||next1=='Y')
{
    bb:
printf("\n enter user id:-");
scanf("%d",&b.id);
//code to call functin to check the book has been repeated or not
duplicateuserid=checkuserid(b.id);
if(duplicateuserid==1)
{
	printf("\n\n the user id which you just typed  is already exist in the data file!!!!!");
	printf("n\nenter the unique user id!!!" );
	lastuserid=findlastuserid();
	printf("\n\nthe last book no is %d:",lastuserid);
	goto bb;
}
	fflush(stdin);
	printf("\enter the name of user of book:-");
	gets(b.name);
	printf("enter the section of user:-");
	gets(b.section);
	printf("enter the adress -");
	scanf("%s",b.adress);
	printf("enter the contact no:- ");
	scanf("%ld",&b.contno);
	printf("enter the issued date-");
	scanf("%d-%d-%d",&b.day1,&b.month1,&b.year1);
	printf("enter the return:-");
	scanf("%d-%d-%d",&b.day2,&b.month2,&b.year2);
	fp=fopen("Book.dat","a");
	if(fp==NULL)
	{
	printf("file creation errror has occure!!");
	}
	else
	{
	fwrite(&b,sizeof(b),1,fp);
	printf("DO YOU WANT TO KEEP THE THE RECORD OF ANOTHER USER(Y/N)?");
	next1=getche();
}
	fclose(fp);
}
}
void displaybookdata(void)
{
fp=fopen("book.dat","r");
rewind(fp);
if(fp==NULL)
{
printf("\n\n read operation failure as the file which you are searching doesnt exist!!!!");
}
else
{
while(fread(&b,sizeof(b),1,fp)==1)
{
printf("\n\tEXISTING BOOK RECORDS ARE");
printf("\n===============================");
printf("\n\tbook no.    :%d",b.bn);
printf("\n\ttitle       :%s",b.title);
printf("\n\tsubject     :%s",b.sub);
printf("\n\tprice       :rs.%2f",b.price);
printf("\n\tNo of books :%d",b.nob);
printf("\n\tAuthor      :%s",b.author);
printf("\n\tPublisher   :%s",b.publisher);
printf("\n===============================");
}
fclose(fp);
}
getch();
}
void displayuserdata(void)
{
fp=fopen("book.dat","r");
rewind(fp);
if(fp==NULL)
{
printf("\n\n read operation failure as the file which you are searching doesnt exist!!!!");
}
else
{
while(fread(&b,sizeof(b),1,fp)==1)
{
printf("\n===============================");
printf("\n\tuser id    :%d",b.id);
printf("\n\tuser name       :%s",b.name);
printf("\n\tadress    :%s",b.adress);
printf("\n\tcontact no       :%ld",b.contno);
printf("\n\tseection     :%s",b.section);
printf("\n\tissue date      :%d-%d-%d",b.day1,b.month1,b.year1);
printf("\n\treturn date      :%d-%d-%d",b.day2,b.month2,b.year2);
printf("\n===============================");
}
fclose(fp);
}
getch();
}
void updatebookdata(int bn)
{
fp=fopen("book.dat","r");
fp1=fopen("newbook.dat","w");
if(fp==NULL||fp1==NULL)
{
	printf("file operation error");
}
//code to show the existing data
else
{
	printf("\n\n the following are the existing data!!!!!");
while(fread(&b,sizeof(b),1,fp)==1)
{
if(b.bn==bn)
{
printf("\n\tbook no.        :%d",b.bn);
printf("\n\t title          :%s",b.title);
printf("\n\tsubject         :%s",b.sub);
printf("/n/tprice           :rs.%2f.",b.price);
printf("\n\tnumber of books :%d",b.nob);
printf("\n\tauthor          :%s",b.author);
printf("\n\tpublisher       :%s",b.publisher);
}
}//code to enter a new data
rewind(fp);
printf("\n\n Enter the new correct data" );
while(fread(&b,sizeof(b),1,fp)==1)
{
if(bn==b.bn)
{
printf("\n\n Enter the book no");
scanf("%d",&b.bn);
fflush(stdin);
printf("\enter the title of the book");
gets(b.title);
printf("\enter the subject of the book");
gets(b.sub);
printf("enter the price of the book");
scanf("%f",&b.price);
printf("\enter the no. of book");
scanf("%d",&b.nob);
fflush(stdin);
printf("\enter the publisher author of the book");
gets(b.author);
printf("enter the publisher of the book ");
gets(b.publisher);
fwrite(&b,sizeof(b),1,fp1);
}
else
{
fwrite(&b,sizeof(b),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("book.dat");
rename("newbook.dat","book.dat");
printf("\n\nthe record has been successfully updated in the data file");
}
getch();
}
void updateuserdata(int id)
{
fp=fopen("book.dat","r");
fp1=fopen("newbook.dat","w");
if(fp==NULL||fp1==NULL)
{
printf("file operationn error!!!!!");
}
else
{
	printf("\n\tfollowing are the existing data");
while(fread(&b,sizeof(b),1,fp)==1)
{
if(b.id==id)
{
printf("\n\tuser id           :%d",b.id);
printf("\n\tuser name         :%s",b.name);
printf("\n\tseection          :%s",b.section);
printf("\n\tadress           :%s",b.adress);
printf("\n\tcontact no       :%ld",b.contno);
printf("\n\tissue date        :%d-%d-%",b.day1,b.month1,b.year1);
printf("\n\treturn date       :%d-%d-%d",b.day2,b.month2,b.year2);
}
}
//code to enter a new data
rewind(fp);
printf("\n\n Enter the new correct data" );
while(fread(&b,sizeof(b),1,fp)==1)
{
if(id==b.id)
{
	printf("enter the user id");
	scanf("%d",&id);
	fflush(stdin);
	printf("\n\tenter the name of user of book:-");
	gets(b.name);
	printf("\n\tenter the section of user:-");
	gets(b.section);
	fflush(stdin);
	printf("\n\tenter the issue date-");
	scanf("%d-%d-%d",&b.day1,&b.month1,&b.year1);
	printf("\n\tenter the return date:-");
	scanf("%d-%d-%d",&b.day2,&b.month2,&b.year2);
}
else
{
fwrite(&b,sizeof(b),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("book.dat");
rename("newbook.dat","book.dat");
printf("\n\nthe record has been successfully updated in the data file");
}
getch();
}
void deletebookdata(int bn)
{
fp=fopen("book.dat","r");
fp1=fopen("newbook.dat","w");
if(fp==NULL||fp1==NULL)
{
printf("\file operation failed");
}
else
{
while(fread(&b,sizeof(b),1,fp)==1)
if(bn==b.bn)
{
continue;
}
else
{
fwrite(&b,sizeof(b),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("book.dat");
rename("newBook.dat","Book.dat");
printf("\n\n the record has been successfully deleted from the data file");
getch();
}
void deleteuserdata(int id)
{
fp=fopen("book.dat","r");
fp1=fopen("newbook.dat","w");
if(fp==NULL||fp1==NULL)
{
printf("\file operation failed");
}
else
{
while(fread(&b,sizeof(b),1,fp)==1)
if(id==b.id)
{
continue;
}
else
{
fwrite(&b,sizeof(b),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("book.dat");
rename("newBook.dat","Book.dat");
printf("\n\n the record has been successfully deleted from the data file");
getch();
}
void searchdata(void)
{
int found=0;
char bname[100],uid;
int ch;
printf("\n\t\t***************************************");
printf("\n\t\t*******SEARCH MENU*********************");
printf("\n\t\t***************************************");
printf("\n\t\t1.search book data");
printf("\n\t\t2.search user data");
printf("\n\t\t3.quit search operation");
printf("\n\tenter your choice for search:-");
scanf("%d",&ch);
switch(ch)
{
case 1:
//search on the basis of book title
//clrscr();
fflush(stdin);
printf("\n\n Enter the title of the book which you want to search:-");
gets(bname);
fp=fopen("Book.dat","r");
if(fp==NULL)
{
printf("\n file search operation failed!!!!!!!!");
}
else
{
while(fread(&b,sizeof(b),1,fp)==1)
{
if(strcmpi(b.title,bname)==0)
{
printf("\n\tBook no.        :%d",b.bn);
printf("\n\tTitle           :%s",b.title);
printf("\n\tsubject         :rs.%2f",b.price);
printf("\n\tNo of books     :%d",b.nob);
printf("\n\tAuthor          :%s",b.author);
printf("\n\tpublisher       :%s",b.publisher);
found=1;
}
}
if(found==0)
{
printf("n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
printf("\n the book  which you want to searching is not found");
}
fclose(fp);
}
break;
case 2:
//search user data
fflush(stdin);
printf("\n\n enter the id of user you want to search:-");
scanf("%d",&uid);
fp=fopen("book.dat","r");
if(fp==NULL)
{
printf("\nfile search operatio failed!!!!!!!!!!!");
}
else
{
while(fread(&b,sizeof(b),1,fp)==1)
{
if(b.id==uid)
{
printf("\n\tuser id           :%d",b.id);
printf("\n\tuser name         :%s",b.name);
printf("\n\tseection          :%s",b.section);
printf("\n\tadress           :%s",b.adress);
printf("\n\tcontact no       :%ld",b.contno);
printf("\n\tissue date        :%d-%d-%d",b.day1,b.month1,b.year1);
printf("\n\treturn date       :%d-%d-%d",b.day2,b.month2,b.year2);
found=1;
}
}
if(found==0)
{
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
printf("\n the user data you are searching is not found");
}
fclose(fp);
}
break;
case 3:
//code to close search window
printf("\npress any key to quit the search operation");
break;
default:
printf("\n you entered invalid choice for search");
}
getch();
}
int checkbookno(int bn)
{
int repeated=0,lastbookno;
struct library b1;
fp=fopen("book.dat","r");
if(fp==NULL)
{
printf("\n\n read operation failure as the file which you are searching does not esist!!");
}
else
{
while(fread(&b1,sizeof(b1),1,fp)==1)
{
if(b1.bn==bn)
{
repeated=1;
break;
}
}
fclose(fp);
}
return(repeated);
}
int checkuserid(int id)
{
int repeated2=0,lastuserno;
struct library b2;
fp=fopen("book.dat","r");
if(fp==NULL)
{
printf("\n\n read operation failure as the file which you are searching does not esist!!");
}
else
{
while(fread(&b2,sizeof(b2),1,fp)==1)
{
if(b2.id==id)
{
repeated2=1;
break;
}
}
fclose(fp);
}
return(repeated2);
}
int findlastbookno()
{
int lastbookno;
struct library b3;
fp=fopen("book.dat","r");
if(fp==NULL)
{
printf("\n\n FILE OPEN OPERATION FAILURE!!!!");
}
else
{
while(fread(&b3,sizeof(b3),1,fp)==1)
{
lastbookno=b3.bn;
}
fclose(fp);
}
return(lastbookno);
}
int findlastuserid()
{
int lastuserid2;
struct library b4;
fp=fopen("book.dat","r");
if(fp==NULL)
{
printf("\n\n FILE OPEN OPERATION FAILURE!!!!");
}
else
{
while(fread(&b4,sizeof(b4),1,fp)==1)
{
lastuserid2=b4.id;
}
fclose(fp);
}
return(lastuserid2);
}









