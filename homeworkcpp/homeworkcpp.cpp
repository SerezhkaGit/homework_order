#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    string p_name;
    double price;
public:
    Product() : p_name(""), price(0) {}
    Product(string name_, double price_) : p_name(name_), price(price_) {}

    void setPrice(double price_) {
        price = price_;
    }

    void setName(string name_) {
        p_name = name_;
    }

    double getPrice() const {
        return price;
    }

    string getName() const {
        return p_name;
    }

    friend ostream& operator<<(ostream& out, const Product& a) {
        out << "\nProduct name: " << a.p_name;
        out << "\nPrice: " << a.price;
        return out;
    }

    friend istream& operator>>(istream& in, Product& a) {
        cout << "\nEnter product name: ";
        in >> a.p_name;
        cout << "\nEnter product price: ";
        in >> a.price;
        return in;
    }
};

class Dish {
private:
    string name;
    vector<Product> productList;
public:
    Dish() : name(""), productList(vector<Product>()) {}
    Dish(string name_) : name(name_), productList(vector<Product>()) {}

    void addProduct(const Product& product) {
        productList.push_back(product);
    }

    void removeProduct(int index) {
        if (index >= 0 && index < productList.size()) {
            productList.erase(productList.begin() + index);
        }
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& product : productList) {
            total += product.getPrice();
        }
        return total;
    }

    friend ostream& operator<<(ostream& out, const Dish& a) {
        out << "\nDish Name: " << a.name;
        for (size_t i = 0; i < a.productList.size(); ++i) {
            out << "\nProduct " << (i + 1) << ": " << a.productList[i];
        }
        return out;
    }
};

class Beverage {
private:
    string name;
    vector<Product> productList;
public:
    Beverage() : name(""), productList(vector<Product>()) {}
    Beverage(string name_) : name(name_), productList(vector<Product>()) {}

    void addProduct(const Product& product) {
        productList.push_back(product);
    }

    void removeProduct(int index) {
        if (index >= 0 && index < productList.size()) {
            productList.erase(productList.begin() + index);
        }
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& product : productList) {
            total += product.getPrice();
        }
        return total;
    }

    friend ostream& operator<<(ostream& out, const Beverage& a) {
        out << "\nBeverage Name: " << a.name;
        for (size_t i = 0; i < a.productList.size(); ++i) {
            out << "\nProduct " << (i + 1) << ": " << a.productList[i];
        }
        return out;
    }
};

class Order {
private:
    int table_num;
    vector<Dish> dishList;
    vector<Beverage> beverageList;
public:
    Order(int table_num_) : table_num(table_num_), dishList(vector<Dish>()), beverageList(vector<Beverage>()) {}

    void addDish(const Dish& dish) {
        dishList.push_back(dish);
    }

    void addBeverage(const Beverage& beverage) {
        beverageList.push_back(beverage);
    }

    void removeDish(int index) {
        if (index >= 0 && index < dishList.size()) {
            dishList.erase(dishList.begin() + index);
        }
    }

    void removeBeverage(int index) {
        if (index >= 0 && index < beverageList.size()) {
            beverageList.erase(beverageList.begin() + index);
        }
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& dish : dishList) {
            total += dish.calculateTotal();
        }
        for (const auto& beverage : beverageList) {
            total += beverage.calculateTotal();
        }
        return total;
    }

    void showOrdersForTable(int table) const {
        if (table == table_num) {
            cout << "Orders for Table " << table << ":" << endl;
            for (const auto& dish : dishList) {
                cout << dish << endl;
            }
            for (const auto& beverage : beverageList) {
                cout << beverage << endl;
            }
        }
        else {
            cout << "No orders for Table " << table << endl;
        }
    }
};

int main() 
{
    Product product1("Pizza", 10.99);
    Product product2("Salad", 5.99);
    Product product3("Coke", 1.99);

    Dish dish("Special Pizza");
    dish.addProduct(product1);
    dish.addProduct(product2);

    Beverage beverage("Soft Drinks");
    beverage.addProduct(product3);

    Order order(1);
    order.addDish(dish);
    order.addBeverage(beverage);

    order.showOrdersForTable(1);
    return 0;
}
