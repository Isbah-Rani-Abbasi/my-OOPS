# include<iostream>
# include<string>
using namespace std;
void sum(int arr[] , int size)
{
    int sum;
    for (int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    cout<<sum;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    sum(arr , 5);
}