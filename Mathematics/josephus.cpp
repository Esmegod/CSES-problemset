#include<iostream>
using namespace std;
int main(){
    long long q, n, k;
    cin>>q;
    while(q--){
        cin>>n>>k;
        if(n==1) cout<<"1";
        else if(2*k>n)
        cout<<(((2*k)-1)%n)+1<<"\n";
    }
    return 0;
}