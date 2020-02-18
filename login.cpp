#include<bits/stdc++.h>
using namespace std;

class login{
    string username[100];
    string password[100];
    static int n;

    public :
    
        void setlogindetails()
        {
            char ch;
            do{
            cout<<"Enter your username : ";
            cin>>username[n];
            cout<<"Enter your password : ";
            cin>>password[n];
            cout<<"Entered username is : "<<username[n]<<endl;
            cout<<"Entered password is : "<<password[n]<<endl;      
            //do{
                cout<<"Do you confirm ? (Y/N)";
            cin>>ch;//} while((ch!='N')||(ch!='Y')) ;
           }while (ch=='N');
          n++;
          cout<<"Login details set up successfully !\n";
        }
        
        int checklogindetails()
        {
            string u,p;
            cout<<"Enter your username : ";
            cin>>u;
            cout<<"Enter your password : ";
            cin>>p;
            int flag=0;
            for (int i=0;i<n;i++)
            {
                if (username[i]==u)
                {
                    if (password[i]==p)
                      flag=1;
                }
            }

            return flag;
        }

    };

int login::n=0;

int main()
{
   login l;
   l.setlogindetails();
   l.setlogindetails();
   int p;
   p=l.checklogindetails();
   cout<<p<<endl;
   return 0;
}