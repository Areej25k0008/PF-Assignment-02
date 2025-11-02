#include<stdio.h>
#include<string.h>
void addBook(int isbns[],char titles[][50],float prices[],int qtys[],int *bookCnt)
{
int x, q;
char t[50];
float p;
printf("enter isbn: ");
scanf("%d",&x);
for(int i=0;i<*bookCnt;i++)
{
if(isbns[i]==x)
{
printf("book already there\n");
return;
}
}
printf("enter title: ");
scanf(" %[^\n]",t);
printf("enter price: ");
scanf("%f",&p);
printf("enter qty: ");
scanf("%d",&q);
isbns[*bookCnt]=x;
strcpy(titles[*bookCnt],t);
prices[*bookCnt]=p;
qtys[*bookCnt]=q;
(*bookCnt)++;
printf("book added\n");
}

void sellBook(int isbns[],char titles[][50],float prices[],int qtys[],int *bookCnt)
{
int x;
int sold;
printf("enter isbn to sell: ");
scanf("%d",&x);
for(int i=0;i<*bookCnt;i++)
{
if(isbns[i]==x)
{
printf("how many copies: ");
scanf("%d",&sold);
if(qtys[i]<sold)
{
printf("not enough stock\n");
return;
}
qtys[i]-=sold;
printf("sold ok\n");
return;
}
}
printf("book not found\n");
}

void lowStock(int isbns[],char titles[][50],float prices[],int qtys[],int *bookCnt)
{
printf("low stock books:\n");
int found=0;
for(int i=0;i<*bookCnt;i++)
{
if(qtys[i]<5)
{
printf("%d %s %.2f %d\n",isbns[i],titles[i],prices[i],qtys[i]);
found=1;
}
}
if(!found)
{
printf("none\n");
}
}

int main()
{
int isbns[100];
char titles[100][50];
float prices[100];
int qtys[100];
int bookCnt=0;
int ch;
while(1)
{
printf("\n1 add book\n2 sell book\n3 low stock\n4 exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
addBook(isbns,titles,prices,qtys,&bookCnt);
break;
case 2:
sellBook(isbns,titles,prices,qtys,&bookCnt);
break;
case 3:
lowStock(isbns,titles,prices,qtys,&bookCnt);
break;
case 4:
return 0;
default:
printf("wrong choice\n");
}
}
}

