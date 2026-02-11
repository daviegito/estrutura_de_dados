#include<stdio.h>
int main()
{
      int i,j,size,loc,temp,min,a[20];
      printf("\tSelection sort\n");
      printf("-----------------------------------\n");
      printf(" How many numbers you want to sort?: ");
      scanf("%d",&size);
      printf("\n Enter %d numbers: \n",size);

      for(i=0;i<size;i++)
      {
            scanf("%d",&a[i]);
      }
      for(i=0;i<size-1;i++)
      {
            min=a[i];
            loc=i;
            for(j=i+1;j<size;j++)
            {
                  if(min>a[j])
                  {
                        min=a[j];
                        loc=j;
                  }
            }
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
      }
      printf("\n Sorted numbers after using selection sort: \n");
      for(i=0;i<size;i++)
      {
            printf("  %d ",a[i]);
      }
      return 0;
}