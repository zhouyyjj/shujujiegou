//任意输入十个整数，在输入一个整数，利用“折半查找法”验证该数字是否在该数列中 
#include"stdio.h"
int main()
{
	void sort(int a[10],int m);//排序函数 
	void search(int a[10],int n);//查找函数 
	int a[10],n,i;
	printf("请输入10个整数：\n");
	for(i=0;i<10;i++)
	   scanf("%d",&a[i]);
	printf("请输入你想要查找的数字：\n");
	scanf("%d",&n);
	sort(a,10);
	search(a,n);
	return 0;
}
void sort(int a[10],int m)//选择排序法 
{
	int i,j,k,temp;
	for(i=0;i<m-1;i++)
	{
		k=i;
		for(j=i+1;j<m;j++)
		{
			if(a[j]<a[k])
			  k=j;
		}
		temp=a[i];a[i]=a[k];a[k]=temp;
	}
	printf("排序后：\n");
	for(i=0;i<m;i++)
	   printf("%d ",a[i]);
	printf("\n");
}
void search(int a[10],int n)
{
	int low=0,high=9,mid,flag;//low,high分别为区间的左端点和右端点，mid为区间中间，flag存放逻辑值 
	while(low<=high)
	{
		mid=(low+high)/2;//折半 
		if(n==a[mid])
		{
		  flag=1;//如果区间中间值等于待查找值，则查找成功，flag值为 1,为真 
		  break;//找到，则终止循环 
	    }
		else
		   if(n<a[mid])//待查找值小于中间值，则在前一半区间内继续查找 
		     high=mid-1;//调整右端点 
		   else if(n>a[mid])//待查找值大于中间值，则在后一半区间内继续查找 
		     low=mid+1;//调整左端点 
	}
	if(flag==1)//如果找到 
	  printf("found! 序号为：%d\n",mid+1);//mid为待查找值在数组中的下标，而mid+1才是人数数习惯中的下标 
	else
	  printf("NO found !\n");
}



