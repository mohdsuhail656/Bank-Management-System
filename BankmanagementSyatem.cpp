// Admin username -> Admin0101
// Admin pin      -> admin@111
#include<iostream>
#include<string>
#include<fstream> //for using files
#include<ctime>   //for creating a random account no. according to time using srand(time(0))
#include<cstdlib>  //for selecting random number
using namespace std;
class Account{
    public:
    string holdername,accountno,email;
    string phone;
    string pin;
    long long balance;
    void input(){
        cout<<"Name: ";getline(cin,holdername);
        cout<<"Phone Number: ";cin>>phone;cin.ignore();
        cout<<"Email: ";getline(cin,email);
        cout<<"Deposit Amount: ";cin>>balance;cin.ignore();
        cout<<"Set 4-digit Pin: ";getline(cin,pin);
    }
    void display(){
        cout<<"Holder Name: "<<holdername<<", Phone: "<<phone<<", Balance: "<<balance;
    }
    string getacc(){ // for create a random account number 
        string character="123456789";
        string acc="";
        int charsize=character.size();
        int index;
        srand(time(0));
        for(int i=0;i<4;i++){
            index=rand()%charsize;
            acc+=character[index];
        }
        return "ACC"+acc;
    }
};
class User{
    private:
    Account acc;
    public:
    void accountinfo(){
        cout<<"============================================\n";
        cout<<"             - ACCOUNT INFO -     \n";
        cout<<"============================================\n";
      
        string getaccno,getpin;//cin.ignore();
        cout<<"Acount Number: ";getline(cin,getaccno);
        cout<<"PIN: ";getline(cin,getpin);
        ifstream file("bank.txt");
        if(!file.is_open()){
            cout<<"Error! File not open";
            return;
        }
        bool found=false;
        while(getline(file,acc.accountno,'*') &&
            getline(file,acc.holdername,'*') &&
            getline(file,acc.phone,'*') &&
            getline(file,acc.email,'*')&&
            file>>acc.balance &&    //read the balance this not a string 
            file.ignore() &&
            getline(file,acc.pin)){
                if(getaccno==acc.accountno && getpin==acc.pin){
                    found=true;
                    cout<<"============= Account Info ================ \n";
                    cout<<"Account Number : "<<acc.accountno<<endl;
                    cout<<"Holder Name    : "<<acc.holdername<<endl;
                    cout<<"Phone Number   : "<<acc.phone<<endl;
                    cout<<"Email          : "<<acc.email<<endl;
                    cout<<"Balance        : "<<acc.balance<<endl;
                    cout<<"-----------------------------------------\n";
                    break;
                }
        }
        file.close();
        if(!found){
            cout<<"-------------------------------\n";
            cout<<" Incorrect Account No. or Pin \n";
            cout<<"--------------------------------\n";
        }
    }
    void depositamount(){
        string getaccno,getpin;
        long long getamount;
       // long long temp_str;
        cout<<"==============================================\n";
        cout<<"              - DEPOSIT SECTION -\n";
        cout<<"==============================================\n";
        cout<<"Account Number: ";getline(cin,getaccno);
        cout<<"PIN: ";getline(cin,getpin);
        ifstream file("bank.txt");
        ofstream temp("temp.txt");
        bool found =false;
         while(getline(file,acc.accountno,'*') &&
            getline(file,acc.holdername,'*') &&
            getline(file,acc.phone,'*') &&
            getline(file,acc.email,'*')&&
            file>>acc.balance &&     // use this without converting the string 
            file.ignore() &&
            getline(file,acc.pin)){
            if(getaccno==acc.accountno && getpin==acc.pin){
                found=true;
                // temp_str=stoll(acc.balance); //conerting string into long long
                cout<<"Available Balance : "<<acc.balance<<endl;
                cout<<"Enter Amount      : ";cin>>getamount;cin.ignore();
               acc.balance+=getamount;
               cout<<" - Deposit Successfully -\n";
                cout<<"------------------------------------\n";
                cout<<"Your Balance : "<<acc.balance<<endl;
                cout<<"------------------------------------\n";
            }
             temp<<acc.accountno<<"*"<<acc.holdername<<"*"<<acc.phone<<"*"<<acc.email<<"*"<<acc.balance<<"*"<<acc.pin<<endl;
           }
           file.close();
           temp.close();
           if(!found){
            cout<<"-----------------------------------------\n";
            cout<<" Incorrect Account Number or Pin   \n";
            cout<<"-----------------------------------------\n";
        }
        remove("bank.txt");
        rename("temp.txt","bank.txt");
    }
    void withdrowamount(){
        string getaccno,getpin;
        long long getamount;
        cout<<"==================================================\n";
        cout<<"              - WITHDRAWL SECTION - \n";
        cout<<"==================================================\n";
        cout<<"Account No: ";getline(cin,getaccno);
        cout<<"PIN: ";getline(cin,getpin);
        ifstream file("bank.txt");
        ofstream temp("temp.txt");
        bool found=false;
        while(getline(file,acc.accountno,'*')&&
        getline(file,acc.holdername,'*')&&
        getline(file,acc.phone,'*')&&
        getline(file,acc.email,'*')&&
        file>>acc.balance &&
        file.ignore() &&
        getline(file,acc.pin)) {
    if(acc.accountno==getaccno && acc.pin==getpin){
        found =true;
        // temp_bal=stoll(acc.balance); // THIS is the 2nd method conert the balance into stoll if the acc.balance are declare as string we need to convert 
        cout<<"Available Balance : "<<acc.balance<<endl;
        cout<<"Enter Amount to Withdraw : ";cin>>getamount;cin.ignore();
        if(acc.balance<getamount || getamount<=0){
            cout<<"----------------------------------\n";
            cout<<"Invailed or Insufficient amount\n";
            cout<<"----------------------------------\n";
        }
        else{
        acc.balance-=getamount;
        cout<<"-Amount Withdrow Successfully-\n";
        cout<<"Remaining Balance: "<<acc.balance<<endl;
        cout<<"======================================================\n";
        }
    }
    temp<<acc.accountno<<"*"<<acc.holdername<<"*"<<acc.phone<<"*"<<acc.email<<"*"<<acc.balance<<"*"<<acc.pin<<endl;
}
if(!found){
        cout<<"-------------------------------------\n";
        cout<<"  Incorrect Account No. or Password  \n";
        cout<<"-------------------------------------\n";
    }
file.close();
temp.close();
remove("bank.txt");
rename("temp.txt","bank.txt");
    }
    void forgetpin(){
        string getaccno,getphone;
        cout<<" -------------- Forget PIN -----------------\n";
        cout<<"Account NO: ";getline(cin,getaccno);
        cout<<"Enter Registered PHone NO: ";getline(cin,getphone);
        ifstream file("bank.txt");
        bool found=false;
         while(getline(file,acc.accountno,'*')&&
        getline(file,acc.holdername,'*')&&
        getline(file,acc.phone,'*')&&
        getline(file,acc.email,'*')&&
        file>>acc.balance &&
        file.ignore()&&
        getline(file,acc.pin)){
            if(acc.accountno==getaccno && acc.phone==getphone){
                found=true;
                cout<<"---------------------------------\n";
                cout<<" Your Account PIN: "<<acc.pin<<endl;
                cout<<"---------------------------------\n";
            }
        }
       if(!found){
        cout<<"----------------------------------\n";
        cout<<"  Incorrect Account or phone \n";
        cout<<"----------------------------------\n";
       }
        file.close();
    }
    void changepin(){
        string getacc,pin,newpin;
        cout<<"------------ CHANGE PIN -------------\n";
        cout<<"ENTER ACCOUNT NUMBER : ";getline(cin,getacc);
        cout<<"ENTER OLD PIN        : ";getline(cin,pin);
        ifstream file("bank.txt");
        ofstream temp("temp.txt");
        bool found =false;
        while(getline(file,acc.accountno,'*')&&
        getline(file,acc.holdername,'*')&&
        getline(file,acc.phone,'*')&&
        getline(file,acc.email,'*')&&
        file>>acc.balance &&
        file.ignore()&&
        getline(file,acc.pin)){
            if(getacc==acc.accountno && pin==acc.pin){
                found=true;
                cout<<"----------------------------------\n";
                cout<<"ENTER NEW PIN : ";getline(cin,acc.pin);
                cout<<"\n----------------------------------\n";
                cout<<"    PIN CHANGE SUCCESSFULLY      \n";
                cout<<"-----------------------------------\n";
            }
            temp<<acc.accountno<<"*"<<acc.holdername<<"*"<<acc.phone<<"*"<<acc.email<<"*"<<acc.balance<<"*"<<acc.pin<<endl;
        }
        if(!found){
            cout<<"----------------------------------\n";
            cout<<"  Incorrect Account No. or Pin \n";
            cout<<"----------------------------------\n";
        }
        file.close();
        temp.close();
        remove("bank.txt");
        rename("temp.txt","bank.txt");
    }
    void Usermenu(){
        int choice;
        system("cls");
        do{
            cout<<"==================== USER MENU ====================\n";
            cout<<"1.Account Info\n2.Deposit Money\n3.Withdrow Money\n4.Forget Pin\n5.Change Pin\n6.Main Menu\n";
            cout<<"Enter Your choice: ";cin>>choice;cin.ignore();
            switch(choice){
                case 1:accountinfo();
                break;
                case 2:depositamount();
                break;
                case 3:withdrowamount();
                break;
                case 4:forgetpin();
                break;
                case 5:changepin();
                break;
                case 6:cout<<"Main Menu\n";
                break;
                default:cout<<"Invailed Choice! Try Again\n";
            }
        }while(choice!=6);
    }
};
class Admin{
    private:
    Account acc;
    public:
    void createaccount(){
        cout<<"=================================================\n";
        cout<<"                - CREATE ACCOUNT -\n";
        cout<<"==================================================\n";
        acc.input();
        acc.accountno=acc.getacc(); // call the function to create a account number
        ofstream file("bank.txt",ios::app);
        file<<acc.accountno<<"*"<<acc.holdername<<"*"<<acc.phone<<"*"<<acc.email<<"*"<<acc.balance<<"*"<<acc.pin<<endl;
        cout<<"-------------------------------------\n";
        cout<<"  Account Created Successfully\n";
        cout<<"  Your Account Number: "<<acc.accountno<<endl;
        cout<<"-------------------------------------\n";
        file.close();
    }
    void deleteAccount(){
        string getaccno,getpin;
        cout<<"================= DELETE ACCOUNT ================\n";
        cout<<"Account Number: ";getline(cin,getaccno);
        cout<<"PIN: ";getline(cin,getpin);
        ifstream file("bank.txt");
        ofstream temp("temp.txt");
        bool found =false;
        while(getline(file,acc.accountno,'*')&&
        getline(file,acc.holdername,'*')&&
        getline(file,acc.phone,'*')&&
        getline(file,acc.email,'*')&&
        file>>acc.balance &&
        file.ignore() &&
        getline(file,acc.pin)){
            if(acc.accountno==getaccno && acc.pin==getpin){
                found=true;
                cout<<"----------------------------------\n";
                cout<<"  Account Deleted Successfully \n";
                cout<<"----------------------------------\n";
            }
            else{
                temp<<acc.accountno<<"*"<<acc.holdername<<"*"<<acc.phone<<"*"<<acc.email<<"*"<<acc.balance<<"*"<<acc.pin<<endl;
            }
        }
        if(!found){
            cout<<"--------------------------------\n";
            cout<<"  Incorrect Account no. or Pin\n";
            cout<<"--------------------------------\n";
        }
        file.close();
        temp.close();
        remove("bank.txt");
        rename("temp.txt","bank.txt");
    }
    void allaccount(){
        ifstream file("bank.txt");
        if(file.peek()==EOF){
            cout<<"-------------------------\n";
            cout<<"        No Account \n";
            cout<<"-------------------------\n";
        }
        else{
            int i=1;
            cout<<"=================== ACCOUNT LIST ==================\n";
            while(getline(file,acc.accountno,'*')&& 
            getline(file,acc.holdername,'*')&& 
            getline(file,acc.phone,'*')&&
            getline(file,acc.email,'*')&&
            file>>acc.balance &&
            file.ignore() &&
            getline(file,acc.pin)){
            cout << i++ << ". Account Number : " << acc.accountno << endl;
            cout << "   Holder Name    : " << acc.holdername << endl;
            cout << "   Phone Number   : " << acc.phone << endl;
            cout << "   Email          : " << acc.email << endl;
            cout << "   Balance        : " << acc.balance << endl;
            cout << "----------------------------------------------------\n";
            }
            file.close();      
        }
    }
    void updateInfo(){
        string getaccno,getpin;
        cout<<"=================================================\n";
        cout<<"                  - UPDATE INFO -\n";
        cout<<"=================================================\n";
        cout<<"Account NO: ";getline(cin,getaccno);
        cout<<"PIN: ";getline(cin,getpin);
        ifstream file("bank.txt");
        ofstream temp("temp.txt");
        bool found=false;
        while(getline(file,acc.accountno,'*')&&
        getline(file,acc.holdername,'*')&&
        getline(file,acc.phone,'*')&&
        getline(file,acc.email,'*')&&
        file>>acc.balance &&
        file.ignore()&&
        getline(file,acc.pin)){
            if(acc.accountno==getaccno && acc.pin==getpin){
                found=true;
                cout<<"================== Current Details ==================\n";
                cout<<"Name: "<<acc.holdername<<endl<<"Phone NO: "<<acc.phone<<endl<<"Email: "<<acc.email<<endl;
                cout<<"------------ Enter New Details ------------\n";
                cout<<"Holder Name  : ";getline(cin,acc.holdername);
                cout<<"Phone Number : ";getline(cin,acc.phone);
                cout<<"Email        : ";getline(cin,acc.email);
                cout<<"--------------------------------\n";
                cout<<"   Details Updated Successfully \n";
                cout<<"--------------------------------\n";
            }
            temp<<acc.accountno<<"*"<<acc.holdername<<"*"<<acc.phone<<"*"<<acc.email<<"*"<<acc.balance<<"*"<<acc.pin<<endl;
        }
        if(!found){
            cout<<"-------------------------\n";
            cout<<"   Account Not Found \n";
            cout<<"-------------------------\n";
        }
        file.close();
        temp.close();
        remove("bank.txt");
        rename("temp.txt","bank.txt");
//          if (remove("bank.txt") != 0)     //FOR check the file are remove or rename 
//     perror("Error deleting original file");

// if (rename("temp.txt", "bank.txt") != 0)
//     perror("Error renaming temp file");
    }
    void Adminmenu(){
        string getusername,getpass;
        int choice;
        system("cls"); //they clear the 
        cout<<"=================== ADMIN LOGIN ==================\n";
        cout<<"UserName: ";getline(cin,getusername);
        cout<<"Password: ";getline(cin,getpass);
        system("cls");
        bool found =false;
        if(getusername=="Admin0101" && getpass=="admin@111"){
        found=true;
        do{
           // system("cls");
            cout<<"====================== ADMIN MENU =====================\n";
            cout<<"1.Create Accout\n2.Update Acocunt Info\n3.Delete Account\n4.All Account\n5.Main Menu\n";
            cout<<"Enter your Choice: ";cin>>choice;cin.ignore();
            switch(choice){
                case 1:
                createaccount();
                break;
                case 2:updateInfo();
                break;
                case 3:deleteAccount();
                break;
                case 4:allaccount();
                break;
                case 5:cout<<"Exit\n";
                break;
                default:cout<<"Invailed choice\n";
            }
        }while(choice!=5);
        }
        if(!found){
            cout<<"------------------------------------\n";
            cout<<"  Incorrect Username or Password \n";
            cout<<"------------------------------------\n";
        }
    }
};
int main(){
    User b;
    Admin m;
   //system("notepad bank.txt");
   // ofstream file("bank.txt", ios::trunc); // clean the file 
    int choice;
    do{
        system("cls");
        cout<<"======================================================\n";
        cout<<"         WELCOME TO BANK MANAGEMENT SYSTEM\n";
        cout<<"======================================================\n";
        cout<<"1.User \n2.Admin\n3.Exit\n";
        cout<<"Enter Your Choice: ";cin>>choice;cin.ignore();
        switch(choice){
            case 1:b.Usermenu();
            break;
            case 2:m.Adminmenu();
            break;
            case 3:cout<<"Exit\n";
            break;
            default:cout<<"Invailed choice! Try Again\n";
        }
    }while(choice!=3);

    return 0;
}
