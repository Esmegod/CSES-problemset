#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int const MAX = 1005;
pair<int, int> A, B;
int visitados[MAX][MAX], n, m;
char tablero[MAX][MAX], caminos[MAX][MAX];

pair<int, int> deltas[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; //arriba, abajo, izq, derecha
char movimientos[4] = {'U', 'D', 'L', 'R'};

void hace_caminos(int x, int y){
    queue<pair<int,int>> cola;
    cola.push({x,y});
    visitados[x][y] = 1;
    int i;
    while(!cola.empty()){
        pair<int, int> nodo = cola.front();
        cola.pop();
        // visitamos los nodos a donde puede llegar 
        i=0;
        for(auto delta: deltas){
            x = nodo.first + delta.first; y = nodo.second + delta.second; 
            if((x>=0 && x<n && y>=0 && y<m) && tablero[x][y]!='#' && !visitados[x][y]){
                visitados[x][y] = 1;
                caminos[x][y] = movimientos[i]; 
                cola.push({x,y});
            }
            i++;
        } 
    }
}

void imprime_caminos(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(caminos[i][j]=='\0') cout<<"# ";
            else cout<<caminos[i][j]<<" ";
        }
        cout<<endl;
    }
}

string hace_camino_mas_corto(int x, int y){
    string camino_mas_corto = "";
    while(x!=A.first || y!=A.second){
        camino_mas_corto += caminos[x][y];
        if(caminos[x][y]=='U') x += 1;
        else if (caminos[x][y]=='D') x -= 1;
        else if (caminos[x][y]=='L') y += 1;
        else y -= 1;
    }

    return camino_mas_corto;
}

int main(){
    cin>>n>>m;

    //Llenamos tablero
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tablero[i][j];
            if(tablero[i][j] == 'A') A = {i,j};
            else if(tablero[i][j] == 'B') B = {i,j};
        }
    }

    //Hacemos caminos a partir de A
    hace_caminos(A.first, A.second);

    //Corroboramos que existe un camino
    if(caminos[B.first][B.second] == '\0') cout<<"NO\n";
    else{
        cout<<"YES\n";
        string camino_mas_corto = hace_camino_mas_corto(B.first, B.second);
        reverse(camino_mas_corto.begin(), camino_mas_corto.end());
        cout<<camino_mas_corto.size()<<"\n";
        cout<<camino_mas_corto<<"\n";
    }

    return 0;
}