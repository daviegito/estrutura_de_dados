#include<stdio.h>
#define maxsize 20
int main()
{
      int array[maxsize];
      int i, j, num, t;
      printf("How many numbers you want to enter : ");
      scanf("%d", &num);
      printf("\nEnter %d numbers :\n",num);
      for (i = 0; i < num; i++)
      {
            scanf("%d", &array[i]);
      }
      printf("\nInput array is : \n\n");
      for (i = 0; i < num; i++)
      {
            printf("%d ", array[i]);
      }
      /* Bubble sorting begins */
      for (i = 0; i < num; i++)
      {
            for (j = 0; j < (num - i - 1); j++)
            {
                  if (array[j] > array[j + 1])
                  {
                        t = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = t;
                  }
            }
      } // end of sorting
      printf("\n\nSorted array is : \n\n");
      for (i = 0; i < num; i++)
      {
            printf("%d ", array[i]);
      }
      return 0;
}