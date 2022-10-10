//���ڵ�����Ŀ�������
#include<stdio.h>
#include<malloc.h> 
typedef struct Lnode
{
	int key;
	struct Lnode* next;
}Lnode, *Linklist;
//����ṹ������
Linklist createList(Linklist L, int n)
{
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	Lnode *p, *r;
	r = L;
	p = (Lnode*)malloc(sizeof(Lnode));
	scanf("%d", &r->key);
	for (int i = 1; i < n; i++)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		scanf("%d", &p->key);
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}
//��ʼ��ʼ����β�巨�����򣩴���������
Linklist getTail(Linklist L)
{
	while (L->next)
		L = L->next;
	return L;
}
//�õ�βָ��
void Print(Linklist L)
{
	Lnode *p;
	p = L;
	while (p)
	{
		printf("%d ", p->key);
		p = p->next;
	}
}
//����������
Linklist Quicksort(Linklist *listHead, Linklist *listTail)
{
	Lnode *current;
	Lnode* lessHead = NULL, *lessTail = NULL, *moreHead = NULL, *moreTail = NULL;
	current = (*listHead)->next;//ÿ��ȡ�׽ڵ�Ϊ��Ŧ��currentָ��ڶ����ڵ����ڱ���
	if ((*listHead)->next != NULL)//������ڵ�����Ϊ1ʱ(˵������δ�ź���)
	{
		for (current = (*listHead)->next; current; current = current->next)
		{
			if (current->key < (*listHead)->key)
			{
				if (lessHead == NULL)
					lessHead = current;
				else
					lessTail->next = current;
				lessTail = current;
			}//current���keyС����Ŧkeyʱ����less����
			else
			{
				if (moreHead == NULL)
					moreHead = current;
				else
					moreTail->next = current;
				moreTail = current;
			}//current���key������Ŧkeyʱ����more����
		}
		//������Ŧ��㽫T�����Ϊless��more��������
		if (moreTail)
			moreTail->next = NULL;
		if (lessTail)
			lessTail->next = NULL;
		//��more����β���next���ÿ�
		if (moreHead != NULL)
		{
			moreTail->next = NULL;
			Quicksort(&moreHead, &moreTail);
			(*listHead)->next = moreHead;
			*listTail = moreTail;
		}
		//��moreHead���գ���currentΪmore�����β��㣬��more������еݹ鴦��,��more���������Ŧ�ڵ��
		else
		{
			(*listHead)->next = NULL;
			*listTail = *listHead;
		}
		//��moreHeadΪ�գ���ֻ��less����(�����keyȫС����Ŧ)������Ŧ������less�ڵ��
		if (lessHead != NULL)
		{
			lessTail->next = NULL;
			Quicksort(&lessHead, &lessTail);
			lessTail->next = *listHead;
			*listHead = lessHead;
		}
		//��lesseHead���գ���less������еݹ鴦���ٽ���Ŧ�ڵ����less�����
		else
		{
			lessHead = *listHead;
		}
		//��lesseHeadΪ�գ�����Ŧ�����Ϊ�׽ڵ�
		return lessHead;
	}
	else
		return *listHead;
}
int main()
{
	Lnode* L = NULL;
	int n;
	printf("������Ԫ�ظ���\n");
	scanf("%d", &n);
	printf("������Ԫ��\n");
	L = createList(L, n);
	Lnode* listTail;
	listTail = getTail(L);
	Quicksort(&L, &listTail);
	printf("�����Ԫ������Ϊ\n");
	Print(L);
	return 0;
}