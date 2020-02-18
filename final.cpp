#include<bits/stdc++.h>
#include<conio.h>  

using namespace std;


//to check if a string is number
bool isnumber(string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 

//to check if a string has only characters 
bool ischaracter(char s[50]) 
{ 
    int p=strlen(s);
    for (int i = 0; i < p; i++) 
        if (isdigit(s[i]) == true) 
            return false; 
  
    return true; 
} 


// login part

class login{
    protected:
    char username[10];
    char password[10];
    int scheck;

    public :
    
        void setlogindetails()
        {
            system("cls");
            char ch;
            //fstream file;
           // login part;
            do
            {            
            int flag=0;
            cout<<"Enter your username : ";
            cin>>username;        
           /*    
            while(!file.eof())
            {
                
                file.read((char*)&part,sizeof(part));
                cout<<part.username;
                if (strcmp(part.username,username)==0)
                {
                 flag=1;
                 break;
                }
            }
            */
            if (flag==1)
              {
               system("cls");    
               cout<<"Username already exists!\n";
               cout<<"Enter Again ? (Y/N)"<<endl;
               cin>>ch;
               }
            else
            {
            cout<<"Enter your password : ";
            cin>>password;
            cout<<"1->Administrative\t2->Student\n";
            cin>>scheck;            
            cout<<endl;
            cout<<"Entered username is : "<<username<<endl;
            cout<<"Entered password is : "<<password<<endl; 
            cout<<"Account made for "<<" type"<<scheck<<endl;     
            cout<<"Do you confirm ? (Y/N)";
            string temp;
                  do
                    {
                    cin>>temp;
                    if ((temp.length())>1)
                    {
                    ch='p'; 
                    system("cls");  
                    cout<<"Wrong Input!\nEnter Again(Y/N)\n";
                    }
                    else
                    {
                    ch=temp[0];
                    if (!((ch=='Y')||(ch=='N')))
                    {
                    system("cls");   
                    cout<<"Wrong Input!\nEnter Again(Y/N)\n";
                    }
                    }
                    }while(!((ch=='Y')||(ch=='N')));            
            }
            }while (ch=='N');
          
          system("cls");
          cout<<"Login details set up successfully !\n";
        }
        
        int checklogindetails()
        {
            system("cls");
            string u,p;
            fstream file;
            int x;
            cout<<"Enter your username : ";
            cin>>u;
            cout<<"Enter your password : ";
            cin>>p;
            cout<<"Enter your account type : (1->Administrative\t2->Student)"<<endl;
            cin>>x;
            int flag=0;
            login temp;
            file.open("logindetails.txt",ios::in|ios::out|ios::app);
            file.seekg(0);
            file.read((char*)& temp, sizeof(temp));
            while(!file.eof())
            {
                //cout<<temp.username<<" "<<temp.password<<" "<<temp.scheck<<endl;
                if (temp.username==u)
                {
                    if ((temp.password==p)&&(temp.scheck==x))
                    {
                      if (temp.scheck==1)  
                      flag=1;
                      else if (temp.scheck==2)
                      flag=2;
                    } 
                }
              file.read((char*)& temp, sizeof(temp));
            }
            file.close();

            return flag;
        }

    };



class checklogin : protected login
{
  public:

  int check()
  {
       login l;
       fstream file;
       int c,p,flag=0;
       while (1)
       {
           int t=0;
           string temp;
           cout<<"1.Login\n2.Exit\n";
           do{
           cin>>temp;
           if (isnumber(temp))
                {
                stringstream pb(temp);
                pb>>c; 
                t=1;
                }
           else
            cout<<"Enter a number!\n";
           }while(t!=1);
          if (c==1)
            {
               p=l.checklogindetails();
               if (p==0) 
               {
                    system("cls");              
                   cout<<"Wrong details !\n";
               }
               else if (p==1)
                  { 
                    flag=1;
                    break;
                  }
               else if (p==2)
                   {
                    flag=2;     
                    break;
                   }
            }
           else if (c==2)
               {flag=3;
                break;}
           else 
            {
                system("cls");
               cout<<"Wrong Choice\n";        
            }
       }
       return flag;
  }
};



// book details part
class bookdetails
{
    protected:
    char bookname[50],author[50],bookcode[50];
    int price,quantity;
};

class bookoperations : protected bookdetails
{
    public:
    void getbookdetails()
    {
        system("cls");
        cout<<"Enter bookname : "; cin>>bookname;
        cout<<"Enter book code : "; cin>>bookcode;
        cout<<"Enter author name : "; cin>>author;
        cout<<"Enter price : Rs "; cin>>price;       
        cout<<"Enter quantity : "; cin>>quantity;
    }

    void displaybookdetails()
    {
       cout<<bookname<<std::setfill (' ') << std::setw (25)<<bookcode<<std::setfill (' ') << std::setw (25)<<author<<std::setfill (' ') << std::setw (25)<<price<<std::setfill (' ') << std::setw (25)<<quantity<<endl;
      
    }

    void starting ()
    {
         system("cls");
         cout<<"BookName"<<std::setfill (' ') << std::setw (25)<<"BookCode"<<std::setfill (' ') << std::setw (25)<<"BookAuthor"<<std::setfill (' ') << std::setw (25)<<"BookPrice"<<std::setfill (' ') << std::setw (25)<<"BookQuantity"<<endl;
    }
    
    void editbook()
    {
        fstream file2;
        int ch2,Change;
        char change[50],ch[50];
        char c;
        do{
        system("cls");    
        cout<<"Enter the bookcode which you want to edit\n";
        cin>>ch;     
        c='Y';
        while (1)
        {
         system("cls");
         cout<<"Edit:\n1.Bookname\t2.Author\t3.Price\t\t4.Quantity\t5.Exit\n";
         cin>>ch2;
         if (ch2==1)
         {
             file2.open("bookdetails.txt",ios::in|ios::out|ios::ate);
             file2.seekg(0);
             bookoperations buk;
             int flag=0;
             while (!file2.eof())
                    {
                        file2.read((char*)&buk,sizeof(buk));
                        //cout<<buk.bookcode<<endl;
                        if (strcmp(buk.bookcode,ch)==0)
                        {
                            cout<<"Enter the new bookname : ";
                            cin>>change;
                            strcpy(buk.bookname,change);
                            cout<<"Bookname successfully updated to "<<buk.bookname<<endl;
                            getch();
                            flag=1;                            
                            file2.seekp(int(file2.tellp())-sizeof(buk));
                            file2.write((char*)&buk,sizeof(buk));
                            break;
                        }
                                              
                    }
           
            if (flag==0)
            {
             system("cls");   
             cout<<"Wrong Book Code!\n";
            }
         }
         
         else if (ch2==2)
         {
             file2.open("bookdetails.txt",ios::in|ios::out|ios::ate);
             file2.seekg(0);
             bookoperations buk;
             int flag=0;
             while (!file2.eof())
                    {
                    
                        file2.read((char*)&buk,sizeof(buk));
                        //cout<<buk.bookcode<<endl;
                        if (strcmp(buk.bookcode,ch)==0)
                        {
                        cout<<"Enter the new author : ";
                        cin>>change;
                        strcpy(buk.author,change);
                        cout<<"BookAuthor successfully updated to "<<buk.author<<endl;
                        getch();
                        flag=1;
                        file2.seekp(int(file2.tellp())-sizeof(buk));
                        file2.write((char*)&buk,sizeof(buk));
                        break;
                       }
                    }
            if (flag==0)
            {
             system("cls");   
             cout<<"Wrong Book Code!\n";
            }
         }
  
        else if (ch2==3)
        {    
             file2.open("bookdetails.txt",ios::in|ios::out|ios::ate);
             file2.seekg(0);
             bookoperations buk;
             int flag=0;
             while (!file2.eof())
             {
                 file2.read((char*)&buk,sizeof(buk));
                // cout<<buk.bookcode<<endl;
                 if (strcmp(buk.bookcode,ch)==0)
                 {
                    cout<<"Enter the new price : ";
                    cin>>Change;
                    buk.price=Change;
                    cout<<"Bookprice successfully updated to "<<buk.price<<endl;
                    getch();
                    flag=1;
                    file2.seekp(int(file2.tellp())-sizeof(buk));
                    file2.write((char*)&buk,sizeof(buk));
                    break;
                }
                }
         if (flag==0)
            {
             system("cls");   
             cout<<"Wrong Book Code!\n";
            }
        }

           else if (ch2==4)
        {
              
             file2.open("bookdetails.txt",ios::in|ios::out|ios::ate);
             file2.seekg(0);
             bookoperations buk;
             int flag=0;
             while (!file2.eof())
             {
                 file2.read((char*)&buk,sizeof(buk));
                 //cout<<buk.bookcode<<endl;
                 if (strcmp(buk.bookcode,ch)==0)
                 {
                    cout<<"Enter the new quantity : ";
                    cin>>Change;
                    buk.quantity=Change;
                    cout<<"Bookquantity successfully updated to "<<buk.quantity<<endl;
                    flag=1;
                    getch();
                    file2.seekp(int(file2.tellp())-sizeof(buk));
                    file2.write((char*)&buk,sizeof(buk));
                    break;
                }
                }

          if (flag==0)
            {
             system("cls");   
             cout<<"Wrong Book Code!\n";
            }
        }
         
         else if (ch2==5)
           break;
         else
         {
          system("cls");   
          cout<<"Wrong Choice !\n";
         }
      }
      
      cout<<"Do you want to change another book?(Y/N)";
      cin>>c;
      }while(c=='Y');
      
       
    }

    void deletebook()
    {
        system("cls");
        char ch[50];
        bookoperations stud;
        cout<<"Enter the Book ID of the record you want to delete\n";
        cin>>ch;
        fstream file2,file5;
        file2.open("bookdetails.txt",ios::in|ios::out|ios::ate);
        file5.open("bookdetails2.txt",ios::in|ios::out|ios::app);
        file2.seekg(0);
        file5.seekp(0);
        file2.read((char*)&stud,sizeof(stud));
        int flag=0;
        while(!file2.eof())
        {
        if (strcmp(stud.bookcode,ch)!=0)
         {file5.write((char*)&stud,sizeof(stud));}
        if (strcmp(stud.bookcode,ch)==0)
        {flag=1;}

          file2.read((char*)&stud,sizeof(stud));                  
        }
        if (flag==1)
         cout<<"Deleted record of "<<ch<<" ID succesfully !\n";
        else
         cout<<"Record not found\n";
         getch();
        file2.close();
        file5.close();
        remove("bookdetails.txt");
        rename("bookdetails2.txt", "bookdetails.txt"); 

    }
    
};



// student details part

class student
{
    protected :
    char studentname[50],studentid[10],studentemail[20],studentbooks[3][3];
    float fine;
    long long int phoneno;
    public:
    student()
    {
        int i;
          for (i=0;i<3;i++)          
           strcpy(studentbooks[i],"-");
    }
};

class studentoperations : protected student
{
    public:
    void getstudentdetails()
    {
        char temp[50];
        int flag=0;
        system("cls");
        cout<<"Enter student ID : ";
        cin>>studentid;
        cout<<"Enter student name : ";
        do{
        flag=0;
       cin.ignore();
       cin.getline(temp,sizeof(temp));
        if (ischaracter(temp)==false)
         {
         cout<<"No Digit,Enter Again!\n"; 
         flag=1;
         }
        }while(flag==1);
        strcpy(studentname,temp);
        cout<<"Enter student phone number : ";
        cin>>phoneno;
        cout<<"Enter student email id : "; 
        cin>>studentemail;
              
    }

    void displaystudentdetails()
    {
        system("cls");
        fstream file3;
        cout<<"Id"<<std::setfill (' ') << std::setw (15)<<"Name"<<std::setfill (' ') << std::setw (15)<<"PhoneNo"<<std::setfill (' ') << std::setw (15)<<"EmailId"<<std::setfill (' ') << std::setw (15)<<"BIC1"<<std::setfill (' ') << std::setw (15)<<"BIC2"<<std::setfill (' ') << std::setw (15)<<"BIC3"<<endl;
        file3.open("studdetails.txt",ios::in|ios::out|ios::app);
        file3.seekg(0);
        file3.read((char*)this,sizeof(*this));
        while(!file3.eof())
        {                        
        cout<<studentid<<std::setfill (' ') << std::setw (15)<<studentname<<std::setfill (' ') << std::setw (15)<<phoneno<<std::setfill (' ') << std::setw (15)<<studentemail<<std::setfill (' ') << std::setw (15)<<studentbooks[0]<<std::setfill (' ') << std::setw (15)<<studentbooks[1]<<std::setfill (' ') << std::setw (15)<<studentbooks[2]<<endl;
        file3.read((char*)this,sizeof(*this));
        }
        file3.close();
        getch();
    }  
    
    void displayonerecord()
    {
        system("cls");
        fstream file3;
        char id[50];
        cout<<"Enter your ID : ";
        cin>>id;
        cout<<"Id"<<std::setfill (' ') << std::setw (15)<<"Name"<<std::setfill (' ') << std::setw (15)<<"PhoneNo"<<std::setfill (' ') << std::setw (15)<<"EmailId"<<std::setfill (' ') << std::setw (15)<<"BIC1"<<std::setfill (' ') << std::setw (15)<<"BIC2"<<std::setfill (' ') << std::setw (15)<<"BIC3"<<endl;
        file3.open("studdetails.txt",ios::in|ios::out|ios::app);
        file3.seekg(0);
        file3.read((char*)this,sizeof(*this));
        int flag=0;
        while(!file3.eof())
        {
        if (strcmp(studentid,id)==0)
        {
        flag=1;
        cout<<studentid<<std::setfill (' ') << std::setw (15)<<studentname<<std::setfill (' ') << std::setw (15)<<phoneno<<std::setfill (' ') << std::setw (15)<<studentemail<<std::setfill (' ') << std::setw (15)<<studentbooks[0]<<std::setfill (' ') << std::setw (15)<<studentbooks[1]<<std::setfill (' ') << std::setw (15)<<studentbooks[2]<<endl;
        }
        file3.read((char*)this,sizeof(*this));
        }
        if (flag==0)
          cout<<"ID not found !\n";
        cout<<"Press any key to exit!\n";
        file3.close();
        getch();
    }

    void edit()
    {
        
        fstream file3,file4;
        int ch2,Change;
        char ch[50],change[50];
        char c;
        studentoperations stud;
        do
        {
        system("cls");    
        cout<<"Enter the studentid which you want to edit\n";
        cin>>ch;
        int flag=0;
        c='Y';
        while (1)
        {   
         system("cls");     
         cout<<"Edit :\n1.StudentName\t2.Student Phone No\t3.Student Email ID\t4.Exit\n";
         cin>>ch2;
        if (ch2==1)
        {
        file3.open("studdetails.txt",ios::in|ios::out|ios::ate);
        file4.open("studentdetails2.txt",ios::in|ios::out|ios::app);
        file3.seekg(0);
        file4.seekp(0);
        file3.read((char*)&stud,sizeof(stud));
        while(!file3.eof())
        {
         cout<<stud.studentid<<endl;
         if (strcmp(stud.studentid,ch)==0)
         {
             cout<<"Enter the new studentname : ";
             cin>>change;
             strcpy(stud.studentname,change);
             cout<<"Student Name successfully updated to "<<stud.studentname<<endl;
             getch();
             file4.write((char*)&stud,sizeof(stud));
             flag=1;
             
         }
         else
            { file4.write((char*)&stud,sizeof(stud));}

          file3.read((char*)&stud,sizeof(stud));
                  
        }
        file3.close();
        file4.close();
        remove("studdetails.txt");
        rename("studentdetails2.txt", "studdetails.txt"); 

       
         if (!flag)
         {
           cout<<"Wrong ID !"<<endl;
           getch();
         }
         }
         
        if (ch2==2)
        {
        file3.open("studdetails.txt",ios::in|ios::out|ios::ate);
        file4.open("studentdetails2.txt",ios::in|ios::out|ios::app);
        file3.seekg(0);
        file4.seekp(0);
        file3.read((char*)&stud,sizeof(stud));
        while(!file3.eof())
        {
        if (strcmp(stud.studentid,ch)==0)
         {
             cout<<"Enter the new Student Phone No : ";
             cin>>Change;
             stud.phoneno=Change;
             cout<<"Student Phone No successfully updated to "<<stud.phoneno<<endl;
             getch();
             flag=1;
             file4.write((char*)&stud,sizeof(stud));
             
         }
         else
            { file4.write((char*)&stud,sizeof(stud));}

          file3.read((char*)&stud,sizeof(stud));                  
        }
        file3.close();
        file4.close();
        remove("studdetails.txt");
        rename("studentdetails2.txt", "studdetails.txt"); 
        if (!flag)
        {
         cout<<"Wrong ID !"<<endl;
         getch();
        }
        }
      

         if (ch2==3)
         {
        file3.open("studdetails.txt",ios::in|ios::out|ios::ate);
        file4.open("studdetails2.txt",ios::in|ios::out|ios::app);
        file3.seekg(0);
        file4.seekp(0);
        file3.read((char*)&stud,sizeof(stud));
        while(!file3.eof())
        {
        if (strcmp(stud.studentid,ch)==0)
         {
             cout<<"Enter the new Student Email ID : ";
             cin>>change;
             strcpy(stud.studentemail,change);
             cout<<"Student Email ID successfully updated to "<<stud.studentemail<<endl;
             getch();
             flag=1;
             file4.write((char*)&stud,sizeof(stud));
             
         }
         else
            { file4.write((char*)&stud,sizeof(stud));}

          file3.read((char*)&stud,sizeof(stud));                  
        }

        file3.close();
        file4.close();
        remove("studdetails.txt");
        rename("studdetails2.txt", "studdetails.txt"); 
        if (!flag)
        {
         cout<<"Wrong ID!\n";
         getch(); 
         }
        }        

         if (ch2==4)
           break;
         if ((ch2<1)||(ch2>4))
          cout<<"Wrong Choice !\n";
      } 
      
      cout<<"Do you want to change another student detail?(Y/N)";
      cin>>c;

      
      }while(c=='Y');
      
       
    }

    void deletestud()
    {
        system("cls");
        char ch[10];
        studentoperations stud;
        cout<<"Enter the Student ID of the record you want to delete\n";
        cin>>ch;
        fstream file3,file4;
        file3.open("studdetails.txt",ios::in|ios::out|ios::ate);
        file4.open("studdetails2.txt",ios::in|ios::out|ios::app);
        file3.seekg(0);
        file4.seekp(0);
        file3.read((char*)&stud,sizeof(stud));
        int flag=0;
        while(!file3.eof())
        {
        if (strcmp(stud.studentid,ch)!=0)
         {file4.write((char*)&stud,sizeof(stud));}
        if (strcmp(stud.studentid,ch)==0)
        {flag=1;}

          file3.read((char*)&stud,sizeof(stud));                  
        }
        if (flag==1)
         cout<<"Deleted record of "<<ch<<" ID succesfully !\n";
        else
         cout<<"Record not found\n";
        file3.close();
        file4.close();
        remove("studdetails.txt");
        rename("studdetails2.txt", "studdetails.txt"); 

    } 
    void issuebooks()
    {
       system("cls");
       studentoperations stud;
       fstream file3;
       int bookstaken=0,booksleft,i,token=-1;
       char a[10];
       char b;
       do
       {
       b='Y';
       file3.open("studdetails.txt",ios::in|ios::out|ios::ate);
       file3.seekg(0);
       int flag=0;
       cout<<"Enter the student ID for issue : "; cin>>a;
       while(!file3.eof())
        {
         file3.read((char*)&stud,sizeof(stud));   
         cout<<stud.studentid<<endl;
         if (strcmp(stud.studentid,a)==0)
         {
           for (int i=0;i<3;i++)
           {
              if (strcmp(stud.studentbooks[i],"-")==1)
                bookstaken++;
           }
           system("cls");
             booksleft=3-bookstaken;
            cout<<booksleft<<endl;
            if (booksleft==0)
             cout<<"Sorry, "<<stud.studentname<<" cant issue more books !\n";

             else
             {
                char a[50];
                cout<<stud.studentname<<" can issue "<<booksleft<<" books\n";
                cout<<"Enter the bookcode to issue book\n";
                cin>>a;                
                for (int i=0;i<3;i++)
                {
                    if ((strcmp(stud.studentbooks[i],"-"))==0)
                       {token=i;
                        break;
                       }
                }
                strcpy(stud.studentbooks[token],a);
                file3.seekp(int(file3.tellp())-sizeof(stud));
                file3.write((char*)&stud,sizeof(stud));
                system("cls");
                cout<<"Successfully issued !\n";        
                getch();       
              } 
              flag=1;
              break;
           }
           file3.close();            
         }
        if (flag==0)
        {cout<<"Wrong ID !\n";
        cout<<"Do you want to exit?\n(Y/N)";  cin>>b;}
        } while(b=='N');       

    }

    void returnbook()
    {
       system("cls");
       fstream file3;
       int i,token=-1;
       char a[10];
       studentoperations stud;
       char b;
        do
       {
       file3.open("studdetails.txt",ios::in|ios::out|ios::ate);
       file3.seekg(0);      
       int flag=0;char b='N';
       cout<<"Enter the student ID for return : "; 
       cin>>a;

        while(!file3.eof())
        {
         file3.read((char*)&stud,sizeof(stud));   
         cout<<stud.studentid<<endl;
         if (strcmp(stud.studentid,a)==0)
         {
           char c[50];  
           cout<<"Enter Book Code for return\n ";
           cin>>c;  
           flag=1;  
           int flag1=0;
            for (i=0;i<3;i++)
             {
                if (strcmp(stud.studentbooks[i],c)==0)
                    {
                        cout<<"reached here\n";
                        strcpy(stud.studentbooks[i],"-");
                        flag1=1;
                        cout<<"Successfully Returned !\n";
                        file3.seekp(int(file3.tellp())-sizeof(stud));
                        file3.write((char*)&stud,sizeof(stud));
                        b='Y';
                        break;
                    }    
            }
            if (flag1==0)
              cout<<"Wrong BookCode!\n";
            else
              break;          
         }             
        }
        if (flag==0)
        {cout<<"Wrong ID !\n";
        cout<<"Do you want to exit?\n(Y/N)";  cin>>b;}
       } while(b=='N');

    }

};

int checkauthenticity(int p)
{
    if (p==6211)
      return 1;
    else 
      return 0;
}

int main()
{
   char ch;
   string temp;
   int x=0,y,flag=0;
   do
   {
   system("cls");
   cout<<"Enter software code : "; 
   cin>>temp;
   if (isnumber(temp))
   {
       stringstream pb(temp);
       pb>>x; 

     y=checkauthenticity(x);
     if (y==0)
    {
        system("cls");
        cout<<"Wrong software code!\n";
        cout<<"Want to try again?(Y/N)\n";
        do
        {
        cin>>temp;
        if ((temp.length())>1)
        {
         ch='p'; 
         system("cls");  
         cout<<"Wrong Input!\nEnter Again(Y/N)\n";
        }
        else
        {
        ch=temp[0];
        if (!((ch=='Y')||(ch=='N')))
        {
         system("cls");   
         cout<<"Wrong Input!\nEnter Again(Y/N)\n";
        }
        }
        }while(!((ch=='Y')||(ch=='N')));
    }
    if (y==1)
    {
      flag=1;
      break;
    }

   }
   else  
   {
       system("cls");
       cout<<"Enter a number !\n";  
       ch='Y';
   }
   }while (ch=='Y'); 
 
  if (flag==1)
  {
     system("cls");
     cout<<"----------------------------------------------------------------------------"<<endl;
     cout<<"-             INDIAN INSTITUTE OF INFORMATION TECHNOLOGY NAGPUR            -"<<endl;
     cout<<"-                           LIBRARY SYSTEM                                 -"<<endl; 
     cout<<"----------------------------------------------------------------------------"<<endl;   
     getch();
    char ans;
    cout<<"Do you have an account ?(Y/N)\n";
    cin>>ans;
    if (ans=='N')
    {
    login l;
    fstream file;
    file.open("logindetails.txt",ios::out|ios::app|ios::in);
    l.setlogindetails();
    file.write((char*)&l, sizeof(l));
    file.close();
    }
  while(1)
   {       
       int ac=0,p;
       checklogin c;
       ac=c.check();
       if (ac==1)
       {  
           system("cls");
           cout<<"Sucessfully logged in as an administrative account\n";
           getch();
           do{         
           system("cls");    
           cout<<"1.Book Details\t2.Student Details\t3.Logout\n4.Set Login Details\n5.Exit\n";
           int flag;
           
           char temp[50];
           cin>>temp;
           if (ischaracter(temp)==true)
           {
             cout<<"Enter a number!\n";
             getch();
             exit(0);
           }           
           else
           {                       
           stringstream pb(temp);
           pb>>p; 
           }
           if (p==1)
           {
               
               bookoperations b;
               int a;
               while (1)
               {
                system("cls");
               cout<<"1.Enter Book Detail\n2.Display Book Detail\n3.Edit Book Detail\n4.Delete a Record\n5.Exit\n";
               cin>>a;
               if (a==1)
               {
                 fstream file2;  
                 file2.open("bookdetails.txt",ios::in|ios::out|ios::app);
                 b.getbookdetails();
                 file2.write((char*)&b,sizeof(b));
                 file2.close();
                 cout<<"Successfully Entered!\n";
                 getch();
               }
               else if (a==2)
               {
                 fstream file2;  
                 file2.open("bookdetails.txt",ios::in|ios::out|ios::app);
                 file2.seekg(0);
                 b.starting();
                 file2.read((char*)&b,sizeof(b));
                 while(!file2.eof())
                 {                 
                 b.displaybookdetails();
                 file2.read((char*)&b,sizeof(b));
                 }
                 file2.close();
                  getch();
               }
               else if (a==3)
                  b.editbook();
               else if (a==4)
                  b.deletebook();
               else if (a==5)
                  break;
               else 
                 cout<<"Wrong Choice\n";                 
               }

           }

           else if (p==2)
           {
               studentoperations s;
               int a;
              while (1)
               {
               system("cls");    
               cout<<"1.Enter Student Details\n2.Display Student Details\n3.Edit Student Details\n4.Issue Book\n5.Return Book\n6.Delete a record\n7.Exit\n";
               cin>>a;
               if (a==1)
               {
                fstream file3;
                file3.open("studdetails.txt",ios::in|ios::out|ios::app);
                s.getstudentdetails();
                file3.write((char*)&s,sizeof(s));
                file3.close();
                cout<<"Succesfully Entered!\n";
                getch();
               }
               else if (a==2)
                s.displaystudentdetails();
               else if (a==3)
                s.edit();
               else if (a==4)
                  s.issuebooks();
               else if (a==5)
                 s.returnbook();
               else if (a==6)
                 s.deletestud();
               else if (a==7)
                 break;
               else 
                 cout<<"Wrong Choice\n";                   
               }
           }

           else if (p==3){
               cout<<"Sucessfully Logged Out !\n";
           }
           else if (p==4)
           {
              login l;
              fstream file;
              file.open("logindetails.txt",ios::out|ios::app|ios::in);
              l.setlogindetails();
              file.write((char*)&l, sizeof(l));
              file.close();
           }
           
           else if (p==5)
            break;
           else 
           cout<<"Wrong Choice !\n";             
       }while (p!=3);
     }
     else if (ac==2)
     {
         system("cls");
         cout<<"Successfully logged in via a Student Acccout\n";
         getch();
         studentoperations s;
         s.displayonerecord();
     }
     else if (ac==3)
      break;    
   }
  }
   return 0;
}