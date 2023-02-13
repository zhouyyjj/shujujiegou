#include <stdio.h>
#define MAXINT (0X7FFF7FFF)
#define VER_LEN (101)
typedef struct {
    int cost;
    int flag;
    int pre;
} vertex;
//����
int Graph[VER_LEN][VER_LEN];
vertex Vertex[VER_LEN];

// ��ʼ��ͼ�����ݣ���ʼ��Ϊ����֮�以������
void init_graph(int length) {
    int i, j;
    for(i = 1; i <= length; i++)
      for(j = 1; j <= length; j++)
        Graph[i][j] = MAXINT;
}

void prim(int start, int length) {
    int i,j;
    int min_cost, min_v;

    // ���ݳ�ʼ����start����ʼΪ������������Ϣ
    // cost��ʾȨ�أ�flag��ʾ�Ƿ��Ѿ�������С��������pre��ʾ��parent�ڵ�
    for(i = 1; i <= length; i++) {
        Vertex[i].cost = Graph[start][i];
        Vertex[i].flag = 0;
        Vertex[i].pre = start;
    }

    // ����ʼ������뵽��С��������
    Vertex[start].cost = 0;
    Vertex[start].flag = 1;

    for(i = 2; i <= length; i++) {
        min_cost = MAXINT;
        // �ҳ�cost��С�ı�
        for(j = 1; j <= length; j++) {
            if(Vertex[j].flag == 0 && Vertex[j].cost < min_cost) {
                min_cost = Vertex[j].cost;
                min_v = j;
            }
        }

        // �������ҳ�����cost��С�ıߵĶ�����뵽��С��������
        Vertex[min_v].flag = 1;

        // ���������¼��뵽��С�������Ķ�������������costֵ
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
	printf("�����������\tѧ�ţ�21404070\t�༶����212\t\n");

    printf("���붥�����ͱ�����\n");
    scanf("%d %d", &ver_num, &edge_num);
    init_graph(ver_num);
    
    printf("����ͼ����Ϣ��\n");
    for(i = 1; i <= edge_num; i++) {
        scanf("%d %d %d", &edge_u, &edge_v, &cost);
        Graph[edge_u][edge_v] = cost;
        Graph[edge_v][edge_u] = cost;
    }

    prim(1, ver_num);
    printf("prim�㷨�����С��������\n");
    for(i = 2; i <= ver_num; i++)
        printf("%d -> %d, the cost is %d\n", Vertex[i].pre, i, Vertex[i].cost);
    return 0;
}
