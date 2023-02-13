
 
//交换
void Swap(int* p1, int* p2)
{
 int tmp = *p1;
 *p1 = *p2;
 *p2 = tmp;
}
 
//向下调整
void AdjustDown(int* a, int n, int parent)
{
 int child = parent * 2 + 1;
 while (child < n)
 {
  //选出左右孩子中的小孩子，建大堆就把第二个<改成>
  if (child + 1 < n && a[child + 1] < a[child])
  {
   child++;
  }
  //小孩子比父亲小，交换小孩子和父亲，建大堆就把<改成>
  if (a[child] < a[parent])
  {
   Swap(&a[child], &a[parent]);
   //交换父亲和孩子后，可能导致不满足堆的定义，需要继续调整
   parent = child;
   child = parent * 2 + 1;
  }
  //小孩子比父亲大，跳出while循环，结束这一次的向下调整，否则一直死循环并且什么都不做
  else
  {
   break;
  }
 }
}
 
//向上调整
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
 
//初始化
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
 
 //建堆
 for (int i = (n - 1 - 1) / 2; i >= 0; i--)
 {
  AdjustDown(php->a, php->size, i);
 }
}
 
//销毁
void HeapDestroy(HP* php)
{
 assert(php);
 free(php->a);
 php->a = NULL;
 php->size = 0;
 php->capacity = 0;
}
 
//堆的插入
void HeapPush(HP* php, HPDataType x)
{
 assert(php);
 
 //满了则需要增容
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
 
//堆的删除
void HeapPop(HP* php)
{
 assert(php);
 assert(php->size > 0);
 
 //将堆顶元素和最后一个叶子结点进行交换
 Swap(&php->a[0], &php->a[php->size - 1]);
 php->size--;
 
 //对堆顶元素进行向下调整
 AdjustDown(php->a, php->size, 0);
 
}
 
//返回堆顶元素
HPDataType HeapTop(HP* php)
{
 assert(php);
 return php->a[0];
}
 
//堆的大小
int HeapSize(HP* php)
{
 assert(php);
 return php->size;
}
 
//堆判空
bool HeapEmpty(HP* php)
{
 assert(php);
 return php->size == 0;
}

//打印
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
 

