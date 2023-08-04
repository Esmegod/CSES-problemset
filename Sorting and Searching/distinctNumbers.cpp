#include<iostream>
#include<map>
using namespace std;
map<int, int> numbers; 
int main(){
    int n, x, r=0; 
    cin>>n;
    

    for(int i=0; i<n; i++){
        cin>>x; 
        if(numbers[x]==0) r++;
        numbers[x]++;
    }

    cout<<r<<"\n";

    return 0;
}