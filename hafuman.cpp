//����������
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct HTreeNode{
    int parent;
    int lchild;
    int rchild;
    int weight;
};
struct HTree{
    struct HTreeNode *body;
    int length;
};
struct HTree *iniHTree(int num){/*�Թ���������ʼ��*/
    struct HTree *ht;
    ht=(struct HTree *)malloc(sizeof(struct HTree));
    int size=2*num-1;
    ht->body=(struct HTreeNode *)malloc(sizeof(struct HTreeNode)*size);
    ht->length=0;
    int i;
    for(i=0;i<num;i++){
        ht->body[i].parent=-1;
        ht->body[i].lchild=-1;
        ht->body[i].rchild=-1;
        int temp;
        printf("The %dth weight=",i);
        scanf("%d",&temp);
        ht->body[i].weight=temp;
        ht->length++;
    }
    for(;i<size;i++){
        ht->body[i].parent=-1;
        ht->body[i].lchild=-1;
        ht->body[i].rchild=-1;
        ht->body[i].weight=pow(2,31)-1;
    }
    return ht;
}
void show(struct HTree *ht){/*��ӡ��������*/
    if(ht->body!=NULL){
        for(int i=0;i<ht->length;i++){
            printf("%4d",ht->body[i].lchild);
            printf("%4d",ht->body[i].weight);
            printf("%4d",ht->body[i].rchild);
            printf("%4d",ht->body[i].parent);
            printf("\n");
        }
    }
}
void findTwoMinHTNode(struct HTree *ht,int *min1,int *min2){
    int m1,m2;
    int minWeight;
    int j=0;
    while(ht->body[j].parent!=-1){
        j++;
    }
    m1=j;
    minWeight=ht->body[m1].weight;
    for(int i=m1+1;i<ht->length;i++){
        if(ht->body[i].parent==-1&&ht->body[i].weight<minWeight){
            m1=i;
            minWeight=ht->body[i].weight;
        }
    }
    ht->body[m1].parent=1;
    *min1=m1;
    j=0;
    while(ht->body[j].parent!=-1){
        j++;
    }
    m2=j;
    minWeight=ht->body[m2].weight;
    for(int i=m2+1;i<ht->length;i++){
        if(ht->body[i].parent==-1&&ht->body[i].weight<minWeight){
            m2=i;
            minWeight=ht->body[m2].weight;
        }
    }
    *min2=m2;
    ht->body[m2].parent=1;
}
void consummateHT(struct HTree *ht,int num){/*���ƹ�������*/
    if(ht==NULL){
        printf("HT is not exit\n");
        return;
    }
    int min1,min2;
    for(int i=num;i<2*num-1;i++){
        findTwoMinHTNode(ht,&min1,&min2);
        ht->body[min1].parent=i;
        ht->body[min2].parent=i;
        ht->body[i].lchild=min1;
        ht->body[i].rchild=min2;
        ht->body[i].weight=ht->body[min1].weight+ht->body[min2].weight;
        ht->length++;
    }
}
void codeHT(struct HTree *ht){/*������������Ĵ���*/
    int count=(ht->length+1)/2;
    int weightdata[count];
    for(int i=0;i<count;i++){
        weightdata[i]=ht->body[i].weight;
    }
    char *ch[count];
    char a[count];
    int index=0;
    for(int i=0;i<ht->length;i++){
        ht->body[i].weight=0;
    }
    int cur=ht->length-1;
    while(cur!=-1){
        if(ht->body[cur].weight==0){/*weightΪ0��ʾû�б����ʹ�*/
            ht->body[cur].weight=1;/*weightΪ1��ʾ�����������ʹ�*/
            if(ht->body[cur].lchild!=-1){/*���Ӳ�����-1˵�������м�ڵ㣬cur���������ߣ�������0��1�����Ա�Ϊ0*/
                a[index++]='0';
                cur=ht->body[cur].lchild;
            }else{/*��ǰ�ڵ������Ϊ-1˵��������ͷ�ˣ���ǰ�ڵ����������ʹ�������a��*/
                a[index]='\0';
                ch[cur]=(char *)malloc(sizeof(char)*count);
                strcpy(ch[cur],a);/*�Ա��뿽��*/
            }
        }else if(ht->body[cur].weight==1){/*weightΪ1��ʾ������û�����ʹ�*/
            ht->body[cur].weight=2;/*weightΪ2��ʾ���������������ʹ�*/
            if(ht->body[cur].rchild!=-1){/*�Һ��Ӻ��Ӳ�����-1˵�������м�ڵ㣬cur���������ߣ�������0��1�����Ա�Ϊ1*/
                a[index++]='1';
                cur=ht->body[cur].rchild;
            }
            /*�Һ���Ϊ-1ʱ˵��������ͷ�ˣ�����֮ǰ�����Ѿ��������ˣ�����ֱ����������������*/
        }else{/*weightΪ2˵�����Ҷ����ʹ������˵����ڵ㣬���������±��һ���൱��ɾ�����������һ���ַ�*/
            ht->body[cur].weight=0;
            cur=ht->body[cur].parent;
            index--;
        }
    }
    printf("����ǰ׺�룺\n");
    for(int i=0;i<count;i++){
        printf("Ȩ��Ϊ%d�ı���:%s\n",weightdata[i],ch[i]);
    }
}
int main(){
    struct HTree *ht;
    int num;
    printf("leaf=");
    scanf("%d",&num);
    ht=iniHTree(num);
    consummateHT(ht,num);
    printf("���������洢������:\n");
    show(ht);
    printf("\n");
    codeHT(ht);
    return 0;
}