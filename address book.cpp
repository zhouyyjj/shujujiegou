#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;//ȫ�ֱ����������txt�ļ���Ϣ������ 
//�����ṹ������Ϣ
struct Info{
 char name[16];//���� 
 char worktel[20];//�����绰 
 char hometel[20];//��ͥ�绰 
 char mobeltel[20];//�ƶ��绰 
 char sex[10];//�Ա� 
 char group[10]; //���� 
}a[20];//����Info�������������洢20����Ϣ

//�жϵ�ǰ�ļ��м�������
int  r_num(){
 int l=0;
 char c;
    FILE *fp=fopen("LN.txt", "r");
    while((c=fgetc(fp)) != EOF)
  if(c=='\n')
   l++;
     l++;
    return(l);//l���� 
}

//����txt���ݱ��浽�ṹ����
void Read_txt(){
 FILE *fp; 
 int i,count;
 count = r_num();
 fp = fopen("LN.txt","r");
 for(i=0;i<count;i++){
  fscanf(fp,"%s%s%s%s%s%s",&a[i].name,&a[i].worktel,&a[i].hometel,&a[i].mobeltel,&a[i].sex,&a[i].group);
 }
 fclose(fp);
}

//������Ϣ
void Insert_Info1(int i){ 
 printf("������");
 scanf("%s",a[i].name);
 printf("�����绰��");
 scanf("%s",a[i].worktel);
 printf("��ͥ�绰��");
 scanf("%s",a[i].hometel);
 printf("�ƶ��绰��");
 scanf("%s",a[i].mobeltel);
 printf("�Ա�");
 scanf("%s",a[i].sex);
 printf("���飺");
 scanf("%s",a[i].group);
 num=num+1;
}
//������ϵ����Ϣ
void Insert_Info(num){
 int i,count,flag=0;
 char name[20]; 
 printf("������Ҫ������������");
 gets(name);
 for(i=1;i<20;i++){
  if(strcmp(name,a[i].name)==0){
   printf("��ϵ���Ѵ��ڣ�\n");
   flag=1;
   break;
  }
 }
 if(flag!=1){ 
  Insert_Info1(num);
 }
} 
//ɾ����ϵ�� 
void Delete_Info(){
 char name[20];
 printf("����Ҫɾ����������");
 gets(name);
 int i,flag=0;
 for(i=1;i<20;i++){
  if(strcmp(name,a[i].name)==0){
   for(;i<20;i++){
    strcpy(a[i].name,a[i+1].name);
    strcpy(a[i].worktel,a[i+1].worktel);
    strcpy(a[i].hometel,a[i+1].hometel);
    strcpy(a[i].mobeltel,a[i+1].mobeltel);
    strcpy(a[i].sex,a[i+1].sex);
    strcpy(a[i].group,a[i+1].group);
   }
   flag=1;
   printf("ɾ���ɹ���\n");
  }
 }
 if(flag!=1){
  printf("û�ҵ���\n");
 }
} 
//�޸Ĺ��ܺ��� 
void Update_Info(num){
 char name[20];
 printf("����Ҫ�޸ĵ�������");
 gets(name);
 int i,flag=0;
 for(i=0;i<num;i++){
  if(strcmp(name,a[i].name)==0){
   printf("�������µ���Ϣ��\n");
   printf("������");
   scanf("%s",a[i].name);
   printf("�����绰��");
   scanf("%s",a[i].worktel);
   printf("��ͥ�绰��");
   scanf("%s",a[i].hometel);
   printf("�ƶ��绰��");
   scanf("%s",a[i].mobeltel);
   printf("�Ա�");
   scanf("%s",a[i].sex);
   printf("���飺");
   scanf("%s",a[i].group);
   printf("�޸ĳɹ���\n");
   flag=1;
   break;
  }
 }
 if(flag!=1){
  printf("û�ҵ���\n");
 }
 
} 
//�����Ϣ
void Input_Info(int i){
 printf("%s\t",a[i].name);
 printf("%s\t",a[i].worktel);
 printf("%s\t",a[i].hometel);  
 printf("%s\t",a[i].mobeltel);
 printf("%s\t",a[i].sex);
 printf("%s\t",a[i].group);
 printf("\n");
} 

