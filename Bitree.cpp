//二叉树中序遍历 
#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode{
 char data;
 struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

BiTree init_Tree(BiTree T){

 T = (BiTree)malloc(sizeof(struct BiTNode));
 T->data = 'A';
 T->lchild = NULL;
T->rchild = NULL;
return T;
}
BiTree insert_Tree_left(BiTree Tree,char ch){
BiTree p = (BiTree) malloc(sizeof(struct BiTNode));
p->lchild = NULL;
p->rchild = NULL;
p->data = ch;
Tree->lchild = p;
return p;
}
BiTree insert_Tree_right(BiTree Tree,char ch){
 BiTree p = (BiTree) malloc(sizeof(struct BiTNode));
 p->lchild = NULL;
 p->rchild = NULL;
 p->data = ch;
 Tree->rchild = p;
 return p;
}

void visit(BiTree tree){
 printf("%c ",tree->data);
 return;
}


void preOrder(BiTree T){
 if(T != NULL){
 visit(T);
 preOrder(T->lchild);
 preOrder(T->rchild);
 }
 return;
}

void midOrder(BiTree T){
if(T != NULL){
 midOrder(T->lchild);
 visit(T);
 midOrder(T->rchild);
 }
 return;
}
void lastOrder(BiTree T){
 if(T != NULL){
 lastOrder(T->lchild);
 lastOrder(T->rchild);
 visit(T);
 }
 return;
}
int main() {
 BiTree T = NULL;
T = init_Tree(T);
 BiTree B = insert_Tree_left(T,'B');
 BiTree C = insert_Tree_right(T,'C');
 BiTree D = insert_Tree_left(B,'D');
 BiTree E = insert_Tree_right(B,'E');
 insert_Tree_right(D,'G');
 insert_Tree_left(C,'F');
 printf("先序遍历：");
 preOrder(T);
 printf("\n");
 printf("中序遍历：");
 midOrder(T);
 printf("\n");
 printf("后序遍历：");
 lastOrder(T);
 return 0;
}
