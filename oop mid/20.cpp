# include<iostream>
# include<string>
using namespace std;
class matrix
{
    private:
    int rows;
    int cols;
    double **arr;
    public:
    matrix()
    {
        rows=0;
        cols=0;
        arr=nullptr;
    }
    matrix(int r, int c): rows(r) ,cols(c)
    {
        arr = new double *[rows];
        for(int i=0 ;i<rows ;i++)
        {
            arr[i] = new double [cols];
        }
        for(int i=0 ;i<rows ;i++)
        {
            for(int j=0 ;j<cols ;j++)
            {
                arr[i][j] =0.0;
            }
        }
    }
    matrix (const matrix & obj)
    {
        rows = obj.rows;
        cols = obj.cols;
        arr = new double *[rows];
        for(int i=0 ;i<rows ;i++)
        {
            arr[i] = new double [cols];
        }
        for(int i=0 ;i<rows ;i++)
        {
            for(int j=0 ;j<cols ;j++)
            {
                arr[i][j] =obj.arr[i][j];
            }
        }

    }
    matrix &operator = (const matrix & obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        for(int i=0 ; i<rows ;i++)
        {
            delete []arr[i];
        }
        delete []arr;
        rows = obj.rows;
        cols = obj.cols;
        arr = new double *[rows];
        for(int i=0 ;i<rows ;i++)
        {
            arr[i] = new double [cols];
        }
        for(int i=0 ;i<rows ;i++)
        {
            for(int j=0 ;j<cols ;j++)
            {
                arr[i][j] =obj.arr[i][j];
            }
        }
        return *this;
    }
    matrix (matrix && obj)noexcept
    {
       rows = obj.rows;
       cols = obj.cols;
       arr =obj.arr;
       obj.rows =0;
       obj.cols =0;
       obj.arr =nullptr;
    }
    matrix & operator = (matrix &&obj)noexcept
    {
      if (this != &obj)
      {
        
        for(int i=0 ; i<rows ;i++)
        {
            delete []arr[i];
        }
        delete []arr;
        arr = obj.arr;
        rows = obj.rows;
        cols = obj.cols;
        obj.arr = nullptr;
        obj.rows = 0;
        obj.cols = 0;

      }
      return *this;
    }
    int getrows()const{
        return rows;
    }
    int getcols()const{
        return cols;
    }
    void fill (double value)
    {
        for (int i=0 ;i<rows ;i++)
        {
            for (int j=0 ; j<cols ;j++)
            {
               arr[i][j] = value;
            }
        }
    }
    const double * at(int r , int c)
    {
       if(r>=0 && r<rows && c>=0 && c<cols)
       {
        //  double *ptr = new double;
        //  ptr  =(double*)&arr[r][c];
         return &arr[r][c];
       }
       else
       {
         return nullptr;
       }
    }
    matrix transpose()
    {
        matrix t(cols ,rows);
        for (int i=0 ;i<rows ;i++)
        {
            for (int j=0 ; j<cols ;j++)
            {
               t.arr[j][i] = arr[i][j];
            }
        }
        return t;

    }
    void display()
    {
        for (int i=0 ;i<rows ;i++)
        {
            for (int j=0 ; j<cols ;j++)
            {
               cout<<arr[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    ~matrix()
    {
        for(int i=0 ; i<rows ;i++)
        {
            delete []arr[i];
        }
        delete []arr;
    }
};
int main()
{
    matrix m(2 , 3);
    cout<<m.getrows()<<endl;
    cout<<m.getcols()<<endl;
    m.fill(2.7);
    m.display();
    matrix t =m.transpose();
    t.display();
    cout<<*m.at(1,1)<<endl;
}