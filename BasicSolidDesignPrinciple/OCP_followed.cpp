#include <bits/stdc++.h>
using namespace std;

class Product
{

public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{

private:
    vector<Product *> products;

public:
    //   this function add product into the product vector
    void addProduct(Product *p)
    {

        products.push_back(p);
    }

    const vector<Product *> &getProducts()
    {

        return products;
    }

    double calculateTotalPrice()
    {

        double total = 0;
        for (auto it : products)
        {
            total += it->price;
        }
        return total;
    }

    void printInvoice()
    {

        cout << "Shopping Cart Invoice\n"
             << endl;

        for (auto p : products)
        {
            cout << p->name << "   " << "-$" << p->price << endl;
        }
    }

    void saveToDB()
    {

        cout << "Saving Shopping Cart to DB ....." << endl;
    }
};

class CartPrintInvoice
{

private:
    ShoppingCart *cart;

public:
    CartPrintInvoice(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void invoicePrint()
    {

        for (auto p : cart->getProducts())
        {
            cout << "price -$: " << p->price << " " << "name : " << p->name << endl;
        }
        return;
    }
};

// this class does not follow open-closed design principle
// because if we add more function to the same class then it will not follow OCP

class CartSaveToDB
{

private:
    ShoppingCart *cart;

public:
    CartSaveToDB(ShoppingCart *cart)
    {

        this->cart = cart;
    }

    void saveToSqlDatabase()
    {

        cout << "save to SQL DB" << endl;

        return;
    }

    void saveToMongoDatabase()
    {

        cout << "save to MongoDB" << endl;

        return;
    }

    void saveToFileDatabase()
    {

        cout << "save to File" << endl;

        return;
    }
};

// abstract class
class Persistence
{
private:
    ShoppingCart *cart;

public:
    Persistence(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    virtual void save(ShoppingCart *cart) = 0;
};

// Inheritance of the class
class SaveToSqlDatabase : public Persistence
{

public:
    SaveToSqlDatabase(ShoppingCart *cart)
        : Persistence(cart) {}

    void save(ShoppingCart *cart)
    {

        cout << "Save to SQL Database" << endl;
    }
};

class SaveToMongoDatabase : public Persistence
{

public:
    SaveToMongoDatabase(ShoppingCart *cart)
        : Persistence(cart) {}

    void save(ShoppingCart *cart)
    {

        cout << "Save to Mongo Database" << endl;
    }
};

class SaveToFileDatabase : public Persistence
{

public:
    SaveToFileDatabase(ShoppingCart *cart)
        : Persistence(cart) {}

    void save(ShoppingCart *cart)
    {

        cout << "Save to File Database" << endl;
    }
};

int main()
{

    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("laptop", 1500));
    cart->addProduct(new Product("ipad", 320));

    CartPrintInvoice *print = new CartPrintInvoice(cart);
    print->invoicePrint();

    Persistence *saveToSQL = new SaveToSqlDatabase();
    saveToSQL->save(cart);

    Persistence *SaveToMongo = new SaveToMongoDatabase();
    saveToSQL->save(cart);

    Persistence *saveToFile = new SaveToFileDatabase();
    saveToSQL->save(cart);
};
