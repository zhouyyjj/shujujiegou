/*********************************
用链表求解约瑟夫问题：
算法思想：由于约瑟夫问题是n个人围坐一圈，所以采用循环链表实现，又由于报数
时可能循环到开始，所以采用不带头结点的循环链表结构。 
算法步骤：
1.在不带头结点的循环链表中查找第s个结点，用p作为第s个结点的指针
2.从p所指的结点开始计数查找第m个结点，pre指向p的前驱
3.输出该结点元素值
4.删除该结点，同时将该结点下一结点指针作为当前指针即p指针，重复到步骤2，直到链表中所有结点都被删完为止。 
*********************************/ 
#include "stdio.h"
#include "malloc.h"


typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}LNode,*LinkList;

//创建空的单链表 
LinkList Creat_LinkList(void){
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if(H)
		H->next=NULL;
	return H;
}
//查找操作，1.按序号查找 
LinkList Locate_LinkList_Pos(LinkList H, int i)
{
	LinkList p = H;
	int j = 0;

	while(p && j<i)
	{
		p = p->next;
		j++;
	}
	if (j!=i || !p)
	{
		printf("参数i出错或单链表不存在");
		return NULL;
	}
	return p;
}
//查找操作，2.按值查找 
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	
	while(p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//插入：在单链表 的第i个位置前插入一个值为x的新结点 
int Insert_LinkList(LinkList H,int i,DataType x){
	LinkList p,q;
	p=Locate_LinkList_Pos(H,i-1);
	if(!p){
		return -1;
	}
	q=(LinkList)malloc(sizeof(LNode));
	if(!q){
		
		return 0;
	}
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}

//删除 第i个结点
int Del_LinkList(LinkList H,int i){
	//删除单链表H上的第i个结点，入口参数：单链表，删除元素序号，返回参数：成功标志，0表示不成功，1表示成功
	LinkList p,q;
	if(H==NULL||H->next==NULL) {
		printf("单链表不存在或空表不能删除");
		return 0;
	}
	p = Locate_LinkList_Pos(H,i-1);//找第i-1个结点地址
	if(p==NULL||p->next==NULL){
		printf("参数i错误");
		return 0;
	} 
	q=p->next;
	p->next=q->next;
	free(q);
	return 1;
} 
 
//销毁单链表 
void Destroy_LinkList(LinkList *H){
	
	LinkList p,q;
	p = *H;
	while(p){
		q=p;
		p=p->next;
		free(q);
	}
	*H=NULL;
}
void print_LinkList(LinkList H)
{
	LinkList p;
	
	if(H == NULL || H->next == NULL)
	{
		printf("链表不存在或链表为空");
		return;
	}

	printf("链表中数据为：\n");
	p = H->next;
	while(p)
	{
		printf("%4d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int josephus_LinkList(LinkList josephus_Link,int s,int m){
	LinkList p,pre;
	int count;
	if(!josephus_Link){
		printf("表中无元素");
		return 0;
	}
	/*找第s个元素*/
	p = josephus_Link;
	for(count = 1; count < s;count ++)
		p=p->next;
	 
	printf("输出约瑟夫序列：");
	while(p!=p->next){
		pre=p->next;
		while(pre->next!=p) pre=pre->next;
		for(count=1;count<m;count++){
			pre = p;
			p=p->next;
		} 
		printf("%d\t",p->data);
		pre->next=p->next;
		free(p);
		p=pre->next;
	}
	printf("%d\t",p->data);
	free(p);
	return 1;
} 
 
main(){
	
	
	LinkList C;
	C =  Creat_LinkList_H();
	int i;
	int x;
	printf("请输入C集合的数据：\n");
	Insert_LinkList_H(C);

	print_LinkList_H(C);
	josephus_LinkList(C,2,3);
	
	
} 
	
	
