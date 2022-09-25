#include "stdio.h"
#include "LinkList.h"
#include "malloc.h"

/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ������յ�����                                                          �U
�U��ڲ������ޣ�                                                              �U
�U����ֵ���������ͷָ�룬0������ʧ�ܣ���0��ɹ�                            �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
LinkList Create_LinkList(void)
{
	LinkList H;
	
	H = (LinkList)malloc(sizeof(LNode));
	if (H)  /*ȷ�ϴ���ͷ��㴴���Ƿ�ɹ������ɹ����޸ĵ�����ͷ����ָ����Ϊ0����ձ�*/
		H->next = NULL;
	return H;
}

/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ����ٵ�����                                                            �U
�U��ڲ������ޣ�                                                              �U
�U����ֵ���������ͷָ�룬0������ʧ�ܣ���0��ɹ�                            �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
void Destroy_LinkList(LinkList *H) 
{
	LinkList p, q;
	if (H==NULL || *H == NULL)
	{
		return;
	}
	else
	{
		p = *H;
		q = p;
		while(q != NULL)
		{
			q = p;
			p = p->next;
			free(q);
		}
	}
	*H = NULL;
}
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ��������                                                          �U
�U��ڲ�����������ͷָ��                                                      �U
�U����ֵ�����ڲ���������-1��ʾ����������                                  �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int Length_LinkList(LinkList H)
{
	LinkList p = H;  /*pָ��ͷ���*/
	int count = -1;  /*H��ͷ������Դӣ�1��ʼ*/

	while(p)
	{                /*p��ָ���ǵ� count + 1 �����*/  
		p = p->next;
		count ++;
	}/*while */
	return count;
}
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ����Ҳ���������Ų��ң�                                                �U
�U      �ӵ�����ĵ�һ��Ԫ�ؽ���� �жϵ�ǰ����Ƿ��ǵ�i�������ǣ��򷵻ظ�  �U
�U		����ָ�룬���������һ�����Ĳ��ң�ֱ�������Ϊֹ�� ��û�еڣ��   �U
�U		����򷵻ؿա����i=0����ͷָ�롣                                     �U
�U��ڲ�����������ͷָ��,�������                                             �U
�U����ֵ�����ڲ�����Ҫ���ҽ���ָ�룬NULL������i�������������           �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
LinkList Locate_LinkList_Pos(LinkList H, int i)
{
	LinkList p = H;
	int j = 0;

	while(p && j<i)
	{
		p = p->next;
		j++;
	}
	if (j!=i || !p)
	{
		printf("����i�������������");
		return NULL;
	}
	return p;
}
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ����Ҳ�������ֵ���ң��ڵ������в���ֵΪx�Ľ�㣩                       �U
�U      ������İ�ֵ�����������Ա���ڵ�����£�����ֵΪ��������Ԫ��          �U
�U		���ɹ��������״γ��ֵ�ֵΪ�����Ǹ�Ԫ�����ڽ���ָ��                  �U
�U		����δ�ҵ�ֵΪ��������Ԫ�أ�����NULL��ʾ����ʧ��                    �U
�U��ڲ�����������ͷָ��,����Ԫ��                                             �U
�U����ֵ�����ڲ������ҵ��󷵻���ָ�룬���򷵻�NULL                            �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	
	while(p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ��������                                                              �U
�U      ����������ָ�ڵ�����ĵ�i��λ��ǰ����һ��ֵΪx���½�㣬����          �U
�U		��i-1���ĺ������ֵΪx���½��                                      �U
�U��ڲ�����������ͷָ��,����λ�á�����Ԫ��                                   �U
�U���ز������ɹ���־��0���ɹ���1�ɹ�                                          �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int Insert_LinkList(LinkList H, int i, DataType x)
{
	LinkList p, q;
	
	p = Locate_LinkList_Pos(H, i-1);/*�ҵ�i-1������ַ*/
	if (!p)
	{
		printf("i����");
		return 0;
	}
	q =(LinkList)malloc(sizeof(LNode));
	if (!q)
	{
		printf("����ռ�ʧ��");
		return 0;
	}/*����ռ�ʧ�ܣ����ܲ���*/
	q->data = x;
	q->next = p->next;
	p->next = q;/*�½������ڵ�i-1�����ĺ���*/
	return 1;   /*����ɹ����򷵻�*/
}


/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U���ܣ�ɾ������                                                              �U
�U      ɾ��������ָɾ��������ĵ�i����㣬������i-1��Ԫ�ؽ���ָ����ָ��    �U
�U		��i+1Ԫ�ؽ��                                                         �U
�U��ڲ�����������ͷָ��,ɾ��Ԫ�����                                         �U
�U���ز������ɹ���־��0���ɹ���1�ɹ�                                          �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int Del_LinkList(LinkList H, int i)
{
	LinkList p, q;

	if (H == NULL || H->next == NULL)
	{
		printf("�������ڻ�ձ���ɾ��");
		return 0;
	}
	
	p = Locate_LinkList_Pos(H, i-1);/*�ҵ�i-1������ַ*/
	if (p == NULL || p->next == NULL) 
	{
		printf("����i����"); /*��i-1����㲻����*/
		return 0;
	}
	q = p->next;        /*qָ���i�����*/
	p->next = q->next;  /*��������ɾ��*/
	free(q);            /*�ͷ�*s */
	return 1;  
}


void reverse_LinkList(LinkList H)
{
	LinkList p, q;


	if(H == NULL || H->next == NULL)
	{
		printf("�������ڻ�����Ϊ��");
		return;
	}
	p = H->next;      //pָ���һ�����ݽ��
	H->next = NULL;   //��ԭ������Ϊ�ձ�
	while(p)          //�ӵ�һ����㿪ʼ������ȡ��ÿ����㣬���뵽H������ĵ�һ��λ��
	{                 
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q;
	}
}


void print_LinkList(LinkList H)
{
	LinkList p;
	
	if(H == NULL || H->next == NULL)
	{
		printf("�������ڻ�����Ϊ��");
		return;
	}

	printf("����������Ϊ��\n");
	p = H->next;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void Inter_Sec(LinkList A, LinkList B)
{
	LinkList p, pre;

	pre = A; 
	p = A->next;

	while(p)
	{

		if (Locate_LinkList_Value(B, p->data) == NULL)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void Merge_sec(LinkList A, LinkList B)
{
	LinkList p;

	p = B->next;

	while(p)
	{
		if (Locate_LinkList_Value(A, p->data) == NULL)
		{
			Insert_LinkList(A, 1, p->data);
		}
		p = p->next;
	}
}

int josephus_LinkList(LinkList  josephus_Link, int s, int m) 
{   /*����ֵ��1��ʾ�ɹ���0��ʾ����û��Ԫ��*/
    LinkList p,pre; int count; /*pָ��ǰ��㣬preָ����ǰ�����*/    
    if (!josephus_Link) 
    {   
		printf("������Ԫ��"); 
		return (0); 
    }
    p= josephus_Link;
    for(count=1;count<s;count++)  /*���ҵ�s����㣬��pָ���s�����*/
		p=p->next;
	printf("���Լɪ�����У�");
	while ( p!=p->next) 
	{ /*�������һ��Ԫ��,��� n-1��Ԫ�ظ����*/   
		//pre=p->next;
		//while(pre->next != p)  pre = pre->next;
		for(count=1;count<m;count++) 
		{     
			pre=p; 
			p=p->next; 
		}
		printf("%d\t", p->data);    
		pre->next=p->next;
		free(p);   
		p=pre->next;
	}/*while*/
	printf("%d\t",p->data); /*������һ��Ԫ�ظ����*/
	free(p);    
	return 1; 
}
