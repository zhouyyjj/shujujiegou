//写出求数组中各元素之和的算法
 
#include<stdio.h>
#include<string.h>

int sum(int a[],int l,int h)
{
	if(l==h)
	returna[l];
	else
	return(sum(a,l,h-1)+a(h))
 } 
 
 
int main()
{
	int i,len;
	printf("Enter the len:");
	scanf("%d",&len);//利用变长数组，先输入求和数组的长度

	int a[len];
	printf("Enter the number:");
	for(i=0;i<len;i++){
		scanf("%d",&a[i]);
    }//输入数组的具体数字
	
	int sumall;	
	sumall=sum(a,len);
	printf("the sum of your number is %d",sumall);//求和并输出
}

 
