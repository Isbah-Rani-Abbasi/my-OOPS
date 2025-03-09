# include<iostream>
# include<string>
using namespace std;
class book
{
    private:
    string name;
    string isbn;
    string publisher;
    string author;
    public:
    book():name("Null"),isbn("Null"),publisher("Null"),author("Null"){}
    void setname(string n)
    {
        name = n;
    }
    void setisbn(string n)
    {
        isbn = n;
    }
    void setpublisher(string p)
    {
        publisher = p;
    }
    void setauthor(string a)
    {
        author = a;
    }
    string getname();
    string getisbn();
    string getauthor();
    string getpublisher();
    void getbookinfo();

};
string book:: getname()
{
    return name;
}
string book::getisbn()
{
    return isbn;
}
string book::getauthor()
{
    return author;
}
string book::getpublisher()
{
    return publisher;
}
void book::getbookinfo()
{
    cout<<"Name of book:"<<name<<endl<<"ISBN of book:"<<isbn<<endl<<"Author of book:"<<author<<endl<<"Publidher of book:"<<publisher<<endl;
}
int main()
{
    string name , n , p ,a;
    book *b = new book[2];
    for(int i=0 ;i<2;i++)
    {
        cout<<"Enter book name"<<endl;
        cin>>name;
        cout<<"Enter book isbn"<<endl;
        cin>>n;
        cout<<"Enter book author"<<endl;
        cin>>a;
        cout<<"Enter book publisher"<<endl;
        cin>>p;
        b[i].setauthor(a);
        b[i].setisbn(n);
        b[i].setname(name);
        b[i].setpublisher(p);

    }
    for(int i=0; i<2;i++)
    {
        b[i].getbookinfo();
    }
    for(int i=0; i<2;i++)
    {
       delete []b;
    }
}