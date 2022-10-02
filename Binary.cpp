//�Զ�������Ϊ�洢�ṹ��дһ�㷨�Զ��������в�α���
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct BinaryNode {
 char data;  //������
 struct BinaryNode* left; //ָ���� ����
 struct BinaryNode* right; //ָ���� �Һ���
}Tree;
typedef struct {
 Tree* pl;    //ָ����
 int no;     //������ڲ�κ�
}TreeNo;
//��ֵ
Tree* getTree(char data) {
 Tree* tree = (Tree*)malloc(sizeof(Tree));
 tree->data = data;
 tree->left = NULL;
 tree->right = NULL;
 return tree;
}
//ǰ�����
void preOrder(Tree* tree) {
 if (tree != NULL) {
  printf("%c ",tree->data);
  preOrder(tree->left);
  preOrder(tree->right);
 }
}
//��α���
void levelOrder(Tree* tree) {
 int front, rear;
 //����һ��ѭ������,������¼��Ҫ���ʵĲ���ϵĽ��
 Tree* queue[MAXSIZE];
 front = rear = 0;
 Tree* p;
 if (tree != NULL) {
  rear = (rear + 1) % MAXSIZE;
  //��������
  queue[rear] = tree;
  while (front != rear) {
   front = (front + 1) % MAXSIZE;
   //��ͷ������
   p = queue[front];
   printf("%c ", p->data);
   //�������������,���������ڵ����
   if (p->left != NULL) {
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = p->left;
   }
   //�������������,���������ĸ��ڵ����
   if (p->right != NULL) {
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = p->right;
   }
  }
 }
 printf("\n");
}

int maxNode(Tree* brn) {
 //����ѭ���ǿն���
 TreeNo queue[MAXSIZE];
 int front, rear;
 int treeno, i, j, n, max;
 front = rear = 0;  //�������ÿ�
 Tree* p;
 if (brn != NULL) {
  ++rear;
  //�������
  queue[rear].pl = brn;
  //�������ڵĲ�κ�����Ϊ1,�������֪����
  queue[rear].no = 1;
  while (front != rear) {
   ++front;
   p = queue[front].pl;
   //treeno������ȡ��ǰ���Ĳ�κ�
   treeno = queue[front].no;
   if (p->left != NULL) {
    ++rear;
    queue[rear].pl = p->left;
    //���ݵ�ǰ���Ĳ�κ���֪�亢�ӽ��Ĳ�κ�
    queue[rear].no = treeno + 1;
   }
   if (p->right != NULL) {
    ++rear;
    queue[rear].pl = p->right;
    queue[rear].no = treeno + 1;
   }
  }//����ѭ����ʱ��,treeno�Ѿ��������������������
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
 //����ֱ�ӷ��� 0
 else {
  return 0;
 }
}

int main(int argc, char* argv[]) {
 //�ͼ�еĶ�����
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

 //ǰ������Ͳ�α����Ա�
 //ǰ�����
 printf("ǰ�����: ");  preOrder(tree); printf("\n\n");
 //��α���
 printf("��α���: "); levelOrder(tree);
 //����
 int max = maxNode(tree);
 printf("\n������tree�Ŀ����: %d ", max);
 getchar();
 return 0;
}