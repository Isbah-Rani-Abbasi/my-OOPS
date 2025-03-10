# include<iostream>
# include<cstring>
using namespace std;
class array
{
    private:
    int size;
    int *arr;
    public:
    array()
    {
        size =0;
        arr =nullptr;
    }
    array(int s )
    {
        size =s;
        arr = new int[size];
        for (int i=0 ;i<size;i++)
        {
            arr[i] = 0;
        }
    }
    array (const array &obj)
    {
        size  =obj.size;
        arr = new int[size];
        for(int i=0 ;i<size;i++)
        {
            arr[i] = obj.arr[i];
        }

    }
    array & operator =(const array & obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        delete []arr;
        size = obj.size;;
        arr = new int [size];
        for(int i=0 ;i<size;i++)
        {
          arr[i] = obj.arr[i];
        }
        return *this;
    }
    array (array && obj)noexcept
    {
        size = obj.size;
        arr = obj.arr;
        obj.arr= nullptr;
        obj.size = 0;
    }
    array & operator =(array && obj)noexcept
    {
       if (this != &obj)
       {
        delete []arr;
        size =obj.size;
        arr =obj.arr;
        obj.arr = nullptr;
        obj.size = 0;
       }
       return *this;
    }
    const int getsize(){
        return size;
    }
    const int *at(int index)
    {
      if (index<0)
      {
        return nullptr;
      }
      return &arr[index];
    }
    void resize(int newsize)
    {
        if(newsize > 0)
        {
            int *temp = new int[newsize];
            memcpy(temp , arr , sizeof(int)*size);
            delete []arr;
            arr =temp;
            size = newsize;
        }
    }
    ~array()
    {
        delete []arr;
    }
};
int main()
{
    array a(5);
    cout<<a.getsize()<<endl;
    const int *at  = a.at(2);
    cout<<*at<<endl;
    a.resize(10);
    cout<<a.getsize()<<endl;

}