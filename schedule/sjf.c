#include<stdio.h>
int main()
{
int bt[20],wt[20],tt[20],i,j,n,temp;
float avwt,avtt;
printf("Enter number of process:");
scanf("%d",&n);
printf("Enter Burst Time");
for(i=0;i<n;i++)
{
printf("p[%d]:",i+1);
scanf("%d",&bt[i]);
}
for(j=0;j<n;j++)
{
for(i=0;i<n-1-j;i++)
{
if(bt[i]>bt[i+1])
{
temp=bt[i];

bt[i]=bt[i+1];
bt[i+1]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
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
