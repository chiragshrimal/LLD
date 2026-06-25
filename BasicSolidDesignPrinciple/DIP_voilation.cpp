// DIP---> Dependency inversion principle

#include<bits/stdc++.h>
using namespace std;

class MongoDB{

    public : 

    void save(string data){
        cout<<"save data to MongoDB"<<data<<endl;
    }
};


class SqlDB{

    public: 

    void save(string data){
        cout<<"save data to SqlDB"<<data<<endl;
    }
};


// Application
class UserService{

    private :
    string data;
    MongoDB*m;
    SqlDB*s;

    public :

     UserService(string data){
        this->data=data;
     }

    void saveToMongo(){
        m->save(data);
    }

    void saveToSql(){
        s->save(data);
    }
};

int main(){

    string data ="i am chirag";
    UserService* user=new UserService(data);
    user->saveToMongo();
    user->saveToSql();

}