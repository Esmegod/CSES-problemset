#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

int n, noMovs;

int obtineOtroNumero(int ant, int prs){
    if((ant==1 && prs==2) || (ant==2 && prs==1)) return 3; 
    else if((ant==1 && prs==3) || (ant==3 && prs==1)) return 2; 
    else return 1;
}

vector<pair<int,int>> obtieneMovimientos(int ficha, vector<pair<int,int>> anterior){
    if(ficha>n) return anterior;

    int nuevoTam = pow(2,ficha) - 1;
    vector<pair<int,int>> nuevo(nuevoTam);

    //pasar anterior a nuevo
    for(int i=1, j=0; i<nuevoTam; i+=2, j++)
        nuevo[i] = anterior[j];
    
    //Llenar faltante nuevo 
    int ant = 1, prs, x; 
    prs = ficha%2==0?2:3;
    for(int i=0; i<nuevoTam; i+=2){
        nuevo[i] = make_pair(ant,prs);
        x = prs;
        prs = obtineOtroNumero(ant, x); 
        ant = x; 
    }

    return obtieneMovimientos(ficha+1, nuevo);
}

int main(){
    
    cin>>n; 
    noMovs = pow(2,n) - 1; 

    vector<pair<int,int>> movimientos, anterior(1); 
    int ficha = 2;
    anterior[0] = make_pair(1,3); 

    movimientos = obtieneMovimientos(ficha, anterior);

    cout<<noMovs<<"\n";
    for(auto movimiento: movimientos)
        cout<<movimiento.first<<" "<<movimiento.second<<"\n";
    
    return 0;
}