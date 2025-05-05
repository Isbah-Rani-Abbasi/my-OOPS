# include<iostream>
# include<fstream>
# include<string>
using namespace std;
int main()
{
    ofstream outputfile;
    outputfile.open("file.txt",ios::app);

    if(!outputfile)
    {
        return 1;
    }
    outputfile<<"oooooohooohooh";
    outputfile.close();

    ifstream inputfile;
    inputfile.open("file.txt");

    if(inputfile.is_open())
    {
        string line;
        while (getline(inputfile , line))
        {
            cout<<line<<endl;
        }
        inputfile.close();
        
    }
    else{
        cout<<"close";
    }
}