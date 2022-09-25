#include "stdio.h"
#include "SeqList.h"

void main( )
{
	PSeqList PL;
	int i, ret;
	DataType e;

	printf("��1\n������ Init_SeqList ����...\n");		//1.����Init_SeqList����
	{
		printf("��ʼ��˳��� L ...\n");					 
		PL = Init_SeqList();
		printf("\n");	
	}
	getchar();
		
	printf("��5\n������ Insert_SeqList ����...\n");		//5.����Insert_SeqList����
	{
		for(i=1; i<=6; i++)									
		{
			printf("��Ϊʾ������ L �� %d ��λ�ò��� \"%d\"...\n", i, 2*i);
			ret = Insert_SeqList(PL, i, 2*i);
			if(ret==0)  
				printf("����λ�ò��Ϸ�\n");
			else if(i==-1) 
				printf("������\n");
			else if(i==-2) 
				printf("���\n");
		}
		printf("\n");	
	}
	getchar();

	printf("��3\n������ Length_SeqList ����...\n");		//3.����Length_SeqList����
	{
		i = Length_SeqList(PL);
		printf(" L �ĳ���Ϊ %d \n", i);
	}
	getchar();
	
	printf("��3\n������ Delete_SeqList ����...\n");		//3.����Delete_SeqList����
	{
		int pos = 0;
		printf("ɾ��ǰ��L �е�Ԫ��Ϊ��L = ");						 
		Print_SeqList(PL);
		printf("\n������Ҫɾ��Ԫ�ص�λ��:\n");
		scanf("%d", &pos);
		Delete_SeqList(PL, pos);
		
		printf("ɾ����L �е�Ԫ��Ϊ��L = ");						 
		Print_SeqList(PL);
		printf("\n\n");
	}
	
	getchar();
	printf("��4\n������ Location_SeqList ����...\n");	  	//4.����Location_SeqList����
	{
		printf("������Ҫ���ҵ�Ԫ�أ�");
		scanf("%d", &e);
		i = Location_SeqList(PL, e);
		if(i==0)  
			printf("����ʧ��\n");
		else if(i==-1) 
			printf("������\n");
		else
			printf(" L ��Ҫ���ҵ�Ԫ�ص�λ��Ϊ %d \n", i); 
		printf("\n");
	}

	getchar();
	printf("��2\n������ DestroyList_Sq ����...\n");		//2.����DestroyList_Sq����
	{
		printf("���� L ǰ��");
		Print_SeqList(PL);
		Destroy_SeqList(&PL);
		printf("���� L ��");
		Print_SeqList(PL);
		printf("\n");
	}
}