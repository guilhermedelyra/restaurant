#include "Person.hpp"
int main(){
    vector<Client> c;
    vector<Functionary> f;

    int x;
    for(int i = 0; i < 4; ++i){
        cin >> x;
        if(x){
            Functionary * tmp = new Functionary();
            f.push_back(*tmp);
        } else {
            Client * tmp = new Client();
            c.push_back(*tmp);
        }
    }
}
