# include<iostream>
# include<fstream>
# include<string>
using namespace std;

int main()
{
    ofstream file("isbah.txt",ios::app); // file is name of stream , isbah.txt is name of file , ios::app id actutally file opening mode in whihc file pointer is at end of file.


    if(!file)
    {
      cout<<"file doesnot open"<<endl;
      return 1;
    }
    file<<" isbah";
    file<<" rani";
    file<<" abbasi";

    file.close();

    ifstream file1;
    file1.open("isbah.txt");
    string line;
    if(file1.is_open())
    {
        
        while(getline(file1,line))  // read liune by line
        {
          cout<<line;
          cout<<endl;
        }
        file1.close();
    }
    else{
        cout<<"not open";
    }
    
    ifstream file2;
    file2.open("isbah.txt");
    if(file2.is_open())
    {
        string word;
        char c;
        while(file2>>word)    // read word by word
        {
            cout<<word<<endl;
        }
      
        file2.close();
    }
  
   
    ifstream file3;
    file3.open("isbah.txt");
    if(file3.is_open())
    {
        string word;
        char c;
       
        while(file3.get(c))  //read char by char
        {
          cout<<c<<endl;
        }
        file3.close();
    }

    
}