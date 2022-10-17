//图的遍历
#include<stdio.h>
#include<stdlib.h> 
#define max 20
//边表节点 
typedef struct node{
	int adjvex;
	struct node *next; 
}eNode;
//头节点
typedef struct headnode{
	char vertex;
	eNode *firstedge;
}hNode; 
//邻接表
typedef struct{
	hNode adjlist[max];
	int n,e;   //顶点数，边数 
}linkG; 

//创建（邻接表） 
linkG *creat(linkG *g,int c) //c为0表示无向图 
{
	int i,j,k;
	eNode *s;
	int n1,e1;
	char ch;
	g=(linkG *)malloc(sizeof(linkG));
	printf("请输入顶点数及边数: ");
	scanf("%d%d",&n1,&e1);
	g->n=n1;g->e=e1;
	printf("请输入顶点信息：");
	getchar();
	for(i=0;i<n1;i++)
	{
		scanf("%c",&ch);
		g->adjlist[i].vertex=ch;
		g->adjlist[i].firstedge=NULL;
	} 
	getchar();
	int i1,j1;
	for(k=0;k<e1;k++)
	{
		printf("请输入对（i,j）: ");
		scanf("%d%d",&i1,&j1);
		s=(eNode *)malloc(sizeof(eNode));
		s->adjvex=j1;
		s->next=g->adjlist[i1].firstedge;
		g->adjlist[i1].firstedge=s;
		if(c==0)
		{
			s=(eNode *)malloc(sizeof(eNode));
			s->adjvex=i1;
			s->next=g->adjlist[j1].firstedge;
			g->adjlist[j1].firstedge=s;
		} 
	}
	return g;
}

int visited[max]; //标记是否访问 

//深度优先遍历DFS
void dfs(linkG *g,int i) //顶点i
{
	eNode *p;
	printf("%c ",g->adjlist[i].vertex);
	visited[i]=1;
	p=g->adjlist[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			dfs(g,p->adjvex);
		p=p->next;
	}
	
}

void dfstravel(linkG *g)
{
	int i;
	for(i=0;i<g->n;i++)
		visited[i]=0;
	for(i=0;i<g->n;i++)
		if(!visited[i])
			dfs(g,i);
} 

//广度优先遍历BFS
void bfs(linkG *g,int i) 
{
	int j;
	eNode *p;
	int q[max],front,rear;
	front=rear=0;
	printf("%c ",g->adjlist[i].vertex);
	visited[i]=1;
	q[rear++]=i;
	while(rear>front)
	{
		j=q[front++];
		p=g->adjlist[j].firstedge;
		while(p)
		{
			if(visited[p->adjvex]==0)
			{
				printf("%c ",g->adjlist[p->adjvex].vertex);
				q[rear++]=p->adjvex;
				visited[p->adjvex]=1;
			}
			p=p->next;
		}
	}
}

void bfstravel(linkG *g)
{
	int i,count=0;
	for(i=0;i<g->n;i++)
		visited[i]=0;
	for(i=0;i<g->n;i++)
		if(!visited[i])
			bfs(g,i);
}

//主函数 
int main()
{
	linkG *g;
	g=creat(g,0);
	printf("DFS：");
	dfstravel(g);
	printf("\n");
	printf("BFS：");
	bfstravel(g);
	printf("\n");
	
	
}