#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define CHUNKSIZE 80

typedef struct 
{
	char *ch;
	int length;
}HString;


int StrAssign(HString &T,char *chars)//生成一个其值等于串常量chars的T 
{
int i,n;char *c;
	for(i=0,c=chars;*c;++i,++c);
	if(!i)
	{
		T.ch=NULL;
		T.length=0;
	}
	else
	{
		if(!(T.ch=(char *)malloc(i*sizeof(char))))
			return -1;
		for(n=0;n<=i-1;n++)
		{
			T.ch[n]=chars[n];
			T.length=i;
		}
	}
	return 1;
}

 int SubString(HString &Sub,HString S,int pos,int len)//求子串 
 {
 	int n; 
 	if(pos<0||pos>S.length||len<0||len>S.length-pos+1)
 	{
 		 		return 0;
	 }
//	if(Sub.ch) free(Sub.ch);
	if(!len)
		{
			Sub.ch=NULL;
			Sub.length=0;
		 } 
	else
		{
			Sub.ch=(char *)	malloc(len * sizeof(char));
			for(int n=0;n<=len-1;n++)
			{
				Sub.ch[n]=S.ch[pos+n-1];
			}
			Sub.length=len;
		}
	return 1;
 }

 int StrCompare(HString S,HString T)//若S>T，则返回值>0; 若S=T，则返回值0；若S<T，则返回值<0 
 {
 	for(int i=0;i<S.length&&i<T.length;i++)
 	{
 		if(S.ch[i]!=T.ch[i])
 			return S.ch[i]-T.ch[i];
		else
			  return S.length-T.length;
	 }	
 }


int Index(HString S,HString T,int pos)
{
	int i=pos,j=0;
	while(i<S.length&&j<T.length)
	{
		if(S.ch[i]==T.ch[j])
		{
			++i;++j;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
		
	}
	if(j>=T.length) return i-T.length;
	else return 0;
}


int StrLength(HString T)//求串长 
{
	return T.length;
 } 


void StrPrint(HString T)
{
	int i;
	for(i=0;i<T.length;i++)
	{
		printf("%c",T.ch[i]);
	}
} 

void Show()
{
	printf("请输入想选择的指令:\n");
	printf("1.显示串\n");
	printf("2.显示串长\n");
	printf("3.两串做比较\n");
	printf("4.求子串\n");
	printf("5.定位\n");
	printf("0.退出\n");
	printf("-------------------\n");
}

int main()
{
	int n;
	Show();	
	scanf("%d",&n);	
	char s[15]="qwertasdfzxc";		
	HString S;
	StrAssign(S,s);	
	char t[5]="asdf";
	HString T;
	StrAssign(T,t);	
	HString Sub;
	while(n!=0)
	{
		switch(n)
		{
			case 1:	
					printf("第一个串为：%s\n",S.ch);
					printf("第二个串为：%s\n",T.ch);break;
			case 2: printf("第一条串长：%d\n",StrLength(S));
					printf("第二条串长：%d\n",StrLength(T));break;
			case 3: 	int n ;
						n=StrCompare(S,T);
						if(n!=0)
							if(n>0)
								printf("前面长\n");
							else
								printf("后面长\n");
						else
							printf("一样长\n");break; 
			case 4:printf("请输入你想取的位置及长度:\t");
					int j,l;
					scanf("%d %d",&j,&l);
					SubString(Sub,S,j,l);
					StrPrint(Sub);break;
			case 5: int k;
					printf("输入查询的位置:\n");
					scanf("%d",&k);
					int x=Index(S,T,k);
				    printf("定位到的位置为：%d",x);break;
		 } 
			printf("\n");
			Show();
			scanf("%d", &n);
		}
	return 0;
 } 




