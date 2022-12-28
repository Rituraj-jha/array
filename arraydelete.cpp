#include<iostream>
using namespace std;
struct array
{
    int A[20];
    int size;
    int length;
};
void display(struct array arr)
{
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
        cout<<endl;
}
void add(struct array *arr,int x)
{
    arr->A[arr->length++]=x;
}
void insert(struct array *arr,int index,int x)
{
    if(index>=0&&index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
int delete1(struct array *arr,int index)
{
    int x;
    if(index>=0&&index<arr->length)
    {
     x=arr->A[index];
     for(int i=index;i<(arr->length)-1;i++)
            arr->A[i]=arr->A[i+1];
     arr->length--;
     return x;
    }
    return -1;
}
int linearsearch(struct array arr ,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        {
           return i;
        }
    }
    return -1;
}
void swap1(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=*x;
}
int linsearch(struct array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap1(&arr->A[i],&arr->A[0]);
            return 0;
        }

    }
    return -1;
}
int binarysearch(struct array arr,int key)
{
    int l,h,mid;
    l=0;h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}
int rbinarysearch(int a[],int l,int h,int key)
{int mid;
    if(l<=h)
    {
       mid=(l+h)/2;
     if(key==a[mid])
        return mid;
     else if(key<a[mid])
     {
         return rbinarysearch(a,l,mid-1,key);
     }
     else
        return rbinarysearch(a,mid+1,h,key);
    }
    return -1;
}
int main()
{
    struct array arr={{1,2,3,4,5},10,5};
   // display(arr);
    //add(&arr,30);
   // insert(&arr,3,18);
  // cout<<delete1(&arr,4);
 //  cout<<endl;
    //display(arr);
   //cout<<binarysearch(arr,6);
  // cout<<linsearch(&arr,7);
  //cout<<binarysearch(arr,2);
  cout<<rbinarysearch(arr.A,0,arr.length-1,1);
    return 0;
}
