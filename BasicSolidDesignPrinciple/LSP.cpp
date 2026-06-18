#include<bits/stdc++.h>
using namespace std; 


// abstract class or interface hai jisse client cumunicate karega 
class Account{
    
    public:
    virtual void  deposite(double amount)=0;
    virtual void withdrawal(double amount)=0;
};

class SavingAccount: public Account{

    private:
     double balance =0;

    public:

    SavingAccount(){
        balance=0;
    }
     
    void deposite(double amount){
        balance+=amount;
        cout<<"Amount deposite "<<"new balance is "<<balance<<endl;
        return ;

    }

    void withdrawal(double amount){

        if(balance>=amount){
            balance-=amount;
            cout<<"Amount Withdrawal"<<"new balance is :"<<balance<<endl;
        }else{
            cout<<"Not Sufficient Amount"<<endl;
        }
        return ;
        
    }
};


class CurrentAccount: public Account{

    private:
     double balance =0;

    public:

    CurrentAccount(){
        balance=0;
    }
     
    void deposite(double amount){
        balance+=amount;
        cout<<"Amount deposite "<<"new balance is "<<balance<<endl;
        return ;

    }

    void withdrawal(double amount){

        if(balance>=amount){
            balance-=amount;
            cout<<"Amount Withdrawal"<<"new balance is :"<<balance<<endl;
        }else{
            cout<<"Not Sufficient Amount"<<endl;
        }
        return ;
        
    }
};

// only deposite happen
class FixedDipositeAccount: public Account{

    private:
     double balance =0;

    public:

    FixedDipositeAccount(){
        balance=0;
    }
     
    void deposite(double amount){
        balance+=amount;
        cout<<"Amount deposite "<<"new balance is "<<balance<<endl;
        return ;

    }

    void withdrawal(double amount){

        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
        
    }
};

class Client{

    private:
    vector<Account*>accounts;

    public:
    
    Client(vector<Account*>accounts){
        this->accounts=accounts;
    }

    void processTransactions(){

        for(auto it : accounts){
            it->deposite(1000);

             //Assuming all accounts support withdrawal (LSP Violation)
            try {
                it->withdrawal(500);
            } catch (const logic_error& e) {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }
};


int main(){

vector<Account*> accounts;
SavingAccount* save= new SavingAccount();
CurrentAccount*current =new CurrentAccount();
FixedDipositeAccount* fixed=new FixedDipositeAccount();
accounts.push_back(save);
accounts.push_back(current);
accounts.push_back(fixed);
Client* c=new Client(accounts);

c->processTransactions();

}