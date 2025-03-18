#include<stdio.h>
#include<time.h>

void simple_sort(int a[],int low,int mid,int high,int n)
{
    int i=low,k=low,j=mid+1;
    int c[n];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];

        }
        else
        {

            c[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        c[k++]=a[i++];

    }
    while(j<=high)
    {

        c[k++]=a[j++];
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=c[i];
    }
}
void merge_sort(int a[],int low,int high,int n)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(a,low,mid,n);
        merge_sort(a,mid+1,high,n);
        simple_sort(a,low,mid,high,n);
    }
}
void main()
{
    int n;
    printf("\n Enter no. of elements\n");
    scanf("%d",&n);
    int a[n];
    clock_t start,end;
    printf("\n Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start=clock();
    merge_sort(a,0,n-1,n);
    end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThe sorted array is ");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\nTime taken is %f ",time_taken);
}

