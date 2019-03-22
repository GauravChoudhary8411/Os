#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct process
{
	int i,j,n,count;
	int a[1000],b[1000],pr[1000];
}p;
void getdata()
{
	printf("**********************************WELCOME TO PREEMTIVE PRIORITY SCHEDULING ALGORITHM***********************************\n\n\n");
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
	
	for(p.i=1;p.i<=p.n;p.i++){
	printf("Enter the Priority for process %d : ",p.i);
	scanf("%d",&p.pr[p.i]);
	}
}
void display()
	{
	printf("Process Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	for(p.i=1;p.i<=p.n;p.i++){
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	}
}
void priority(){
	p.count=0;
	printf("Enter the process number you want to execute : ");
	scanf("%d",&p.i);
	p.pr[p.i]==0;
	if(p.pr[p.i]==0){
	p.pr[p.i]=1;
	printf("%d is executing \n",p.i);
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	p.count++;
	}
	printf("\n\n\nProcesses in the ready queue are \n\n");
	for(p.i=1;p.i<=p.n;p.i++){
	if(p.pr[p.i]!=p.count++){
	p.pr[p.i]=2;
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);	
		}
	}
	//Editing from my second account
}
int main()
{
	getdata();
	display();
	priority();
}
