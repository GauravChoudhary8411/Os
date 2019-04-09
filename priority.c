#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct process
{
	int i,j,n,count,tq,slice;
	int a[1000],b[1000],pr[1000],com[1000],tat[1000],wat[1000],rem_bt[1000];
	char yes;
}p;
void getdata()
{
	printf("**********************************WELCOME TO PREEMTIVE PRIORITY SCHEDULING ALGORITHM***********************************\n\n\n");
B:	printf("Enter the number of processes you want : ");
	scanf("%d",&p.n);
	if(p.n<=0){
		printf("Invalid Input try again\n");
		goto B;
	}
	
	for(p.i=1;p.i<=p.n;p.i++){
C:	printf("Enter the Burst Time for process %d : ",p.i);
	scanf("%d",&p.b[p.i]);
	if(p.b[p.i]<=0){
		printf("Invalid Input try again\n");
		goto C;
	}
}
	
	for(p.i=1;p.i<=p.n;p.i++){
D:	printf("Enter the Arrival Time for process %d : ",p.i);
	scanf("%d",&p.a[p.i]);
	if(p.a[p.i]<0){
		printf("Invalid Input try again\n");
		goto D;
	}
}
	
	for(p.i=1;p.i<=p.n;p.i++){
E:	printf("Enter the Priority for process %d : ",p.i);
	scanf("%d",&p.pr[p.i]);
	if(p.pr[p.i]<=0){
		printf("Invalid Input try again\n");
		goto E ;
		}
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
	if(p.i<=0||p.i>p.n){
		printf("Invalid Input Try Again\n");
		//goto used to redirect the user to feed the process number
		goto A;
	}
	p.pr[p.i]==0;
	if(p.pr[p.i]==0){
	p.pr[p.i]+=1;
	printf("%d is in Ready queue \n",p.i);
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	p.count++;
	fflush(stdin);
	printf("Do you want to execute more process? Y/N : ");
	scanf("%c",&p.yes);
	//if the user says yes the priority for that process will be changed to 1 and the old process will be preempted and moved to the waiting queue
	if(p.yes=='Y'||p.yes=='y'){
		printf("%d is preempted from the ready queue\n",p.i);
		p.pr[p.i]=2;
		goto A;
	}
	//and the priority of the newer process will be lesser than that of the priority of that process which was once preempted from the ready queue
	//the process which has not executed yet in the ready queue will have same priority   
	else{
	printf("\n\n\nProcesses in the Waiting queue are \n\n");
	for(p.i=1;p.i<=p.n;p.i++){
	p.count=1;
	if(p.pr[p.i]!=p.count){
	p.pr[p.i]+=2;
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);	
				}
			}
		}
	}
}
void timeslice()
{
	p.slice=1;
	int t=0;	
	for(p.i=1;p.i<=p.n;p.i++)
	{
		p.rem_bt[p.i]=p.b[p.i];
	}
	while(1)
	{
		bool done=true;
		for(p.i=1;p.i<=p.n;p.i++)
		if(p.rem_bt[p.i]>0){
			done = false;
			if(p.rem_bt[p.i]>p.slice){
				t+=p.slice;
				p.rem_bt[p.i]-=p.slice;
			}
			else{
				t=t+p.rem_bt[p.i];
				p.wat[p.i]=t-p.b[p.i];
				p.rem_bt[p.i]=0;
			}
		}
	if(done==true)
	break;
	}
}
void turnaround()
{
	printf("\n\n\n********************************************TURNAROUND TIME OF THE PROCESSES********************************************\n");
	for(p.i=1;p.i<=p.n;p.i++){
	p.tat[p.i]=p.wat[p.i]+p.b[p.i];
	printf("\nProcess Number\t\tBurst Time\t\tArrival Time\t\tPriority\t\tTurnaround Time\n");
	printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i],p.tat[p.i]);
	}
}
void waiting(){
	printf("\n\n\n*********************************************WAITING TIME OF THE PROCESSES********************************************\n");
	for(p.i=1;p.i<=p.n;p.i++){
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
	timeslice();
	turnaround();
	waiting();
	for(p.i=1;p.i<=p.n;p.i++){
	k=k+p.tat[p.i];
	m=m+p.wat[p.i];
	}
	k=k/p.n;
	m=m/p.n;
	printf("Average turnaround time : %f",k);
	printf("\nAverage waiting time : %f",m);
}
