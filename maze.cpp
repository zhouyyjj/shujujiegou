#include <iostream>
#define STACKSIZE 40
using namespace std;

typedef int Maze[STACKSIZE][STACKSIZE];//��һ����ά�������������� 
typedef struct{
 int x;
 int y;
}Pos;//�Թ�����λ������ 
typedef struct{
 int ord;//ͨ�����ڸ�·���ϵ���� 
 Pos coor;//ͨ�������Թ��е����� 
 int di;//��ͨ����������һͨ����ķ��� 
}ElemType;//ÿ��ͨ�������Ϣ 

typedef struct{
 ElemType data[STACKSIZE];
 int top;
}SeqStack;//��ջ�洢��ͨ���� 

Maze m;//�Թ����� 
int x, y;//�Թ������������� 
Pos bg, ed;//��㡢�յ������ 
int step = 1;//�������߹���ͨ�������Ŀ 

void Push(SeqStack &s, ElemType e)
{
 s.data[s.top] = e;
 s.top ++; 
} 
void Pop(SeqStack &s)
{
 s.top --;
}
void GetTop(SeqStack s, ElemType &e) 
{
 e = s.data[s.top - 1];
}

void Print()//��ӡ�Թ����� 
{
 for (int i = 0; i < x; i ++)
 {
  for (int j = 0; j < y; j ++)
   printf("%3d", m[i][j]);
  printf("\n");
 }
}
void Init()//��ʼ���Թ���ǽ����Ϊ0��ͨ��ֵ����Ϊ1 
{
 printf("�������Թ���������������������ǽ����");
 scanf("%d%d", &x, &y);
 
 for (int i = 0; i < x; i ++)
 {
  m[0][i] = 0;//��һ�� 
  m[x - 1][i] = 0;//���һ�� 
 }
 for (int i = 0; i < y; i ++)
 {
  m[i][0] = 0;//��һ�� 
  m[i][y - 1] = 0;//���һ�� 
 }
 for (int i = 1; i < x - 1; i ++)
  for (int j = 1; j < y - 1; j ++)
   m[i][j] = 1;//�Ƚ�����λ�þ���Ϊ1 
 
 printf("�������Թ���ǽ�����Ŀ��");
 int n;
 scanf("%d", &n);
 printf("�����������Թ���ÿ��ǽ������꣨��������������\n");
 int xt, yt;
 while (n --) 
 {
  scanf("%d%d", &xt, &yt);
  m[xt][yt] = 0;
 }
 printf("�Թ��Ľṹ���£�\n");
 Print();
 printf("��������ʼλ�õ����꣨��������������");
 scanf("%d%d", &bg.x, &bg.y); 
 printf("�������յ�λ�õ����꣨��������������");
 scanf("%d%d", &ed.x, &ed.y);
}

bool Pass(Pos p)//�жϸ������Ƿ����ͨ�� 
{
 if (m[p.x][p.y] == 1) return true;
 else return false;
}
void FootPrint(Pos p)
{
 m[p.x][p.y] = step;//��ʾ��ͨ������·���еĵڼ��������ڼ����� 
}
void NextPos(Pos &p, int di)//���ݵ�ǰλ�ü��ƶ����������һ��λ�����꣬��p�Ƶ���һ��λ�� 
{
 Pos dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//��������������������ʾ�ƶ����� 
 p.x += dir[di].x;//diΪ0��ʾ�����ƶ���1��ʾ�����ƶ���2��ʾ�����ƶ���3��ʾ�����ƶ���������������3Ϊ���ĳ��� 
 p.y += dir[di].y;
}
void MarkPrint(Pos p)
{
 m[p.x][p.y] = -1;//��־��ͨ�����Ǵ���ģ�����Ҳ���� 
}

int MazePath()//ע�����֣�ջ��Ԫ�ء�e��p��ջ��Ԫ��Ϊ�Ѿ��洢��·����Ԫ�飬eΪ��ǰ����ĵ�Ԫ�飬��e���������ջ��pΪe��ĳ�������һ����Ԫ�飬��p���ߣ���e�������Ϊp����p�����ߣ���һ������ 
{
 SeqStack S;//���·����ջ 
 S.top = 0;//��ʼ�� 
 ElemType e;
 Pos p = bg;
 do {
  if (Pass(p))//����÷������� 
  {
   FootPrint(p);//Ϊ�÷�����˳�� 
   e.ord = step;
   e.coor = p;
   e.di = 0;//Ĭ�������ƶ� 
   Push(S, e);//����ͨ�������Ϣ��ջ 
   if (p.x == ed.x && p.y == ed.y) return 1;//��������յ�ͽ��� 
   else 
   {
    NextPos(p, e.di);//�ƶ�����һ��λ�� 
    step ++;//����+1
   } 
  }
  else//�÷��鲻���� 
  {
   if (S.top > 0)//��·����û���˻ص���㣨�����·���л���ͨ���飩 
   {
    Pop(S);//������в�ͨ��ͨ���飨�洢���ƶ�������󣩴�ջ��ɾ������e��û�б䣬ֻ��e����ջ���� 
    step --;
    while (e.di == 3 && S.top > 0)//���ǰһ��λ�ñ�ǵ�Ϊ���һ������˵����ͨ�������в�ͨ�� 
    {
     MarkPrint(e.coor);//��ǰ��e�Ѿ���ȷ�˲����У���ʱ��eҲ�Ѳ���ջ�ڣ�S.data[S.top]�� 
     GetTop(S, e);//ȡ��һ����λ������� 
     Pop(S);//e�ֲ���ջ���� 
     step --;
    }
    if (e.di < 3)
    {
     e.di ++;//������һ������ 
     Push(S, e);//�����޸��˷���֮���ͨ���� 
     step ++;
     p = e.coor;//pָ��e 
     NextPos(p, e.di);//���·����Ƶ���һ��λ�� 
    }
   }
  }
 } while (S.top > 0);//ֻҪջ��Ϊ�վ�һֱѭ����ȥ 
 return 0;
}

int main()
{
 Init();
 if (MazePath())
 {
  printf("һ��·��Ϊ��\n");
  Print();
 }
 else printf("���Թ��޽�");
 return 0;
}
