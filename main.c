//综合实例3
//dev
#include<stdio.h>
#include<stdlib.h>
#define M 5
#define N 5

float score[N][M];
float a_stu[N],a_cor[M];

void initial();
void input();
int judge();
void ave_stu();
void ave_cor();
void highest();
float s_diff();
void print();

int main ()
{
    int i,j,select;
    float diff;

    initial();
    do
    {

        printf("\n");
        printf("1.输入成绩\n");
        printf("2.输出学生平均分\n");
        printf("3.输出学科平均分\n");
        printf("4.输出最高分\n");
        printf("5.输出方差\n");
        printf("6.退出\n");

        scanf("%d",&select);

        switch(select)
        {
            case 1:input();
                   print();
                   break;
            case 2:
                   if(judge()==-1)
                    break;
                   else
                   {
                       for(i=0;i<N;i++)
                            printf("NO %d 的学生的平均分是%f \n",i+1,a_stu[i]/M);
                       break;
                       }
            case 3:
                   if(judge()==-1)
                    break;
                   else
                    {

                        for(j=0;j<M;j++)
                            printf("课程 %d 的平均分是 %f \n",j+1,a_cor[j]/N);
                        break;
                    }
            case 4:
                   if(judge()==-1)
                    break;
                   else
                    {highest();break;}
            case 5:
                   if(judge()==-1)
                    break;
                   else
                    {
                        diff=s_diff(a_stu,a_cor);
                        printf("%f",diff/N);
                        break;
                    }
            case 6:
                exit(0);
                break;
            default:
                exit(0);
                break;

        }
    }while(1);
    return 0;

}
void initial()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
          score[i][j]=-1;
}
int judge()
{
    if(score[0][0]==-1)
           {
               printf("未输入成绩,请重新输入");
               return -1;
           }
    else
        return 1;

}
void input()
{
    int i,j;
    for(i=0;i<N;i++)
     {
       printf("请输入第%d个学生的5个成绩: \n",i+1);
       for(j=0;j<M;j++)
           scanf("%f",&score[i][j]);
        printf("\n");
     }
}
void ave_stu()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
          a_stu[i]=a_stu[i]+score[i][j];

    }
}
void ave_cor()
{
    int i,j;
    for(j=0;j<M;j++)
    {
        for(i=0;i<N;i++)
            a_cor[j]=a_cor[j]+score[i][j];
    }
}
void highest()
{
    int x=-1,y=-1;
    int i,j;
    int high=score[0][0];
  for(i=0;i<N;i++)
  {
      for(j=0;j<M;j++)
        if(score[i][j]>high)
          {
              high=score[i][j];
              x=i;
              y=j;
          }
  }
  printf("最高分是第%d 同学的第%d课的%f成绩 \n",x,y,score[x][y]);
}
float s_diff()
{
    float diff,diff1=0,diff2=0,diff3=0;
    int i;
    for(i=0;i<N;i++)
    {
        diff1=diff1+a_stu[i]*a_stu[i];
        diff2=diff2+a_stu[i];
    }
    diff3=(diff2/N)*(diff2/N);
    diff=diff1/N-diff3;
    return diff;
}
void print()
{
    int i,j;ave_stu();ave_cor();
    printf("课程号   课程1   课程2   课程3   课程4   课程5   平均分    \n");
    for(i=0;i<N;i++)
        {
            printf("NO%d      ",i+1);
            for(j=0;j<M;j++)
               printf("%.1f      ",score[i][j]);

            printf("%.1f  \n",a_stu[i]/N);
        }
    printf("课平均分 ");
    for(j=0;j<M;j++)
    {

        printf("%.1f      ",a_cor[j]/M);
    }
}




