#include<stdio.h>
#include<conio.h>
#include<string.h>
struct process
{
	int i,n,m1,n1,m2,n2,m3,n3,m4,n4;
	int a[1000],b[1000];
	int setp;
}p;
void getdata()
{
	printf("\t*********************************WELCOME TO PRIORITY SCHEDULING ALGORITHM********************************\n\n\n");
	printf("Enter the number of processes you want : ");
	scanf("%d",&p.n);
	for(p.i=1;p.i<=p.n;p.i++){
	printf("Enter the Burst Time for process %d : ",p.i);
	scanf("%d",&p.b[p.i]);
	}
	for(p.i=1;p.i<=p.n;p.i++){
	printf("Enter the Arrival Time for process %d : ",p.i);
	scanf("%d",&p.a[p.i]);
	}
}
void display()
	{
	printf("Process Number\t\t\tBurst Time\t\t\tArrival Time\n");
	for(p.i=1;p.i<=p.n;p.i++){
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i]);
	}
}
int main()
{
	getdata();
	display();
}
