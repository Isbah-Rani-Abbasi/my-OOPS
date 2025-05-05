# include<iostream>
# include<string>
# include<fstream>
using namespace std;

class A
{
    public:
    int id;
    char name[50];
};

int main()
{
    A obj1 ={123,"isbah"};
    ofstream outputfile("A.dat",ios::binary);
    if(!outputfile)
    {
        return 1;
    }
    outputfile.write((char*)&obj1, sizeof(obj1));
    outputfile.close();

    A obj2;
    ifstream inputfile("A.dat",ios::binary);
    if(inputfile.is_open())
    {
        inputfile.read((char*)&obj2, sizeof(obj2));
        inputfile.close();
    }
    cout<<obj2.id<<endl<<obj2.name;
}