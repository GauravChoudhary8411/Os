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
//p is the object of the structure block
void getdata()
//funtion definition to ask for user input 
{
	printf("**********************************WELCOME TO PREEMPTIVE PRIORITY SCHEDULING ALGORITHM***********************************\n\n\n");
B:	printf("Enter the number of processes you want : ");
	scanf("%d",&p.n);
	//if process number<=0 then the user is redirected to feed the correct input
	if(p.n<=0){
		printf("Invalid Input try again\n");
		goto B;
	}
	
	for(p.i=1;p.i<=p.n;p.i++){
C:	printf("Enter the Burst Time for process %d : ",p.i);
	scanf("%d",&p.b[p.i]);
	//if burst time<=0 then the user is redirected to feed the correct input
	if(p.b[p.i]<=0){
		printf("Invalid Input try again\n");
		//goto used to redirect the user to feed the correct Burst time
		goto C;
	}
}
	
	for(p.i=1;p.i<=p.n;p.i++){
D:	printf("Enter the Arrival Time for process %d : ",p.i);
	scanf("%d",&p.a[p.i]);
	//if arrival time<=0 then the user is redirected to feed the correct input
	if(p.a[p.i]<0){
		printf("Invalid Input try again\n");
		//goto used to redirect the user to feed the correct Arrival time
		goto D;
	}
}
	
	for(p.i=1;p.i<=p.n;p.i++){
	printf("Enter the Priority for process %d : ",p.i);
	scanf("%d",&p.pr[p.i]);
	//if priority < 0 then invalid input user has fill value equal or greater than 0
E:	if(p.n<0){
		printf("Invalid Input try again\n");
		//goto used to redirect the user to feed the correct priority number
		goto E ;
		}
	}
}
void display()
//funtion definition to display the data fed by the user
	{
	printf("Process Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	for(p.i=1;p.i<=p.n;p.i++){
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	}
}
void priority(){
	//funtion to determine the priorities of the processes
	p.count=0;
A:	printf("Enter the process number you want to execute : ");
	scanf("%d",&p.i);
	//if process number greater than the number of process then shows invalid input
	if(p.i<=0||p.i>p.n){
		printf("Invalid Input Try Again\n");
		//goto used to redirect the user to feed the process number
		goto A;
	}
	p.pr[p.i]==0;
	if(p.pr[p.i]==0){
	//Assigning the priority for the process to be executed = 1
	p.pr[p.i]+=1;
	printf("%d is in Ready queue \n",p.i);
	printf("\nProcess Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	p.count++;
	//using count to determine the process has moved to the ready and 
	//will not be executed in the waiting queue
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
	//initializing the count variable to 1
	p.count=1;
	//if priority!=1 then the process are in ready queue since the priority in the
	//ready queue is equal to 1.Thereofore will not be executed in the waiting queue
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
		p.rem_bt[p.i]=p.b[p.i];   //made a copy of burst time to store the remaining burst time
	}
	while(1)
	{
		bool done=true;
		//keep traversing until all of the process are not done
		for(p.i=1;p.i<=p.n;p.i++){
		//if the burst time > 0 ,proceed
		if(p.rem_bt[p.i]>0){
			done = false;	//indicates process is pending
			if(p.rem_bt[p.i]>p.slice){
				//shows how much the process has been processed
				t+=p.slice;
				//decrease the burst_time of the current process by time slice=1
				p.rem_bt[p.i]-=p.slice;
			}
			//if burst time <=time slice. This is the last cycle of the process
			else{
				//shows how much time a process has been processed
				t=t+p.rem_bt[p.i];
				//waiting time = current time - time used by the process
				p.wat[p.i]=t-p.b[p.i];
				
				//Since, the process is excecuted the remaining burst time=0
				p.rem_bt[p.i]=0;
			}
		}
	//if all the processes are done
	if(done==true)
	break;
		}
	}
}
void turnaround()
{
	//funtion for calculating turnaround time
	printf("\n\n\n********************************************TURNAROUND TIME OF THE PROCESSES********************************************\n");
	for(p.i=1;p.i<=p.n;p.i++){
	//turnaround time=waiting time + burst time + response time=0
	p.tat[p.i]=p.wat[p.i]+p.b[p.i];
	printf("\nProcess Number\t\tBurst Time\t\tArrival Time\t\tPriority\t\tTurnaround Time\n");
	printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i],p.tat[p.i]);
	}
}
void waiting(){
	//function for calculating waiting time
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
	//storing the value in k and m for turnaound time and waiting time respectively
	k=k+p.tat[p.i];
	m=m+p.wat[p.i];
	}
	k=k/p.n;	//average turnaround time=total time/total number of processes
	m=m/p.n;	//average waiting time=total waiting time/total number of processes
	printf("Average turnaround time : %f",k);
	printf("\nAverage waiting time : %f",m);
}
