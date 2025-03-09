# include<iostream>
using namespace std;
float* secondHighest(float *arr , int size )
{
    float h1=arr[0];
    float h2=arr[1];
    float temp;
    if(h2>h1)
    {
        temp = h2;
        h2 = h1;
        h1 = temp;
    }
    for (int i =0 ;i<size ;i++)
    {
        if(arr[i]>h1 )
        {
            h2=h1;
            h1=arr[i];
        }
        else if(arr[i]>h2 && arr[i]!=h1)
        {
            h2 = arr[i];
        }
    }
    
    float *h = new float ;
    h = &h2;

    return h;
  


}
int main()
{
    int size;
    float h=0;
    cout<<"Enter size"<<endl;
    cin>>size;
    float arr[size];
    for (int i=0 ; i<size;i++)
    {
        cout<<"Enter arr["<<i+1<<"]"<<endl;
        cin>>arr[i];
    }
    float *h2 ;
    h2= secondHighest(arr , size);
    cout<<"The second highest element of array is:"<<*h2;
    delete h2;
}