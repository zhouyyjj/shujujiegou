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
Seq_Queue*init_seqqueue();//循环队列的初始化
void fun(int n);//函数实现
void enter_seqqueue(Seq_Queue*Q,element x);//循环队列元素入队
void delet_seqqueue(Seq_Queue*Q,int *x);//循环队列的出队
void getdata_seqqueue(Seq_Queue*Q,int *x);//取对头元素
void main()
{
    int n;
    printf("请输入杨辉三角的行数:\n");
     scanf("%d",&n);
     printf("打印的杨辉三角为:\n");
        fun(n);
}
Seq_Queue*init_seqqueue()//循环队列的初始化
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
void   enter_seqqueue(Seq_Queue*Q,element x)//循环队列元素入队
{
            Q->data[Q->rear]=x;
          Q->rear=(Q->rear+1)%MAXSIZE;
}
void  delet_seqqueue(Seq_Queue*Q,int *x)//循环队列的出队
{
     *x=Q->data[Q->front];
     Q->front=(Q->front+1)%MAXSIZE;
}
void getdata_seqqueue(Seq_Queue*Q,int *x)//取对头元素
{
    *x=Q->data[Q->front];

}
void fun(int n)//函数实现
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
          enter_seqqueue(q,1);//将i+1个元素入队
          for(k=0;k<=i-2;k++)
            {
                delet_seqqueue(q,&a1);//将队列第一个元素出队
                getdata_seqqueue(q,&a2);//得到队列的第二个元素的值
                 printf("%d ",a1);
                   enter_seqqueue(q,a1+a2);
                   //将i+1行的计算后的结果入队
            }
              delet_seqqueue(q,&a2);//使第i行的最后一个元素出队
              printf("%d\n",a2);//打印第i行最后一个元素
             enter_seqqueue(q,1);//将i+1的最后一个元素入队
    }
}