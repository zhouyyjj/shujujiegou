#include "stdio.h"
#include "SeqList.h"

void main( )
{
	PSeqList PL;
	int i, ret;
	DataType e;

	printf("▼1\n▲函数 Init_SeqList 测试...\n");		//1.函数Init_SeqList测试
	{
		printf("初始化顺序表 L ...\n");					 
		PL = Init_SeqList();
		printf("\n");	
	}
	getchar();
		
	printf("▼5\n▲函数 Insert_SeqList 测试...\n");		//5.函数Insert_SeqList测试
	{
		for(i=1; i<=6; i++)									
		{
			printf("作为示范，在 L 第 %d 个位置插入 \"%d\"...\n", i, 2*i);
			ret = Insert_SeqList(PL, i, 2*i);
			if(ret==0)  
				printf("插入位置不合法\n");
			else if(i==-1) 
				printf("表不存在\n");
			else if(i==-2) 
				printf("溢出\n");
		}
		printf("\n");	
	}
	getchar();

	printf("▼3\n▲函数 Length_SeqList 测试...\n");		//3.函数Length_SeqList测试
	{
		i = Length_SeqList(PL);
		printf(" L 的长度为 %d \n", i);
	}
	getchar();
	
	printf("▼3\n▲函数 Delete_SeqList 测试...\n");		//3.函数Delete_SeqList测试
	{
		int pos = 0;
		printf("删除前：L 中的元素为：L = ");						 
		Print_SeqList(PL);
		printf("\n请输入要删除元素的位置:\n");
		scanf("%d", &pos);
		Delete_SeqList(PL, pos);
		
		printf("删除后：L 中的元素为：L = ");						 
		Print_SeqList(PL);
		printf("\n\n");
	}
	
	getchar();
	printf("▼4\n▲函数 Location_SeqList 测试...\n");	  	//4.函数Location_SeqList测试
	{
		printf("请输入要查找的元素：");
		scanf("%d", &e);
		i = Location_SeqList(PL, e);
		if(i==0)  
			printf("查找失败\n");
		else if(i==-1) 
			printf("表不存在\n");
		else
			printf(" L 中要查找的元素的位置为 %d \n", i); 
		printf("\n");
	}

	getchar();
	printf("▼2\n▲函数 DestroyList_Sq 测试...\n");		//2.函数DestroyList_Sq测试
	{
		printf("销毁 L 前：");
		Print_SeqList(PL);
		Destroy_SeqList(&PL);
		printf("销毁 L 后：");
		Print_SeqList(PL);
		printf("\n");
	}
}