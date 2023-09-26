#include<iostream>
#include<vector>
using namespace std; 

void bfs(int node, vector<int> graph [], vector<int>& visited){
    if(visited[node]) return;
    visited[node] = 1;

    for(auto newNode: graph[node]){
        bfs(newNode, graph, visited);
    }
}


int main(){
    int n, m, a, b; 
    cin>>n>>m;

    vector<int> graph[n+1];

    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(n+1, 0);
    vector<int> cities;

    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        bfs(i, graph, visited);
        cities.push_back(i);
    }

    if(cities.size()>1){
        cout<<cities.size()-1<<"\n";
        for(int i=1; i<cities.size(); i++){
            cout<<cities[i-1]<<" "<<cities[i]<<"\n";
        }

    }else cout<<"0\n";

    return 0;
}