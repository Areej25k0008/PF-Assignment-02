#include<stdio.h>
void push(int st[],int *tp,int max)
{
int x;
if(*tp==max-1)
{
printf("full\n");
return;
}
printf("num: ");
scanf("%d",&x);
*tp=*tp+1;
st[*tp]=x;
printf("added\n");
}
void pop(int st[],int *tp)
{
if(*tp==-1)
{
printf("empty\n");
return;
}
printf("out=%d\n",st[*tp]);
*tp=*tp-1;
}
void peek(int st[],int tp)
{
if(tp==-1)
{
printf("empty\n");
return;
}
printf("top=%d\n",st[tp]);
}
void show(int st[],int tp)
{
if(tp==-1)
{
printf("empty\n");
return;
}
printf("stack:\n");
for(int i=tp;i>=0;i--)
{
printf("%d\n",st[i]);
}
}
int main()
{
int st[50];
int tp=-1;
int max=50;
int ch;
while(1)
{
printf("\n1 push\n2 pop\n3 peek\n4 show\n5 exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
push(st,&tp,max);
break;
case 2:
pop(st,&tp);
break;
case 3:
peek(st,tp);
break;
case 4:
show(st,tp);
break;
case 5:
return 0;
default:
printf("wrong\n");
}
}
}

