# include<iostream>
# include<cstring>
using namespace std;
int main()
{
    int size = 5;
    int *arr1 = new int[size];
    int check , i=0 ,j=0;
    while (1)
    {
        cout<<"Enter element or -1 to break"<<endl;
        cin>>check;
        if(check == -1)
        {
            break;
        }
        if (i>=size)
        {
            int newsize = size*2;
            int *temp =new int[newsize];
            memcpy(temp , arr1 , size*sizeof(int));
            delete []arr1;
            arr1 = temp;
            size = newsize;
        }
        arr1[i]=check;
        i++;

    }
    if(size>i)
    {
        int *temp=new int [i];
        memcpy(temp , arr1 , sizeof(int)*i);
        delete []arr1;
        arr1 = temp;
        size =i;
    }

    for(j = 0;j<size ; j++)
    {
        cout<<arr1[j]<<endl;
    }
}