#include <iostream>

using namespace std;
void Merge(int a[],int low,int high,int mid)
{
    int i,j,k,temp[high-low+1];
    i=low;
    k=0;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;

        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {

        temp[k]=a[i];
        k++;
        i++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=temp[i-low];
    }
}
void MergeSort(int a[],int low,int high)
{if(low<high)
{
    int mid=(low+high)/2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    Merge(a,low,high,mid);}
}
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int low,int high)
{
    int i,temp,temp1;
    i=low-1;
    int piv=a[high];
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<=piv)
        {
            i=i+1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;

}
void Quicksort(int a[],int low,int high)
{if(low<high)
{
    int pi=partition(a,low,high);
    Quicksort(a,low,pi-1);
    Quicksort(a,pi+1,high);
}


}
int main()
{cout<<"Welcome to the minor project of Data Analysis and Algorithms"<<endl;
int number,i,arr[100],choice;
 cout<<"enter the number of elements in an array"<<endl;
 cin>>number;
 for(i=0;i<number;i++)
 cin>>arr[i];
 cout<<"enter 1 for merge sort"<<endl;
 cout<<"enter 2 for quick sort"<<endl;
 cin>>choice;
 switch(choice)
 {case 1:
     {
 MergeSort(arr,0,number-1);
 cout<<"The sorted array is"<<endl;
 for(i=0;i<number;i++)
    cout<<arr[i]<<endl;
    break;
     }
 case 2:
    {
        Quicksort(arr,0,number-1);
        cout<<"The sorted array is"<<endl;
        for(i=0;i<number;i++)
            cout<<arr[i]<<endl;
        break;
    }

}
}
