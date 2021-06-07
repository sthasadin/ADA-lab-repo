#include<stdio.h>
 #include<time.h>
 #include <stdlib.h>
void create(int []);
void down_adjust(int [],int);
 
void main()
{
    clock_t start,end;
    double t;
int heap[60000],n,i,last,temp;
printf("Enter no. of elements:\n");
scanf("%d",&n);
for(int o;o<4;o++)
{

printf("\nEnter elements:");
for(i=1;i<=n;i++)
heap[i]=rand()%30000;
start = clock();
heap[0]=n;
create(heap);

while(heap[0] > 1)
{

last=heap[0];
temp=heap[1];
heap[1]=heap[last];
heap[last]=temp;
heap[0]--;
down_adjust(heap,1);
}
 end = clock();

t=((double) (end - start)) / CLOCKS_PER_SEC;
printf("time taken:%f",t);
printf("\nArray after sorting:\n");
for(i=1;i<=n;i++)
printf("%d ",heap[i]);
n=n*10;
}
}
 
void create(int heap[])
{
int i,n;
n=heap[0]; 
for(i=n/2;i>=1;i--)
down_adjust(heap,i);
}
 
void down_adjust(int heap[],int i)
{
int j,temp,n,flag=1;
n=heap[0];
while(2*i<=n && flag==1)
{
j=2*i; //j points to left child
if(j+1<=n && heap[j+1] > heap[j])
j=j+1;
if(heap[i] > heap[j])
flag=0;
else
{
temp=heap[i];
heap[i]=heap[j];
heap[j]=temp;
i=j;
}
}
}
