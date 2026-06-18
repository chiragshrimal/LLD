#include<bits/stdc++.h>
using namespace std; 


// abstract class or interface hai jisse client cumunicate karega 
class NonWithdrawalAccount{
    
    public:
    virtual void  deposite(double amount)=0;
};

// only deposite happen
class FixedDipositeAccount: public NonWithdrawalAccount{

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

};

// this is also abstract class and inherite the nonwithdrawal class 
class WithdrawalAccount : public NonWithdrawalAccount{
    
    public:
    virtual void  withdrawal(double amount)=0;
};


class SavingAccount: public WithdrawalAccount{

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


class CurrentAccount: public WithdrawalAccount{

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



class Client{

    private:
    vector<NonWithdrawalAccount*>nonWithdrawalAccounts;
    vector<WithdrawalAccount*> withdrawalAccounts;

    public:
    
    Client(vector<NonWithdrawalAccount*>nonWithdrawalAccounts, vector<WithdrawalAccount*> withdrawalAccounts){
        this->nonWithdrawalAccounts=nonWithdrawalAccounts;
        this->withdrawalAccounts=withdrawalAccounts;
    }

    void processTransactionsFromNonWithdrawalAccount(){
        for(auto it : nonWithdrawalAccounts){
            it->deposite(1000);
        }
    }

    void processTransactionsFromWithdrawalAccount(){

        for(auto it : withdrawalAccounts){
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

vector<NonWithdrawalAccount*> nonWithdrawalAccounts;
vector<WithdrawalAccount*> withdrawalAccounts;

SavingAccount* save= new SavingAccount();
CurrentAccount*current =new CurrentAccount();
FixedDipositeAccount* fixed=new FixedDipositeAccount();
withdrawalAccounts.push_back(save);
withdrawalAccounts.push_back(current);
nonWithdrawalAccounts.push_back(fixed);
Client* c=new Client(nonWithdrawalAccounts,withdrawalAccounts);

c->processTransactionsFromWithdrawalAccount();
c->processTransactionsFromNonWithdrawalAccount();


}