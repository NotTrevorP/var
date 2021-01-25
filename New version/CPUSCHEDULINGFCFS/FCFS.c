#include <stdio.h>
void main()
{
int bt[10], wt[10], tat[10], i, n;
printf("Enter the number of processes: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
printf("Enter burst time of the process %d: ", i + 1);
scanf("%d", &bt[i]);
}
int sum = 0;
printf("waiting time of P1 = 0 \n");
wt[0] = 0;
for (i = 1; i < n; i++)
{
wt[i] = bt[i - 1] + sum;
sum = sum + bt[i - 1];
printf("Waiting time of P %d = %d \n", i + 1, wt[i] );
}
for (i = 0; i < n; i++)
{
tat[i] = bt[i] + wt[i];
printf("Turn around time of P%d = %d \n", i + 1, tat[i] );
}
float sw = 0, st = 0;
float avgwt, avgtat;
for (i = 0; i < n; i++)
{
sw = sw + wt[i];
st = st + tat[i];
}
avgwt = sw / n;
avgtat = st / n;
printf("Average waiting time = %f \n", avgwt);
printf("Average turn around time = %f \n", avgtat);
}