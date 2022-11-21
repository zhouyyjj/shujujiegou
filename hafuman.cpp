//哈夫曼编码
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
struct HTree *iniHTree(int num){/*对哈夫曼树初始化*/
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
void show(struct HTree *ht){/*打印哈夫曼树*/
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
void consummateHT(struct HTree *ht,int num){/*完善哈夫曼树*/
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
void codeHT(struct HTree *ht){/*哈夫曼编码核心代码*/
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
        if(ht->body[cur].weight==0){/*weight为0表示没有被访问过*/
            ht->body[cur].weight=1;/*weight为1表示左子树被访问过*/
            if(ht->body[cur].lchild!=-1){/*左孩子不等于-1说明还在中间节点，cur继续往左走，编码左0右1，所以编为0*/
                a[index++]='0';
                cur=ht->body[cur].lchild;
            }else{/*当前节点的左孩子为-1说明遍历到头了，当前节点的完整编码就存在数组a中*/
                a[index]='\0';
                ch[cur]=(char *)malloc(sizeof(char)*count);
                strcpy(ch[cur],a);/*对编码拷贝*/
            }
        }else if(ht->body[cur].weight==1){/*weight为1表示右子树没被访问过*/
            ht->body[cur].weight=2;/*weight为2表示左右子树都被访问过*/
            if(ht->body[cur].rchild!=-1){/*右孩子孩子不等于-1说明还在中间节点，cur继续往右走，编码左0右1，所以编为1*/
                a[index++]='1';
                cur=ht->body[cur].rchild;
            }
            /*右孩子为-1时说明遍历到头了，由于之前编码已经拷贝过了，所以直接跳过，不做处理*/
        }else{/*weight为2说明左右都访问过，回退到父节点，并将索引下标减一，相当于删掉数组中最后一个字符*/
            ht->body[cur].weight=0;
            cur=ht->body[cur].parent;
            index--;
        }
    }
    printf("最优前缀码：\n");
    for(int i=0;i<count;i++){
        printf("权重为%d的编码:%s\n",weightdata[i],ch[i]);
    }
}
int main(){
    struct HTree *ht;
    int num;
    printf("leaf=");
    scanf("%d",&num);
    ht=iniHTree(num);
    consummateHT(ht,num);
    printf("哈夫曼树存储表如下:\n");
    show(ht);
    printf("\n");
    codeHT(ht);
    return 0;
}