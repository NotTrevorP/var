#include<stdio.h>
int main()
{
int bt[100],i,j,n,temp,wt[100],tt[100];
float avwt,avtt;
printf("Enter number of process:");
scanf("%d",&n);
printf("Enter Burst Time");
for(i=0;i<n;i++)
{
printf(" p%d:",i+1);
scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]=wt[i]+bt[j];
}
for(i=0;i<n;i++)
{
tt[i]=bt[i]+wt[i];
avwt=avwt+wt[i];

avtt=avtt+tt[i];
}
avwt=avwt/n;
avtt=avtt/n;
printf("Average Waiting Time=%f",avwt);
printf(" ,Average Turnaround Time=%f",avtt);
}
