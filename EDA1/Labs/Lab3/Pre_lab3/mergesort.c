
      }
      else
      {
            for(k=j; k<=mid; k++)
            {
                  tmp[i]=arr[k];
                  i++;
            }
      }
      for(k=min; k<=max; k++)
      arr[k]=tmp[k];
}
void sortm(int arr[],int min,int max)
{
      int mid;
      if(min<max)
      {
            mid=(min+max)/2;
            sortm(arr,min,mid);
            sortm(arr,mid+1,max);
            merge(arr,min,mid,max);
      }
}
int main()
{
      int arr[30];
      int i,size;
      printf("\tMerge sort\n");
      printf("-----------------------------------\n");
      printf(" How many numbers you want to sort?: ");
      scanf("%d",&size);
      printf("\n Enter %d elements :\n ",size);
      for(i=0; i<size; i++)
      {
            scanf("%d",&arr[i]);
      }
      sortm(arr,0,size-1);
      printf("\n Sorted elements after using merge sort:\n\n");
      for(i=0; i<size; i++)
            printf(" %d ",arr[i]);
      return 0;
}