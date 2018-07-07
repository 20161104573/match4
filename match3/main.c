//
//  main.c
//  match3
//
//  Created by 20161104573 on 18/6/26.
//  Copyright © 2018年 20161104573. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "proHead.h"


typedef struct Program
{
    char name[20];
    char sex[5];
    char act[30];
    char acte[30];
    char class[20];
    char num[20];
    struct Program * next;
}Program;


int menu_select();
void input(Program * pro);
void output(Program * pro);
void load(Program * pro);
void save(Program * pro);

int menu_select()
{
    int MenuItem;
    
    printf("\n ");
    printf("         |  **************评分系统**************       |              \n");
    printf("          | ----------------------------------------        |          \n");
    printf("          |                  主菜单项                 |          \n");
    printf("          | ----------------------------------------        |          \n");
    printf("          |	  1 ^ ^ ^ ^ @ 新建选手信息 @ ^ ^ ^ ^  	    |             \n");
    printf("          |	  2 ^ ^ ^ ^ @ 修改选手信息 @ ^ ^ ^ ^	    |             \n");
    printf("          |	  3 ^ ^ ^ ^ @ 查询选手信息 @ ^ ^ ^ ^	    |             \n");
    printf("          |	  4 ^ ^ ^ ^ @ 删除选手信息 @ ^ ^ ^ ^	    |             \n");
    printf("          |	  5 ^ ^ ^ ^ @ 显示选手信息 @ ^ ^ ^ ^	    |             \n");
    printf("          |	  0 ^ ^ ^ ^ @ 保存并退出系统@   ^ ^ ^ ^ 	    |             \n");
    
    do
    {
        printf("\n请输入选项(0-5):");
        fflush(stdin);
        scanf("%d",&MenuItem);
    }while(MenuItem<0||MenuItem>5);
    
    return MenuItem;
}
/**********************************************
 *Function Name:input
 *Description:
 ***********************************************/
void input(Program * pro)
{
    char name[20];
    char sex[5];
    char act[30];
    char acte[30];
    char class[20];
    char num[20];
    Program *rear,*p,*s;
    char cContinue;
    int flag=1;
    
    rear = pro;
    while(rear->next!=NULL)
    {
        rear = rear->next;
    }
    
    while (flag)
    {
        printf("请输入选手姓名");
        scanf("%s",name);
        printf("请输入选手性别");
        scanf("%s",sex);
        printf("请输入选手表演节目名称");
        scanf("%s",act);
        printf("请输入选手表演节目类别");
        scanf("%s",acte);
        printf("请输入选手班级");
        scanf("%s",class);
        printf("请输入选手电话号码");
        scanf("%s",num);

        
        p = pro->next;
        while(p!=NULL)
        {
            if(strcmp(p->name,name)!=0)
                p = p->next;
            else
                break;
        }
        
        if(p!=NULL)
        {
            printf("∏√øŒ∫≈“—¥Ê‘⁄£¨«Î÷ÿ–¬ ‰»Î’˝»∑µƒøŒ∫≈£°\n");
            flag = 1;
            continue;
        }
        else
        {
            s = (Program *)malloc(sizeof(Program));
            strcpy(s->name,name);
            
            printf("«Î ‰»ÎøŒ√˚£∫");
            scanf("%s",s->name);
            
	           s->next = NULL;
	           rear->next = s;
	           rear = s;
		          
	           fflush(stdin);
	           printf("–Ë“™ºÃ–¯¬º»Î¬£ø(Y/N)");
	           scanf("%c",&cContinue);
              /*switch(cContinue)
	           {
                   case 'Y':
                   case 'y':
                       flag = 1;
                       break;
                   case 'N':
                   case 'n':
                       flag = 0;
                       break;
               }*/
        }
    }
}
/**********************************************
 *Function Name:output
 *Description: ‰≥ˆøŒ≥Ã–≈œ¢
 ***********************************************/0
void output(Program * pro)
{
    Program * p = pro->next;
    printf("|       øŒ∫≈       |   øŒ√˚       |\n");
    printf("|------------------|--------------|\n");
    while (p!=NULL)
    {
        printf("|%-6s            |%-14s|\n", p->name,p->sex,p->act,p->acte,p->class,p->num);
        p = p->next;
    }
}

/**********************************************
 *Function Name:load
 *Description:º”‘ÿŒƒº˛
 ***********************************************/
void load(Program * pro)
{
    FILE *fp;
    char a[20],b[20],c[20],d[20],e[20],f[20];
    Program * p=pro,*q;
    printf("                 - Œƒº˛∂¡»°≥…π¶ -\n");
    fp=fopen("//Users//a20161104573//Desktop//com.com","r");
    if(fp==NULL)
    {
        printf("¥Úø™Œƒº˛¥ÌŒÛ£¨ø…ƒ‹“™¥Úø™µƒŒƒº˛≤ª¥Ê‘⁄£°\n");
    }
    else
    {
        while(fscanf(fp,"%s %s %s %s %s %s",a,b,c,d,e,f)!=EOF)
        {
            q= (Program *)malloc(sizeof(Program));
            strcpy(q->name,a);
            strcpy(q->sex,b);
            strcpy(q->act,c);
            strcpy(q->acte,d);
            strcpy(q->class,e);
            strcpy(q->num,f);
            q->next=NULL;
            p->next=q;
            p=p->next;
        }
        fclose(fp);
    }
}

/**********************************************
 *Function Name:save
 *Description:±£¥ÊŒƒº˛
 ***********************************************/
void save(Program * pro)
{
    int n;
    Program * p;
    FILE *fp; 
    printf("–Ë“™±£¥Ê¬£ø(1***±£¥Ê  0***≤ª±£¥Ê)\n");
    scanf("%d",&n);
    if(n)
    {
        if (pro->next==NULL)
            printf("Œﬁº«¬º");
        else 
            p=pro->next;
        if((fp=fopen("course.txt","w"))==NULL)  //¥Úø™Œƒº˛£¨≤¢≈–∂œ¥Úø™ «∑Ò’˝≥£
            printf("can not open file!\n"); 
        while (p!=NULL)
        {
            fprintf(fp,"%s %s\n",p->name,p->sex,p->act,p->acte,p->class,p->num);
            p=p->next;
        }
        
        fclose(fp); 
    }
}



int main(int argc, const char * argv[]) {
    /*FILE *fr;
     //char xsex[5],xact[30],xacte[30],xclass[30],xnum[20];
     int i;
     char str1;
     fr=fopen("//Users//a20161104573//Desktop//com.com","r+");
     fscanf(fr,"%s",str1);
     printf("结果:%s\n",str1);

    if(fr==NULL)
    {
        printf("打开文件错误，要打开的文件可能不存在");
        return -1;
    }
    else{
        for (int i=0;i<6;++i)
        {
            char xname[10];
            sprintf(xname,"%s",孙慧珠,i);
        }
    }*/
    Program * pro= (Program *)malloc(sizeof(Program));
    pro->next = NULL;
    load(pro);
    while(1)
    {
        switch(menu_select())
        {
            case 1:
                input(pro);
                break;
            case 5:
                output(pro);
                break;
            case 0:
                save(pro);
                printf("Thank you for using£°\n");
                system("pause");
                return 0;
        }
    }
    



    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
