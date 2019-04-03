#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct process
{
	int i,j,n,count;
	int a[1000],b[1000],pr[1000],com[1000],tat[1000],wat[1000];
	char yes;
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
A:	printf("Enter the process number you want to execute : ");
	scanf("%d",&p.i);
	p.pr[p.i]==0;
	if(p.pr[p.i]==0){
	p.pr[p.i]=1;
	printf("%d is in Ready queue \n",p.i);
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	p.count++;
	fflush(stdin);
	printf("Do you want to execute more process? Y/N");
	scanf("%c",&p.yes);
	if(p.yes=='Y'||p.yes=='y'){
		p.pr[p.i]=2;
		goto A;
	}
	else{
	printf("\n\n\nProcesses in the Waiting queue are \n\n");
	for(p.i=1;p.i<=p.n;p.i++){
	p.count=1;
	if(p.pr[p.i]!=p.count){
	p.pr[p.i]=2;
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);	
		}
	}
}
}
}
void completion(){
	p.com[p.i]=0;
	for(p.i=1;p.i<=p.n;p.i++){
	p.com[p.i]=p.a[p.i]+p.b[p.i];
	printf("\nProcess Number\t\tBurst Time\t\tArrival Time\t\tPriority\t\tCompletion Time\n");
	printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i],p.com[p.i]);	
	}
}
void turnaround()
{
	for(p.i=1;p.i<=p.n;p.i++){
	p.tat[p.i]=p.com[p.i]-p.a[p.i];
	printf("\nProcess Number\t\tBurst Time\t\tArrival Time\t\tPriority\t\tTurnaround Time\n");
	printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i],p.tat[p.i]);
	}
}
void waiting(){
	for(p.i=1;p.i<=p.n;p.i++){
		p.wat[p.i]=p.tat[p.i]-p.b[p.i];
		printf("\nProcess Number\t\tBurst Time\t\tArrival Time\t\tPriority\t\tWaiting Time\n");
	    printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i],p.wat[p.i]);
	}
}
int main()
{
	float k=0,m=0;
	getdata();
	display();
	priority();
	completion();
	turnaround();
	waiting();
	for(p.i=1;p.i<=p.n;p.i++){
	k=k+p.tat[p.i];
	m=m+p.wat[p.i];
	}
	k=k/p.n;
	m=m/p.n;
	printf("Average turnaround time : %f",k);
	printf("\nAverage waiting time : %f",p);
}