//��������ѯ
void Search_Name(){
 int i,count,flag=0;
 count=r_num(); 
 char name[16];
 printf("������Ҫ��ѯ�����֣�");
 gets(name);//������������ִ�ŵ�name������ 
 for(i=1;i<count;i++){
  if(strcmp(name,a[i].name)==0){
   Input_Info(i);
   flag=1;
  }
 }
 if(flag!=1){
  printf("û�ҵ���\n");
 }
} 
//�������ѯ
void Search_Group(){
 int i,count,flag=0;
 count=r_num(); 
 char group[16];
 printf("������Ҫ��ѯ�ķ��飺");
 gets(group);//��������ķ�������ŵ�group������ 
 for(i=1;i<count;i++){
  if(strcmp(group,a[i].group)==0){
   Input_Info(i);
   flag=1;
  }
 }
 if(flag!=1){
  printf("û�ҵ���\n");
 }
 
}
//��ʾȫ��ȫ������ 
void Show_ALL(int num){
 int i;
 for(i=0;i<num;i++){
  printf("%8s %11s %11s %11s %4s %5s\n",a[i].name,a[i].worktel,a[i].hometel,a[i].mobeltel,a[i].sex,a[i].group);
 }
 printf("______________________________________\n");
 printf("\n");
 printf("��ǰ����%d����¼!\n",num-1);
 printf("\n");
}
//���ṹ�������е����ݴ�ŵ�txt�ļ���
void Write_txt(int num){
 int i;
 FILE *fp;
 if((fp=fopen("LN.txt","wt"))==NULL){
  printf("cannot open file\n");
  return;
 }
 for(i=0;i<num;i++){
  fprintf(fp,"%s %s %s %s %s %s\n",&a[i].name,&a[i].worktel,&a[i].hometel,&a[i].mobeltel,&a[i].sex,&a[i].group);
 }
 fclose(fp);
}
 
//������������(ð�ݷ�)
void name_sort(int n)
{
 int i,j;
 struct Info temp;
 for(i=0;i<n;i++)
 {
  for(j=1;j<n-1-i;j++)
  {
   if(strcmp(a[j].name,a[j+1].name)>0)
   {
    temp =a[j+1];
    a[j+1]=a[j];
    a[j]=temp;
 
   }
  }
 }
}

//���������� 
void menu(void){

 int com;
 printf("\n");
 printf("--------------�˵�----------------\n");
 printf("                                  \n");
 printf("        1.������ϵ��              \n");
 printf("        2.ɾ����ϵ��              \n");
 printf("        3.�޸���ϵ����Ϣ          \n");
 printf("        4.��������ѯ              \n");
 printf("        5.�������ѯ              \n");
 printf("        6.��ʾȫ����Ϣ            \n");
 printf("        7.����������              \n");
 printf("        8.�����Ļ��Ϣ            \n");
 printf("        9.���浱ǰ������txt�ļ�   \n");
 printf("        10.�˳�                    \n");
 printf("\n");
 printf("----------------------------------\n");
}

//������ 
int main(){
 Read_txt();
 menu();
 int com;
 num=r_num();
 while(printf("�����빦�ܴ���:")&&(scanf("%d",&com))&&(com!=11)){
  fflush(stdin);
  switch(com){
   case 1:
    Insert_Info(num);
    break;
   case 2:
    Delete_Info();
    num=num-1;
    break;
   case 3:
    Update_Info(num);
    break;
   case 4:
    Search_Name();
    break;
   case 5:
    Search_Group();
    break;
   case 6:
    Show_ALL(num);
    break;
   case 7:
    name_sort(num);
    break;
   case 8:
    system("cls");
    menu(); 
    break;
   case 9:
    Write_txt(num);
    break;
   case 10: 
    printf("��лʹ�ã��ټ�������");
    exit(0);
  }
 }
}
