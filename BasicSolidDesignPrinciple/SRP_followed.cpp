#include <bits/stdc++.h>
using namespace std;

class Product{
    
    public: 
     
      string name;
      double price;

      Product(string name, double price ){
        this->name=name;
        this->price=price;
      }
      
};

class ShoppingCart{

    private:

    vector<Product*> products;

    public : 

    //   this function add product into the product vector 
       void addProduct(Product* p){
        
        products.push_back(p);
       }

       const vector<Product*>& getProducts(){

        return products;
       }


       double calculateTotalPrice(){
        
        double total=0;
        for(auto it : products){
            total+=it->price;
        }
        return total;
       }

       void printInvoice(){

        cout<<"Shopping Cart Invoice\n"<<endl;

        for(auto p : products){
            cout<<p->name<< "   "<< "-$" <<p->price<<endl;
        }
       }

       void saveToDB(){
        
        cout<<"Saving Shopping Cart to DB ....."<<endl;
       }


};

class CartPrintInvoice{

    private : 
     ShoppingCart *cart;

    public:

    CartPrintInvoice(ShoppingCart*cart){
        this->cart=cart;
    }

    void invoicePrint(){

        for(auto p : cart->getProducts()){
            cout<<"price -$: "<<p->price<<" "<<"name : "<<p->name<<endl;
        }
        return ;
    }
};

class CartSaveToDB{


    private:
    
      ShoppingCart*  cart;
    
      public:

      CartSaveToDB(ShoppingCart*cart){

        this->cart=cart;
      }

      void saveToDB(){
        
        cout<<"save to DB"<<endl;
        
        return ;
      }
};

int main(){

    ShoppingCart* cart= new ShoppingCart();

    cart->addProduct(new Product("laptop",1500));
    cart->addProduct(new Product("ipad",320));

    CartPrintInvoice* print=new CartPrintInvoice(cart);
    print->invoicePrint();

    CartSaveToDB* save= new CartSaveToDB(cart);
    save->saveToDB();
}




