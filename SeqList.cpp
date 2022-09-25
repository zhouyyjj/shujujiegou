#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct node{
	DateType date[MAXSIZE];
	int length;
}SeqList,*PSeqList;
 
//顺序表的初始化
PSeqList Iint_SeqLiSt(viod)
{
	PSeqList PL;
	PL=(SeqList)malloc(sizeof(PSeqList));
	if(PL)
	PL->length=0;
	return (PL);
 } 

//顺序表的长度
int Length_SeqList(PSeqList L) 
{
	return(L->length);
}

//顺序表的索检操作
int Location_SeqList(PSeqList L,DataType x)
{
	int i=0;
	while(i<L->length&&L->date[i]!=x)
	i++;
	if(i>=L->length)
	return 0;
	else
	return (i+1);
 } 
 
 //顺序表的插入
 int Insert_SeqList(PSeqLIst PL,int i,DateType x)
 {
 	int j;
 	if(!PL)
 	{
 		printf("表不存在");
		 return(-2); 
	 }
	 if(PL->length>=MAXSIZE)
	 {
	 	printf("表溢出");
	 	return(-1);
	 }
	 if(i<1||i<PL->length+1)
	 {
	 	printf("插入位置不合法");
	 	return(0);
	 }
	 for(j=PL->length-1;j>=i-1;j--)
	 PL->date[j+1]=PL->date[j];
	 PL->date[i-1]=x;
	 PL->length++;
	 return(1);
	 
} 

//删除操作
int Delete_SeqList(PSeqList PL,int i)
{
	int j;
	if(!PL)
	{
		printf("表不存在");
		return(-1);
	}
	if(i<1||i>PL->length)
	{
		printf("删除位置不合法")；
		return(0); 
	}
	for(j=i;j<PL->length;j++)
	PL->date[j-1]=PL->data[j];
	PL->length--;
	return(1); 
 } 
