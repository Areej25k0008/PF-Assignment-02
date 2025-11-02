#include<stdio.h>
#include<string.h>
void custInfo(char name[],char cnic[])
{
printf("name: ");
scanf(" %[^\n]",name);
printf("cnic: ");
scanf(" %[^\n]",cnic);
}
void showInv(int code[],int qty[],int price[],int n)
{
printf("code qty price\n");
for(int i=0;i<n;i++)
{
printf("%d %d %d\n",code[i],qty[i],price[i]);
}
}
void updInv(int code[],int qty[],int n,int c,int q)
{
for(int i=0;i<n;i++)
{
if(code[i]==c)
{
qty[i]-=q;
if(qty[i]<0)qty[i]=0;
return;
}
}
printf("no such item\n");
}
void addCart(int code[],int qty[],int price[],int carC[],int carQ[],int *cc,int n)
{
int c,q;
printf("enter code: ");
scanf("%d",&c);
printf("qty: ");
scanf("%d",&q);
for(int i=0;i<n;i++)
{
if(code[i]==c)
{
if(q>qty[i])
{
printf("not enough stock\n");
return;
}
carC[*cc]=c;
carQ[*cc]=q;
(*cc)++;
updInv(code,qty,n,c,q);
printf("added\n");
return;
}
}
printf("item not found\n");
}
int totalBill(int carC[],int carQ[],int code[],int price[],int cc,int n)
{
int t=0;
for(int i=0;i<cc;i++)
{
for(int j=0;j<n;j++)
{
if(carC[i]==code[j])
{
t+=price[j]*carQ[i];
}
}
}
return t;
}
void showInvoice(char name[],char cnic[],int bill,int disBill)
{
printf("customer: %s\n",name);
printf("cnic: %s\n",cnic);
printf("bill no discount: %d\n",bill);
printf("bill with discount: %d\n",disBill);
}
int main()
{
int code[4]={1,2,3,4};
int qty[4]={50,10,20,8};
int price[4]={100,200,300,150};
char name[50];
char cnic[30];
int carC[50],carQ[50],cc=0;
int ch;
int gotCust=0;
while(1)
{
printf("\n1 customer info\n2 show inventory\n3 add to cart\n4 total bill\n5 show invoice\n6 exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
custInfo(name,cnic);
gotCust=1;
break;
case 2:
showInv(code,qty,price,4);
break;
case 3:
if(!gotCust)
{
printf("enter customer info first\n");
break;
}
addCart(code,qty,price,carC,carQ,&cc,4);
break;
case 4:
if(cc==0)
{
printf("cart empty\n");
break;
}
{
int bill=totalBill(carC,carQ,code,price,cc,4);
char p[20];
printf("promocode? ");
scanf("%s",p);
int disBill=bill;
if(strcmp(p,"Eid2025")==0)disBill=bill-(bill*25/100);
printf("bill=%d disBill=%d\n",bill,disBill);
}
break;
case 5:
{
int bill=totalBill(carC,carQ,code,price,cc,4);
int disBill=bill;
char p[20];
printf("enter promocode to verify invoice: ");
scanf("%s",p);
if(strcmp(p,"Eid2025")==0)disBill=bill-(bill*25/100);
showInvoice(name,cnic,bill,disBill);
}
break;
case 6:
return 0;
default:
printf("wrong\n");
}
}
}

