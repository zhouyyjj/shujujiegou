//�۰���ҷ�
#include<stdio.h>

void zb(int key,int a[],int n)//key��ʾҪ�ҵ�����a��ʾ���飬n��ʾ����Ԫ�ظ��� 
{
	int i,high,low,mid;
	int count1=0,count=0;
	low=0;
	high=n-1;
	while(high>=low)//��֤���±겻С�����±� 
	{ 
		count++;
		mid=(high+low)/2;//�ܵ���˵������м�λ���൱�ڰ��м�λ���Ƶ���key�Ǹ����������midӦ�ô���ѭ������ 
		if(key<a[mid])//˵��key��a��mid�������� ,��ô���ұߵ�high�±�Ϳ������±�mid�����������һ����λ��
			high=mid-1;
		else if(key>a[mid])//˵��key��a��mid�����Ұ�� ,��ô����ߵ�low�±�Ϳ������±�mid���������ҽ�һ����λ�� 
			low=mid+1;
		if(key==a[mid])
		{
			printf("Ԫ���ҵ��ˣ�����\nһ��������%d��\n������a[%d]λ����\na[%d]=%d\n",count,mid,mid,key);
			count1++;
			break;
		}
	}
	if(count1==0)
		printf("Ԫ�ز����ڣ�����\n");
}

int main ()
{
	int key,n,a[100];
	int i;
	void zb(int key,int a[],int n);//�������庯�� 
	printf("����������Ԫ�ظ�����\n");
	scanf("%d",&n);
	printf("�����루��С������������Ԫ�أ�\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("������Ҫ���ҵ�����\n");
	scanf("%d",&key);
	zb(key,a,n);
	printf("\n");
	return 0;
}