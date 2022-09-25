/*********************************
���������Լɪ�����⣺
�㷨˼�룺����Լɪ��������n����Χ��һȦ�����Բ���ѭ������ʵ�֣������ڱ���
ʱ����ѭ������ʼ�����Բ��ò���ͷ����ѭ������ṹ�� 
�㷨���裺
1.�ڲ���ͷ����ѭ�������в��ҵ�s����㣬��p��Ϊ��s������ָ��
2.��p��ָ�Ľ�㿪ʼ�������ҵ�m����㣬preָ��p��ǰ��
3.����ý��Ԫ��ֵ
4.ɾ���ý�㣬ͬʱ���ý����һ���ָ����Ϊ��ǰָ�뼴pָ�룬�ظ�������2��ֱ�����������н�㶼��ɾ��Ϊֹ�� 
*********************************/ 
#include "stdio.h"
#include "malloc.h"


typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}LNode,*LinkList;

//�����յĵ����� 
LinkList Creat_LinkList(void){
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if(H)
		H->next=NULL;
	return H;
}
//���Ҳ�����1.����Ų��� 
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
		printf("����i�������������");
		return NULL;
	}
	return p;
}
//���Ҳ�����2.��ֵ���� 
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	
	while(p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//���룺�ڵ����� �ĵ�i��λ��ǰ����һ��ֵΪx���½�� 
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

//ɾ�� ��i�����
int Del_LinkList(LinkList H,int i){
	//ɾ��������H�ϵĵ�i����㣬��ڲ�����������ɾ��Ԫ����ţ����ز������ɹ���־��0��ʾ���ɹ���1��ʾ�ɹ�
	LinkList p,q;
	if(H==NULL||H->next==NULL) {
		printf("���������ڻ�ձ���ɾ��");
		return 0;
	}
	p = Locate_LinkList_Pos(H,i-1);//�ҵ�i-1������ַ
	if(p==NULL||p->next==NULL){
		printf("����i����");
		return 0;
	} 
	q=p->next;
	p->next=q->next;
	free(q);
	return 1;
} 
 
//���ٵ����� 
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
		printf("�������ڻ�����Ϊ��");
		return;
	}

	printf("����������Ϊ��\n");
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
		printf("������Ԫ��");
		return 0;
	}
	/*�ҵ�s��Ԫ��*/
	p = josephus_Link;
	for(count = 1; count < s;count ++)
		p=p->next;
	 
	printf("���Լɪ�����У�");
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
	printf("������C���ϵ����ݣ�\n");
	Insert_LinkList_H(C);

	print_LinkList_H(C);
	josephus_LinkList(C,2,3);
	
	
} 
	
	
