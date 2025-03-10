# include<iostream>
# include<string>
using namespace std;


class book
{
 public:
 string name;
 string author;
 int isbn;
};

class catalog
{
  private:
  book **b;
  int bookCount;
  int bookCapacity;
  public:
  catalog():b(nullptr) , bookCapacity(0) , bookCount(0){}
 
  ~catalog()
  {
    delete []b;
  }
  void addbook(book *B)
  {
    if(bookCount == bookCapacity)
    {
        bookCapacity = (bookCapacity==0)?1:2*bookCapacity;
        book **temp = new book *[bookCapacity];
        for(int i=0 ;i<bookCount ;i++)
        {
            temp[i] = b[i];
        }
        delete []b;
        b = temp;
    }
    b[bookCount++] = B;
  }
  
  void deletebook(book *B)
  {
    int index = -1;
    if(bookCount == 0)
    {
        cout<<"Library is empty!"<<endl;
        return ;
    }
    
    
     for (int i=0 ;i<bookCount ;i++)
        {
            if (b[i] == B)
            {
                
                index = i;
                break;
            }
        }
        if(index >=0)
        {
           
        

        for(int i=index ;i<bookCount-1 ;i++)
        {
            b[i] = b[i+1];
        }
    
        bookCount--;
       
       }
       else{
        cout<<"Book not found!"<<endl;
       }
       
    
  }
  book* foundBook(book *B)
  {

      if(bookCount==0)
      {
        cout<<"Catalog is empty"<<endl;
        return nullptr;
      }
      
        for(int i=0 ;i<bookCount ;i++)
        {
            if(b[i]->isbn == B->isbn)
            {
                return b[i];
            }
        }
        cout<<"Book not found"<<endl;
        return nullptr;

        
      
  }
  void display()
  {
    for(int i=0 ;i<bookCount ;i++)
    {
        cout<<b[i]->name<<endl;
        cout<<b[i]->author<<endl;
        cout<<b[i]->isbn<<endl;

    }
  }

};





class library
{
  private:
  catalog c;
  public:
  void find(book *B)
  {
    book *b = c.foundBook(B);
    if(b != nullptr)
    {
      cout<<b->author<<endl;
      cout<<b->name<<endl;
      cout<<b->isbn<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
  }
  void addBook(book *B)
  {
    c.addbook(B);
  }
  void deletebook(book *B)
  {
    c.deletebook(B);
  }
  void display()
  {
    c.display();
  }
  

  
  
};
int main()
{
  library l;
  book *b = new book [2];
  b[0].author = "isbah";
  b[0].name = "haalim";
  b[0].isbn = 1234;
  b[1].author = "nemrah";
  b[1].name = "haalim";
  b[1].isbn = 1234;

  l.addBook(&b[0]);
  l.addBook(&b[1]);
  l.display();
  l.deletebook(&b[1]);
  l.display();
  l.find(&b[0]);
  

  
}