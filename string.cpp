//�õݹ�д�ַ������õ��㷨 
#include<stdio.h>

int my_strlen(char *str)  
{
	if(*str == '\0')    //��������ַ�����û���ַ�
		return 0;		//�ַ�������Ϊ0
	else
		return 1+ my_strlen(str+1);	/*���õݹ飬ÿ�ݹ�һ��
	���ȼ�1��ֱ����������'\0'ʱ�����ݹ�*/
} 
/*******�ݹ鷽ʽд�ַ�����ת*******/
void reverse_string(char *string)
{
	int len = my_strlen(string);//����������ַ������Ⱥ���;
	if(len <= 1)	//���ַ�������С�ڵ���1ʱ����ִ�У�
		return ;
	else
	{
		char temp = string[0];	 //����һ���ַ���ֵ������temp��;
		string[0] = string[len-1];//�����һ���ַ�������һ���ַ�;
		string[len-1] = '\0';	//�����һ���ַ������ݸ�Ϊ'\0';
		reverse_string(string+1);//�ݹ������һ�η�ת��
		string[len-1] = temp;	//��temp������ǰ�����һ���ַ���
	}
}
 
int main()
{
	char ch[] = "abcdefghijklmno";
	reverse_string(ch);
	printf("%s ",ch);
	printf("\n");
	getchar();	//���壻
	return 0;
}
