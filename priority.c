#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct process
{
	int i,j,n,m1,n1,m2,n2,m3,n3,m4,n4;
	int a[1000],b[1000],pr[1000];
	int setp,pos,temp;
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
	
	for(p.i=1;p.i<=p.n;p.i++){
	printf("Enter the Priority for process %d : ",p.i);
	scanf("%d",&p.pr[p.i]);
	}
	system("cls");
}
void display()
	{
	printf("Process Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	for(p.i=1;p.i<=p.n;p.i++){
	printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p.i,p.b[p.i],p.a[p.i],p.pr[p.i]);
	}
}
void priority(){
	for(p.i=0;p.i<p.n;p.i++)
    {
        p.pos=p.i;
        for(p.j=p.i+1;p.j<p.n;p.j++)
        {
            if(p.pr[p.j]<p.pr[p.pos])
                p.pos=p.j;
        }
 
        p.temp=p.pr[p.i];
        p.pr[p.i]=p.pr[p.pos];
        p.pr[p.pos]=p.temp;
 
        p.temp=p.b[p.i];
        p.b[p.i]=p.b[p.pos];
        p.b[p.pos]=p.temp;
 
        p.temp=p.i;
        p.i=p.i;
        p.pos=p.temp;
    }
}
int main()
{
	getdata();
	display();
	priority();
}
