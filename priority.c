#include<stdio.h>
#include<conio.h>
#include<string.h>
struct process
{
	int i,n,m1,n1,m2,n2,m3,n3,m4,n4,setp;
	int a[1000],b[1000];
}p;
int getdata()
{
	printf("\t*********************************WELCOME TO PRIORITY SCHEDULING ALGORITHM********************************\n\n\n");
	/*printf("Enter the process P1 Arrival time : ");
	scanf("%d",&p.m1);
	printf("Enter the process P1 Burst time : ");
	scanf("%d",&p.n1);
	printf("Enter the process P2 Arrival time : ");
	scanf("%d",&p.m2);
	printf("Enter the process P2 Burst time : ");
	scanf("%d",&p.n2);	
	printf("Enter the process P3 Arrival time : ");
	scanf("%d",&p.m3);
	printf("Enter the process P3 Burst time : ");
	scanf("%d",&p.n3);	
	printf("Enter the process P4 Arrival time : ");
	scanf("%d",&p.m4);
	printf("Enter the process P4 Burst time : ");
	scanf("%d",&p.n4);	*/
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
	int display();
	{
	printf("Process Number\t\t\tBurst Time\t\t\tArrival Time\n");
	for(p.i=1;p.i<=p.n;p.i++){
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i]);
	}
	}
}
int main()
{
	getdata();
}
