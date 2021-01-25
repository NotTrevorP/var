
#include <stdio.h>
int main()
{
int P, R, i, j, k;
 P = 5; //processes
 R = 3; //resources
 int finish[P], sequence[P], index = 0, need[P][R];
 int allocationMat[5][3] = {
 { 3, 1, 1 }, // P0
 { 2, 1, 2 }, // P1
 { 3, 0, 2 }, // P2
 { 0, 1, 1 }, // P3
 { 2, 1, 2 } // P4
 };
 int maxMat[5][3] = {
 { 6, 4, 1 }, // P0
 { 4, 3, 2 }, // P1
 { 8, 1, 3 }, // P2
 { 9, 3, 4 }, // P3
 { 5, 2, 2 } // P4
 };
 int available[3] = { 2, 3, 2 };
 for (k = 0; k < P; k++)
 {
 finish[k] = 0;
 }
 for (i = 0; i < P; i++)
 {
 for (j = 0; j < R; j++)
 need[i][j] = maxMat[i][j] - allocationMat[i][j];
 }
 int y = 0;
 for (k = 0; k < 5; k++)
 {
 for (i = 0; i < P; i++)
 {
 if (finish[i] == 0)
 {
 int flag = 0;
 for (j = 0; j < R; j++)
 {
 if (need[i][j] > available[j])
 {
 flag = 1;
 break;
 }
 }
 if (flag == 0)
 {
 sequence[index++] = i;
 for (y = 0; y < R; y++)
 available[y] += allocationMat[i][y];
 finish[i] = 1;
 }
 }
 }
 }
 printf("Following is the safe sequence:\n\n");
 for (i = 0; i < P - 1; i++)
 printf(" P%d ->", sequence[i]);
 printf(" P%d\n", sequence[P - 1]);
}