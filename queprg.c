#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int stk[SIZE];
int sp=-1;
void main()
{
void push(int);
int pop();
void print();
int opt,item;
do
{
printf("\n1.Push\n2.Pop\n3.display\n4.Exit\n");
printf("Enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("enter item:");
scanf("%d",&item);
push(item);
break;
case 2:
item=pop(); 
if(item!=-9)
printf("popped value=%d\n",item);
break;
case 3:
print();
break;
case 4:
exit(0);
}
}
while(1);
}

//function push
void push(int x)
{
if(sp==SIZE-1)
{
printf("stack is full....");
return;
}
else
stk[++sp]=x;
return;
}
//function pop
int pop()
{
if(sp==-1)
{
printf("stack is empty...\n");
return -9;
}
else
return stk[sp--];
}
//function to display the elements
void print()
{
int i;
for(i=0;i<=sp;i++)
if(sp!=-1)
printf("%d\t",stk[i]);
else
printf("stack is empty...\n");
return;
}

