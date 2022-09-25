#include <iostream>
#define STACKSIZE 40
using namespace std;

typedef int Maze[STACKSIZE][STACKSIZE];//给一个二维数组类型重命名 
typedef struct{
 int x;
 int y;
}Pos;//迷宫坐标位置类型 
typedef struct{
 int ord;//通道块在该路径上的序号 
 Pos coor;//通道块在迷宫中的坐标 
 int di;//此通道块走向下一通道块的方向 
}ElemType;//每个通道块的信息 

typedef struct{
 ElemType data[STACKSIZE];
 int top;
}SeqStack;//用栈存储各通道块 

Maze m;//迷宫数组 
int x, y;//迷宫的行数、列数 
Pos bg, ed;//起点、终点的坐标 
int step = 1;//计数已走过的通道块的数目 

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

void Print()//打印迷宫矩阵 
{
 for (int i = 0; i < x; i ++)
 {
  for (int j = 0; j < y; j ++)
   printf("%3d", m[i][j]);
  printf("\n");
 }
}
void Init()//初始化迷宫，墙设置为0，通道值设置为1 
{
 printf("请输入迷宫的行数、列数（包括外墙）：");
 scanf("%d%d", &x, &y);
 
 for (int i = 0; i < x; i ++)
 {
  m[0][i] = 0;//第一行 
  m[x - 1][i] = 0;//最后一行 
 }
 for (int i = 0; i < y; i ++)
 {
  m[i][0] = 0;//第一列 
  m[i][y - 1] = 0;//最后一列 
 }
 for (int i = 1; i < x - 1; i ++)
  for (int j = 1; j < y - 1; j ++)
   m[i][j] = 1;//先将其余位置均赋为1 
 
 printf("请输入迷宫内墙块的数目：");
 int n;
 scanf("%d", &n);
 printf("请依次输入迷宫内每个墙块的坐标（行数，列数）：\n");
 int xt, yt;
 while (n --) 
 {
  scanf("%d%d", &xt, &yt);
  m[xt][yt] = 0;
 }
 printf("迷宫的结构如下：\n");
 Print();
 printf("请输入起始位置的坐标（行数、列数）：");
 scanf("%d%d", &bg.x, &bg.y); 
 printf("请输入终点位置的坐标（行数、列数）：");
 scanf("%d%d", &ed.x, &ed.y);
}

bool Pass(Pos p)//判断该坐标是否可以通过 
{
 if (m[p.x][p.y] == 1) return true;
 else return false;
}
void FootPrint(Pos p)
{
 m[p.x][p.y] = step;//表示该通道块是路径中的第几个（即第几步） 
}
void NextPos(Pos &p, int di)//根据当前位置及移动方向，求得下一个位置坐标，即p移到下一个位置 
{
 Pos dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//用行增量、列增量来表示移动方向 
 p.x += dir[di].x;//di为0表示向右移动，1表示向下移动，2表示向左移动，3表示向上移动（东南西北），3为最后的尝试 
 p.y += dir[di].y;
}
void MarkPrint(Pos p)
{
 m[p.x][p.y] = -1;//标志该通道块是错误的，走了也白走 
}

int MazePath()//注意区分：栈中元素、e、p。栈中元素为已经存储的路径单元块，e为当前处理的单元块，若e可走则存入栈，p为e沿某方向的下一个单元块，若p可走，则e的坐标变为p；若p不可走，则换一个方向 
{
 SeqStack S;//存放路径的栈 
 S.top = 0;//初始化 
 ElemType e;
 Pos p = bg;
 do {
  if (Pass(p))//如果该方块能走 
  {
   FootPrint(p);//为该方块标记顺序 
   e.ord = step;
   e.coor = p;
   e.di = 0;//默认向右移动 
   Push(S, e);//将该通道块的信息入栈 
   if (p.x == ed.x && p.y == ed.y) return 1;//如果到达终点就结束 
   else 
   {
    NextPos(p, e.di);//移动到下一个位置 
    step ++;//步数+1
   } 
  }
  else//该方块不能走 
  {
   if (S.top > 0)//该路径还没有退回到起点（保存的路径中还有通道块） 
   {
    Pop(S);//将这个行不通的通道块（存储的移动方向错误）从栈中删除，但e并没有变，只是e不在栈内了 
    step --;
    while (e.di == 3 && S.top > 0)//如果前一个位置标记的为最后一个方向，说明该通道块是行不通的 
    {
     MarkPrint(e.coor);//当前的e已经明确了不可行，此时的e也已不在栈内（S.data[S.top]） 
     GetTop(S, e);//取上一个单位块的数据 
     Pop(S);//e又不在栈内了 
     step --;
    }
    if (e.di < 3)
    {
     e.di ++;//尝试下一个方向 
     Push(S, e);//存入修改了方向之后的通道块 
     step ++;
     p = e.coor;//p指回e 
     NextPos(p, e.di);//以新方向移到下一个位置 
    }
   }
  }
 } while (S.top > 0);//只要栈不为空就一直循环下去 
 return 0;
}

int main()
{
 Init();
 if (MazePath())
 {
  printf("一条路径为：\n");
  Print();
 }
 else printf("该迷宫无解");
 return 0;
}
