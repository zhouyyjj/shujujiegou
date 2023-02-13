#include <stdio.h>
#define MAXINT (0X7FFF7FFF)
#define VER_LEN (101)
typedef struct {
    int cost;
    int flag;
    int pre;
} vertex;
//定义
int Graph[VER_LEN][VER_LEN];
vertex Vertex[VER_LEN];

// 初始化图的数据，初始化为两点之间互不连接
void init_graph(int length) {
    int i, j;
    for(i = 1; i <= length; i++)
      for(j = 1; j <= length; j++)
        Graph[i][j] = MAXINT;
}

void prim(int start, int length) {
    int i,j;
    int min_cost, min_v;

    // 根据初始顶点start，初始为各顶点的相关信息
    // cost表示权重，flag表示是否已经加入最小生成树，pre表示其parent节点
    for(i = 1; i <= length; i++) {
        Vertex[i].cost = Graph[start][i];
        Vertex[i].flag = 0;
        Vertex[i].pre = start;
    }

    // 将初始顶点加入到最小生成树中
    Vertex[start].cost = 0;
    Vertex[start].flag = 1;

    for(i = 2; i <= length; i++) {
        min_cost = MAXINT;
        // 找出cost最小的边
        for(j = 1; j <= length; j++) {
            if(Vertex[j].flag == 0 && Vertex[j].cost < min_cost) {
                min_cost = Vertex[j].cost;
                min_v = j;
            }
        }

        // 将上面找出来的cost最小的边的顶点加入到最小生成树中
        Vertex[min_v].flag = 1;

        // 根据上面新加入到最小生成树的顶点调整各顶点的cost值
        for(j = 1; j <= length; j++) {
            if(Vertex[j].flag == 0 && Vertex[j].cost > Graph[min_v][j]) {
                Vertex[j].cost = Graph[min_v][j];
                Vertex[j].pre = min_v;
            }
        }
    }
}

int main() {
    int i;
    int ver_num, edge_num;
    int edge_u, edge_v, cost;
	printf("姓名：周杨洁\t学号：21404070\t班级：计212\t\n");

    printf("输入顶点数和边数：\n");
    scanf("%d %d", &ver_num, &edge_num);
    init_graph(ver_num);
    
    printf("输入图的信息：\n");
    for(i = 1; i <= edge_num; i++) {
        scanf("%d %d %d", &edge_u, &edge_v, &cost);
        Graph[edge_u][edge_v] = cost;
        Graph[edge_v][edge_u] = cost;
    }

    prim(1, ver_num);
    printf("prim算法输出最小生成树：\n");
    for(i = 2; i <= ver_num; i++)
        printf("%d -> %d, the cost is %d\n", Vertex[i].pre, i, Vertex[i].cost);
    return 0;
}
