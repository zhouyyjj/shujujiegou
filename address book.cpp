#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;//全局变量用来存放txt文件信息的行数 
//创建结构体存放信息
struct Info{
 char name[16];//姓名 
 char worktel[20];//工作电话 
 char hometel[20];//家庭电话 
 char mobeltel[20];//移动电话 
 char sex[10];//性别 
 char group[10]; //分组 
}a[20];//创建Info类型数组用来存储20条信息

//判断当前文件有几行数据
int  r_num(){
 int l=0;
 char c;
    FILE *fp=fopen("LN.txt", "r");
    while((c=fgetc(fp)) != EOF)
  if(c=='\n')
   l++;
     l++;
    return(l);//l传参 
}

//读出txt内容保存到结构体中
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

//插入信息
void Insert_Info1(int i){ 
 printf("姓名：");
 scanf("%s",a[i].name);
 printf("工作电话：");
 scanf("%s",a[i].worktel);
 printf("家庭电话：");
 scanf("%s",a[i].hometel);
 printf("移动电话：");
 scanf("%s",a[i].mobeltel);
 printf("性别：");
 scanf("%s",a[i].sex);
 printf("分组：");
 scanf("%s",a[i].group);
 num=num+1;
}
//新增联系人信息
void Insert_Info(num){
 int i,count,flag=0;
 char name[20]; 
 printf("请输入要新增的姓名：");
 gets(name);
 for(i=1;i<20;i++){
  if(strcmp(name,a[i].name)==0){
   printf("联系人已存在！\n");
   flag=1;
   break;
  }
 }
 if(flag!=1){ 
  Insert_Info1(num);
 }
} 
//删除联系人 
void Delete_Info(){
 char name[20];
 printf("输入要删除的姓名：");
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
   printf("删除成功！\n");
  }
 }
 if(flag!=1){
  printf("没找到！\n");
 }
} 
//修改功能函数 
void Update_Info(num){
 char name[20];
 printf("输入要修改的姓名：");
 gets(name);
 int i,flag=0;
 for(i=0;i<num;i++){
  if(strcmp(name,a[i].name)==0){
   printf("请输入新的信息：\n");
   printf("姓名：");
   scanf("%s",a[i].name);
   printf("工作电话：");
   scanf("%s",a[i].worktel);
   printf("家庭电话：");
   scanf("%s",a[i].hometel);
   printf("移动电话：");
   scanf("%s",a[i].mobeltel);
   printf("性别：");
   scanf("%s",a[i].sex);
   printf("分组：");
   scanf("%s",a[i].group);
   printf("修改成功！\n");
   flag=1;
   break;
  }
 }
 if(flag!=1){
  printf("没找到！\n");
 }
 
} 
//输出信息
void Input_Info(int i){
 printf("%s\t",a[i].name);
 printf("%s\t",a[i].worktel);
 printf("%s\t",a[i].hometel);  
 printf("%s\t",a[i].mobeltel);
 printf("%s\t",a[i].sex);
 printf("%s\t",a[i].group);
 printf("\n");
} 

//按姓名查询
void Search_Name(){
 int i,count,flag=0;
 count=r_num(); 
 char name[16];
 printf("请输入要查询的名字：");
 gets(name);//接收输入的名字存放到name数组中 
 for(i=1;i<count;i++){
  if(strcmp(name,a[i].name)==0){
   Input_Info(i);
   flag=1;
  }
 }
 if(flag!=1){
  printf("没找到！\n");
 }
} 
//按分组查询
void Search_Group(){
 int i,count,flag=0;
 count=r_num(); 
 char group[16];
 printf("请输入要查询的分组：");
 gets(group);//接收输入的分组名存放到group数组中 
 for(i=1;i<count;i++){
  if(strcmp(group,a[i].group)==0){
   Input_Info(i);
   flag=1;
  }
 }
 if(flag!=1){
  printf("没找到！\n");
 }
 
}
//显示全部全部内容 
void Show_ALL(int num){
 int i;
 for(i=0;i<num;i++){
  printf("%8s %11s %11s %11s %4s %5s\n",a[i].name,a[i].worktel,a[i].hometel,a[i].mobeltel,a[i].sex,a[i].group);
 }
 printf("______________________________________\n");
 printf("\n");
 printf("当前共有%d条记录!\n",num-1);
 printf("\n");
}
//将结构体数组中的内容存放到txt文件中
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
 
//按照姓名排序(冒泡法)
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

//程序主界面 
void menu(void){

 int com;
 printf("\n");
 printf("--------------菜单----------------\n");
 printf("                                  \n");
 printf("        1.新增联系人              \n");
 printf("        2.删除联系人              \n");
 printf("        3.修改联系人信息          \n");
 printf("        4.按姓名查询              \n");
 printf("        5.按分组查询              \n");
 printf("        6.显示全部信息            \n");
 printf("        7.按姓名排序              \n");
 printf("        8.清除屏幕信息            \n");
 printf("        9.保存当前操作到txt文件   \n");
 printf("        10.退出                    \n");
 printf("\n");
 printf("----------------------------------\n");
}

//主函数 
int main(){
 Read_txt();
 menu();
 int com;
 num=r_num();
 while(printf("请输入功能代码:")&&(scanf("%d",&com))&&(com!=11)){
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
    printf("感谢使用！再见！！！");
    exit(0);
  }
 }
}
