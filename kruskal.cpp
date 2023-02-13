#include <stdio.h>
#define VER_LEN (101)
#define EDGE_LEN (10001)
typedef struct {
    int u,v,cost;
}edge;

edge Edge[EDGE_LEN];
int Parent[VER_LEN];
int Size[VER_LEN];
int Flag[VER_LEN];

// ���򣬰��ձߵ�Ȩ�أ���С��������
void sort(int edge_num){
    int i,j;
    int temp_u, temp_v, temp_cost;

    for(i = 1; i < edge_num; i++) {
        for(j = 1; j <= edge_num - i; j++) {
            if(Edge[j].cost > Edge[j+1].cost) {
                temp_u = Edge[j].u;
                temp_v = Edge[j].v;
                temp_cost = Edge[j].cost;
                Edge[j].u = Edge[j+1].u;
                Edge[j].v = Edge[j+1].v;
                Edge[j].cost = Edge[j+1].cost;
                Edge[j+1].u = temp_u;
                Edge[j+1].v = temp_v;
                Edge[j+1].cost = temp_cost;
            }
        }
    }
}

void init(int ver_num) {
    int i;
    for(i=1; i<=ver_num; i++) {
        Parent[i]=i;// ��parent��ʼ��Ϊ����
        Size[i]=1;/*��size��ʼ��Ϊ1�����ڰ���ѹ����
		�������Ҫ���а���ѹ��������Ҫ���������Ϣ��*/
    }
}

int find(int vertex) {
    if(vertex != Parent[vertex]) {
        Parent[vertex]=find(Parent[vertex]);//·��ѹ��
    }
    return Parent[vertex];
}

int union_set(int i) {
    int parent_u = find(Edge[i].u);
    int parent_v = find(Edge[i].v);
    
    // �ڵ�u��v�Ѿ���ͬһ��������
    if(parent_u == parent_v)     return 0;
    
    // ����ѹ��������СһЩ�������뵽�ȴ�һЩ����
    if(Size[parent_u] > Size[parent_v]) {
        Parent[parent_v] = parent_u;
        Size[parent_u] += Size[parent_v];
    } else {
        Parent[parent_u] = parent_v;
        Size[parent_v] += Size[parent_u];
    }
    return 1;
}

void Kruskal(int ver_num, int edge_num) {
    int i,counter;

    // ���򣬰��ձߵ�Ȩ�أ���С��������
    sort(edge_num);

    // ���г�ʼ��
    init(ver_num);

    counter = 0;
    // ���ձߵ�Ȩ�أ���С����������еı�
    // ֱ�����������бߣ�������������С������Ϊֹ
    for(i = 1; i <= edge_num && counter < ver_num-1; i++) {
        // ���¼���ı߻��γɻ�ʱ����Ҫ����
        if(union_set(i) == 0)    continue;
        
        // ���¼���ıߵı�ű�����Flag�����У��Ա�����
        counter++;
        Flag[counter] = i;
    }
}

int main() {
    int i,ver_num, edge_num;
    printf("�����������\tѧ�ţ�21404070\t�༶����212\t\n");
    printf("���붥�����ͱ�����\n");
    scanf("%d %d", &ver_num, &edge_num);
    printf("����ͼ����Ϣ��\n");
    for(i = 1; i <= edge_num; i++)
        scanf("%d %d %d", &Edge[i].u, &Edge[i].v, &Edge[i].cost);
        
    Kruskal(ver_num, edge_num);
    printf("Kruskal�㷨�����С��������\n");
    for(i = 1; i < ver_num; i++)
        printf("%d -> %d\n", Edge[Flag[i]].u, Edge[Flag[i]].v);
    return 0;
}
