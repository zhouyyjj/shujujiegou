#include<stdio.h>
#include<stdlib.h>
 
//���ַ�����
int search(int a[],int length, int x)       //a���������飬xΪ����Ԫ��
{
 int i = 0, j = 0;
 int detection = -1;//��־λ
 int top = length - 1; // ������ұ߽�
 int middle = 0;  //�м�ֵ���±�
 int low = 0; //�������߽�
 
 while (low <= top)
 {
  middle = (low + top) / 2;
  if (a[middle] == x)
  {
   detection = middle;
  }
  if (a[middle] < x)
  {
   low = middle + 1;
  }
  else
  {
   top = middle - 1;
  }
 }
 if (detection == -1)
 {
  //���xû�������У���ִ���꣬topΪ�ף�lowΪ����x���м䡣
  i = top;
  j = low;
 }
 else
 {
  i = detection;
  j = i;
 }
 
 printf("i��ֵΪ��%d\nj��ֵΪ��%d\n",i,j);
 return 0;
}
 
void main()
{
 int arr[] = { 1,2,3,4,5,6,7,8,55,60,100 };
 int length = sizeof(arr) / sizeof(int);
 search(arr,length,2);
 system("pause");
}