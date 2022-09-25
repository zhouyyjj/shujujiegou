#include<stdio.h>
#include<malloc.h>
#define MAxSIZE 100//队列的最大容量

typedef struct{
	DataType date[MAXSIZE];
	int front,rear;//队头和队尾指针 
}SeqQueue,*PSeqQueue;

//初始化队列
PSeqQueue Init_SeqQueue()
{
	PSeqQueue Q;
	Q=(PSeqQueue)malloc(sizeof(SeqQueue));
	if(Q)
	{
		Q->front=0;
		Q->rear=0;
	}
	return Q;
} 


