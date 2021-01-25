#include<stdio.h>
int main()
{
int bt[20],p[20],wt[20],tt[20],pr[20],i,j,n,total=0,pos,temp;
float avwt,avtt;
printf("Enter Total Number of Process:");
scanf("%d",&n);
printf("\nEnter Burst Time and Priority\n");
for(i=0;i<n;i++)
{

printf("\np%d\n",i+1);
printf("Burst Time:");
scanf("%d",&bt[i]);
printf("Priority:");
scanf("%d",&pr[i]);
p[i]=i+1;
}
for(j=0;j<n;j++)
{
for(i=0;i<n-1-j;i++)
{
if(pr[i]>pr[i+1])
{
temp=pr[i];
pr[i]=pr[i+1];
pr[i+1]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]=wt[i]+bt[j];
total=total+wt[i];
}
avwt=total/n;
total=0;

printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tt[i]=bt[i]+wt[i];
total=total+tt[i];
printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
}
avtt=total/n;
printf("\n\nAverage Waiting Time=%f",avwt);
printf("\nAverage Turnaround Time=%f\n",avtt);
return 0;
}