#include<bits/stdc++.h>
using namespace std;

class bookdetails
{

    char bookname[50],author[50],bookcode[50];
    int price;

    public:
    void getbookdetails()
    {    
        
        cout<<"Enter bookname : "; cin>>bookname;
        cout<<"Enter book code : "; cin>>bookcode;
        cout<<"Enter author name : "; cin>>author;
        cout<<"Enter price : Rs "; cin>>price;  
    
    }

    void displaybookdetails()
    {
               
        cout<<std::setfill (' ') << std::setw (15)<<bookname<<std::setfill (' ') << std::setw (15)<<bookcode<<std::setfill (' ') << std::setw (15)<<author<<std::setfill (' ') << std::setw (15)<<price<<endl;
    
    }
 
};

int main()
{
    bookdetails c,b;
    fstream file2;
    /*
    file2.open("bookdetails.txt",ios::out|ios::app);
     b.getbookdetails();
    file2.write((char*)&b,sizeof(b));
    b.getbookdetails();
    file2.write((char*)&b,sizeof(b));
    file2.close();
    */
    file2.open("bookdetails.txt",ios::in);
    file2.seekg(0);
    file2.read((char*)&c,sizeof(c));
    while (!file2.eof())
    {
    c.displaybookdetails();
     file2.read((char*)&c,sizeof(c));
    }
    file2.close();
    return 0;
}