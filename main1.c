#include <stdio.h>
#include <stdlib.h>

void inv(int *x,int n);
int main()
{
    int i;
    int array[10]={1,3,9,11,0,8,5,6,14,98};
    printf("ԭʼ������: \n");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");
    inv(array,10);
    printf("���෴�����ź������Ϊ:\n");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);

    return 0;
}

void inv(int *x,int n)
{
    int t,i;
    for(i=0;i<n;i++)
    {
        t=*(x+i);
        *(x+i)=*(x+n-i);
        *(x+n-i)=t;
    }
}
