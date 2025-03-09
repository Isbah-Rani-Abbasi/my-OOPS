# include<iostream>
using namespace std;
int *sun(int *arr , int size)
{
    int *sum=new int[1];
    *sum = 0;
    for(int i=0 ;i<size;i++)
    {
        *sum+=*(arr+i);
    }
    return sum;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int *s ;
    s = sun(arr , 5);
    cout<<*s;
    delete s;
}