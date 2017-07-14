#include <bits/stdc++.h>
using namespace std;

int main(){
    string x = "1234(5$)";
    int a = x.length() - 1, b = x.length() - 2, c = x.length() - 3;
    cout << x[a] << x[b] << x[c] << endl;
}
