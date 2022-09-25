#include "stdio.h"
#include "LinkList.h"
#include "malloc.h"

/*══════════════════════════════════════╗
║功能：创建空单链表                                                          ║
║入口参数：无；                                                              ║
║返回值：单链表的头指针，0代表创建失败，非0表成功                            ║
╚══════════════════════════════════════*/
LinkList Create_LinkList(void)
{
	LinkList H;
	
	H = (LinkList)malloc(sizeof(LNode));
	if (H)  /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0代表空表*/
		H->next = NULL;
	return H;
}

/*══════════════════════════════════════╗
║功能：销毁单链表                                                            ║
║入口参数：无；                                                              ║
║返回值：单链表的头指针，0代表创建失败，非0表成功                            ║
╚══════════════════════════════════════*/
void Destroy_LinkList(LinkList *H) 
{
	LinkList p, q;
	if (H==NULL || *H == NULL)
	{
		return;
	}
	else
	{
		p = *H;
		q = p;
		while(q != NULL)
		{
			q = p;
			p = p->next;
			free(q);
		}
	}
	*H = NULL;
}
/*══════════════════════════════════════╗
║功能：求单链表表长                                                          ║
║入口参数：单链表头指针                                                      ║
║返回值：出口参数：表长，-1表示单链表不存在                                  ║
╚══════════════════════════════════════*/
int Length_LinkList(LinkList H)
{
	LinkList p = H;  /*p指向头结点*/
	int count = -1;  /*H带头结点所以从－1开始*/

	while(p)
	{                /*p所指的是第 count + 1 个结点*/  
		p = p->next;
		count ++;
	}/*while */
	return count;
}
/*══════════════════════════════════════╗
║功能：查找操作（按序号查找）                                                ║
║      从单链表的第一个元素结点起， 判断当前结点是否是第i个，若是，则返回该  ║
║		结点的指针，否则继续下一个结点的查找，直到表结束为止。 若没有第ｉ个   ║
║		结点则返回空。如果i=0返回头指针。                                     ║
║入口参数：单链表头指针,查找序号                                             ║
║返回值：出口参数：要查找结点的指针，NULL：参数i出错或单链表不存在           ║
╚══════════════════════════════════════*/
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
/*══════════════════════════════════════╗
║功能：查找操作（按值查找：在单链表中查找值为x的结点）                       ║
║      单链表的按值查找是在线性表存在的情况下，查找值为ｘ的数据元素          ║
║		若成功，返回首次出现的值为ｘ的那个元素所在结点的指针                  ║
║		否则，未找到值为ｘ的数据元素，返回NULL表示查找失败                    ║
║入口参数：单链表头指针,检索元素                                             ║
║返回值：出口参数：找到后返回其指针，否则返回NULL                            ║
╚══════════════════════════════════════*/
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	
	while(p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

/*══════════════════════════════════════╗
║功能：插入操作                                                              ║
║      插入运算是指在单链表的第i个位置前插入一个值为x的新结点，即在          ║
║		第i-1结点的后面插入值为x的新结点                                      ║
║入口参数：单链表头指针,插入位置、插入元素                                   ║
║返回参数：成功标志，0不成功，1成功                                          ║
╚══════════════════════════════════════*/
int Insert_LinkList(LinkList H, int i, DataType x)
{
	LinkList p, q;
	
	p = Locate_LinkList_Pos(H, i-1);/*找第i-1个结点地址*/
	if (!p)
	{
		printf("i有误");
		return 0;
	}
	q =(LinkList)malloc(sizeof(LNode));
	if (!q)
	{
		printf("申请空间失败");
		return 0;
	}/*申请空间失败，不能插入*/
	q->data = x;
	q->next = p->next;
	p->next = q;/*新结点插入在第i-1个结点的后面*/
	return 1;   /*插入成功，则返回*/
}


/*══════════════════════════════════════╗
║功能：删除操作                                                              ║
║      删除运算是指删除单链表的第i个结点，即将第i-1个元素结点的指针域指向    ║
║		第i+1元素结点                                                         ║
║入口参数：单链表头指针,删除元素序号                                         ║
║返回参数：成功标志，0不成功，1成功                                          ║
╚══════════════════════════════════════*/
int Del_LinkList(LinkList H, int i)
{
	LinkList p, q;

	if (H == NULL || H->next == NULL)
	{
		printf("链表不存在或空表不能删除");
		return 0;
	}
	
	p = Locate_LinkList_Pos(H, i-1);/*找第i-1个结点地址*/
	if (p == NULL || p->next == NULL) 
	{
		printf("参数i有误"); /*第i-1个结点不存在*/
		return 0;
	}
	q = p->next;        /*q指向第i个结点*/
	p->next = q->next;  /*从链表中删除*/
	free(q);            /*释放*s */
	return 1;  
}


void reverse_LinkList(LinkList H)
{
	LinkList p, q;


	if(H == NULL || H->next == NULL)
	{
		printf("链表不存在或链表为空");
		return;
	}
	p = H->next;      //p指向第一个数据结点
	H->next = NULL;   //将原链表置为空表
	while(p)          //从第一个结点开始，依次取出每个结点，插入到H单链表的第一个位置
	{                 
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q;
	}
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
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void Inter_Sec(LinkList A, LinkList B)
{
	LinkList p, pre;

	pre = A; 
	p = A->next;

	while(p)
	{

		if (Locate_LinkList_Value(B, p->data) == NULL)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void Merge_sec(LinkList A, LinkList B)
{
	LinkList p;

	p = B->next;

	while(p)
	{
		if (Locate_LinkList_Value(A, p->data) == NULL)
		{
			Insert_LinkList(A, 1, p->data);
		}
		p = p->next;
	}
}

int josephus_LinkList(LinkList  josephus_Link, int s, int m) 
{   /*返回值：1表示成功，0表示表中没有元素*/
    LinkList p,pre; int count; /*p指向当前结点，pre指向其前驱结点*/    
    if (!josephus_Link) 
    {   
		printf("表中无元素"); 
		return (0); 
    }
    p= josephus_Link;
    for(count=1;count<s;count++)  /*查找第s个结点，用p指向第s个结点*/
		p=p->next;
	printf("输出约瑟夫序列：");
	while ( p!=p->next) 
	{ /*不是最后一个元素,输出 n-1个元素个结点*/   
		//pre=p->next;
		//while(pre->next != p)  pre = pre->next;
		for(count=1;count<m;count++) 
		{     
			pre=p; 
			p=p->next; 
		}
		printf("%d\t", p->data);    
		pre->next=p->next;
		free(p);   
		p=pre->next;
	}/*while*/
	printf("%d\t",p->data); /*输出最后一个元素个结点*/
	free(p);    
	return 1; 
}
