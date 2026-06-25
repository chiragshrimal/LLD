// DIP---> Dependency inversion principle

#include<bits/stdc++.h>
using namespace std;


// abstract class hogi ye 
class Database{

    public : 

    virtual void save(string data)=0;
};

class MongoDB: public Database{

    public : 

    void save(string data)override{
        cout<<"save data to MongoDB"<<data<<endl;
    }
};


class SqlDB : public Database{

    public: 

    void save(string data)override{
        cout<<"save data to SqlDB"<<data<<endl;
    }
};


// Application
class UserService{

    private: 
    string data ;
    Database* p;

    public : 

    UserService(Database*p, string data){
        this->p=p;
        this->data=data;
    }
    
    void save(){
        p->save(data);
    }
};

int main(){

    string data ="i am chirag";
    MongoDB*m=new MongoDB();
    SqlDB*s=new SqlDB();
    UserService* mongo=new UserService(m,data);
    mongo->save();
    UserService*sql= new UserService(s,data);
    sql->save();

}