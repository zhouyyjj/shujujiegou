//д���������и�Ԫ��֮�͵��㷨
 
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
	scanf("%d",&len);//���ñ䳤���飬�������������ĳ���

	int a[len];
	printf("Enter the number:");
	for(i=0;i<len;i++){
		scanf("%d",&a[i]);
    }//��������ľ�������
	
	int sumall;	
	sumall=sum(a,len);
	printf("the sum of your number is %d",sumall);//��Ͳ����
}

 
