#include<bits/stdc++.h>
using namespace std;

class bookdetails{
    string bookname[100],author[100],bookcode[100];
    int price[100],bookid[100];
    static int n2;

    public:
    void getbookdetails()
    {
        cout<<"Enter bookname : "; cin>>bookname[n2];
        bookid[n2]=n2+1;
        cout<<"Enter book code : "; cin>>bookcode[n2];
        cout<<"Enter author name : "; cin>>author[n2];
        cout<<"Enter price : Rs "; cin>>price[n2];
        n2=n2+1;
    }

    void displaybookdetails()
    {
       cout<<"Bookid\tBookname\tBookcode\tBookauthor\tBookprice\n";

        for (int i=0;i<n2;i++){
        cout<<bookid[i]<<std::setfill (' ') << std::setw (15)<<bookname[i]<<std::setfill (' ') << std::setw (15)<<bookcode[i]<<std::setfill (' ') << std::setw (15)<<author[i]<<std::setfill (' ') << std::setw (15)<<price[i]<<endl;
        }
    }

    void editbook()
    {
        int ch,ch2,Change;
        string change;
        char c;

        do{
        cout<<"Enter the bookid which you want to edit\n";
        cin>>ch;
        int flag=0;
        if(ch>n2){
         cout<<"Wrong ID !\n";
         flag=1;
        }
        c='Y';
        if (flag==0)
        {
        while (1){
        
         cout<<"Edit :\n1.Bookname\t2.Book Code\t3.Author\t4.Price\t5.Exit\n";
         cin>>ch2;
         if (ch2==1){
             
        for (int i=0;i<n2;i++)
        {
         if (i==ch)
         {
             cout<<"Enter the new bookname : ";
             cin>>change;
             bookname[i]=change;
             cout<<"Bookname successfully updated to "<<change<<endl;
             flag=1;
             break;
         }
        }
         }

         if (ch2==2){
            
        for (int i=0;i<n2;i++)
        {
         if (i==ch)
         {
             cout<<"Enter the new bookcode : ";
             cin>>change;
             bookcode[i]=change;
             cout<<"Bookcode successfully updated to "<<change<<endl;
             flag=1;
             break;
         }
        }
         }
      

         if (ch2==3){
             
        for (int i=0;i<n2;i++)
        {
         if (i==ch)
         {
             cout<<"Enter the new author : ";
             cin>>change;
             author[i]=change;
             cout<<"BookAuthor successfully updated to "<<change<<endl;
             flag=1;
             break;
         }
        }
         }
  
        if (ch2==4){
        
        for (int i=0;i<n2;i++)
        {
         if (i==ch)
         {
             cout<<"Enter the new bookprice : ";
             cin>>Change;
             price[i]=Change;
             cout<<"Bookprice successfully updated to "<<Change<<endl;
             flag=1;
             break;
         }
        }
        }

         if (ch2==5)
           break;


         if ((ch2<1)||(ch2>5))
          cout<<"Wrong Choice !\n";
      }
      
      cout<<"Do you want to change another book?(Y/N)";
      cin>>c;

      }
      }while(c=='Y');
       
    }
    
};
int bookdetails::n2=0;

int main()
{
    bookdetails b;

    b.getbookdetails();
    b.getbookdetails();
    b.displaybookdetails();
    b.editbook();
    b.displaybookdetails();
    return 0;
}