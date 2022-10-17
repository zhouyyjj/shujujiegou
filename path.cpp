//ͼ�ı���
#include<stdio.h>
#include<stdlib.h> 
#define max 20
//�߱�ڵ� 
typedef struct node{
	int adjvex;
	struct node *next; 
}eNode;
//ͷ�ڵ�
typedef struct headnode{
	char vertex;
	eNode *firstedge;
}hNode; 
//�ڽӱ�
typedef struct{
	hNode adjlist[max];
	int n,e;   //������������ 
}linkG; 

//�������ڽӱ� 
linkG *creat(linkG *g,int c) //cΪ0��ʾ����ͼ 
{
	int i,j,k;
	eNode *s;
	int n1,e1;
	char ch;
	g=(linkG *)malloc(sizeof(linkG));
	printf("�����붥����������: ");
	scanf("%d%d",&n1,&e1);
	g->n=n1;g->e=e1;
	printf("�����붥����Ϣ��");
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
		printf("������ԣ�i,j��: ");
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

int visited[max]; //����Ƿ���� 

//������ȱ���DFS
void dfs(linkG *g,int i) //����i
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

//������ȱ���BFS
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

//������ 
int main()
{
	linkG *g;
	g=creat(g,0);
	printf("DFS��");
	dfstravel(g);
	printf("\n");
	printf("BFS��");
	bfstravel(g);
	printf("\n");
	
	
}