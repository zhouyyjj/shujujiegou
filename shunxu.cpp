#include <stdio.h>
#include <stdlib.h>

#define keyType int 
typedef struct
{
	keyType key;   //���ұ���ÿ������Ԫ�ص�ֵ
}ElemType;

typedef struct 
{
	ElemType *elem;//��Ų��ұ���Ԫ�ص�����
	int length;    //��¼���ұ������ݵ�������
}SSTable;

//�������ұ�
void Create(SSTable *st,int length)
{
	//(*st) = (SSTable *)malloc(sizeof(SSTable));
	st->length = length;
	st->elem = (ElemType *)malloc((length + 1)*sizeof(ElemType));
	printf("������е�����Ԫ��:\n");
	//���ݲ��ұ�������Ԫ�ص��ܳ��ȣ��ڴ洢ʱ���������±�Ϊ1�Ŀռ俪ʼ�洢����
	for (int i = 1;i<=length;i++)
	{
		scanf("%d",&(st->elem[i].key));
	}
}

int search_seq(SSTable *st,keyType key)
{
	st->elem[0].key = key;    //���ؼ�����Ϊһ������Ԫ�طŵ����ұ�ĵ�һ��λ�ã�������ڵ�����
	int i = st->length;
	//�Ӳ��ұ�����һ������Ԫ�����α�����һֱ�����������±�Ϊ0
	while(st->elem[i].key!=key)
	{
		i--;
	}
	//��� i = 0��˵������ʧ�ܣ���֮�����ص��Ǻ��йؼ���key������Ԫ���ڲ��ұ��е�λ��
	return i;
}

int main()
{
	SSTable st;
	Create(&st,6);
	printf("������Ҫ�������ݵĹؼ���:\n");
	int key;
	scanf("%d",&key);
	
	int location = search_seq(&st,key);
	if(location == 0)
	{
		printf("����ʧ��\n");
	}
	else
	{
		printf("�����ڲ��ұ��е�λ��Ϊ:%d\n",location);
	}
	return 0;
}