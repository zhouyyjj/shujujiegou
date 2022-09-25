//用递归写出全排列问题的求解方法 
#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void  Allarrange(char *str,int k,int len)
{
	int i;
	if(k==len)
	{
		static int s_i=1;
		printf("第%d种排列为:\t%s\n",s_i++,str);
	}
	else
	{
		for(i=k;i<=len;i++)
		{
			swap(str+i,str+k);
			Allarrange(str,k+1,len);
			swap(str+i,str+k);
		}
	}
}

int main()
{
	char str[10];
	printf("请输入排列的字符串："); 
	gets(str);
	Allarrange(str,0,strlen(str)-1);
	return 0;
}

