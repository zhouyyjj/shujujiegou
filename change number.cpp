#include<stdio.h>
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
 SElemType data;//数据域
 struct StackNode* next;//指针域
}StackNode,*LinkStack;

/*空栈的初始化*/
Status InitStack(LinkStack& S)
{
 S = NULL;
 return OK;
}

/*入栈操作*/
Status Push(LinkStack& S, int e)
{
 LinkStack p;
 p = new StackNode;//开辟一个新结点
 p->data = e;
 p->next = S;
 S = p;//更改栈顶指针
 return OK;
}

/*出栈操作*/
Status Pop(LinkStack& S, SElemType& e)
{
 LinkStack p;
 if (S == NULL) return ERROR;//空栈
 e = S->data;//将栈顶元素赋值给e
 p = S;//p临时存储S的空间
 S = S->next;//修改栈顶指针位置
 delete p;//释放空间
 return OK;
}

/*数值转换操作*/
void Conversion(int N, int m)
{
 LinkStack S;
 int e;
 printf("十进制数%d转换成%d进制数为：", N, m);
 InitStack(S);//初始化栈
 while (N)
 {
  Push(S,N % m);//将m进制数压入栈中
  N = N / m;//更新N
 }
 while (S != NULL)
 {
  Pop(S,e);//出栈
  printf("%d ", e);
 }
}

int main(void)
{
 int N,m;
 printf("请输入要转换的十进制数：");
 scanf_s("%d", &N);
 printf("请输入要转换成的进制数：");
 scanf_s("%d", &m);
 Conversion(N,m);//数制的转换

 printf("\n");
 return 0;
}
