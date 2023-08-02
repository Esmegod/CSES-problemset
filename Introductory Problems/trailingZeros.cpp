#include<iostream>
using namespace std;
int main(){
    int n, zeros=0;
    cin>>n;
    for(int i=5; i<=n; i*=5){
       zeros += n/i;
    }

    cout<<zeros<<"\n";
    return 0;
}