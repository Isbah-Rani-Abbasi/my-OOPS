# include<iostream>
# include<fstream>

using namespace std;

class writefile
{
    private:
    ofstream outputfile;
    string name;
    public:

    writefile(string n)
    {
        outputfile.open(n,ios::app);
        if(! outputfile)
        {
            exit(1);
        }
    }
    void write(string data)
    {
        if(outputfile.is_open())
        {outputfile<<endl;
        outputfile<<data;
        }
    }
    ~writefile()
    {
        if (outputfile.is_open()){
        outputfile.close();}

    }

};
class readfile
{
    private:
    ifstream inputfile;
    public:
    readfile(const string& n)
    {
        inputfile.open(n);
        if(!inputfile)
        {
            exit(0);
        }
    }
    void read()
    {
        string n;
        if (inputfile.is_open())
        {
            
            while ((getline(inputfile,n)))
            
            {
             cout<<n<<endl;
            }
            
        }
    }
    ~readfile()
    {
        if(inputfile.is_open())
        {
            inputfile.close();
        }
    }
};

int main()
{
    writefile f("outputfile.txt");
    f.write("i am isbah");

    readfile a("outputfile.txt");
    a.read();

}