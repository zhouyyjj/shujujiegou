#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024
typedef  int element;
typedef struct seqqueue
{
    element data[MAXSIZE];
      int front;
      int rear;
}Seq_Queue;
Seq_Queue*init_seqqueue();//ѭ�����еĳ�ʼ��
void fun(int n);//����ʵ��
void enter_seqqueue(Seq_Queue*Q,element x);//ѭ������Ԫ�����
void delet_seqqueue(Seq_Queue*Q,int *x);//ѭ�����еĳ���
void getdata_seqqueue(Seq_Queue*Q,int *x);//ȡ��ͷԪ��
void main()
{
    int n;
    printf("������������ǵ�����:\n");
     scanf("%d",&n);
     printf("��ӡ���������Ϊ:\n");
        fun(n);
}
Seq_Queue*init_seqqueue()//ѭ�����еĳ�ʼ��
{
    Seq_Queue*q;
    q=(Seq_Queue*)malloc(sizeof(Seq_Queue));
      if(q==NULL)
         return NULL;
        else
           {
               q->front=0;
               q->rear=0;
           }
           return q;
}
void   enter_seqqueue(Seq_Queue*Q,element x)//ѭ������Ԫ�����
{
            Q->data[Q->rear]=x;
          Q->rear=(Q->rear+1)%MAXSIZE;
}
void  delet_seqqueue(Seq_Queue*Q,int *x)//ѭ�����еĳ���
{
     *x=Q->data[Q->front];
     Q->front=(Q->front+1)%MAXSIZE;
}
void getdata_seqqueue(Seq_Queue*Q,int *x)//ȡ��ͷԪ��
{
    *x=Q->data[Q->front];

}
void fun(int n)//����ʵ��
{
    int i,k;
    Seq_Queue*q;
    q=init_seqqueue();
    int a1,a2;
    printf("%d\n",1);
     enter_seqqueue(q,1);
      enter_seqqueue(q,1);
      for(i=2;i<=n;i++)
      {
          enter_seqqueue(q,1);//��i+1��Ԫ�����
          for(k=0;k<=i-2;k++)
            {
                delet_seqqueue(q,&a1);//�����е�һ��Ԫ�س���
                getdata_seqqueue(q,&a2);//�õ����еĵڶ���Ԫ�ص�ֵ
                 printf("%d ",a1);
                   enter_seqqueue(q,a1+a2);
                   //��i+1�еļ����Ľ�����
            }
              delet_seqqueue(q,&a2);//ʹ��i�е����һ��Ԫ�س���
              printf("%d\n",a2);//��ӡ��i�����һ��Ԫ��
             enter_seqqueue(q,1);//��i+1�����һ��Ԫ�����
    }
}