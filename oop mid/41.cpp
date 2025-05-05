# include<iostream>
# include<string>
using namespace std;


class A
{
    int a;
    int b;
    string arr[3];
    int size;
    friend class B;
    public:
    A(int a , int b, int s , string arr[]):a(a),b(b),size(s)
    {
        for(int i=0 ;i<this->size ;i++)
        {
            this->arr[i]=arr[i];
        }
    }
    A(string *ptr , int s)
    {
        size =s;
        for (int i=0;i<size;i++)
        {
            arr[i]=ptr[i];
        }
    }

};
class B
{
    int c;
    public:
    void AccessclassA( A &obj)
    {
       for(int i=0 ;i<obj.size ;i++)
       {
        cout<<obj.arr[i]<<endl;
       }
    }
    friend void classB(B & obj);

};
void classB( B &obj)
{
    string arr[3]={"isbah","rani","abbasi"};
    A obj1(8,3,3,arr);
  obj.c=10;
  cout<<obj.c<<endl;
  obj.AccessclassA(obj1);

}
int main()
{
    
    string arr[3]={"isbah","rani","abbasi"};
    A obj(8,3,3,arr);
    A obj3(arr , 3);
    B obj2;
    //obj2.AccessclassA(obj3);
    classB(obj2);
}
