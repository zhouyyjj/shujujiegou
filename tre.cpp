//线索二叉树上进行遍历
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef char elemType;
typedef struct BiTNode {
    elemType data;
    struct BiTNode *lchild, *rchild;
    int LTag, RTag;
} BiThreadNode, *BiThreadTree;

void visit(elemType x);                        
BiThreadTree createBiThreadTree();            
BiThreadNode* CreateInThrTree(BiThreadTree T); 
void InThreading(BiThreadTree T);              
void ThrInOrderTraverse(BiThreadTree T);       

BiThreadNode* pre; 

int main(void)
{
    BiThreadTree root;

    printf("请按先序顺序输入节点值，输入‘#’代表节点为空：\n");
    root = createBiThreadTree();
    BiThreadNode* ThrHead = CreateInThrTree(root);
    ThrInOrderTraverse(ThrHead);

    return 0;
}

void visit(elemType x) { printf("%c, ", x); }
BiThreadTree createBiThreadTree()
{
    BiThreadNode* T;
    char ch;

    if ((ch = getchar()) == '#') {
        T = NULL;
    } else {
        T = (BiThreadNode*)malloc(sizeof(BiThreadNode));
        T->data = ch;
        T->lchild = createBiThreadTree();
        T->rchild = createBiThreadTree();
    }

    return T;
}
void InThreading(BiThreadTree T)
{
    if (T != NULL) {
        InThreading(T->lchild); 

        
        if (T->lchild == NULL) {
            T->LTag = 1;
            T->lchild = pre;
        } else {
            T->LTag = 0;
        }

        
        if (pre->rchild == NULL) {
            pre->RTag = 1;
            pre->rchild = T;
        } else {
            pre->RTag = 0;
        }

        pre = T;
        InThreading(T->rchild); 
    }
}
BiThreadNode* CreateInThrTree(BiThreadTree T)
{
    BiThreadNode* ThrHead; 
   

    ThrHead = (BiThreadNode*)malloc(sizeof(BiThreadNode));
    ThrHead->RTag = 1;
    ThrHead->rchild = ThrHead; 
    ThrHead->LTag = 0;

    if (T == NULL) {
        ThrHead->lchild = ThrHead; 
    } else {
        ThrHead->lchild = T;
        pre = ThrHead;         
        InThreading(T);        
        pre->rchild = ThrHead; 
        pre->RTag = 1;
        ThrHead->rchild = pre; 
    }

    return ThrHead;
}
void ThrInOrderTraverse(BiThreadTree ThrHead)
{
    BiThreadNode* temp = ThrHead->lchild; 

    while (temp != ThrHead) {
        while (temp->LTag == 0) {
            temp = temp->lchild; 
        }
        visit(temp->data);
        
        while (temp->RTag == 1 && temp->rchild != ThrHead) {
            temp = temp->rchild;
            visit(temp->data);
        }
        temp = temp->rchild; 
    }
}
