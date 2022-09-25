#include<stdio.h>
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
 SElemType data;//������
 struct StackNode* next;//ָ����
}StackNode,*LinkStack;

/*��ջ�ĳ�ʼ��*/
Status InitStack(LinkStack& S)
{
 S = NULL;
 return OK;
}

/*��ջ����*/
Status Push(LinkStack& S, int e)
{
 LinkStack p;
 p = new StackNode;//����һ���½��
 p->data = e;
 p->next = S;
 S = p;//����ջ��ָ��
 return OK;
}

/*��ջ����*/
Status Pop(LinkStack& S, SElemType& e)
{
 LinkStack p;
 if (S == NULL) return ERROR;//��ջ
 e = S->data;//��ջ��Ԫ�ظ�ֵ��e
 p = S;//p��ʱ�洢S�Ŀռ�
 S = S->next;//�޸�ջ��ָ��λ��
 delete p;//�ͷſռ�
 return OK;
}

/*��ֵת������*/
void Conversion(int N, int m)
{
 LinkStack S;
 int e;
 printf("ʮ������%dת����%d������Ϊ��", N, m);
 InitStack(S);//��ʼ��ջ
 while (N)
 {
  Push(S,N % m);//��m������ѹ��ջ��
  N = N / m;//����N
 }
 while (S != NULL)
 {
  Pop(S,e);//��ջ
  printf("%d ", e);
 }
}

int main(void)
{
 int N,m;
 printf("������Ҫת����ʮ��������");
 scanf_s("%d", &N);
 printf("������Ҫת���ɵĽ�������");
 scanf_s("%d", &m);
 Conversion(N,m);//���Ƶ�ת��

 printf("\n");
 return 0;
}
