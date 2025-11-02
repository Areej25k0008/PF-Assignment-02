#include<stdio.h>
void setFlag(int grid[][5],int r,int c,int flag)
{
grid[r][c]|=(1<<flag);
printf("done\n");
}
void clearFlag(int grid[][5],int r,int c,int flag)
{
grid[r][c]&=~(1<<flag);
printf("done\n");
}
void query(int grid[][5],int r,int c)
{
int v=grid[r][c];
printf("power: ");
if(v&1)printf("on\n");else printf("off\n");
printf("overload: ");
if(v&2)printf("yes\n");else printf("no\n");
printf("maint: ");
if(v&4)printf("yes\n");else printf("no\n");
}

void diag(int grid[][5],int rows,int cols)
{
int o=0,m=0;
for(int i=0;i<rows;i++)
{
for(int j=0;j<cols;j++)
{
if(grid[i][j]&2)o++;
if(grid[i][j]&4)m++;
}
}
printf("overloaded=%d\n",o);
printf("maintenance=%d\n",m);
}

int main()
{
int grid[5][5];
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
grid[i][j]=0;
}
}
int ch;
int r,c,f;
while(1)
{
printf("\n1 set flag\n2 clear flag\n3 query\n4 diag\n5 exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("row col flag(0 power 1 overload 2 maint): ");
scanf("%d%d%d",&r,&c,&f);
setFlag(grid,r,c,f);
break;
case 2:
printf("row col flag: ");
scanf("%d%d%d",&r,&c,&f);
clearFlag(grid,r,c,f);
break;
case 3:
printf("row col: ");
scanf("%d%d",&r,&c);
query(grid,r,c);
break;
case 4:
diag(grid,5,5);
break;
case 5:
return 0;
default:
printf("wrong choice\n");
}
}
}

