
 
//����
void Swap(int* p1, int* p2)
{
 int tmp = *p1;
 *p1 = *p2;
 *p2 = tmp;
}
 
//���µ���
void AdjustDown(int* a, int n, int parent)
{
 int child = parent * 2 + 1;
 while (child < n)
 {
  //ѡ�����Һ����е�С���ӣ�����ѾͰѵڶ���<�ĳ�>
  if (child + 1 < n && a[child + 1] < a[child])
  {
   child++;
  }
  //С���ӱȸ���С������С���Ӻ͸��ף�����ѾͰ�<�ĳ�>
  if (a[child] < a[parent])
  {
   Swap(&a[child], &a[parent]);
   //�������׺ͺ��Ӻ󣬿��ܵ��²�����ѵĶ��壬��Ҫ��������
   parent = child;
   child = parent * 2 + 1;
  }
  //С���ӱȸ��״�����whileѭ����������һ�ε����µ���������һֱ��ѭ������ʲô������
  else
  {
   break;
  }
 }
}
 
//���ϵ���
void AdjustUp(int* a, int child)
{
 int parent = (child - 1) / 2;
 while (child > 0)
 {
  if (a[child] > a[parent])
  {
   Swap(&a[child], &a[parent]);
   child = parent;
   parent = (child - 1) / 2;
  }
  else
  {
   break;
  }
 }
}
 
//��ʼ��
void HeapInit(HP* php, HPDataType* a, int n)
{
 assert(php);
 php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
 if (php->a == NULL)
 {
  printf("malloc fail\n");
  exit(-1);
 }
 
 memcpy(php->a, a, sizeof(HPDataType) * n);
 php->size = n;
 php->capacity = n;
 
 //����
 for (int i = (n - 1 - 1) / 2; i >= 0; i--)
 {
  AdjustDown(php->a, php->size, i);
 }
}
 
//����
void HeapDestroy(HP* php)
{
 assert(php);
 free(php->a);
 php->a = NULL;
 php->size = 0;
 php->capacity = 0;
}
 
//�ѵĲ���
void HeapPush(HP* php, HPDataType x)
{
 assert(php);
 
 //��������Ҫ����
 if (php->size == php->capacity)
 {
  HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * 2 * php->capacity);
  if (tmp == NULL)
  {
   printf("realloc fail\n");
   exit(-1);
  }
  php->a = tmp;
  php->capacity *= 2;
 }
 
 php->a[php->size] = x;
 php->size++;
 
 AdjustUp(php->a, php->size - 1);
}
 
//�ѵ�ɾ��
void HeapPop(HP* php)
{
 assert(php);
 assert(php->size > 0);
 
 //���Ѷ�Ԫ�غ����һ��Ҷ�ӽ����н���
 Swap(&php->a[0], &php->a[php->size - 1]);
 php->size--;
 
 //�ԶѶ�Ԫ�ؽ������µ���
 AdjustDown(php->a, php->size, 0);
 
}
 
//���ضѶ�Ԫ��
HPDataType HeapTop(HP* php)
{
 assert(php);
 return php->a[0];
}
 
//�ѵĴ�С
int HeapSize(HP* php)
{
 assert(php);
 return php->size;
}
 
//���п�
bool HeapEmpty(HP* php)
{
 assert(php);
 return php->size == 0;
}

//��ӡ
void HeapPrint(HP* php)
{
 for (int i = 0; i < php->size; i++)
 {
  printf("%d ", php->a[i]);
 }
 printf("\n");
 
 int num = 0;
 int levelSize = 1;
 for (int i = 0; i < php->size; i++)
 {
  printf("%d ", php->a[i]);
  num++;
  if (num == levelSize)
  {
   printf("\n");
   levelSize *= 2;
   num = 0;
   
  }
  
 }
 
 printf("\n\n");
}
 

