#include<stdio.h>
#define MAX_VERTEX_NUM 20  //最大顶点数 
/*
*采用邻接表存储无向图 
*无论哪种存储结构，都需要想办法来构造结构存储 顶点集和边集 
*/ 
typedef struct{
 char vexs[MAX_VERTEX_NUM]; //一维数组存储顶点集 
 //int vexs[] = {1,2,3,4,5}; //根据顶点的类型来选择存储顶点的数组类型，复杂的顶点可以定义结构体来存储 
 int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接表存储边集 
 int vexnum,arcnum;  //图中顶点数和弧的数量 
} MGraph; 

/*定位顶点在图中的位置*/
int LocateVex(MGraph G,char vex){
 for(int i=0;i<G.vexnum;i++){
  if(G.vexs[i] == vex)
   return i;
 }
 return -1;
} 

/*创建图*/
void CreateGraph(MGraph &G) {
 /*初始化图的基本信息*/
 //输入图中顶点 
 printf("请输入图中顶点数量：");
 scanf("%d",&G.vexnum);
 for(int i=0;i<G.vexnum;i++){
  printf("请输入第%d个顶点:",i+1);
  scanf(" %c",&G.vexs[i]);
 }
 //输入图中的边 
 printf("请输入图中边的数量：");
 scanf("%d",&G.arcnum);
 //初始化邻接矩阵
 for(int i=0;i<G.vexnum;i++){
  for(int j=0;j<G.vexnum;j++){
   G.AdjMatrix[i][j] = 0;  //初始化时顶点间都不存在边 
  }
 } 
 //构造邻接矩阵
 for(int k=0;k<G.arcnum;k++) {
  char v1,v2;
  printf("请输入第%d条边（如：AB):",k+1);
  scanf(" %c%c",&v1,&v2);
  int i = LocateVex(G,v1);  //获取边第一个顶点在图中的位置 
  int j = LocateVex(G,v2);  //获取边第二个顶点在图中的位置 
  G.AdjMatrix[i][j] = 1;  //存在边就设置为1 
  G.AdjMatrix[j][i] = 1;  //由于是无向图所以相反反向也存在边 
 }
 printf("图创建成功！\n");  
}
/*
*G：不为空的图
*v：需要访问的顶点 
*/
void VisitFun(MGraph G,int v){
 printf("%c ",G.vexs[v]);
} 
/*
*G：不为空的图
*v：其实访问的顶点 
*/
void DFS(MGraph G,int *visited,int v){
 visited[v] = 1;  //将访问的结点设置为1 
 //访问这个这个顶点
 VisitFun(G,v);
 //寻找与这个顶点相邻的其他结点 
 for(int k=0;k<G.vexnum;k++){
  if(G.AdjMatrix[v][k]==1){  //有边 
   if(visited[k]==0){  //且该顶点没有被访问过 
    //那么久递归调用DFS去遍历与这个边邻接的顶点 
    DFS(G,visited,k);
   } 
  }
 }
}
main() {
 int visited[MAX_VERTEX_NUM];
 //初始化访问标记数组 顶点访问则设置为1 
 for(int i=0;i<MAX_VERTEX_NUM;i++){
  visited[i] = 0;
 }
 MGraph G;
 CreateGraph(G);
 DFS(G,visited,0);
}
