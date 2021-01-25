#include <stdio.h>
int mat[10][6];
void arrangeArrival(int num, int mat[][6])
{
for (int i = 0; i < num; i++)
{
for (int j = 0; j < num - i - 1; j++)
{
if (mat[j][1] > mat[j + 1][1])
{
for (int k = 0; k < 5; k++)
{
// swap(mat[j][k], mat[j+1][k]);
int temp;
temp = mat[j][k];
mat[j][k] = mat[j+1][k];
mat[j+1][k] = temp;
}
}
}
}
}
void completionTime(int num, int mat[][6])
{
int temp, val;
mat[0][3] = mat[0][1] + mat[0][2];
mat[0][5] = mat[0][3] - mat[0][1];
mat[0][4] = mat[0][5] - mat[0][2];
for (int i = 1; i < num; i++)
{
temp = mat[i - 1][3];
int low = mat[i][2];
for (int j = i; j < num; j++)
{
if (temp >= mat[j][1] && low >= mat[j][2])
{
low = mat[j][2];
val = j;
}
}
mat[val][3] = temp + mat[val][2];
mat[val][5] = mat[val][3] - mat[val][1];
mat[val][4] = mat[val][5] - mat[val][2];
for (int k = 0; k < 6; k++)
{
// swap(mat[val][k], mat[i][k]);
int temp;
temp = mat[val][k];
mat[val][k] = mat[i][k];
mat[i][k] = temp;
}
}
}
void main()
{
int num, temp;
printf("\nEnter number of Process: ");
scanf("%d", &num);
printf("\n...Enter the process ID...\n");
for (int i = 0; i < num; i++)
{
printf("\n___Process___\n\n", i + 1);
printf("Enter the Process Id: ");
scanf("%d", &mat[i][0]);
printf("Enter the Arrival Time: ");
scanf("%d", &mat[i][1]);
printf("Enter the Burst Time: ");
scanf("%d", &mat[i][2]);
}
printf("\nBefore the arrangement...\n");
printf("Process ID\tArrival Time\tBurst Time\n");
for (int i = 0; i < num; i++)
{
printf("%d \t\t%d \t\t%d \n", mat[i][0], mat[i][1], mat[i][2]);
}
arrangeArrival(num, mat);
completionTime(num, mat);
printf("\n__Final Result__\n");
printf("Process ID\t Arrival Time\t Burst Time\t Waiting Time\t TurnaroundTime\n");
for (int i = 0; i < num; i++)
{
printf("%d \t\t%d \t\t%d \t\t%d \t\t%d \n", mat[i][0], mat[i][1],
mat[i][2], mat[i][4], mat[i][5]);
}
}
