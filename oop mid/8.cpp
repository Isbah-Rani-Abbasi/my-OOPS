# include<iostream>
# include<string>
using namespace std;
void* sum(void* arr , void* size)
{
    int *aptr = (int*)arr;
    int *sptr = (int*)size;
    int *pro = new int;
    *pro = 1;
    for(int i=0;i<*sptr ;i++)
    {
    *pro *= aptr[i];
    }
    return (void*)pro;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int a=5;
    int size =5; //&a;
    void *aptr =(void*)arr;
    void *sptr =(void*)&size;
    int *pptr = (int*)sum(aptr , sptr);
    cout<<*pptr;
    delete pptr;
}