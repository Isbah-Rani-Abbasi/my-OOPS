# include<iostream>
# include<string>
# include<fstream>
using namespace std;
int main()
{
    ofstream out("abc.txt",ios::binary|ios::app);
    char a[20]={"isbah rani abbasi"};// read and write function require type of variable as char*
    out.write(a,17);
    streampos p=out.tellp();
    cout<<p;
    out.close();

    ifstream in("abc.txt",ios::binary);
    char b[6];
    if(in.is_open())
    {
        //in.read(b,2);  //you are saying 2 bytes read karo aur b main store karwao
        in.seekg(12,ios::beg);
        streampos pos=in.tellg();
        in.read(b,2);

        cout<<pos;
        in.close();
    }
    cout<<b[0]<<b[1];

}