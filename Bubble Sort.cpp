void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(&arr[j],&arr[j+1])
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}

int array[100],n;
scanf("%d",&n)
for(int i=0;i<n;i++)
{
    scanf("%d",&array[i]);
}

bubblesort(array,n)