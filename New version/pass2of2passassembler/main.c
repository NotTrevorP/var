
#include<stdio.h>
#include<string.h>
int main()
{
 FILE *fInter,*fOptab,*Length,*fSymtab, *fObjCode;
int i,j=0,len;
char
address[5],symAddress[5],opCode[5],start[10],label[20],instr[10],operand[10],symbol[10],opName[10];
 fInter=fopen("intermediate.txt","r");
 Length=fopen("length.txt","r");
 fOptab=fopen("optab.txt","r");
 fSymtab=fopen("symtab.txt","r");
 fObjCode=fopen("objcode.txt","w");
 fscanf(fInter,"%s%s%s%s",address,label,instr,operand);
if(strcmp(instr,"START")==0)
 {
 strcpy(start,operand);
 fscanf(Length,"%d",&len);
 }
 fprintf(fObjCode, "H^%s^%s^%d\nT^00%s^",label,start,len,start);
 printf("H^%s^%s^%d\nT^00%s^",label,start,len,start);
 fscanf(fInter,"%s%s%s%s",address,label,instr,operand);
while(strcmp(instr,"END")!=0)
 {
 fscanf(fOptab,"%s%s",opName,opCode);
 while(!feof(fOptab))
 {
 if(strcmp(instr,opName)==0)
 {
 fclose(fOptab);
 fscanf(fSymtab,"%s%s",symAddress,symbol);
 while(!feof(fSymtab))
 {
 if(strcmp(operand,symbol)==0)
 {
 fprintf(fObjCode, "%s%s^",opCode,symAddress);
 printf("%s%s^",opCode,symAddress);
 break;
 }
 else
 fscanf(fSymtab,"%s%s",symAddress,symbol);
 }
 break;
 }
 else
 fscanf(fOptab,"%s%s",opName,opCode);
 }
 if((strcmp(instr,"BYTE")==0)||(strcmp(instr,"WORD")==0))
 {
 if(strcmp(instr,"WORD")==0)
 {
 fprintf(fObjCode, "0000%s^", operand);
 printf("0000%s^", operand);
 }
 else
 {
 len=strlen(operand);
 for(i=2;i<len;i++)
 {
 fprintf(fObjCode, "%d", operand[i]);
 printf("%d", operand[i]);
 }
 fprintf(fObjCode, "^");
 printf("^");
 }
 }
 fscanf(fInter,"%s%s%s%s",address,label,instr,operand);
 fOptab=fopen("optab.txt","r");
 fseek(fOptab,SEEK_SET,0);
 }
 fprintf(fObjCode, "\nE^00%s", start);
 printf("\nE^00%s", start);
 fclose(fInter);
 fclose(fOptab);
 fclose(fSymtab);
 fclose(Length);
 fclose(fObjCode);
}

