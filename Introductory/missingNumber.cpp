#include<iostream>
using namespace std;
int main(){
    long long n, numero, suma=0, total;
    cin>>n;
    total = (n*(n+1))/2;
    for(int i=1; i<n; i++){
        cin>>numero;
        suma += numero;
    }
    cout<<total-suma;
    return 0;
}