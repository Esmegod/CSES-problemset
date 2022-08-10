#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, x;
    cin>>n>>x;
    vector<int> answer;
    answer.resize(x+1,0);
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    answer[0]=1;
    for(int i=1; i<=x; i++){
        for(auto ci:coins){
            if(ci<=i){
                answer[i] += answer[i-ci];
                answer[i] %= 1000000007;
            }
        }
    }
    cout<<answer[x];
    return 0;
}