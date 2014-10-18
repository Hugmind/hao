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
        printf("1.����ɼ�\n");
        printf("2.���ѧ��ƽ����\n");
        printf("3.���ѧ��ƽ����\n");
        printf("4.�����߷�\n");
        printf("5.�������\n");
        printf("6.�˳�\n");

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
                            printf("NO %d ��ѧ����ƽ������%f \n",i+1,a_stu[i]/M);
                       break;
                       }
            case 3:
                   if(judge()==-1)
                    break;
                   else
                    {

                        for(j=0;j<M;j++)
                            printf("�γ� %d ��ƽ������ %f \n",j+1,a_cor[j]/N);
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
               printf("δ����ɼ�,����������");
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
       printf("�������%d��ѧ����5���ɼ�: \n",i+1);
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
  printf("��߷��ǵ�%d ͬѧ�ĵ�%d�ε�%f�ɼ� \n",x,y,score[x][y]);
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
    printf("�γ̺�   �γ�1   �γ�2   �γ�3   �γ�4   �γ�5   ƽ����    \n");
    for(i=0;i<N;i++)
        {
            printf("NO%d      ",i+1);
            for(j=0;j<M;j++)
               printf("%.1f      ",score[i][j]);

            printf("%.1f  \n",a_stu[i]/N);
        }
    printf("��ƽ���� ");
    for(j=0;j<M;j++)
    {

        printf("%.1f      ",a_cor[j]/M);
    }
}




