# include<iostream>
# include<exception>
using namespace std;
int main()
{
    int arr[2]={1,2};
    try
    {
        int *ptr=new int[99999999999999999];
       
    }
    catch(std::bad_alloc &e)
    {
     cout<< e.what() << '\n';
    }
    
}








