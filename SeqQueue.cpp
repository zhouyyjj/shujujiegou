#include<stdio.h>
#include<malloc.h>
#define MAxSIZE 100//���е��������

typedef struct{
	DataType date[MAXSIZE];
	int front,rear;//��ͷ�Ͷ�βָ�� 
}SeqQueue,*PSeqQueue;

//��ʼ������
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


