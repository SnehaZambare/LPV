#include<iostream>
#include<omp.h>
using namespace std;

void Bubble_Sort(int arr[],int size)
{
  
        int i,temp,flag =1;
        while(flag)
        {
            flag = 0;
            #pragma omp parallel for
                for(i = 0;i<size-1;i++)
                {
                    if(arr[i]>arr[i+1])
                    {
                        temp = arr[i];
                        arr[i] = arr[i+1];
                        arr[i+1] = temp;
                        flag=1;
                    }
                }
        }
    
}

int main()
{
    int *a,n,i;
    cout<<"\n Enter total no of elements: ";
    cin>>n;
    a= new int[n];
    cout<<"\n Enter elements: ";
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    Bubble_Sort(a,n);
    cout<<"\n Sorted array is: ";
    for(i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;

}