#include<iostream>
using namespace std;
int main(){
    int max=0, suma_tmp=1;
    string s;
    cin>>s;
    char anterior=s[0];
    for(int i=1; i<s.size(); i++){
        if(anterior==s[i]) suma_tmp += 1;
        else{
            if(suma_tmp>max) max=suma_tmp;
            suma_tmp=1;
        }
        anterior = s[i];
    }

    if(suma_tmp>max)max=suma_tmp;
    cout<<max;
    return 0;
}