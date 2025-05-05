# include<iostream>
# include<exception>
# include<string>
using namespace std;
template <typename t>
class matrix
{
    int rows;
    int cols;
    t element;
    t **arr;
    public:
    matrix(int r, int c ):element(t())
    { 
        rows=r;
        cols=c;
    
        arr = new t*[rows];
        for(int i=0 ;i<rows ;i++)
        {
            arr[i]=new t[cols];
        }
        for(int i=0 ;i<rows;i++)
        {
            for(int j=0 ;j<cols ;j++)
            {
                arr[i][j] = t();
            }
        }
    }
    void setelement(int r ,int c , t e)
    {
        
        
        if((r>=0&& r<rows) &&(c>=0 &&c<cols))
        {
            arr[r][c]=e;
        }
    
        else
        {
            throw runtime_error{"dss"};
        }
        
    }
   
    matrix operator+(const matrix &m)
    {
        if (m.rows==rows && m.cols==cols)
            {
               matrix m2(rows,cols);
                for(int i=0 ;i<rows;i++)
                {
                    for(int j=0 ;j<cols;j++)
                    {
                      m2.arr[i][j]=arr[i][j]+m.arr[i][j];
                    }
                }
                return m2;
            } 
            else{
                throw runtime_error{"asasas"};
            } 
    }
   // template<typename t>
   friend ostream &operator <<(ostream & out , const matrix<int> &m);
        
    
    matrix(const matrix &other) : rows(other.rows), cols(other.cols) {
        arr = new t *[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new t[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    matrix &operator=(const matrix &other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;

        rows = other.rows;
        cols = other.cols;
        arr = new t *[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new t[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
        return *this;
    }
        

    };
    
    
    ostream &operator <<(ostream & out , const matrix<int> &m)
    {
      for(int i=0 ;i<m.rows ;i++)
      {
        for(int j=0 ;j<m.cols ; j++)
        {
         out<<m.arr[i][j]<<endl;
        }
      }
    }
int main()
{
    matrix<int>m2(1,1);
    matrix<int> m(1,1);
   matrix<int>m1(1,1);
    try
    {
  
  

  m.setelement(0,0,1);
  m1.setelement(0,0,1);   // all the functions with error throw call inside try block
  m2=m+m1;

    }
    catch(const exception &e)
    {
    cerr<<e.what();
    }
    cout<<m2;

  
  
 
  

 


}