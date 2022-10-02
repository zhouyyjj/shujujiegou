//以二叉链表为存储结构，写一算法对二叉树进行层次遍历
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct BinaryNode {
 char data;  //数据域
 struct BinaryNode* left; //指针域 左孩子
 struct BinaryNode* right; //指针域 右孩子
}Tree;
typedef struct {
 Tree* pl;    //指针结点
 int no;     //结点所在层次号
}TreeNo;
//赋值
Tree* getTree(char data) {
 Tree* tree = (Tree*)malloc(sizeof(Tree));
 tree->data = data;
 tree->left = NULL;
 tree->right = NULL;
 return tree;
}
//前序遍历
void preOrder(Tree* tree) {
 if (tree != NULL) {
  printf("%c ",tree->data);
  preOrder(tree->left);
  preOrder(tree->right);
 }
}
//层次遍历
void levelOrder(Tree* tree) {
 int front, rear;
 //定义一个循环队列,用来记录将要访问的层次上的结点
 Tree* queue[MAXSIZE];
 front = rear = 0;
 Tree* p;
 if (tree != NULL) {
  rear = (rear + 1) % MAXSIZE;
  //根结点入队
  queue[rear] = tree;
  while (front != rear) {
   front = (front + 1) % MAXSIZE;
   //队头结点出队
   p = queue[front];
   printf("%c ", p->data);
   //如果左子树不空,左子树根节点入队
   if (p->left != NULL) {
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = p->left;
   }
   //如果右子树不空,则右子树的根节点入队
   if (p->right != NULL) {
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = p->right;
   }
  }
 }
 printf("\n");
}

int maxNode(Tree* brn) {
 //定义循环非空队列
 TreeNo queue[MAXSIZE];
 int front, rear;
 int treeno, i, j, n, max;
 front = rear = 0;  //将队列置空
 Tree* p;
 if (brn != NULL) {
  ++rear;
  //树根入队
  queue[rear].pl = brn;
  //树根所在的层次号设置为1,这个是已知条件
  queue[rear].no = 1;
  while (front != rear) {
   ++front;
   p = queue[front].pl;
   //treeno用来存取当前结点的层次号
   treeno = queue[front].no;
   if (p->left != NULL) {
    ++rear;
    queue[rear].pl = p->left;
    //根据当前结点的层次好推知其孩子结点的层次号
    queue[rear].no = treeno + 1;
   }
   if (p->right != NULL) {
    ++rear;
    queue[rear].pl = p->right;
    queue[rear].no = treeno + 1;
   }
  }//结束循环的时候,treeno已经保存了这棵树的最大层数
  max = 0;
  for (i = 1; i <= treeno; i++) {
   n = 0;
   for (j = 1; j <= rear; j++) {
    if (queue[j].no == i) {
     ++n;
    }
    if (max < n) {
     max = n;
    }
   }
  }
  return max;
 }
 //空树直接返回 0
 else {
  return 0;
 }
}

int main(int argc, char* argv[]) {
 //搭建图中的二叉树
 Tree* tree = (Tree*)malloc(sizeof(Tree));
 tree = getTree('A');
 tree->left = getTree('B');
 tree->right = getTree('C');
 tree->left->left = getTree('D');
 tree->left->right = getTree('E');
 tree->left->left->left = getTree('H');
 tree->left->left->right = getTree('I');
 tree->left->right->left = getTree('J');
 tree->left->right->right = getTree('K');
 tree->right->left = getTree('F');
 tree->right->right = getTree('G');

 //前序遍历和层次遍历对比
 //前序遍历
 printf("前序遍历: ");  preOrder(tree); printf("\n\n");
 //层次遍历
 printf("层次遍历: "); levelOrder(tree);
 //求宽度
 int max = maxNode(tree);
 printf("\n二叉树tree的宽度是: %d ", max);
 getchar();
 return 0;
}