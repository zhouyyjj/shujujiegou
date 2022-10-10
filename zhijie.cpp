//以单链表为存储的直接插入排序
#include"stdio.h" 
#include"malloc.h"

typedef struct node
{
 int data;
 struct node *next;
}LinkList;

void InsertSortSingleLink( int arr[], int length );

int main()
{
 int arr[] = { 4, 3, 5, 6, 1, 2 };
 int length = 6;
 int i;
 printf( " initial array: " ) ;
 for( i = 0; i < length; i++ )
 {
  printf( "%5d", arr[i] );
 }
 printf( "\n" );
 
 InsertSortSingleLink( arr, length );
 printf( " sort result  : " ) ;
 for( i = 0; i < length; i++ )
 {
  printf( "%5d", arr[i] );
 }
 printf( "\n" );
 return 0;
}

//基于单链表的直接插入排序算法 
void InsertSortSingleLink( int arr[], int length ) 
{
 LinkList *h, *p, *q, *s;
 int i;
 //h表示单链表的表头节点 
 h = ( LinkList * )malloc( sizeof(LinkList) );
 //s是存储每一个新加入元素的节点 
 s = ( LinkList * )malloc( sizeof(LinkList) );
 s->data = arr[0];
 s->next = NULL;
 h->next = s;
 for( i = 1; i < length; i++ )
 {
  p = h;
  q = p->next;
  s = ( LinkList * )malloc( sizeof(LinkList) );
  s->data = arr[i];
  while( s->data > q->data && q->next != NULL)
  {
   p = q;
   q = q->next;
  }
  if( q->next == NULL && s->data > q->data )
  {
   s->next = NULL;
   q->next = s;
  }
  else 
  {
   p->next = s;
   s->next = q;
  }
 }
 p = h->next;
 for( i = 0; i < length; i++ )
 {
  arr[i] = p->data;
  p = p->next;
 }
 
 //释放单链表 
 p = h;
 q = p->next;
 while( p->next != NULL ) 
 {
  free(p);
  p = q;
  q = q->next;
 }
 free(q);
}