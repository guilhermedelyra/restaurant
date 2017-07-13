#include <ncurses.h>
#include "Person.hpp"
#include "Product.hpp"
#include "Stock.hpp"

int main(){
    vector<Client> c;
    vector<Functionary> f;
    vector<Product> dishs, desserts, drinks;
    vector<Stock> st;
    /*int x;
    for(int i = 0; i < 4; ++i){
        cin >> x;
        if(x){
            Functionary * tmp = new Functionary();
            f.push_back(*tmp);
        } else {
            Client * tmp = new Client();
            c.push_back(*tmp);
        }
    }*/
    int l = 1;
    Product * p0 = new Product("arroz carne feijao", 15.00);
    Stock * d0 = new Stock(l++, 50, 20);
    st.push_back(*d0);
    dishs.push_back(*p0);
    Product * p1 = new Product("macarrao frango feijao", 17.00);
    Stock * d1 = new Stock(l++, 35, 10);
    st.push_back(*d1);
    dishs.push_back(*p1);
    Product * p2 = new Product("stroggonof de carne", 21.50);
    Stock * d2 = new Stock(l++, 20, 5);
    st.push_back(*d2);
    dishs.push_back(*p2);
    Product * p3 = new Product("coca cola", 5.00);
    Stock * d3 = new Stock(l++, 60, 25);
    st.push_back(*d3);
    drinks.push_back(*p3);
    Product * p4 = new Product("sprite", 5.00);
    Stock * d4 = new Stock(l++, 20, 5);
    st.push_back(*d4);
    drinks.push_back(*p4);
    Product * p5 = new Product("suco de limao", 5.00);
    Stock * d5 = new Stock(l++, 35, 10);
    st.push_back(*d5);
    drinks.push_back(*p5);
    Product * p6 = new Product("suco de laranja", 5.00);
    Stock * d6 = new Stock(l++, 35, 10);
    st.push_back(*d6);
    drinks.push_back(*p6);
    Product * p7 = new Product("pudim", 8.50);
    Stock * d7 = new Stock(l++, 10, 3);
    st.push_back(*d7);
    desserts.push_back(*p7);
    Product * p8 = new Product("sorvete", 4.99);
    Stock * d8 = new Stock(l++, 15, 4);
    st.push_back(*d8);
    desserts.push_back(*p8);

    vector<Product>::iterator it;
    for (it = dishs.begin(); it != dishs.end(); ++it) {
        cout << it->name << " " << it->price << endl;
    }

    for (it = drinks.begin(); it != drinks.end(); ++it) {
        cout << it->name << " " << it->price << endl;
    }

    for (it = desserts.begin(); it != desserts.end(); ++it) {
        cout << it->name << " " << it->price << endl;
    }


}
