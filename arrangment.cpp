//�õݹ�д��ȫ�����������ⷽ�� 
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
		printf("��%d������Ϊ:\t%s\n",s_i++,str);
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
	printf("���������е��ַ�����"); 
	gets(str);
	Allarrange(str,0,strlen(str)-1);
	return 0;
}

