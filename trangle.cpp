#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef int DataType;
typedef struct{
	DataType data[MAXSIZE];
	int front,rear;	
}SeqQueue,*PSeqQueue;

//���г�ʼ��
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

//�ж϶ӿ�
int Empty_SeqQueue(PSeqQueue Q)
{
	if(Q&&Q->front==Q->rear)	
		return(1);
	else
		if(!Q)return(-1);
		else return(0);	
}

//���
int In_SeqQueue(PSeqQueue Q,DataType x)
{	
	if((Q->rear+1)%MAXSIZE==Q->front)	
	{
		printf("����");
		return -1;//�����������
	}	
	else	
	{	
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->data[Q->rear]=x;
		return 1;//������	
	}	
}

//����
int Out_SeqQueue(PSeqQueue Q,DataType *x)
{
	if(Empty_SeqQueue(Q))	
	{	
		printf("�ӿ�");	
		return -1;//�ӿղ��ܳ���	
	}
	else	
	{	
		Q->front=(Q->front+1)%MAXSIZE;
		*x=Q->data[Q->front];//�������Ԫ��
		return 1;	
	}
}

//���ٶ���
void Destroy_SeqQueue(PSeqQueue *Q)
{	
	if(*Q)	
		free(*Q);
	*Q=NULL;
}

//�ö���ʵ�ִ�ӡ�������
void Yanghui_trangle(int n)
{	
	int s=0;	
	int i;
	PSeqQueue sq=Init_SeqQueue();//��ʼ������
	In_SeqQueue(sq,1);
	In_SeqQueue(sq,1);
	for(i=1;i<=n;i++,s=0)	
	{
		printf("\n");
		for(int k=0;k<=40-4*i;k+=2)printf(" ");
		In_SeqQueue(sq,0);
		for(int j=1;j<=i+2;j++)	
		{	
			int t;
			Out_SeqQueue(sq,&t);
			In_SeqQueue(sq,s+t);
			s=t;
			if(j!=i+2)	
				printf("%4d",s);
		}	
	}
	printf("\n");
	Destroy_SeqQueue(&sq);
}

void main()
{
	int n;
	printf("please input the n:");
	scanf("%d",&n);
	Yanghui_trangle(n);
}