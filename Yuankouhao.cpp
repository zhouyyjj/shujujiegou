#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef int DataType;
typedef struct{
	DataType data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;

//��ʼ����ջ
PSeqStack Init_SeqStack(void)
{
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(S)
		S->top=-1;
	return S;
}

//��ջ��
int Empty_SeqStack(PSeqStack S)
{
	if(S->top=-1)
		return 1;
	else
		return 0;
}

//��ջ
int Push_SeqStack(PSeqStack S,DataType x)
{
	if(S->top==MAXSIZE-1)
		return 0;
	else
	{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
}

//��ջ
int Pop_SeqStack(PSeqStack S,DataType *x)
{
	if(Empty_SeqStack(S))
		return 0;
	else
	{
		*x=S->data[S->top];
		S->top--;
		return 1;
	}
}

//�б�һ���������ʽ��Բ�����Ƿ�ƥ����ȷ
void pair(char str[])
{
	PSeqStack S;
	char ch,ch1;
	int k=0;
	S=Init_SeqStack();
	while((ch=str[k])!='\0')
	{
		if(ch=='(')
			Push_SeqStack(S,ch);
		else if(ch==')')
		{
			if(Empty_SeqStack(S))
			{
				printf("Բ���Ų����");
				return;
			}
			else Pop_SeqStack(S,&ch1);
		}
		k++;
	}
	if(Empty_SeqStack(S))
		printf("Բ����ƥ��");
	else
		printf("Բ���Ų����");
}

int main()
{
	char str[100];
	printf("please input:");
	gets(str);
	pair(str);
}


