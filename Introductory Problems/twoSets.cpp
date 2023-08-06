#include<iostream>
#include<cmath>
using namespace std;


bool espar(int n){
    return n%2==0;
}

int main(){
    long long n, suma;
    cin>>n; 

    suma = (n * (n+1))/2;

    if(!espar(suma)){
        cout<<"NO\n";
        return 0;
    }
    
    cout<<"YES\n";
    int i, j, limite = espar(n)?(n/2)+1:ceil((double)n/2);

    cout<<limite-1<<"\n";
    for(i = espar(n)?1:0, j=n; i<limite; i+=2, j-=2){
        if(i==0) cout<<j<<" ";
        else cout<<i<<" "<<j<<" ";
    } 

    cout<<"\n";
    if(espar(n)) cout<<limite-1<<"\n"; else cout<<limite<<"\n";
    for(i = espar(n)?2:1, j=n-1; i<limite; i+=2, j-=2){
        cout<<i<<" "<<j<<" ";
    } 

    return 0;
}