#include <stdio.h>
#include <stdlib.h>

void inv(int *x,int n);
int main()
{
    int i;
    int array[10]={1,3,9,11,0,8,5,6,14,98};
    printf("原始数组是: \n");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");
    inv(array,10);
    printf("按相反次序存放后的数组为:\n");
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
